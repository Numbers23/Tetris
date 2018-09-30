#include "main.h"
//#include <SDL_mixer.h>
#include "stdio.h"
#include "graphics.h"
#include "SDL2/SDL.h"
#include "SDL2/aud.h"

#define MUS_PATH "/Users/root1/tet/music/tetris.wav"

Mix_Chunk *wave = NULL;
Mix_Music *music = NULL;

 //test
     length = 4;
     
     //Mix_FreeChunk(wave);
     //Mix_FreeMusic( music );
     
   //test



int main(int argc, char *argv[]) {

    // Start up SDL, and make sure it went ok
    //
    uint32_t flags = SDL_INIT_TIMER | SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

        fprintf(stderr,
                "\nUnable to initialize SDL:  %s\n",
                SDL_GetError());

        return 1;
    }
       


    Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_FLAC |  MIX_INIT_MOD);

    Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT,2,640);
    //Mix_Music *music = NULL;

   //test
   music = Mix_LoadMUS(MUS_PATH);
   wave = Mix_LoadWAV("music/Tetris.wav");
    
     // Mix_PlayChannel(-1,wave,-1);
     // Mix_PlayMusic(music,1); 
     
    initAudio();
    playMusic("music/Tetris.wav", SDL_MIX_MAXVOLUME);//from simple sdl2 audio lib
    Audio fart;  
    fart.length = 5;  
    Audio * new; 
     // while ( Mix_PlayingMusic() ) ;
        //Mix_FreeMusic(music);
   //test
    atexit(cleanup);

    init();
    bool menuLoaded = true;
    bool quit = false;
    while(!quit) {
        
        //test
       /*if(menuLoaded == true){
        drawMenu();
      }
      else{
       preRender();
       }*/
       //test
      //drawMenu();


      //test
        preRender();

        getInput();

        updateTetris();

        updateRender();
        //Mix_PlayingMusic();
        //Mix_PlayChannel(-1,wave,0);
        // Set to ~60 fps.
        // 1000 ms/ 60 fps = 1/16 s^2/frame
        SDL_Delay(16);
    }

    return 0;
}
