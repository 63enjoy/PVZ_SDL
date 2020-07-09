#include "global.h"
int main(int argc,char* argv[])
{

	if (SDL_Init(SDL_INIT_VIDEO)==-1)
	{
#if defined(_WIN32)
		MessageBox(NULL, TEXT("SDL初始化失败"), TEXT("错误"), MB_OK | MB_ICONERROR);
#endif
		return 1;
	}

	SDL_Window* MainWindow = SDL_CreateWindow(
		"PVZ",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		800, 600,
		SDL_WINDOW_SHOWN
	);

	if (!MainWindow)
	{
#if defined(_WIN32)
		MessageBox(NULL, TEXT("主窗口创建失败"), TEXT("错误"), MB_OK | MB_ICONERROR);
#endif
		SDL_Quit();
		return 1;
	}

	SDL_Renderer* Renderer = SDL_CreateRenderer(MainWindow, -1, SDL_RENDERER_ACCELERATED);
	if (!Renderer)
	{
#if defined(_WIN32)
		MessageBox(NULL, TEXT("Renderer创建失败"), TEXT("错误"), MB_OK | MB_ICONERROR);
#endif
		SDL_DestroyWindow(MainWindow);
		SDL_Quit();
		return 1;
	}
	PVZ_ImageFile* imageFile = new PVZ_ImageFile("resource/images/background1.png",Renderer);
	
	PVZ_Image* image = new PVZ_Image(Renderer, imageFile, nullptr);
	PVZ_Image* image1 = new PVZ_Image(Renderer, imageFile, image);
	image->setXY(10, 10);
	image1->setXY(30, 30);
	image->show();
	image1->show();
	bool isQuit=false;
	SDL_Event PVZevent;
	while (!isQuit)//消息循环
	{
		while (SDL_PollEvent(&PVZevent))
		{
			switch (PVZevent.type)
			{
			case SDL_QUIT:
				isQuit = true;
				break;
			default:
				break;
			}	
		}
		image->draw();
		image1->draw();
		SDL_RenderPresent(Renderer);
		
	}
	delete image;
	delete image1;
	delete imageFile;
	
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(MainWindow);
	SDL_Quit();
	return 0;
}