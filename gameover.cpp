#include "AllHeader.h"

void Gameover(){
    // Mix_PlayChannel( -1, replay1, 0 );
            //SDL_RenderClear(rend);
            
            TTF_Font *gFont = TTF_OpenFont("times.ttf", 58);
            SDL_Color color = {255, 255, 255};
            std::string s = std::to_string(score);
            SDL_Surface *surface1 = TTF_RenderText_Solid(gFont, s.c_str(), color);
            SDL_Texture *text = SDL_CreateTextureFromSurface(rend, surface1);
            SDL_FreeSurface(surface1);
            std::string t = std::to_string(Time / 1000);
            SDL_Surface *surface2 = TTF_RenderText_Solid(gFont, t.c_str(), color);
            SDL_Texture *text1 = SDL_CreateTextureFromSurface(rend, surface2);
            SDL_RenderCopy(rend, tex_dark, NULL, NULL);
            SDL_RenderCopy(rend, gameover_tex, NULL, &gameover_rect);
            SDL_RenderCopy(rend, replay_tex, NULL, &replay_rect);
            SDL_RenderCopy(rend, tex_score, NULL, &score_image);
            SDL_RenderCopy(rend, tex_Time, NULL, &Time_image);
            SDL_RenderCopy(rend, text, NULL, &score_rect);
            SDL_RenderCopy(rend, text1, NULL, &Time_rect);
            SDL_RenderCopy(rend, home, NULL, &home_rect);

            SDL_RenderPresent(rend);

            int mousex, mousey;
            int buttons = SDL_GetMouseState(&mousex, &mousey);

            if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
            {
                if (mousex >= replay_rect.x && mousex <= (replay_rect.x + replay_rect.w) && mousey >= replay_rect.y && mousey <= (replay_rect.y + replay_rect.h))
                {
                    Mix_PlayChannel(-1, mouse_click, 0);
                    // y_pos=550.0;
                    playerPosition.x = 400;
                    playerPosition.y = 500;
                    playerRect.x = playerRect.y = 0;

                    // y_pos1=580.0;
                    // boy2_pos.x=500;
                    // boy2_pos.y=550;
                    // boy2.x=boy2.y=0;
                    score = 0;
                    Time = 0;
                    main_game =1;
                    gameover == 0;

                }
            }
             if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
            {
                if (mousex >= home_rect.x && mousex <= (home_rect.x + home_rect.w) && mousey >= home_rect.y && mousey <= (home_rect.y + home_rect.h))
                {
                    Mix_PlayChannel(-1, mouse_click, 0);
                    // y_pos=550.0;

                    score = 0;
                    Time = 0;
                    Next_Back =1 ;
                    main_game =0;
                    gameover == 0;

                }
            }
}