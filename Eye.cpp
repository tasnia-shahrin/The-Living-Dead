#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <bits/stdc++.h>
using namespace std;
#define WINDOW_WIDTH (1280)
#define WINDOW_HEIGHT (720)
#define SCROLL_SPEED (300)

float frameTime = 0;
int prevTime = 0;
int currentTime = 0;
float deltaTime = 0;
int score = 0;

int target;
const int menu = 30;
const int level_changed = 121;
const int game_over = 111;
const int help = 40;
const int scores = 80;
const int RETURN = 90;
const int EXIT = 100;
int getHighScore()
{

    int scores;
    FILE *q = fopen("highscore.txt", "r");
    fscanf(q, "%d", &scores);
    fclose(q);
    return scores;
}

int main(int agr, char *args[])
{
target =menu;
SDL_Event ev ;
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
    // Mix_Init();
    Mix_Chunk *music = Mix_LoadWAV("res/FesliyanStudios.com.mp3");
    Mix_Chunk *mouse_click = Mix_LoadWAV("res/mouseclick.mp3");
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) > 0)
    {
        printf("video and timer: %s\n", SDL_GetError());
    }
    if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)))
        printf("image: %s\n", SDL_GetError());

    printf("Initialization Complete\n");
    if (TTF_Init() < 0)
    {
        cout << "error";
    }
    SDL_Window *win = SDL_CreateWindow("THE LIVING DEAD", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);

    if (!win)
    {
        printf("window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }
    // Mix_PlayChannel(-1,music,0);
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer *rend = SDL_CreateRenderer(win, -1, render_flags);

    if (!rend)
    {
        printf("renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Texture *charli1, *charli2, *tex2, *fire, *tex4, *temp, *temp2;
    SDL_Surface *surface = IMG_Load("res/charli.png");
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

    SDL_Surface *surfaces = IMG_Load("res/score.jpg");
    SDL_Surface *surfacet = IMG_Load("res/time.jpg");

    SDL_Texture *tex_score = SDL_CreateTextureFromSurface(rend, surfaces);

    SDL_Texture *tex_time = SDL_CreateTextureFromSurface(rend, surfacet);

    SDL_Surface *surfacem = IMG_Load("res/m.jpg");
    SDL_Surface *surfaceh = IMG_Load("res/highscore.jpg");
    SDL_Surface *surfacec = IMG_Load("res/credit.jpg");
    SDL_Surface *surfacei = IMG_Load("res/insta.jpg");

    SDL_Texture *tex_menu = SDL_CreateTextureFromSurface(rend, surfacem);

    SDL_Texture *tex_high = SDL_CreateTextureFromSurface(rend, surfaceh);

    SDL_Texture *tex_insta = SDL_CreateTextureFromSurface(rend, surfacei);

    SDL_Texture *tex_credit = SDL_CreateTextureFromSurface(rend, surfacec);

     SDL_Surface *surfaced = IMG_Load("res/dark.jpg");
      SDL_Texture *tex_dark = SDL_CreateTextureFromSurface(rend, surfaced);
    temp2 = charli1;

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

    surface = IMG_Load("res/moon.png");
    if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Texture *moon_tex = SDL_CreateTextureFromSurface(rend, surface);
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

    surface = IMG_Load("res/start.png");
    if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Texture *start_tex0 = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!start_tex0)
    {
        printf("replayTexture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    surface = IMG_Load("res/FirstImage.png");
    if (!surface)
    {
        printf("start Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Texture *First_Back_tex0 = SDL_CreateTextureFromSurface(rend, surface);
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
    SDL_Texture *Sec_Back_tex0 = SDL_CreateTextureFromSurface(rend, surface);
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
    SDL_Texture *NewGame_tex = SDL_CreateTextureFromSurface(rend, surface);
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
    SDL_Texture *instruction_tex = SDL_CreateTextureFromSurface(rend, surface);
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

    SDL_Texture *gameover_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!gameover_tex)
    {
        printf("Green Rectangle Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    surface = IMG_Load("res/zoombie2R.png");
    if (!surface)
    {
        printf("Zoombie Sudface Error: %s", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Texture *ZoombieR_tex = SDL_CreateTextureFromSurface(rend, surface);
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
    SDL_Texture *Zoombie_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!Zoombie_tex)
    {
        printf("Zoombie Texture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Rect gameover_rect;
    gameover_rect.w = 400;
    gameover_rect.h = 300;
    gameover_rect.x = (WINDOW_WIDTH - gameover_rect.w) / 2;
    gameover_rect.y = (WINDOW_HEIGHT - gameover_rect.h) / 2 - 150;

    surface = IMG_Load("res/replay.png");
    if (!surface)
    {
        printf("replay Surface Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }
    SDL_Texture *replay_tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    if (!replay_tex)
    {
        printf("replayTexture %s\n", SDL_GetError());
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    SDL_Rect replay_rect;
    replay_rect.w = 300;
    replay_rect.h = 150;
    replay_rect.x = (WINDOW_WIDTH - replay_rect.w) / 2;
    replay_rect.y = (WINDOW_HEIGHT - replay_rect.h) / 2 + 100;

    SDL_Rect dest, dest1[100], dest2, dest22, dest_fire, newgame;

    SDL_QueryTexture(tex2, NULL, NULL, &dest2.w, &dest2.h);
    SDL_QueryTexture(tex2, NULL, NULL, &dest22.w, &dest22.h);

    SDL_QueryTexture(fire, NULL, NULL, &dest_fire.w, &dest_fire.h);
    SDL_QueryTexture(NewGame_tex, NULL, NULL, &newgame.w, &newgame.h);

    newgame.x = 475;
    newgame.y = 140;

    // for(int i=0; i<100; i++)
    // {
    //     dest1[i].w = (int) dest1[i].w * 0.8;
    //     dest1[i].h = (int) dest1[i].h * 0.8;
    //     dest1[i].x = 0;
    //     dest1[i].y = 0;
    // }
    dest2.w = 1280;
    dest2.h = 720;
    dest2.x = 0;
    dest2.y = 0;
    dest22.w = 1280;
    dest22.h = 720;
    dest22.x = -dest22.w;
    dest22.y = 0;
    dest_fire = {WINDOW_WIDTH * 0.5, 550, (int)(dest_fire.w * .1), (int)(dest_fire.h * .1)};

    SDL_Rect playerRect;     // rect for a single frame of the sprite sheet
    SDL_Rect playerPosition; // rect for the whole sprite sheet
    // ei rec(square) er moddher kothao texture (runman) load hobe

    int textureWidth, textureHeight;
    int frameH, frameW;
    SDL_QueryTexture(charli1, NULL, NULL, &textureWidth, &textureHeight);
    frameH = textureHeight / 2;
    frameW = textureWidth / 4;
    playerRect.w = frameW;
    playerRect.h = frameH;
    playerRect.x = 0;
    playerRect.y = 0;

    playerPosition.x = 0;
    playerPosition.y = 500;
    playerPosition.w = 150;
    playerPosition.h = 150;

    SDL_Rect ZoombieRect;     // rect for a single frame of the sprite sheet
    SDL_Rect ZoombiePosition; // rect for the whole sprite sheet
    // ei rec(square) er moddher kothao texture (runman) load hobe
    int textureWidth1, textureHeight1;
    int frameH1, frameW1;

    // int textureWidth,textureHeight;
    // int frameH,frameW;
    SDL_QueryTexture(ZoombieR_tex, NULL, NULL, &textureWidth1, &textureHeight1);
    frameH1 = textureHeight1;
    frameW1 = textureWidth1 / 4;
    ZoombieRect.w = frameW1;
    ZoombieRect.h = frameH1;
    ZoombieRect.x = 0;
    ZoombieRect.y = 0;

    ZoombiePosition.x = WINDOW_WIDTH;
    ZoombiePosition.y = 500;
    ZoombiePosition.w = 150;
    ZoombiePosition.h = 150;

    SDL_Rect option_1, option_2, option_3, option_4, option_5;

    option_1.x = 452;
    option_1.y = 146;
    option_1.h = 71;
    option_1.w = 382;

    option_2.x = 381;
    option_2.y = 242;
    option_2.h = 95;
    option_2.w = 541;

    option_3.x = 414;
    option_3.y = 364;
    option_3.h = 107;
    option_3.w = 474;

    option_4.x = 478;
    option_4.y = 491;
    option_4.h = 79;
    option_4.w = 321;

    option_5.x = 525;
    option_5.y = 606;
    option_5.h = 83;
    option_5.w = 222;

    SDL_Rect score_rect;

    score_rect.x = WINDOW_WIDTH - 150;
    score_rect.y = 10;
    score_rect.w = 100;
    score_rect.h = 100;

    SDL_Rect time_rect;
    time_rect.x = 250;
    time_rect.y = 10;
    time_rect.h = 100;
    time_rect.w = 100;

    SDL_Rect score_image;
    score_image.x = WINDOW_WIDTH - 400;
    score_image.y = 0;
    score_image.w = 250;
    score_image.h = 122;

    float x_pos = 0;

    SDL_Rect time_image;
    time_image.x = 60;
    time_image.y = -70;
    time_image.h = 300;
    time_image.w = 150;

    SDL_Event e;
    int cnt[100] = {}, flag[100] = {}, one[100] = {};
    int i = 0;
    bool start = 1;
    int main_game = 0, jump = 0, jump_hight = 200, direction = 0, ct = 0;
    int Next_Back = 0;
    int gameover = 0;
    bool Running = true;

    int time;
    while (Running)
    {  
        prevTime = currentTime;
        // currentTime = SDL_GetTicks();
        deltaTime = (currentTime - prevTime) / 1000.0f;

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
                    playerPosition.y += jump_hight;
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
                    playerPosition.y -= jump_hight;
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
            }
        }

        // if(jump==0){
        //     const Uint8 *keystate = SDL_GetKeyboardState(NULL);
        // 	if (keystate[SDL_SCANCODE_UP]) {
        // 		jump = 1;

        //         direction = 1 ;
        //         playerPosition.y = playerPosition.y - jump_hight;

        //    }

        // }

        // if(jump==0){
        //     const Uint8 *keystate = SDL_GetKeyboardState(NULL);
        // 	if (keystate[SDL_SCANCODE_UP]) {
        // 		jump = 1;

        //         direction = 1 ;
        //         playerPosition.y = playerPosition.y - jump_hight;

        //    }

        // }

        if (main_game)
        {
            time = SDL_GetTicks();
            frameTime++;
            if (frameTime == 30 && playerPosition.y + playerPosition.h <= ZoombiePosition.y)
            {
                frameTime = 0;
                playerPosition.y = playerPosition.y + jump_hight;
            }

            frameTime++;
            if (frameTime == 60)
            {
                frameTime = 0;
                ZoombieRect.x += frameW1;
                if (ZoombieRect.x + frameW1 >= textureWidth1)
                {

                    //  ZoombieRect.y+=frameH1;
                    ZoombieRect.x = 0;
                }
            }
            // score++;
            // ZoombiePosition.x-=3 ;

            SDL_RenderClear(rend);

            SDL_RenderCopy(rend, moon_tex, NULL, NULL);
            SDL_RenderCopy(rend, tex2, NULL, &dest2);
            SDL_RenderCopy(rend, tex2, NULL, &dest22);
            SDL_RenderCopy(rend, temp2, &playerRect, &playerPosition);
            SDL_RenderCopy(rend, temp, &ZoombieRect, &ZoombiePosition);
            SDL_RenderCopyEx(rend, fire, 0, &dest_fire, 0, 0, SDL_FLIP_HORIZONTAL);
            SDL_RenderPresent(rend);

            dest_fire.x -= 3;

            if ((playerPosition.x + playerPosition.w >= dest_fire.x && playerPosition.x <= dest_fire.x && playerPosition.y <= dest_fire.y && playerPosition.y + playerPosition.h >= dest_fire.y))
            {
                dest_fire.x = -1280;
                score = score + 10;
            }
            if ((playerPosition.x + playerPosition.w >= ZoombiePosition.x && playerPosition.x <= ZoombiePosition.x && playerPosition.y <= ZoombiePosition.y && playerPosition.y + playerPosition.h >= ZoombiePosition.y))
            {
                ZoombiePosition.x = WINDOW_WIDTH;
                gameover = 1;
                main_game = 0;
            }
            // dest.x+=3 ;
            if (playerPosition.x + playerPosition.w > ZoombiePosition.x + ZoombiePosition.w)
            {

                temp = Zoombie_tex;
                // Zoombie_tex = temp ;
                ZoombiePosition.x += 3;
            }

            else if (playerPosition.x + playerPosition.w < ZoombiePosition.x + ZoombiePosition.w)
            {

                temp = ZoombieR_tex;
                ZoombiePosition.x -= 1;
            }
            else
            {
                temp = ZoombieR_tex;
            }

            // s--;
            // if(s<dest2.w)
            //  s=0;
            dest2.x += 3;
            dest22.x += 3;
            if (dest2.x >= WINDOW_WIDTH)
            {
                dest2.x = 0;
                dest22.x = -dest22.w;
            }
            if (dest_fire.x <= -400)
            {
                dest_fire.x = WINDOW_WIDTH;
            }

            // for(int j=0; j<=99; j++)
            // {
            //     if(cnt[j])
            //         cout<<"cnt"<<j<<" "<<cnt[j]<<endl;

            // if(cnt[j])
            // {
            //     if(!one[j])
            //         dest1[j].x=(int)x_pos+270;
            //     one[j]=1;

            //     if(!flag[j])
            //     {
            //         dest1[j].y=dest.y+73;
            //         flag[j]=1;
            //     }

            //     SDL_RenderCopy(rend, tex1, NULL, &dest1[j]);

            //     dest1[j].x+=6;

            //     if(dest1[j].x>=1680)
            //     {
            //         cnt[j]=0;
            //         flag[j]=0;
            //         one[j]=0;
            //     }
            // }
            // }
            // if(x_pos>=WINDOW_WIDTH)
            // {
            //     x_pos=-400;
            // }
            if (dest.y <= 380)
            {
                dest.y = WINDOW_HEIGHT * 0.45;
            }

            if (playerPosition.x >= WINDOW_WIDTH)
            {
                // SDL_Delay(1500);
                gameover = 1;
                main_game = 0;
                // playerPosition.y=100;
            }

            SDL_RenderPresent(rend);
            // SDL_Delay(1000/40);
        }
        else if (start)
        {

            SDL_RenderClear(rend);

            SDL_RenderCopy(rend, First_Back_tex0, NULL, NULL);

            SDL_RenderPresent(rend);

            SDL_Delay(3000);

            start = 0;
            Next_Back = 1;

            // SDL_Quit();
        }
        
        else if (Next_Back)
        {
            int mousex, mousey;
            int button = SDL_GetMouseState(&mousex, &mousey);
            // Mix_PlayChannel( -1, replay, 0 );
            // Mix_PlayChannel(-1,menu,0);
            SDL_RenderClear(rend);
            // SDL_RenderCopy(rend,fontTex,NULL,&textRect);
            // Mix_PlayChannel(-1,music,0);

            // SDL_RenderCopy(rend, Sec_Back_tex0, NULL, NULL);
           // SDL_RenderCopy(rend, NewGame_tex, NULL, &newgame);
            //SDL_RenderCopy(rend, instruction_tex, NULL, NULL);
 
SDL_RenderCopy(rend, tex_menu, NULL, NULL);
 SDL_RenderPresent(rend);
 



  while (SDL_PollEvent( & ev) != 0) {
            // if (ev.type == SDL_QUIT)
            // {
              
            //   target = EXIT;
            // }

            // if( ev.type == SDL_KEYDOWN)
    		// 	{

        	// 		switch( ev.key.keysym.sym )
        	// 		{
            // 			case SDLK_ESCAPE:
            // 			{
            //    				target = menu;

            //    				break;
            // 			}
            //   		}
           	//  	}
           

            if (ev.button.x > option_1.x && ev.button.x < option_1.x + option_1.w && ev.button.y > option_1.y && e.button.y < option_1.y + option_1.h)
            {
             SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
    SDL_RenderDrawRect(rend, & option_1);

              if (ev.type == SDL_MOUSEBUTTONDOWN && ev.key.repeat == 0)
              {
              	Mix_PlayChannel(-1, mouse_click, 0);
                    main_game = 1;
                    Next_Back = 0;
                    target =0;	
              }
            }

            if (ev.button.x > option_2.x && ev.button.x < option_2.x + option_2.w && ev.button.y > option_2.y && ev.button.y < option_2.y + option_2.h)
            { SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
    SDL_RenderDrawRect(rend, & option_2);

              
              if (ev.type == SDL_MOUSEBUTTONDOWN && ev.key.repeat == 0) {
               Mix_PlayChannel(-1, mouse_click, 0);
            SDL_RenderCopy(rend, tex_high, NULL, NULL);

            SDL_RenderPresent(rend);
            SDL_Delay(2000);
              
            
              }
            }

            if (ev.button.x > option_3.x && ev.button.x < option_3.x + option_3.w && ev.button.y > option_3.y && ev.button.y < option_3.y + option_3.h)
            {
              SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
    SDL_RenderDrawRect(rend, & option_3);


              if (ev.type == SDL_MOUSEBUTTONDOWN && ev.key.repeat == 0) {
   Mix_PlayChannel(-1, mouse_click, 0);
            SDL_RenderCopy(rend, tex_insta, NULL, NULL);

            SDL_RenderPresent(rend);
            SDL_Delay(2000);

                target = menu;
               
              }
            }

            if (ev.button.x > option_4.x && ev.button.x < option_4.x + option_4.w && ev.button.y > option_4.y && ev.button.y < option_4.y + option_4.h)
{
    //            SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
    // SDL_RenderDrawRect(rend, & option_4);


              if (ev.type == SDL_MOUSEBUTTONDOWN && ev.key.repeat == 0)
              {Mix_PlayChannel(-1, mouse_click, 0);
SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
    SDL_RenderDrawRect(rend, & option_4);
               SDL_RenderCopy(rend, tex_credit, NULL, NULL);

            SDL_RenderPresent(rend);
            SDL_Delay(2000);
             
                target =menu;
                
           	 }
           	}

            if (ev.button.x > option_5.x && ev.button.x < option_5.x + option_5.w && ev.button.y > option_5.y && ev.button.y < option_5.y + option_5.h)
            {
               SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
    SDL_RenderDrawRect(rend, & option_5);


              if (e.type == SDL_MOUSEBUTTONDOWN && e.key.repeat == 0) {
                Mix_PlayChannel(-1, mouse_click, 0);
                 Next_Back =0;
              	Running=0;
                main_game =0;
                break;
              }

            }
            }

//  if (mousex >= option_1.x && mousex <= (option_1.x + option_1.w) && mousey >= option_1.y && mousey <= (option_1.y + option_1.h)){


//      SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
//     SDL_RenderDrawRect(rend, & option_1);
//       if (button & SDL_BUTTON(SDL_BUTTON_LEFT)){

//  Mix_PlayChannel(-1, mouse_click, 0);
//                     //    SDL_Delay(1000);

//                     main_game = 1;
//                     Next_Back = 0;
//                     target =0;
//       }
//  }
        


            // SDL_RenderCopy(rend,start_tex0, NULL, &start_rect);
           // SDL_RenderPresent(rend);

            // int mousex, mousey;
            // int button = SDL_GetMouseState(&mousx, &mousy);

            // if (button & SDL_BUTTON(SDL_BUTTON_LEFT))
            // {
            //     if (mousx >= newgame.x && mousx <= (newgame.x + newgame.w) && mousy >= newgame.y && mousy <= (newgame.y + newgame.h))
            //     {
            //         Mix_PlayChannel(-1, mouse_click, 0);
            //         //    SDL_Delay(1000);

            //         main_game = 1;
            //         Next_Back = 0;
            //     }
            // }
            // SDL_Delay(6000);
            // main_game=1;
            // start = 0;
            // Next_Back =0 ; ;

            // SDL_Quit();
        }

        else if (gameover == 1)
        {
            // Mix_PlayChannel( -1, replay1, 0 );
            SDL_RenderClear(rend);
            TTF_Font *gFont = TTF_OpenFont("times.ttf", 58);
            SDL_Color color = {255, 0, 0, 255};
            std::string s = std::to_string(score);
            SDL_Surface *surface1 = TTF_RenderText_Solid(gFont, s.c_str(), color);
            SDL_Texture *text = SDL_CreateTextureFromSurface(rend, surface1);
            SDL_FreeSurface(surface1);
            std::string t = std::to_string(time / 1000);
            SDL_Surface *surface2 = TTF_RenderText_Solid(gFont, t.c_str(), color);
            SDL_Texture *text1 = SDL_CreateTextureFromSurface(rend, surface2);
            SDL_RenderCopy(rend, tex_dark, NULL, NULL);
            SDL_RenderCopy(rend, gameover_tex, NULL, &gameover_rect);
            SDL_RenderCopy(rend, replay_tex, NULL, &replay_rect);
            SDL_RenderCopy(rend, tex_score, NULL, &score_image);
            SDL_RenderCopy(rend, tex_time, NULL, &time_image);
            SDL_RenderCopy(rend, text, NULL, &score_rect);
            SDL_RenderCopy(rend, text1, NULL, &time_rect);
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
time = 0;
                    main_game =1;
                    gameover == 0;

                }
            }
        }
    }
    //  std::string s=std::to_string(score);
    //             SDL_Surface *surface1=TTF_RenderText_Solid(gFont,s.c_str(), {255,255,255});
    //             SDL_Texture * text= SDL_CreateTextureFromSurface(rend, surface1);
    //             SDL_FreeSurface(surface1);
    //    SDL_RenderCopy(rend,text,NULL,&score_rect);
    SDL_RenderPresent(rend);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_DestroyTexture(charli1);

    SDL_DestroyTexture(charli2);

    SDL_Quit();
    return 0;
}