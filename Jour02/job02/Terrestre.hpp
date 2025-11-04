#pragma once
#include <iostream>

class Terrestre {
protected:
    double vitesseMarche_;
public:
    Terrestre(double v = 0.0) : vitesseMarche_(v) {}
    virtual ~Terrestre() = default;

    // virtual method with default implementation
    virtual void marche();

    // accessors
    void setVitesseMarche(double v) { vitesseMarche_ = v; }
    double getVitesseMarche() const { return vitesseMarche_; }
};
