#include "input.h"
#include "main.h"
//#include <SDL_mixer.h>
//#include "graphics.h"

bool paused = false;
Mix_Chunk *wav = NULL;


void getInput() {
    SDL_Event event;

    /* Loop through waiting messages and process them */

    while (SDL_PollEvent(&event)) {
        switch (event.type) {

            /* Closing the Window or pressing Escape will exit the program */
            case SDL_QUIT:
                exit(0);
            break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        return;
                        //exit(0);
                    break;

                    case SDLK_s:
                      preRender();
                      
                      break;
                        
                    case SDLK_DOWN:
                        TETROMINO_ACTION = DOWN;
                    break;

                    case SDLK_d:
                    case SDLK_RIGHT:
                        TETROMINO_ACTION = RIGHT;
                    break;

                    case SDLK_a:
                    case SDLK_LEFT:
                        TETROMINO_ACTION = LEFT;
                    break;

                    case SDLK_w:
                    case SDLK_UP:
                       //test
                         wav = Mix_LoadWAV("music/sound.wav");
    
                        Mix_PlayChannel(-1,wav,0);
                       //test
                        TETROMINO_ACTION = ROTATE;
                    break;

                    case SDLK_r:
                        TETROMINO_ACTION = RESTART;
                    break;

                    case SDLK_SPACE:
                        TETROMINO_ACTION = DROP;
                    break;
                    //test
                    
                    //test
                    default:
                    break;
                }
            break;

            case SDL_KEYUP:
                TETROMINO_ACTION = NONE;
            break;

            case SDL_USEREVENT:
                TETROMINO_ACTION = AUTO_DROP;
            break;

            default:
            break;
        }
    }
}
