#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>
#include "AllHeader.h"

#define WINDOW_WIDTH (1280)
#define WINDOW_HEIGHT (720)
#define SCROLL_SPEED (300)
 SDL_Window *win;
 SDL_Renderer *rend;
 SDL_Surface *surface;
bool init(){
     if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
     if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) > 0)
    {
        printf("video and timer: %s\n", SDL_GetError());
    }
    if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)))
        printf("image: %s\n", SDL_GetError());

    printf("Initialization Complete\n");
    if (TTF_Init() < 0)
    {
        printf("error\n");
    }
    win = SDL_CreateWindow("THE LIVING DEAD", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);

    if (!win)
    {
        printf("window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    // Mix_PlayChannel(-1,music,0);
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    rend = SDL_CreateRenderer(win, -1, render_flags);

    if (!rend)
    {
        printf("renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }


}

void close(){
    SDL_RenderPresent(rend);
    
    
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_DestroyTexture(charli1);

    SDL_DestroyTexture(charli2);
   // SDL_DestroyWindow(win);

   TTF_Quit();
  IMG_Quit();
  SDL_Quit();
}