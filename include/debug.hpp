void debugMsg(std::string msg, std::string element){
    if(cppConfig::getInt("debug") == 1)
        std::cout << msg << " : " << element << std::endl;
}
