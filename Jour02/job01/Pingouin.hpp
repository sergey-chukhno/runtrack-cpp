// Pingouin.hpp
#pragma once

#include "Aquatique.hpp"
#include "Terrestre.hpp"
#include <iostream>

class Pingouin : public Aquatique, public Terrestre {
private:
    std::string nom;
public:
    Pingouin(const std::string& n = "Pingouin", double vN = 0.0, double vM = 0.0)
        : Aquatique(vN), Terrestre(vM), nom(n) {}

    void setNom(const std::string& n) { nom = n; }
    std::string getNom() const { return nom; }

    // override nage and marche
    void nage() override {
        std::cout << nom << " nage a " << getVitesseNage() << " m/s avec ses ailes-adaptees." << std::endl;
    }

    void marche() override {
        std::cout << nom << " marche a " << getVitesseMarche() << " m/s sur la banquise." << std::endl;
    }

    void sePresenter() {
        std::cout << "Je suis " << nom << ", un pingouin. Je peux nager et marcher." << std::endl;
    }
};
