#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"

using namespace std;

int main() {
    Szemely sz1{"Kis", "Janos", 1990};

    Alkalmazott a1{"Nagy", "Peter", 1980, "sofor"};
    Alkalmazott a2{"Kovacs", "Gabor", 1970, "adminisztrator"};
    Alkalmazott a3{"Kiss", "Elvira", 1975, "titkarno"};

    Manager m1{"Torok", "Zoltan", 2000};
    m1.addAlkalmazott(&a1);
    m1.addAlkalmazott(&a2);
    m1.addAlkalmazott(&a3);

    cout << m1;

    m1.deleteAlkalmazott(&a1);

    cout << m1;

}