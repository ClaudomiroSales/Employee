#include <iostream>
using std::cerr;

#include <string>
using std::string;
using std::getline;

#include <fstream>
using std::fstream;
using std::ifstream;

#include <sstream>
using std::istringstream;

#include <map>
using std::map;

bool loadConfig( map<string, double>& variables, string nameFile )
{

    ifstream inputFile("config.txt");

    if ( !inputFile.is_open() ) 
    {
        cerr << "Error opening file." << '\n';
        return false; // Exit with an error code
    }

    string line;    
    string variableName;
    char equalsSign;
    double value;
    while (getline(inputFile, line)) 
    {
        istringstream iss(line);
        if (iss >> variableName >> equalsSign >> value && equalsSign == '=') 
            variables[variableName] = value;
        else
            cerr << "Error parsing line: " << line << '\n';
    }

    inputFile.close();

    return true;

}
