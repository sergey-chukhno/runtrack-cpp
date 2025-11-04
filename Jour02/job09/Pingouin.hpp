#pragma once
#include "Aquatique.hpp"
#include "Terrestre.hpp"
#include <string>
#include <vector>
#include <unordered_map>
#include <string>
#include <memory>
#include <map>
#include <set>

class Pingouin : public Aquatique, public Terrestre, public std::enable_shared_from_this<Pingouin> {
private:
    double vitesseGlisse_;
    // Journal des aventures : date -> description
    std::unordered_map<std::string, std::string> journalAventures_;
    std::string nom_;
    // friends set: weak_ptrs to other Pingouin
    std::set<std::weak_ptr<Pingouin>, std::owner_less<std::weak_ptr<Pingouin>>> amis_;
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

    // public getter for name
    const std::string& getNom() const { return nom_; }

    static std::shared_ptr<Pingouin> create(const std::string &nom, double vNage, double vMarche, double vGlisse);
    static void nettoyerColonie();
    static void trierColonie();

    double tempsParcours() const; // returns total time or +inf if impossible
    static void afficherTempsTous();

    // Job06: lieux management
    static std::vector<std::string> lieux;
    static void ajouterLieu(const std::string &lieu);
    static void retirerLieu(const std::string &lieu);
    static void afficherLieux();

    // Job07: competences map
    static std::map<std::string,int> competences; // skill -> level
    static void ajouterCompetence(const std::string &nom, int niveau);
    static void modifierCompetence(const std::string &nom, int niveau);
    static void retirerCompetence(const std::string &nom);
    static void afficherCompetences();

    // Job08: friends management (instance-level)
    bool ajouterAmi(const std::shared_ptr<Pingouin> &ami);
    bool retirerAmi(const std::shared_ptr<Pingouin> &ami);

    // Journal d'aventures
    bool ajouterAventure(const std::string& date, const std::string& description);
    bool modifierAventure(const std::string& date, const std::string& description);
    bool retirerAventure(const std::string& date);
    void afficherAventures() const;
    std::vector<std::shared_ptr<Pingouin>> listerAmis() const;
    void nettoyerAmis();
};
