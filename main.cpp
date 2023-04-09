#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cmath>
#include <sstream>
#include <random>
#include <SDL2/SDL.h>  
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "subs/trim/just_trim.hpp"
#include "subs/list/list.hpp"
#include "subs/ini/simple_ini.hpp"
#include "subs/config/config.hpp"
#include "include/dimension.hpp"
#include "include/cache.hpp"
#include "include/config.hpp"
#include "sub/verbose/verbose.hpp"
#include "include/result.hpp"
#include "include/screen.hpp"
#include "include/images.hpp"
#include "include/time.hpp"


int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    while(true){
        Screen->clear();
        Images->render();
        Time->render();
        Screen->rendering();
        SDL_Delay(cppConfig::getInt("delay"));
        Images->next();
    }
    return 0;
}
