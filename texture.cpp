#include "AllHeader.h"


 SDL_Texture *charli1, *charli2, *tex2, *moon_tex, *start_tex0 , *First_Back_tex0, *Sec_Back_tex0,*NewGame_tex, *instruction_tex, *gameover_tex, *ZoombieR_tex, *Zoombie_tex, *tex_score,*tex_Time,*tex_menu,*tex_high,*tex_credit, *tex_insta, *tex_dark,*replay_tex,*fire, *tex4, *temp, *temp2, *home;

 bool TexLoad(){
    surface = IMG_Load("res/charli.png");
    if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    charli1 = SDL_CreateTextureFromSurface(rend, surface);
    // SDL_SetTextureColorMod(tex1,200,255,255);
    SDL_FreeSurface(surface);


      surface = IMG_Load("res/charli reverse.png");
    if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    charli2 = SDL_CreateTextureFromSurface(rend, surface);
    // SDL_SetTextureColorMod(tex1,200,255,255);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/tree.png");
    if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    tex2 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/fire.png");
    if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    // SDL_SetColorKey(surface,SDL_TRUE,SDL_MapRGB(surface->format,255,255,255));
    fire = SDL_CreateTextureFromSurface(rend, surface);
    // SDL_SetTextureColorMod(tex3,200,200,200);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/moon.png");
    if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    moon_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/start.png");
    if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    start_tex0 = SDL_CreateTextureFromSurface(rend, surface);
     if (!start_tex0)
    {
        printf("replayTexture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/FirstImage.png");
    if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    First_Back_tex0 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/SecBack.png");
    if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    Sec_Back_tex0 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/NewGame.png");
    if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    NewGame_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/instruction.png");
    if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    instruction_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/gameover.jpeg");
    if (!surface)
    {
        printf("Green rectangle Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    gameover_tex = SDL_CreateTextureFromSurface(rend, surface);
    if (!gameover_tex)
    {
        printf("Green Rectangle Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/zoombie2R.png");
    if (!surface)
    {
        printf("Zoombie Sudface Error: %s", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    ZoombieR_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!ZoombieR_tex)
    {
        printf("Zoombie Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    surface = IMG_Load("res/zoombie2.png");
    if (!surface)
    {
        printf("Zoombie Sudface Error: %s", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    Zoombie_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!Zoombie_tex)
    {
        printf("Zoombie Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }



    surface = IMG_Load("res/score.jpg");
    if (!surface)
    {
        printf("Zoombie Sudface Error: %s", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    tex_score = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/time.jpg");
    if (!surface)
    {
        printf("Zoombie Sudface Error: %s", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    tex_Time = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/m.jpg");
    if (!surface)
    {
        printf("Zoombie Sudface Error: %s", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    tex_menu = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/highscore.jpg");
    if (!surface)
    {
        printf("Zoombie Sudface Error: %s", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    tex_high = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/credit.jpg");
    if (!surface)
    {
        printf("Zoombie Sudface Error: %s", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    tex_credit = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/insta.jpg");
    if (!surface)
    {
        printf("Zoombie Sudface Error: %s", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    tex_insta = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("res/dark.jpg");
     if (!surface)
    {
        printf("Zoombie Sudface Error: %s", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
   // SDL_FreeSurface(surface);
    tex_dark = SDL_CreateTextureFromSurface(rend, surface);
     SDL_FreeSurface(surface);
    temp2 = charli1;

    surface = IMG_Load("res/replay.png");
    if (!surface)
    {
        printf("replay Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    replay_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!replay_tex)
    {
        printf("replayTexture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    surface = IMG_Load("res/home.png");
    home = SDL_CreateTextureFromSurface(rend,surface);
    SDL_FreeSurface(surface);

    
 }