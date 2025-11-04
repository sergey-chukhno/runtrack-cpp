#pragma once
#include "Aquatique.hpp"
#include "Terrestre.hpp"
#include <string>
#include <vector>
#include <memory>

class Pingouin : public Aquatique, public Terrestre, public std::enable_shared_from_this<Pingouin> {
private:
    double vitesseGlisse_;
    std::string nom_;
public:
    static std::vector<std::weak_ptr<Pingouin>> colonie;

    Pingouin(const std::string &nom = "Pingo", double vNage = 0.0, double vMarche = 0.0, double vGlisse = 0.0)
        : Aquatique(vNage), Terrestre(vMarche), vitesseGlisse_(vGlisse), nom_(nom) {}

    Pingouin(const Pingouin &other)
        : Aquatique(other.vitesseNage_), Terrestre(other.vitesseMarche_), vitesseGlisse_(other.vitesseGlisse_), nom_(other.nom_) {}

    ~Pingouin() override;

    void nage() override;
    void marche() override;
    void sePresenter() const;

    void setVitesseGlisse(double v) { vitesseGlisse_ = v; }
    double getVitesseGlisse() const { return vitesseGlisse_; }

    static std::shared_ptr<Pingouin> create(const std::string &nom, double vNage, double vMarche, double vGlisse);
    static void nettoyerColonie();

    // Job04 additions
    double tempsParcours() const; // returns total time or +inf if impossible
    static void afficherTempsTous();
};
