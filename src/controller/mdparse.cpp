#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include "mdparse.h"
#include "../3P/json.hpp"

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
    this->lines = lineByLine(text);
}
ants::MarkDown::MarkDown(){
    std::strcpy(this->fullText, "no text");
    this->lines = lineByLine("no\ntext");
}

void ants::MarkDown::getConfig(const char *filename){
    char *text = readFile(filename);
    nlohmann::json CONFIG = nlohmann::json::parse(text);
    std::strcpy(this->h1color, CONFIG["h1"]["color"].dump().c_str());
    std::strcpy(this->h1style, CONFIG["h1"]["style"].dump().c_str());
    std::strcpy(this->h2color, CONFIG["h2"]["color"].dump().c_str());
    std::strcpy(this->h2style, CONFIG["h2"]["style"].dump().c_str());
    std::strcpy(this->h3color, CONFIG["h3"]["color"].dump().c_str());
    std::strcpy(this->h3style, CONFIG["h3"]["style"].dump().c_str());
    std::strcpy(this->h4color, CONFIG["h4"]["color"].dump().c_str());
    std::strcpy(this->h4style, CONFIG["h4"]["style"].dump().c_str());
    std::strcpy(this->h5color, CONFIG["h5"]["color"].dump().c_str());
    std::strcpy(this->h5style, CONFIG["h5"]["style"].dump().c_str());
    std::strcpy(this->h6color, CONFIG["h6"]["color"].dump().c_str());
    std::strcpy(this->h6style, CONFIG["h6"]["style"].dump().c_str());
    std::strcpy(this->italicColor, CONFIG["italicColor"].dump().c_str());
    std::strcpy(this->boldColor, CONFIG["boldColor"].dump().c_str());
    std::strcpy(this->strikeColor, CONFIG["strikeColor"].dump().c_str());
    std::strcpy(this->listColor, CONFIG["listColor"].dump().c_str());
    std::strcpy(this->dividerColor, CONFIG["dividerColor"].dump().c_str());
}

bool ants::MarkDown::is_h1(int lineIndex){
    
    char head[] = {this->lines[lineIndex].c_str()[0],this->lines[lineIndex].c_str()[1],'\0'};
    char headerHead[] = "# ";
    if(std::strcmp(head,headerHead)==0){
        return true;
    }else{
        return false;
    }
}

bool ants::MarkDown::is_h2(int lineIndex){
    
    char head[] = {this->lines[lineIndex].c_str()[0],this->lines[lineIndex].c_str()[1],this->lines[lineIndex].c_str()[2],'\0'};
    char headerHead[] = "## ";
    if(std::strcmp(head,headerHead)==0){
        return true;
    }else{
        return false;
    }
}

bool ants::MarkDown::is_h3(int lineIndex){
    
    char head[] = {this->lines[lineIndex].c_str()[0],this->lines[lineIndex].c_str()[1],this->lines[lineIndex].c_str()[2],this->lines[lineIndex].c_str()[3],'\0'};
    char headerHead[] = "### ";
    if(std::strcmp(head,headerHead)==0){
        return true;
    }else{
        return false;
    }
}

bool ants::MarkDown::is_h4(int lineIndex){
    
    char head[] = {this->lines[lineIndex].c_str()[0],this->lines[lineIndex].c_str()[1],this->lines[lineIndex].c_str()[2],this->lines[lineIndex].c_str()[3],this->lines[lineIndex].c_str()[4],'\0'};
    char headerHead[] = "#### ";
    if(std::strcmp(head,headerHead)==0){
        return true;
    }else{
        return false;
    }
}

bool ants::MarkDown::is_h5(int lineIndex){
    
    char head[] = {this->lines[lineIndex].c_str()[0],this->lines[lineIndex].c_str()[1],this->lines[lineIndex].c_str()[2],this->lines[lineIndex].c_str()[3],this->lines[lineIndex].c_str()[4],this->lines[lineIndex].c_str()[5],'\0'};
    char headerHead[] = "##### ";
    if(std::strcmp(head,headerHead)==0){
        return true;
    }else{
        return false;
    }
}

bool ants::MarkDown::is_h6(int lineIndex){
    
    char head[] = {this->lines[lineIndex].c_str()[0],this->lines[lineIndex].c_str()[1],this->lines[lineIndex].c_str()[2],this->lines[lineIndex].c_str()[3],this->lines[lineIndex].c_str()[4],this->lines[lineIndex].c_str()[5],this->lines[lineIndex].c_str()[6],'\0'};
    char headerHead[] = "###### ";
    if(std::strcmp(head,headerHead)==0){
        return true;
    }else{
        return false;
    }
}