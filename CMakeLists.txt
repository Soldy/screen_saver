project(screen_saver
    DESCRIPTION ""
    HOMEPAGE_URL "https://github.com/Soldy/screensaver"
)
cmake_minimum_required(VERSION 3.18)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
set_property(GLOBAL PROPERTY CXX_STANDARD 20)
add_library(screen_saver_include INTERFACE)
target_include_directories(screen_saver_include INTERFACE include)
target_include_directories(screen_saver_include INTERFACE subs)
target_include_directories(screen_saver_include INTERFACE pthread)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)
add_executable(screensaver main.cpp)
set_property(TARGET screensaver PROPERTY CXX_STANDARD 20)
target_link_libraries(screensaver PUBLIC screen_saver_include SDL2 SDL2_image SDL2_ttf SDL2_mixer)

