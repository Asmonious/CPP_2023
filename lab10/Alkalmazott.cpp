//
// Created by TZ on 11/27/2023.
//

#include "Alkalmazott.h"

int Alkalmazott::counter = 0;

Alkalmazott::Alkalmazott(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor) : Szemely(
        vezetekNev, keresztNev, szuletesiEv), munkakor(munkakor), id(++counter) {
}

void Alkalmazott::print(ostream &os) const {
    os << "\nId: " << this->id;
    Szemely::print(os);
    os << " // Munkakor: " << this->munkakor << endl;
}
