#include <string>

class ConfigScanner
{
private:
    std::string fileName;

public:
    ConfigScanner(std::string p_inputFileName);
    int readConfig();
};