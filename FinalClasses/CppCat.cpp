//// CppCat.cpp
#include "CppCat.h"

CppCat::CppCat() {
    name = "Mr. Speckles";
}

void CppCat::meow() {
    printf("Meow, I am %s\n", name.c_str());
}

std::string CppCat::getName() {
    return name;
}

void CppCat::setName(std::string name) {
    this->name = name;
}

