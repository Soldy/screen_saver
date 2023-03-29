#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cmath>
#include <sstream>
#include <random>
#include <SDL2/SDL.h>  
#include "SDL2/SDL_image.h"
#include "subs/trim/just_trim.hpp"
#include "subs/list/list.hpp"
#include "subs/ini/simple_ini.hpp"
#include "subs/config/config.hpp"
#include "include/debug.hpp"
#include "include/dimension.hpp"
#include "include/cache.hpp"
#include "include/config.hpp"
#include "include/result.hpp"
#include "include/screen.hpp"
#include "include/images.hpp"


std::vector<std::string> list;
TEST_CASE("simple test") {
};
