
#include <iostream>
#include <fstream>
class ImagesClass{
  private:
    std::vector<std::string> list = simple_list::read("files.lst");
    std::vector<std::string> imgs;
    std::vector<SDL_Texture *> textures;
    std::vector<SDL_Surface *> surfaces;
    SDL_Rect rect;
    Dimension d;
    int current = 0;
    void init(){
        IMG_Init(IMG_INIT_PNG);
        int index = 0;
        for(std::string &v : this->list){
            this->surfaces.push_back(IMG_Load(v.c_str()));
            index = this->surfaces.size()-1;
            if (this->surfaces[index] == NULL)
                std::cout << "Error creating surfce " << v<< std::endl;
        }
        for(auto &v : this->surfaces){
            this->textures.push_back(
                SDL_CreateTextureFromSurface(
                    cache.render, 
                    v
                )
            );
            index = this->textures.size()-1;
            if (this->textures[index] == NULL) 
                std::cout << 
                   "Error creating texture " << 
                   this->list[index] << 
                   " - " << 
                   SDL_GetError() <<
                   std::endl;
            SDL_FreeSurface(v);
        }
    };
    void resize(){
        this->rect.x = result.x(this->d.position.x);
        this->rect.w = result.x(this->d.size.x);
        this->rect.y = result.y(this->d.position.y);
        this->rect.h = result.y(this->d.size.y);
    };
  public:
    ImagesClass(){
         this->d.position.x =0;
         this->d.position.y =0;
         this->d.size.x = 1920;
         this->d.size.y = 1080;
         this->init();
    };
    void next(){
        this->current++;
        if(this->current > this->textures.size())
            this->current = 0;
    };
    void render(){
        SDL_RenderClear(cache.render);
        this->resize();
        SDL_RenderDrawRect(
            cache.render,
            & this->rect
        );
        SDL_RenderCopy(
            cache.render,
            this->textures[this->current],
            nullptr,
            &this->rect
        );
    };
};
ImagesClass * Images = new ImagesClass();
