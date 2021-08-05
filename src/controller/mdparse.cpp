#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
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

int ants::lineCount(const char *text){
    int length = std::strlen(text);
    int lineNum = 0;
    for(int i = 0;i < length;i++){
        if(text[i] == '\n'){
            lineNum++;
        }
    }
    return ++lineNum;
}

std::string* ants::lineByLine(const char *text){
    int lineNum = lineCount(text);
    int length = std::strlen(text);
    std::string *lines = new std::string[lineNum];
    int currentLineIndex = 0;
    for(int i = 0;i < length;i++){
        if(text[i] == '\n'){
            currentLineIndex++;
        }else{
            lines[currentLineIndex] += text[i];
        }
    }
    return lines;

}

ants::MarkDown::MarkDown(const char *text){
    std::strcpy(this->fullText, text);
}
ants::MarkDown::MarkDown(){
    std::strcpy(this->fullText, "no text");
}