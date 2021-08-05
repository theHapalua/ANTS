#ifndef MARKDOWN_PARSE
#define MARKDOWN_PARSE

#include <vector>
#include <string>

namespace ants{
    int fileLength(const char *filename);
    char *readFile(const char *filename);
    int lineCount(const char *text);
    std::string* lineByLine(const char *text);
    
    class MarkDown{
        private:
            char *fullText;
        public:
            MarkDown(const char *text);
            MarkDown();
    };
}

#endif