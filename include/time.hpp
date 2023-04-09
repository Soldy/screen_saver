class TimeClass{
  private:
    TTF_Font* Computerfont ; 
    Dimension d;
    SDL_Color color = {255, 255, 255};
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Rect rect;
  public:
    TimeClass(){
        TTF_Init();
        this->Computerfont = TTF_OpenFont("asset/Computerfont.ttf", 96);
        this->d.position.y = 944;
        this->d.size.x = 360;
        this->d.size.y = 96;
        this->d.position.x = 40;
    };
    void resize(){
        this->rect.x = result.x(this->d.position.x);
        this->rect.w = result.x(this->d.size.x);
        this->rect.y = result.y(this->d.position.y);
        this->rect.h = result.y(this->d.size.y);
    };
    std::string time(){
        std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::string s(30, '\0');
        std::strftime(&s[0], s.size(), "%H:%M", std::localtime(&now));
        return s;
    };
    void render(){
        if(cppConfig::getInt("time") != 1)
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
            this->time().c_str(),
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
