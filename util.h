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

    inputFile.close();

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
