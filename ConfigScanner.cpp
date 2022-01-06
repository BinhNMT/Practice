#include <iostream>
#include <fstream>
#include <sstream>
#include "ConfigScanner.h"

using namespace std;

ConfigScanner::ConfigScanner(std::string p_inputFileName)
{
    fileName = p_inputFileName;
}

int ConfigScanner::readConfig()
{
    int ret;
    string data;
    ifstream infile; 
    infile.open(fileName); 
    infile >> data;
    stringstream geek(data);
    geek >> ret;
    return ret;
}