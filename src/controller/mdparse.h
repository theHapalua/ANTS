#ifndef MARKDOWN_PARSE
#define MARKDOWN_PARSE

#include <string>
#include "../3P/json.hpp"

namespace ants{
    int fileLength(const char *filename);
    char *readFile(const char *filename);
    int lineCount(const char *text);
    std::string* lineByLine(const char *text);
    
    class MarkDown{
        private:
            char *fullText;
            std::string *lines;

            char *h1color;
            char *h1style;
            char *h2color;
            char *h2style;
            char *h3color;
            char *h3style;
            char *h4color;
            char *h4style;
            char *h5color;
            char *h5style;
            char *h6color;
            char *h6style;
            char *italicColor;
            char *boldColor;
            char *strikeColor;
            char *listColor;
            char *dividerColor;
        public:
            MarkDown(const char *text);
            MarkDown();
            void getConfig(const char *filename);
            bool is_h1(int lineIndex);
            bool is_h2(int lineIndex);
            bool is_h3(int lineIndex);
            bool is_h4(int lineIndex);
            bool is_h5(int lineIndex);
            bool is_h6(int lineIndex);
    };
}

#endif