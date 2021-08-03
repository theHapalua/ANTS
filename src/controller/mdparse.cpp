#include <iostream>
#include <fstream>
#include "mdparse.h"

int ants::fileLength(const char *filename){
    std::fstream mdfile;
    mdfile.open(filename,std::ios_base::in);
    mdfile.seekg(0,std::ios_base::end);
    int length = mdfile.tellg();
    mdfile.seekg(0,std::ios_base::beg);
    mdfile.close();
    return length;
}

char *ants::readFile(const char *filename){
    std::fstream mdfile;
    mdfile.open(filename,std::ios_base::in);
    char *text = new char[ants::fileLength(filename)];
    if(mdfile.is_open()){
        mdfile.read(text,fileLength(filename));
    }
    return text;
}