#pragma once
#include "AllHeader.h"

  
bool start = 1;
void Start(){
    
            SDL_RenderClear(rend);

            SDL_RenderCopy(rend, First_Back_tex0, NULL, NULL);

            SDL_RenderPresent(rend);

            SDL_Delay(3000);

            start = 0;
            Next_Back = 1;
}