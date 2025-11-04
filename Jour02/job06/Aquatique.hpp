#pragma once
#include <iostream>

class Aquatique {
protected:
    double vitesseNage_;
public:
    Aquatique(double v = 0.0) : vitesseNage_(v) {}
    virtual ~Aquatique() = default;
    virtual void nage();
    void setVitesseNage(double v) { vitesseNage_ = v; }
    double getVitesseNage() const { return vitesseNage_; }
};
