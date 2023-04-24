#include "AllHeader.h"

SDL_Rect gameover_rect,replay_rect, dest, dest1[100], dest2, dest22, dest_fire,dest_fire1, newgame, playerRect, playerPosition, ZoombieRect, ZoombiePosition, option_1, option_2, option_3, option_4, option_5, score_rect, Time_rect, score_image, Time_image,home_rect ;
int textureWidth, textureHeight, frameH, frameW, textureWidth1, textureHeight1, frameH1, frameW1; 
bool rect(){

    gameover_rect.w = 400;
    gameover_rect.h = 300;
    gameover_rect.x = (WINDOW_WIDTH - gameover_rect.w) / 2;
    gameover_rect.y = (WINDOW_HEIGHT - gameover_rect.h) / 2 - 150;

    replay_rect.w = 300;
    replay_rect.h = 150;
    replay_rect.x = (WINDOW_WIDTH - replay_rect.w) / 2;
    replay_rect.y = (WINDOW_HEIGHT - replay_rect.h) / 2 + 100;
    SDL_QueryTexture(tex2, NULL, NULL, &dest2.w, &dest2.h);
    SDL_QueryTexture(tex2, NULL, NULL, &dest22.w, &dest22.h);

    SDL_QueryTexture(fire, NULL, NULL, &dest_fire.w, &dest_fire.h);
    SDL_QueryTexture(fire, NULL, NULL, &dest_fire1.w, &dest_fire1.h);
    SDL_QueryTexture(NewGame_tex, NULL, NULL, &newgame.w, &newgame.h);


    newgame.x = 475;
    newgame.y = 140;

    for(int i=0; i<100; i++)
    {
        dest1[i].w = (int) dest1[i].w * 0.8;
        dest1[i].h = (int) dest1[i].h * 0.8;
        dest1[i].x = 0;
        dest1[i].y = 0;
    }
    dest2.w = 1280;
    dest2.h = 720;
    dest2.x = 0;
    dest2.y = 0;
    dest22.w = 1280;
    dest22.h = 720;
    dest22.x = -dest22.w;
    dest22.y = 0;
    dest_fire = {WINDOW_WIDTH * .5, 550, (int)(dest_fire.w * .1), (int)(dest_fire.h * .1)};

    dest_fire1 = {WINDOW_WIDTH * 1, 400, (int)(dest_fire1.w * .1), (int)(dest_fire1.h * .1)};

    // int textureWidth, textureHeight;
    // int frameH, frameW;
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

    // int textureWidth1, textureHeight1;
    // int frameH1, frameW1;

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

    score_rect.x = WINDOW_WIDTH - 150;
    score_rect.y = 10;
    score_rect.w = 100;
    score_rect.h = 100;

    
    Time_rect.x = 250;
    Time_rect.y = 10;
    Time_rect.h = 100;
    Time_rect.w = 100;

    
    score_image.x = WINDOW_WIDTH - 400;
    score_image.y = 0;
    score_image.w = 250;
    score_image.h = 122;

    float x_pos = 0;

    
    Time_image.x = 60;
    Time_image.y = -70;
    Time_image.h = 300;
    Time_image.w = 150;

    SDL_QueryTexture(home, NULL, NULL, &home_rect.w, &home_rect.h);
    home_rect.x = 510 ;
    home_rect.y = 530 ;


}