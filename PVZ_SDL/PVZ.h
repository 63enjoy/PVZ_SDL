#ifndef PVZ
#define PVZ
#include "global.h"




class PVZ_ImageFile
{
public:
	PVZ_ImageFile(std::string, SDL_Renderer*);
	int GetError()
	{
		return this->Error;
	}
	SDL_Surface* GetSurface()
	{
		return this->Surface;
	}
	SDL_Texture* GetTexture()
	{
		return this->Texture;
	}
private:
	int Error;
	SDL_Surface* Surface;
	SDL_Texture* Texture;
};
enum PVZ_IMAGE_FILE_ERROR
{
	PVZ_IMAGEFILE_NO_ERROR,
	PVZ_IMAGEFILE_LOAD_ERROR,
	PVZ_IMAGEFILE_CREATETEXTURE_ERROR
};





class PVZ_Image
{
public:
	//构造函数
	PVZ_Image(SDL_Renderer*, PVZ_ImageFile*, PVZ_Image*);
	//析构函数
	~PVZ_Image();
	//设置x坐标
	void setX(double x)
	{
		this->x = x;
	}
	//设置y坐标
	void setY(double y)
	{
		this->y = y;
	}
	//设置x和y坐标
	void setXY(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	//设置宽度
	void setW(double w)
	{
		this->w = w;
	}
	//设置高度
	void setH(double h)
	{
		this->h = h;
	}
	//设置宽度和高度
	void setWH(double w, double h)
	{
		this->w = w;
		this->h = h;
	}
	//设置x和y坐标，以及宽度和高度
	void setXYWH(double x,double y,double w,double h)
	{
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}
	double GetX()
	{
		return this->x;
	}
	double GetGlobalX();
	double GetY()
	{
		return this->y;
	}
	double GetGlobalY();
	double GetW()
	{
		return w;
	}
	double GetH()
	{
		return h;
	}
	void show()
	{
		this->isShow = true;
	}
	void hide()
	{
		this->isShow = false;
	}
	int GetError()
	{
		return this->Error;
	}
	void draw();
private:
	double x;
	double y;
	double w;
	double h;
	SDL_Renderer* Renderer;
	PVZ_Image* Parent;
	SDL_Surface* Surface;
	SDL_Texture* Texture;
	int Error;
	bool isShow;
};
enum PVZ_IMAGE_ERROR
{
	PVZ_IMAGE_NO_ERROR,
	PVZ_IMAGE_IMAGEFILE_ERROR
};
#endif // !PVZ


