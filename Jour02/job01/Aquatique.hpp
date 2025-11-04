// Aquatique.hpp
#pragma once

#include <iostream>

class Aquatique {
protected:
    double vitesseNage; // m/s
public:
    Aquatique(double v = 0.0) : vitesseNage(v) {}
    virtual ~Aquatique() = default;

    void setVitesseNage(double v) { vitesseNage = v; }
    double getVitesseNage() const { return vitesseNage; }

    virtual void nage() {
        std::cout << "L'animal nage a " << vitesseNage << " m/s." << std::endl;
    }
};
