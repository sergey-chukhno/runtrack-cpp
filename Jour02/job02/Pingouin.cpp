#include "Pingouin.hpp"
#include <iostream>

void Pingouin::nage() {
    std::cout << "[Pingouin] " << nom_ << " nage a " << getVitesseNage() << " m/s" << std::endl;
}

void Pingouin::marche() {
    std::cout << "[Pingouin] " << nom_ << " marche a " << getVitesseMarche() << " m/s" << std::endl;
}

void Pingouin::sePresenter() const {
    std::cout << "Bonjour, je suis " << nom_ << ", je nage a " << vitesseNage_ << " m/s, marche a " << vitesseMarche_
              << " m/s et glisse a " << vitesseGlisse_ << " m/s" << std::endl;
}
