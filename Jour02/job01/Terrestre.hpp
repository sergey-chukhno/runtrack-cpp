// Terrestre.hpp
#pragma once

#include <iostream>

class Terrestre {
protected:
    double vitesseMarche; // m/s
public:
    Terrestre(double v = 0.0) : vitesseMarche(v) {}
    virtual ~Terrestre() = default;

    void setVitesseMarche(double v) { vitesseMarche = v; }
    double getVitesseMarche() const { return vitesseMarche; }

    virtual void marche() {
        std::cout << "L'animal marche a " << vitesseMarche << " m/s." << std::endl;
    }
};
