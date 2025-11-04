#include "Pingouin.hpp"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits>

std::vector<std::weak_ptr<Pingouin>> Pingouin::colonie;

void Pingouin::nettoyerColonie() {
    auto it = std::remove_if(colonie.begin(), colonie.end(), [](const std::weak_ptr<Pingouin> &w) {
        return w.expired();
    });
    colonie.erase(it, colonie.end());
}

std::shared_ptr<Pingouin> Pingouin::create(const std::string &nom, double vNage, double vMarche, double vGlisse) {
    auto p = std::make_shared<Pingouin>(nom, vNage, vMarche, vGlisse);
    colonie.push_back(p);
    // clean and sort the colony so it remains ordered by parcours time
    nettoyerColonie();
    // sort with lambda comparator: by tempsParcours ascending, tie-break by name
    std::sort(colonie.begin(), colonie.end(), [](const std::weak_ptr<Pingouin> &aW, const std::weak_ptr<Pingouin> &bW) {
        auto a = aW.lock();
        auto b = bW.lock();
        if (!a && !b) return false;
        if (!a) return false;
        if (!b) return true;
        double ta = a->tempsParcours();
        double tb = b->tempsParcours();
        bool aFin = std::isfinite(ta);
        bool bFin = std::isfinite(tb);
        if (aFin && bFin) {
            if (ta != tb) return ta < tb;
            return a->nom_ < b->nom_; // tie-break alphabetical
        }
        if (aFin) return true; // finite before inf
        if (bFin) return false;
        return a->nom_ < b->nom_;
    });
    return p;
}

Pingouin::~Pingouin() {}

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

double Pingouin::tempsParcours() const {
    using std::numeric_limits;
    if (vitesseGlisse_ <= 0.0 || vitesseMarche_ <= 0.0 || vitesseNage_ <= 0.0) return numeric_limits<double>::infinity();
    double t = 0.0;
    t += 15.0 / vitesseGlisse_;
    t += 20.0 / vitesseMarche_;
    t += 50.0 / vitesseNage_;
    t += 15.0 / vitesseMarche_;
    return t;
}

void Pingouin::afficherTempsTous() {
    nettoyerColonie();
    std::cout << std::fixed << std::setprecision(2);
    for (auto it = colonie.begin(); it != colonie.end(); ) {
        if (auto sp = it->lock()) {
            double t = sp->tempsParcours();
            if (std::isfinite(t)) std::cout << sp->nom_ << " : " << t << " s\n";
            else std::cout << sp->nom_ << " : N/A\n";
            ++it;
        } else {
            it = colonie.erase(it);
        }
    }
}
