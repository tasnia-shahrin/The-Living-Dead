#include "AllHeader.h"

SDL_Event e;
bool Running = true;
int jump_hight = 200;


void GetEvent(){
    while (SDL_PollEvent(&e))
        {

            if (e.type == SDL_QUIT)
                Running = false;

            else if (e.type == SDL_KEYDOWN)
            {
                if (e.key.keysym.sym == SDLK_DOWN)

                {
                    playerRect.x += frameW;
                    if (playerRect.x + frameW >= textureWidth)
                    {
                        playerRect.y += frameH;
                        playerRect.x = 0;
                    }
                    if (playerRect.y + playerRect.h >= textureHeight)
                        playerRect.y = 0;
                    if(playerPosition.y<500) playerPosition.y += jump_hight;
                }

                else if (e.key.keysym.sym == SDLK_UP)
                {
                    dest.y -= 10;
                    playerRect.x += frameW;
                    if (playerRect.x + frameW >= textureWidth)
                    {

                        playerRect.y += frameH;
                        playerRect.x = 0;
                    }
                    if (playerRect.y + playerRect.h >= textureHeight)
                        playerRect.y = 0;
                    if(playerPosition.y>300) playerPosition.y -= jump_hight;
                   // if(playerRect.x<ZoombieRect.x) {playerPosition.x += jump_hight; SDL_Delay(500); playerPosition.y+=jump_hight;}
                    //else playerPosition.x -= jump_hight;
                }
                else if (e.key.keysym.sym == SDLK_RIGHT)
                {
                    temp2 = charli1;
                    playerRect.x += frameW;
                    if (playerRect.x + frameW >= textureWidth)
                    {

                        playerRect.y += frameH;
                        playerRect.x = 0;
                    }
                    if (playerRect.y + playerRect.h >= textureHeight)
                        playerRect.y = 0;
                    playerPosition.x += 10;
                }
                else if (e.key.keysym.sym == SDLK_LEFT)
                {
                    temp2 = charli2;
                    playerRect.x += frameW;
                    if (playerRect.x + frameW >= textureWidth)
                    {

                        playerRect.y += frameH;
                        playerRect.x = 0;
                    }
                    if (playerRect.y + playerRect.h >= textureHeight)
                        playerRect.y = 0;
                    playerPosition.x -= 10;
                }
                  else if (e.key.keysym.sym == SDLK_j)
                {
                    temp2 = charli2;
                    playerRect.x += frameW;
                    playerPosition.y=2*100;
                    playerPosition.x=2*100;
                    if (playerRect.x + frameW >= textureWidth)
                    {

                        playerRect.y += frameH;
                        playerRect.x = 0;
                    }
                    if (playerRect.y + playerRect.h >= textureHeight)
                        playerRect.y = 0;
                    playerPosition.x -= 10;
                }
            }
        }
}