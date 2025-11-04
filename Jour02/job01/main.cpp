// main.cpp
#include "Pingouin.hpp"

int main() {
    Pingouin p("Pingu", 4.2, 1.0);
    p.sePresenter();
    p.nage();
    p.marche();

    // modifier les vitesses
    p.setVitesseNage(5.5);
    p.setVitesseMarche(1.5);
    p.nage();
    p.marche();

    return 0;
}
