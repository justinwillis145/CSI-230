#include "proj_lib.h"
#include <iostream>
#include <fstream>

using namespace std;


void save(string file_name, Hero h, Enemy e1, Enemy e2){
    ofstream fout;
    fout.open (file_name);
    if(fout.good()){
        fout << h.health << endl;
        fout << h.x << endl;
        fout << h.y << endl;
        fout << h.damage << endl;
        fout << e1.health << endl;
        fout << e1.x << endl;
        fout << e1.y << endl;
        fout << e1.damage << endl;
        fout << e2.health << endl;
        fout << e2.x << endl;
        fout << e2.y << endl;
        fout << e2.damage << endl;
        fout.close();
        cout << "Save Successful" << endl;
    }
    else{
        cout << "Save failed" << endl;
    }
}

void load(string file_name, Hero &h, Enemy &e1, Enemy &e2){
    ifstream fin(file_name, ios::in);
    if(fin.good()){
        fin >> h.health >> h.x >> h.y >> h.damage;
        fin >> e1.health >> e1.x >> e1.y >> e1.damage;
        fin >> e2.health >> e2.x >> e2.y >> e2.damage;
        fin.close();
        cout << "Load Successful" << endl;
    }
    else {
        cout << "Load Failed" << endl;
    }
}