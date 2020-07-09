#include "PVZ.h"



//PVZ_ImageFile Start
PVZ_ImageFile::PVZ_ImageFile(std::string file, SDL_Renderer* Renderer)
{
	this->Surface = IMG_Load(file.c_str());
	if (this->Surface == nullptr)
	{
		this->Error = PVZ_IMAGEFILE_LOAD_ERROR;
		return;
	}
	this->Texture = SDL_CreateTextureFromSurface(Renderer, this->Surface);
	if (this->Texture == nullptr)
	{
		this->Error = PVZ_IMAGEFILE_CREATETEXTURE_ERROR;
		return;
	}
	this->Error = PVZ_IMAGEFILE_NO_ERROR;
}
PVZ_ImageFile::~PVZ_ImageFile()
{
	SDL_FreeSurface(this->Surface);
	SDL_DestroyTexture(this->Texture);
}
//PVZ_ImageFile End



//PVZ_Image Start
PVZ_Image::PVZ_Image(SDL_Renderer* renderer, PVZ_ImageFile* imageFile, PVZ_Image* parent)
	:Parent(parent),Renderer(renderer)
{
	this->x = 0; 
	this->y = 0;
	if (imageFile != nullptr)
	{
		if (imageFile->GetError() != PVZ_IMAGEFILE_NO_ERROR)
		{
			this->Error = PVZ_IMAGE_IMAGEFILE_ERROR;
			return;
		}
		this->Surface = imageFile->GetSurface();
		this->Texture = imageFile->GetTexture();
		this->w = this->Surface->w;
		this->h = this->Surface->h;
	}
	else
	{
		this->w = 0;
		this->h = 0;
		this->Surface = nullptr;
		this->Texture = nullptr;
	}
	
	this->isShow = false;
}
PVZ_Image::~PVZ_Image()
{
}
double PVZ_Image::GetGlobalX()
{
	if (this->Parent == nullptr)
	{
		return this->GetX();
	}
	else
	{
		return this->GetX() + this->Parent->GetGlobalX();
	}
}
double PVZ_Image::GetGlobalY()
{
	if (this->Parent == nullptr)
	{
		return this->GetY();
	}
	else
	{
		return this->GetY() + this->Parent->GetGlobalY();
	}
}
void PVZ_Image::draw()
{
	if (isShow)
	{
		if (this->Texture != nullptr)
		{
			SDL_Rect rect;
			rect.x = (int)this->GetGlobalX();
			rect.y = (int)this->GetGlobalY();
			rect.w = (int)this->GetW();
			rect.h = (int)this->GetH();
			SDL_RenderCopy(this->Renderer, this->Texture, nullptr, &rect);
		}
		
	}
}
//PVZ_Image End