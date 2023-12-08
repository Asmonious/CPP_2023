//
// Created by TZ on 11/27/2023.
//

#include "Alkalmazott.h"

int Alkalmazott::counter = 0;

Alkalmazott::Alkalmazott(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor) : Szemely(
        vezetekNev, keresztNev, szuletesiEv), munkakor(munkakor), id(++counter) {
}

void Alkalmazott::print(ostream &os) const {
    os << "Alkalmazott " << this->id << " ";
    Szemely::print(os);
    os << " " << this->munkakor << endl;
}

int Alkalmazott::getId() const {
    return id;
}

string Alkalmazott::getVezetekNev() const {
    return vezetekNev;
}

string Alkalmazott::getKeresztNev() const {
    return keresztNev;
}

string Alkalmazott::getMunkakor() const {
    return munkakor;
}