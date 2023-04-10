#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

class ImagesClass{
  private:
    std::vector<std::string> list;
    std::vector<std::string> imgs;
    std::vector<SDL_Texture *> textures;
    std::vector<SDL_Surface *> surfaces;
    SDL_Rect rect;
    Dimension d;
    int current = 0;
    int prev = -1;
    int load = 0;
    void init(){
        this->initFileList();
        IMG_Init(IMG_INIT_PNG);
        for(std::string &v : this->list){
            cpp_verbose::msg("image load",v);
            this->surfaces.push_back(IMG_Load(v.c_str()));
            this->load = this->surfaces.size()-1;
            if (this->surfaces[this->load] == NULL)
                cpp_verbose::msg(
                  "Error creating surfce ",
                  v
                );
        }
        for(auto &v : this->surfaces){
            this->load = static_cast<int>(this->textures.size());
            cpp_verbose::msg(
              "image texture cache",
              this->list[this->load]
            );
            this->textures.push_back(
                SDL_CreateTextureFromSurface(
                    cache.render, 
                    v
                )
            );
            if (this->textures[this->load] == NULL) 
                cpp_verbose::msg(
                  "Error creating texture",
                  this->list[this->load],
                  SDL_GetError()
                );
            SDL_FreeSurface(v);
        }
    };
    void resize(){
        this->rect.x = result.x(this->d.position.x);
        this->rect.w = result.x(this->d.size.x);
        this->rect.y = result.y(this->d.position.y);
        this->rect.h = result.y(this->d.size.y);
    };
    void dirRead(){
        std::string path = cppConfig::get("image_dir");
        for (const auto & entry : std::filesystem::directory_iterator(path))
             this->list.push_back(entry.path());
    };
    void initFileList(){
        if(cppConfig::getInt("file_lst_enable") == 1)
            this->list = simple_list::read("files.lst");
        if(cppConfig::getInt("image_dir_enable") == 1)
            this->dirRead();
    };
  public:
    ImagesClass(){
         this->d.position.x =0;
         this->d.position.y =0;
         this->d.size.x = 1920;
         this->d.size.y = 1080;
         this->init();
    };
    int nextRandom(){
       std::random_device r;
       std::default_random_engine e1(r());
       std::uniform_int_distribution<int> uniform_dist(0, this->textures.size()-1);
       return uniform_dist(e1);
    };
    void next(){
        this->prev = this->current;
        if(cppConfig::getInt("random") == 1){
            while(this->prev == this->current)
                this->current = this->nextRandom();
        }else{
            this->current++;
        }
        if(this->current >= this->textures.size())
            this->current = 0;
    };
    void render(){
        cpp_verbose::msg(
            "image render",
            this->list[this->current]
        );
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
