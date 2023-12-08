#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"
#include "Ceg.h"

using namespace std;

int main() {
//    Szemely sz1{"Kis", "Janos", 1990};
//
//    Alkalmazott a1{"Nagy", "Peter", 1980, "sofor"};
//    Alkalmazott a2{"Kovacs", "Gabor", 1970, "adminisztrator"};
//    Alkalmazott a3{"Kiss", "Elvira", 1975, "titkarno"};
//
//    Manager m1{"Torok", "Zoltan", 2000};
//    m1.addAlkalmazott(&a1);
//    m1.addAlkalmazott(&a2);
//    m1.addAlkalmazott(&a3);
//
//    cout << m1;
//
//    m1.deleteAlkalmazott(3);
//
//    cout << m1;

    Ceg ceg;

    Manager m1{"Torok", "Zoltan", 2000};
    ceg.hireAlkalmazott(&m1);
    Manager m2{"Varga", "Gabor", 1968};
    ceg.hireAlkalmazott(&m2);
    Manager m3{"Herceg", "Krisztian", 1978};
    ceg.hireAlkalmazott(&m3);
    Alkalmazott a1{"Nagy", "Peter", 1980, "sofor"};
    ceg.hireAlkalmazott(&a1);
    Alkalmazott a2{"Kovacs", "Gabor", 1970, "adminisztrator"};
    ceg.hireAlkalmazott(&a2);
    Alkalmazott a3{"Kiss", "Elvira", 1975, "titkarno"};
    ceg.hireAlkalmazott(&a3);
    Alkalmazott a4{"Balogh", "Zoltan", 1977, "karbantarto"};
    ceg.hireAlkalmazott(&a4);
    Alkalmazott a5{"Szabo", "Levente", 1998, "konyvelo"};
    ceg.hireAlkalmazott(&a5);
    Alkalmazott a6{"Jozsa", "Karola" , 1999, "elemzo"};
    ceg.hireAlkalmazott(&a6);
    Alkalmazott a7{"Kiss", "Karoly", 1999, "adatbazis-kezelo"};
    ceg.hireAlkalmazott(&a7);

    ceg.printAlkalmazottak();
    cout << endl;

    ceg.addToManager(&m1, 4);
    ceg.addToManager(&m1, 5);
    ceg.addToManager(&m2, 6);
    ceg.addToManager(&m2, 7);
    ceg.addToManager(&m3, 8);
    ceg.addToManager(&m3, 9);
    ceg.addToManager(&m3, 10);

    ceg.printManagers();
    cout << endl;

    cout << "Athelyezni kivant alkalmazott id-ja: ";
    int id;
    cin >> id;
    ceg.deleteFromManager(&m3, id);
    ceg.addToManager(&m1, id);

    ceg.printManagers();

    return 0;
}