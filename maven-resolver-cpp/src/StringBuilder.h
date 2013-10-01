#ifndef STRINGBUILDER_H_
#define STRINGBUILDER_H_
#include <string>
#define ScratchSize 1024

class StringBuilder {
private:
    std::string main;
    std::string scratch;

public:
    StringBuilder & append(const std::string & str);

    const std::string & str();
};
#endif /*STRINGBUILDER_H_*/
