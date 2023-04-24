#include "AllHeader.h"

int target;
int menu;

SDL_Event ev;
Mix_Chunk *music1 , *music2, *mouse_click;
int closeFlag = 0;
void CallMenu()
{

  target = menu;
  while (SDL_PollEvent(&ev) != 0)
  {
    if (ev.button.x > option_1.x && ev.button.x < option_1.x + option_1.w && ev.button.y > option_1.y && e.button.y < option_1.y + option_1.h)
    {
      SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
      //   SDL_GetRenderColor(rend,)
      SDL_RenderDrawRect(rend, &option_1);
   
      if (ev.type == SDL_MOUSEBUTTONDOWN && ev.key.repeat == 0)
      {
        Mix_PlayChannel(-1, mouse_click, 0);
        main_game = 1;
        Next_Back = 0;
        target = 0;
      }
    }

    if (ev.button.x > option_2.x && ev.button.x < option_2.x + option_2.w && ev.button.y > option_2.y && ev.button.y < option_2.y + option_2.h)
    {
      SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
      SDL_RenderDrawRect(rend, &option_2);

      if (ev.type == SDL_MOUSEBUTTONDOWN && ev.key.repeat == 0)
      {
        Mix_PlayChannel(-1, mouse_click, 0);
        SDL_RenderCopy(rend, tex_high, NULL, NULL);
        SDL_RenderPresent(rend);
        SDL_Delay(3000);
        main_game = 0;
        Next_Back = 1;
      }
    }

    if (ev.button.x > option_3.x && ev.button.x < option_3.x + option_3.w && ev.button.y > option_3.y && ev.button.y < option_3.y + option_3.h)
    {
      SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
      SDL_RenderDrawRect(rend, &option_3);

      if (ev.type == SDL_MOUSEBUTTONDOWN && ev.key.repeat == 0)
      {
        Mix_PlayChannel(-1, mouse_click, 0);
        SDL_RenderCopy(rend, tex_insta, NULL, NULL);
        SDL_RenderPresent(rend);
        SDL_Delay(3000);
        main_game = 0;
        Next_Back = 1;

        target = menu;
        
      }
    }

    if (ev.button.x > option_4.x && ev.button.x < option_4.x + option_4.w && ev.button.y > option_4.y && ev.button.y < option_4.y + option_4.h)
    {
      SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
        SDL_RenderDrawRect(rend, &option_4);
        // SDL_RenderPresent(rend);
      if (ev.type == SDL_MOUSEBUTTONDOWN && ev.key.repeat == 0)
      {
        Mix_PlayChannel(-1, mouse_click, 0);
        
        SDL_RenderCopy(rend, tex_credit, NULL, NULL);
        SDL_RenderPresent(rend);
        SDL_Delay(3000);
  
        main_game = 0;
        Next_Back = 1;
        
        target = menu;
      }
    }

    // if (ev.button.x > option_5.x && ev.button.x < option_5.x + option_5.w && ev.button.y > option_5.y && ev.button.y < option_5.y + option_5.h)
    // {
    //   SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
    //   SDL_RenderDrawRect(rend, &option_5);


    //   if (e.type == SDL_MOUSEBUTTONDOWN && e.key.repeat == 0)
    //   {
    //     Mix_PlayChannel(-1, mouse_click, 0);
    //     //  Next_Back =0;
    //     main_game = 0;
    //     Next_Back = 0 ;
    //     Running = 0;
    //     // closeFlag = 1;
    //     // close();
    //     SDL_Quit();
    //     // main_game =0;
    //     break;
    //   }
    // }
   // SDL_RenderPresent(rend);
  }
  // SDL_RenderPresent(rend);
  // main_game=0;
  // Next_Back=1;
}