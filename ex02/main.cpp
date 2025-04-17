#include "Classes.hpp"

int main() {
    Base *p = generate();
    identify(p);
    identify(*p);
}
