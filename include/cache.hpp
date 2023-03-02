struct {
    SDL_Renderer * render;
    SDL_Window *window;
    SDL_DisplayMode display_mode;
    bool full_screen;
    TwoD result;
    TwoD screen_size;
    TwoDX ratio;
} cache;
