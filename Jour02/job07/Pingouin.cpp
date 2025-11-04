#include "Pingouin.hpp"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits>

std::vector<std::weak_ptr<Pingouin>> Pingouin::colonie;
std::vector<std::string> Pingouin::lieux;
std::map<std::string,int> Pingouin::competences;

void Pingouin::nettoyerColonie() {
    auto it = std::remove_if(colonie.begin(), colonie.end(), [](const std::weak_ptr<Pingouin> &w) {
        return w.expired();
    });
    colonie.erase(it, colonie.end());
}

std::shared_ptr<Pingouin> Pingouin::create(const std::string &nom, double vNage, double vMarche, double vGlisse) {
    auto p = std::make_shared<Pingouin>(nom, vNage, vMarche, vGlisse);
    colonie.push_back(p);
    nettoyerColonie();
    // keep colony sorted
    trierColonie();
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

void Pingouin::trierColonie() {
    nettoyerColonie();
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
            return a->nom_ < b->nom_;
        }
        if (aFin) return true;
        if (bFin) return false;
        return a->nom_ < b->nom_;
    });
}

// Job06: lieux management
void Pingouin::ajouterLieu(const std::string &lieu) {
    if (std::find(lieux.begin(), lieux.end(), lieu) == lieux.end()) lieux.push_back(lieu);
}

void Pingouin::retirerLieu(const std::string &lieu) {
    lieux.erase(std::remove(lieux.begin(), lieux.end(), lieu), lieux.end());
}

void Pingouin::afficherLieux() {
    if (lieux.empty()) {
        std::cout << "Aucun lieu de rencontre defini." << std::endl;
        return;
    }
    std::cout << "Lieux de rencontre:" << std::endl;
    for (const auto &l : lieux) std::cout << "- " << l << std::endl;
}

// Job07: competences management
void Pingouin::ajouterCompetence(const std::string &nom, int niveau) {
    // only add if not present
    if (competences.find(nom) == competences.end()) competences[nom] = niveau;
}

void Pingouin::modifierCompetence(const std::string &nom, int niveau) {
    auto it = competences.find(nom);
    if (it != competences.end()) it->second = niveau;
}

void Pingouin::retirerCompetence(const std::string &nom) {
    competences.erase(nom);
}

void Pingouin::afficherCompetences() {
    if (competences.empty()) {
        std::cout << "Aucune competence definie." << std::endl;
        return;
    }
    std::cout << "Competences:" << std::endl;
    for (const auto &p : competences) std::cout << "- " << p.first << " : " << p.second << std::endl;
}
