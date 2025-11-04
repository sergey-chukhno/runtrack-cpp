#include "Pingouin.hpp"
#include <iostream>

int main() {
    Pingouin p1("Tux", 2.5, 1.2, 3.0);
    p1.sePresenter();
    p1.nage();
    p1.marche();

    // test copy constructor
    Pingouin p2 = p1;
    p2.setVitesseGlisse(4.2);
    p2.sePresenter();

    return 0;
}
