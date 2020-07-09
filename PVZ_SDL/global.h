#ifndef GLOBAL_H
#define GLOBAL_H



#include <iostream>
#include <fstream>
#include <string>

#if defined(_MSC_VER)
#include <SDL.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif


#include "PVZ.h"

#if defined(_WIN32)
#include <Windows.h>
#endif
using namespace std;



#endif