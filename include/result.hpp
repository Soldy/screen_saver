struct {
   int x (int pos){
       return int(std::floor(float(pos)*cache.ratio.x));
   };
   int y (int pos){
       return int(std::floor(float(pos)*cache.ratio.y));
   };
   void change(){
       cache.ratio.x = float(cache.screen_size.x)/float(cache.result.x);
       cache.ratio.y = float(cache.screen_size.y)/float(cache.result.y);
   };
} result;
