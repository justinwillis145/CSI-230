#ifndef PROJ_LIB_H
#define PROJ_LIB_H
#include <string>

using namespace std;
struct Hero
{
    int health;
    unsigned char x;
    unsigned char y;
    int damage;

};

struct Enemy
{
    int health;
    int damage;
    unsigned char x;
    unsigned char y;
};
void save(string file_name, Hero h, Enemy e1, Enemy e2);
void load(string file_name, Hero &h, Enemy &e1, Enemy &e2);
#endif