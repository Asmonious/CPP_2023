//
// Created by TZ on 12/4/2023.
//

#include <fstream>
#include "GraduationDao.h"

void GraduationDao::enrollStudents(const string &filename) {
    ifstream ifs(filename);
    if(!ifs){
        cout<<"No file!"<<endl;
        exit(1);
    }
    int id;
    string fname, lname;
    while(ifs>>id>>fname>>lname){
        students.emplace(id, Student(id, fname, lname));
    }

}
