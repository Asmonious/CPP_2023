//
// Created by TZ on 12/8/2023.
//

#ifndef CPP_2022_CEG_H
#define CPP_2022_CEG_H

#include <iostream>
#include <vector>
#include "Alkalmazott.h"
#include "Manager.h"

using namespace std;

class Ceg {
private:
    vector<Alkalmazott *> alkalmazottak;
public:
    const vector<Alkalmazott *> &getAlkalmazottak() const;

public:
    void hireAlkalmazott(Alkalmazott *alkalmazott);

    void fireAlkalmazott(int id);

    void addToManager(Manager *manager, int id);

    void deleteFromManager(Manager *manager, int id);

    void printAlkalmazottak() const;

    void printManagers() const;



};


#endif //CPP_2022_CEG_H
