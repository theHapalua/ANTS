#include <iostream>
#include "../../src/controller/mdparse.h"

int main(){
    char *text = ants::readFile("lineCount.txt");
    int lineNum = ants::lineCount(text);
    std::cout << lineNum;
}