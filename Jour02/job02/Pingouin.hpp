#pragma once
#include "Aquatique.hpp"
#include "Terrestre.hpp"
#include <string>

class Pingouin : public Aquatique, public Terrestre {
private:
    double vitesseGlisse_;
    std::string nom_;
public:
    Pingouin(const std::string &nom = "Pingo", double vNage = 0.0, double vMarche = 0.0, double vGlisse = 0.0)
        : Aquatique(vNage), Terrestre(vMarche), vitesseGlisse_(vGlisse), nom_(nom) {}

    // copy constructor
    Pingouin(const Pingouin &other)
        : Aquatique(other.vitesseNage_), Terrestre(other.vitesseMarche_), vitesseGlisse_(other.vitesseGlisse_), nom_(other.nom_) {}

    ~Pingouin() override = default;

    // override base virtuals
    void nage() override;
    void marche() override;

    // presentation
    void sePresenter() const;

    // glisse accessors
    void setVitesseGlisse(double v) { vitesseGlisse_ = v; }
    double getVitesseGlisse() const { return vitesseGlisse_; }
};
