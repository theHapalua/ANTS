#include <iostream>
#include "../../src/controller/mdparse.h"

int main(){
    char *text = ants::readFile("is_h1.txt");
    ants::MarkDown MD(text);
    if(MD.is_h1(0)){
        std::cout << "first line is a header." << "\n";
    }
    if(!MD.is_h1(2)){
        std::cout << "third line is not a header.";
    }
}