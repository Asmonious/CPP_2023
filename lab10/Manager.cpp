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

void Manager::deleteAlkalmazott(int id) {
    auto found = find_if(beosztottak.begin(), beosztottak.end(),
                         [id](const Alkalmazott *beosztott) { return beosztott->getId() == id; });

    if (found != beosztottak.end()) {
        beosztottak.erase(found);
    }
}


int Manager::beosztottakSzama() const {
    return beosztottak.size();
}

void Manager::print(ostream &os) const {
    os << "Manager: " << getId() << " " << getVezetekNev() << " " << getKeresztNev() << " " << getMunkakor() << endl;
    for(auto& beosztott : beosztottak) {
        os << "\t";
        beosztott->print(os);
    }
}
