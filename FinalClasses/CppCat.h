#ifndef PROGRAMOWANIE_CPPCAT_H
#define PROGRAMOWANIE_CPPCAT_H

#include <string>

class CppCat {
private:
    std::string name;
public:
    CppCat();
    void meow();
    std::string getName();
    void setName(std::string name);
};

#endif //PROGRAMOWANIE_CPPCAT_H
