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
    // colony: public static vector of shared_ptr<Pingouin>
        // colony: public static vector of weak_ptr to avoid keeping objects alive
        static std::vector<std::weak_ptr<Pingouin>> colonie;

        // utility to remove expired entries from the colony
        static void nettoyerColonie();

    Pingouin(const std::string &nom = "Pingo", double vNage = 0.0, double vMarche = 0.0, double vGlisse = 0.0)
        : Aquatique(vNage), Terrestre(vMarche), vitesseGlisse_(vGlisse), nom_(nom) {
        // registration must be done by factory that returns shared_ptr
    }

    // copy constructor
    Pingouin(const Pingouin &other)
        : Aquatique(other.vitesseNage_), Terrestre(other.vitesseMarche_), vitesseGlisse_(other.vitesseGlisse_), nom_(other.nom_) {}

    ~Pingouin() override;

    void nage() override;
    void marche() override;
    void sePresenter() const;

    void setVitesseGlisse(double v) { vitesseGlisse_ = v; }
    double getVitesseGlisse() const { return vitesseGlisse_; }

    // Factory to create shared_ptr and register in colony
    static std::shared_ptr<Pingouin> create(const std::string &nom, double vNage, double vMarche, double vGlisse);
};
