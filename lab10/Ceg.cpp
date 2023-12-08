//
// Created by TZ on 12/8/2023.
//

#include <algorithm>
#include "Ceg.h"

void Ceg::hireAlkalmazott(Alkalmazott *alkalmazott) {
    alkalmazottak.push_back(alkalmazott);
}

void Ceg::fireAlkalmazott(int id) {
    auto found = find_if(alkalmazottak.begin(), alkalmazottak.end(),
                         [id](const Alkalmazott *alkalmazott) { return alkalmazott->getId() == id; });

    if (found != alkalmazottak.end()) {
        alkalmazottak.erase(found);
    }
}

void Ceg::addToManager(Manager *manager, int id) {
    auto found = find_if(alkalmazottak.begin(), alkalmazottak.end(),
                         [id](const Alkalmazott *alkalmazott) { return alkalmazott->getId() == id; });

    if (found != alkalmazottak.end()) {
        manager->addAlkalmazott(*found);
    }
}

void Ceg::deleteFromManager(Manager *manager, int id) {
    manager->deleteAlkalmazott(id);
}

void Ceg::printAlkalmazottak() const {
    cout << "Az osszes alkalmazott: " << endl;
    for(auto& alkalmazott : alkalmazottak) {
        alkalmazott->print(cout);
    }
}

void Ceg::printManagers() const {
    cout << "Managerek: " << endl;
    for(auto& alkalmazott : alkalmazottak) {
        if(alkalmazott->getMunkakor() == Manager::manager_munkakor) {
            alkalmazott->print(cout);
        }
    }

}

const vector<Alkalmazott *> &Ceg::getAlkalmazottak() const {
    return alkalmazottak;
}
