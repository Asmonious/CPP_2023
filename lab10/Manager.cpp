//
// Created by TZ on 11/27/2023.
//

#include <algorithm>
#include "Manager.h"

const string Manager::manager_munkakor = "manager";

Manager::Manager(string vezetekNev, string keresztNev, int szuletesiEv) : Alkalmazott(vezetekNev, keresztNev, szuletesiEv, manager_munkakor) {
}

void Manager::addAlkalmazott(Alkalmazott *beosztott) {
    beosztottak.push_back(beosztott);

}

void Manager::deleteAlkalmazott(Alkalmazott *beosztott) {
    auto found =  find(beosztottak.begin(), beosztottak.end(), beosztott);
    if (found != beosztottak.end()) {
        beosztottak.erase(found);
    }


}

int Manager::beosztottakSzama() const {
    return beosztottak.size();
}

void Manager::print(ostream &os) const {
    os << "\nManager: " << endl;
    Alkalmazott::print(os);
    os << "\nBeosztottak: " << endl;
    for(auto& beosztott : beosztottak) {
        os << "\t";
        beosztott->print(os);
    }
}
