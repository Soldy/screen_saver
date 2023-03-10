class ConfigClass{
  public:
    ConfigClass(){
        for(auto const & [k, v] : simple_ini_tool::read("config.ini"))
            cppConfig::set(k, v);
    };
};
ConfigClass * config = new ConfigClass();
