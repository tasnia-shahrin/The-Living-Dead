#include "AllHeader.h"

void NextBackGround(){
    
    int mousex, mousey;
            int button = SDL_GetMouseState(&mousex, &mousey);
            
            SDL_RenderClear(rend);
           
 
            SDL_RenderCopy(rend, tex_menu, NULL, NULL);
            SDL_RenderPresent(rend);
            


            CallMenu();
}