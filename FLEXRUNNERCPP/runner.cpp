#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

int main()
{
    system("find . -type f -name \"*.l\" | tee settings.txt") ;
    system("find . -type f -name \"*.txt\" -not -name \"settings.txt\" | tee -a settings.txt") ;

    std::ifstream settings("settings.txt") ;
    std::string flexProgramName = "" ; 
    std::string inputFile = "" ; 
    std::string flexProgramRealName = "" ;

    int numberOfLines = 0 ; 

    if (!settings) 
        { std::cerr << "File not opened" << std::endl ; return 1 ; }

    // Read the first two lines
    if (std::getline(settings, flexProgramName) && std::getline(settings, inputFile)) {
        std::cout << "inputFile: " << inputFile << std::endl;
    } else {
        std::cerr << "File empty" << std::endl;
        return 1; // Return an error code
    }

    if(flexProgramName.length() > 2) 
        flexProgramRealName = flexProgramName.substr(2, flexProgramName.length() - 4) ;

    system(("flex " + flexProgramName).c_str()) ; 
    system(("g++ -o " + flexProgramRealName + " lex.yy.c -ll").c_str()) ;
    system(("./"+flexProgramRealName + " < " + inputFile + " > output.txt").c_str()) ;

    return 0 ;
}