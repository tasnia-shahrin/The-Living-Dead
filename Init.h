#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>

#define WINDOW_WIDTH (1280)
#define WINDOW_HEIGHT (760)
#define SCROLL_SPEED (300)
extern SDL_Window *win;
extern SDL_Renderer *rend;
extern SDL_Surface *surface;
bool init();
void close();