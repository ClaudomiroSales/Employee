#include <iostream>
using std::cerr;
using std::cin;
using std::cout;

#include <string>
using std::string;
using std::getline;

#include <fstream>
using std::fstream;
using std::ifstream;
using std::ofstream;

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

    if( variables.size( ) == 0 )
    {   
        cerr << "No variables found.\n";
        return false;
    }

    inputFile.close();

    return true;

}

bool loadConfig( map<string, string>& stringVariables, map<string, double>& doubleVariables, string nameFile )
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
    string value;
    while (getline(inputFile, line)) 
    {
        istringstream iss(line);
        if (!(iss >> variableName >> equalsSign)) 
            cerr << "Error parsing line: " << line << '\n';
        
        if (!equalsSign == '=')
            cerr << "Error parsing line: " << line << '\n';
        
        if (!getline(iss, value)) 
            cerr << "Error parsing line: " << line << '\n';
        
        // Remove leading and trailing whitespaces from the value
        value = value.substr(value.find_first_not_of(" \t"));
        value = value.substr(0, value.find_last_not_of(" \t") + 1);

        // Check if the value is a number (double)
        istringstream valueStream(value);
        double valueDouble;
        if (valueStream >> valueDouble)
            doubleVariables[variableName] = valueDouble;
        else
            stringVariables[variableName] = value;           
    }    

    inputFile.close();

    /*
    cout << "doubleVariables keys.\n";
    for (const auto& pair : doubleVariables)
        cout << "Key: " << pair.first << '\n';
    */

    if (doubleVariables.empty() && stringVariables.empty()) 
    {
        cerr << "No variables found.\n";
        return false;
    }

    return true;

}


bool saveConfigs( map<string, double>& variables, string nameFile )
{
    // abre o arquivo pra escrita 
    ofstream outputFile(nameFile, std::ios::out | std::ios::trunc);
    if (!outputFile.is_open()) {
        cerr << "Erro ao abrir aquivo para escrita!" << '\n';
        return false; //
    }

    for (const auto& pair : variables)
        outputFile << pair.first << " = " << pair.second << '\n';   
  
    outputFile.close();
    cout << "Dados salvos com sucesso!" << '\n';
    return true;
}

bool saveConfigs( map<string, string>& stringVariables, map<string, double>& doubleVariables, string nameFile )
{
    // abre o arquivo pra escrita 
    ofstream outputFile(nameFile);//, std::ios::out | std::ios::trunc);
    if (!outputFile.is_open()) {
        cerr << "Erro ao abrir aquivo para escrita!" << '\n';
        return false; //
    }

    for (const auto& pair : doubleVariables)
        outputFile << pair.first << " = " << pair.second << '\n';  

    /*
    cout << "Salvando strings.\n";
    cout << "Nome = " << stringVariables["nome"] << '\n';
    cout << "id = " << stringVariables["id"] << '\n';
    cout << "Weapon = " << stringVariables["weapon"] << '\n';
    */

    for (map<string, string>::value_type&  pairString : stringVariables)
       outputFile << pairString.first << " = " << pairString.second << '\n';    

    outputFile.close();
    cout << "Dados salvos com sucesso!" << '\n';
    return true;
}



void createInfos( string nameFile, int id = 0 )
{
    int dia;
    int mes;
    int ano;

    cout << "Para jogar, insira sua data de nascimento (dia mês ano): ";
    if (!(cin >> dia >> mes >> ano)) {
        cerr << "entrada inválida!" << '\n';
        return; // Exit with an error code
    }

    // abre o arquivo pra escrita 
    ofstream outputFile(nameFile, std::ios::out | std::ios::trunc);
    if (!outputFile.is_open()) {
        cerr << "Erro ao abrir aquivo para escrita!" << '\n';
        return; //
    }
		// escreve no arquivo 
    outputFile << "id = " << id << '\n';
    outputFile << "dia = " << dia << '\n';
    outputFile << "mes = " << mes << '\n';
    outputFile << "ano = " << ano << '\n';

    outputFile.close();
    cout << "Dados salvos com sucesso!" << '\n';
    return;
}

/*if (std::getline(iss, value)) {: This line is used to read the rest of the line 
from the iss stream and store it in the value variable. It reads characters from 
the current position in the stream until the end of the line. If successful, it means 
that the remaining part of the line (after the = sign) is stored in the value variable. 
The getline function is used here because it reads until the end of the line, which 
allows you to capture the entire value, even if it contains spaces.
For example, if your input line is "variableName = This is the value", this line would 
read "This is the value" and store it in the value variable.*/