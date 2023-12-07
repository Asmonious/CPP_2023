//
// Created by TZ on 11/27/2023.
//

#ifndef CPP_2022_ALKALMAZOTT_H
#define CPP_2022_ALKALMAZOTT_H

#include "Szemely.h"

class Alkalmazott : public Szemely {

protected :
    string munkakor;
    int id;
    static int counter;

public:
    Alkalmazott(string vezetekNev, string keresztNev, int szuletesiEv, string munkakor);

    virtual void print(ostream &os) const override;

};


#endif //CPP_2022_ALKALMAZOTT_H
