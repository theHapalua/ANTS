#include <iostream>
#include "../../src/controller/mdparse.h"

int main(){
    char *text = ants::readFile("readingFile.txt");
    std::cout << text;
}