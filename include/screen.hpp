class ScreenClass{
  public:
    ScreenClass(){
        cache.result.x=cppConfig::getInt("result_x");
        cache.result.y=cppConfig::getInt("result_y");
        cache.screen_size.x=cppConfig::getInt("result_x");
        cache.screen_size.y=cppConfig::getInt("result_y");
        result.change();
        this->checkSize();
        this->createWindow();
        this->createRender();
    };
    void clear(){
         this->setBlack();
         if(this->update_round > this->update_rate){
              this->update_round = 0;
              SDL_RenderClear(cache.render);
         }
    };
    void rendering(){
        SDL_RenderPresent(cache.render);
        this->update_round++;
    };
    void close(){
        SDL_DestroyWindow( cache.window );
    }
  private:
    int update_round = 0;
    int update_rate = 20;
    void checkSize(){
        SDL_GetCurrentDisplayMode(
            0, 
            & cache.display_mode
        );
    };
    void createWindow(){
        cache.window = SDL_CreateWindow(
           "screen saver",
           cache.result.x,
           cache.result.y,
           cache.result.x,
           cache.result.y,
           SDL_WINDOW_SHOWN
        );
        cache.full_screen = false;
        SDL_SetWindowFullscreen(
            cache.window, 
            !cache.full_screen
        );
        SDL_ShowCursor(cache.full_screen);
    };
    void createRender(){
        cache.render = SDL_CreateRenderer(
            cache.window,
            -1,
            SDL_RENDERER_ACCELERATED
        );
        this->setBlack();
        SDL_RenderClear(cache.render);
    };
    void setBlack(){
        SDL_SetRenderDrawColor(
            cache.render,
            0,
            0,
            0,
            SDL_ALPHA_OPAQUE
        );
    }
};
ScreenClass * Screen = new ScreenClass();
