#include "Classes.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdint.h>
#include <unistd.h>

Base::~Base() {}

extern char **environ;

Base *generate(void) {
    // Leverage both ASLR and epoch
    srand(static_cast<unsigned int>(reinterpret_cast<uintptr_t>(environ)) + static_cast<unsigned int>(time(NULL)));
    int r = rand() % 3;
    if (!r)
        return new A();
    else if (!(r - 1))
        return new B();
    return new C();
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p) try {
    (void)dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
} catch (...) {
    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
    } catch (...) {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
    }
}
