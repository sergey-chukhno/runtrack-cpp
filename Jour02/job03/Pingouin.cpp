#include "Pingouin.hpp"
#include <algorithm>
#include <iostream>

// static member definition
std::vector<std::weak_ptr<Pingouin>> Pingouin::colonie;

void Pingouin::nettoyerColonie() {
    auto it = std::remove_if(colonie.begin(), colonie.end(), [](const std::weak_ptr<Pingouin> &w) {
        return w.expired();
    });
    colonie.erase(it, colonie.end());
}

std::shared_ptr<Pingouin> Pingouin::create(const std::string &nom, double vNage, double vMarche, double vGlisse) {
    auto p = std::make_shared<Pingouin>(nom, vNage, vMarche, vGlisse);
    // store weak_ptr so colony doesn't keep objects alive
    colonie.push_back(p);
    // optional cleanup to remove expired entries
    nettoyerColonie();
    return p;
}

Pingouin::~Pingouin() {
    // nothing special: we keep weak_ptrs in colony and clean expired entries elsewhere
}

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
