class ConfigClass{
  public:
    ConfigClass(){
        cppConfig::map(simple_ini_tool::read("config.ini"));
    };
};
ConfigClass * config = new ConfigClass();
