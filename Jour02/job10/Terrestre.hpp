#pragma once
#include <iostream>

class Terrestre {
protected:
    double vitesseMarche_;
public:
    Terrestre(double v = 0.0) : vitesseMarche_(v) {}
    virtual ~Terrestre() = default;
    virtual void marche();
    void setVitesseMarche(double v) { vitesseMarche_ = v; }
    double getVitesseMarche() const { return vitesseMarche_; }
};
