class TimeClass{
  private:
    TTF_Font* Computerfont ; 
    std::string font = "asset/Computerfont.ttf";
    Dimension d;
    SDL_Color color = {0, 0, 0};
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Rect rect;
    SDL_Color hexToSdl(std::string input){
        if(input[0] == '#')
            input.erase(0, 1);
        unsigned long value = stoul(input, nullptr, 16);
        SDL_Color color;
        color.a = (value >> 24) & 0xff;
        color.r = (value >> 16) & 0xff;
        color.g = (value >> 8) & 0xff;
        color.b = (value >> 0) & 0xff;
        return color;
    };
  public:
    TimeClass(){
        #ifdef __DEBUG_
        cpp_verbose::msg(
          "font","init"
        ); 
        #endif
        TTF_Init();
        #ifdef __DEBUG_
        cpp_verbose::msg(
          "ttf init","done"
        );
        #endif
        this->d.size.x = 480;
        this->d.size.y = 96;
        this->d.position.x = 40;
        this->d.position.y = 944;
        #ifdef __DEBUG_
        cpp_verbose::msg(
          "config font details",cppConfig::get("clock_font_size")
        );
        #endif
        if(cppConfig::getInt("clock_font_size") != 0)
            this->d.size.y = cppConfig::getInt("clock_font_size");
        if(cppConfig::get("clock_font") != "")
            this->font = cppConfig::get("clock_font");
        if(cppConfig::get("clock_color") != "")
            this->color = this->hexToSdl(cppConfig::get("clock_color"));
        #ifdef __DEBUG_
        cpp_verbose::msg(
          "config font details check","done"
        );
        #endif
        this->Computerfont = TTF_OpenFont(this->font.c_str(), this->d.size.y);
        this->d.position.y = 1080 - this->d.position.x - this->d.size.y;
        this->d.size.x = this->d.size.y*3;
        #ifdef __DEBUG_
        cpp_verbose::msg(
          "font","initilized"
        );
        #endif

    };
    void resize(){
        #ifdef __DEBUG_
        cpp_verbose::msg(
          "font","resize"
        );
        #endif
        this->rect.x = result.x(this->d.position.x);
        this->rect.w = result.x(this->d.size.x);
        this->rect.y = result.y(this->d.position.y);
        this->rect.h = result.y(this->d.size.y);
    };
    std::string clock(){
        std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::string s(30, '\0');
        std::strftime(&s[0], s.size(), "%H:%M", std::localtime(&now));
        return s;
    };
    void render(){
        if(cppConfig::getInt("clock") != 1)
            return;
        this->resize();
        if (this->Computerfont == NULL) {
            cpp_verbose::msg(
              "font load",
              "ComputerFont",
              TTF_GetError()
            );
            return ; // never fail
        }
        this->surface = TTF_RenderText_Solid(
            this->Computerfont,
            this->clock().c_str(),
            this->color
        );
        this->texture = SDL_CreateTextureFromSurface(
            cache.render,
            this->surface
        );
        SDL_RenderCopy(
            cache.render,
            this->texture,
            nullptr, 
            &this->rect
        );
    };

};
TimeClass * Time = new TimeClass();
