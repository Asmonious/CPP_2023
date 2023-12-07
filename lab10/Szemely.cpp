//
// Created by TZ on 11/27/2023.
//

#include "Szemely.h"

Szemely::Szemely(string vezetekNev, string keresztNev, int szuletesiEv) {
    this->vezetekNev = vezetekNev;
    this->keresztNev = keresztNev;
    this->szuletesiEv = szuletesiEv;
}

void Szemely::print(ostream &os) const {
    os << "\n Vezeteknev: " << this->vezetekNev << " // ";
    os << "Keresztnev: " << this->keresztNev << " // ";
    os << "Szuletesi ev: " << this->szuletesiEv;
}

ostream& operator<<(ostream &os, const Szemely &sz) {
    sz.print(os);
    return os;
}
