#include <iostream>
#include <vector>
#include "../../src/controller/mdparse.h"

int main(){
    char *text = ants::readFile("lineByLine.txt");
    std::string* lines = ants::lineByLine(text);
    std::cout << lines[9];
}