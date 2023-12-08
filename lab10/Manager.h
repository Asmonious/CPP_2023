//
// Created by TZ on 11/27/2023.
//

#ifndef CPP_2022_MANAGER_H
#define CPP_2022_MANAGER_H

#include <vector>
#include "Alkalmazott.h"
using namespace std;

class Manager : public Alkalmazott {
private:
    vector<Alkalmazott *> beosztottak;
public:
    static const string manager_munkakor;
    Manager(string vezetekNev, string keresztNev, int szuletesiEva);

    void addAlkalmazott(Alkalmazott *beosztott);

    void deleteAlkalmazott(int id);

    int beosztottakSzama() const;

    virtual void print(ostream &os) const override;
};


#endif //CPP_2022_MANAGER_H
