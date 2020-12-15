/*
Final Project
Author: Justin Willis
Dungeon Crawler Game


This code will simulate a dungeon crawler game
You can save and load your game
You will be prompted to fight enemies and your goal is to reach the end of the maze
Input WASD to move the dollar sign through the maze




*/





#include <iostream>
#include <string>
#include <fstream>
#include "proj_lib.h"

using namespace std;


int main(int argc, char* argv[])
{
    cout << "You have just woken up and you find yourself trapped in a dangerous demonic \ndungeon... you have to escape... can you find your way out?" << endl;
    bool hero_win = false;
    unsigned char maze[20][40] = {
    {1,1,1,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1},
    {1,1,1,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1},
    {1,1,1,0,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,1,1,1,1},
    {1,1,1,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,0,1,1,1,1,1,1,0,1,0,1},
    {1,1,1,1,1,1,1,1,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,1,1,1,1,1,0,1,0,1},
    {1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,0,1,0,1},
    {1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,0,1,1,0,1},
    {1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,0,1,1,0,0,0,1,1,1,1,0,1,1,0,0},
    {1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,0,1,1,1,0},
    {1,1,1,1,1,1,0,1,1,0,0,0,0,0,3,0,0,0,0,2,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,0,1,1,1,0},
    {1,1,1,1,1,1,0,0,1,1,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,1,1,1,0},
    {1,1,1,1,1,1,1,0,1,1,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,0,1,1,1,0},
    {1,1,1,1,1,1,1,0,1,1,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,0,1,0,0,0,1,0},
    {1,1,1,1,1,1,1,0,1,1,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,1,1,1,0},
    {1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}

    };
    // for (int i=0; i < 20; i++){
    //     for (int j =0; j < 40; j++){
    //         if (maze [i][j] > 1){
    //             cout << "Row: " << i << " Col: " << j << endl;
    //         }
    //     }
    // }
    Hero Steven;
    Steven.health = 100;
    Steven.x =39;
    Steven.y =19;
    Steven.damage = rand()%26;

    Enemy Stinger;
    Enemy Hitter;
    Stinger.health = 20;
    Hitter.health = 25;
    Stinger.x = 18;
    Hitter.x = 13;
    Stinger.y = 12;
    Hitter.y = 12;
    Stinger.damage = (rand()%20)+1;
    Hitter.damage = (rand()%30)+1;
    if (argc > 1){
        string fname(argv[1]);
        load(fname, Steven, Stinger, Hitter);
    }

    char key = 0;
    while(key != 'q'){
        if(hero_win = true){
            for(int y=0; y <20; y++){
                cout << endl;
                for (int x =0; x <40; x++){
                    if(x == Steven.x && y == Steven.y){
                        cout << '$';

                    }
                    else if (maze[y][x] == 1){
                        cout << (unsigned char)'#';
                    }
                    else if (maze[y][x] == 0){
                        cout << (unsigned char)' ';
                    }
                    else if (maze[y][x] == 2){
                        cout << (unsigned char)'M';
                    }
                    else if (maze[y][x] == 3){
                        cout << (unsigned char)'S';
                    }
                    else if (maze[y][x] == 4){
                        cout << (unsigned char)'T';
                    }
                    hero_win =false;

                }
            }
        }

        cout << endl;


        cout << "Steven's damage is: " << Steven.damage << endl;
        cout << "Steven's current health: " << Steven.health << endl;
        cout << "To move upwards press 'W', left 'A', down 'S', right 'D', 'C' to save game, 'V' to load game" << endl;
        cout << "Your move:" << endl;
        cin >> key;
        string file_name;
        if(key =='s' && Steven.y < 19 && maze[Steven.y+1][Steven.x] != 1){
            Steven.y++; system("cls");
        }
        if(key =='w' && Steven.y > 0 && maze[Steven.y-1][Steven.x] != 1){
            Steven.y--; system("cls");
        }
        if(key =='a' && Steven.y > 0 && maze[Steven.y][Steven.x-1] != 1){
            Steven.x--; system("cls");
        }
        if(key =='d' && Steven.y < 39 && maze[Steven.y][Steven.x+1] != 1){
            Steven.x++; system("cls");
        }
        if(key =='c'){
            cout << "Please Input file name to save: " << endl;
            cin >> file_name; 
            save(file_name, Steven, Stinger, Hitter);
        }
        if (key =='v'){
            cout << "Please input file name to load: " << endl;
            cin >> file_name;
            load(file_name, Steven, Stinger, Hitter);
        }

        if(maze[Steven.y][Steven.x] == 4){
            cout << "YOU WIN!" << endl;
            system("pause");
            exit(1);
        }
        string fightOrDie = "";

        if(Steven.x == 19 && Steven.y == 11){
            cout << "write Fight to fight the enemy or write flee to run from the enemy and lose\n" << endl;
            for(Stinger.health =20; Stinger.health > 0; Stinger.health){
                cin >> fightOrDie;
                if (fightOrDie == "Fight" || fightOrDie == "fight"){
                    Stinger.health = Stinger.health - Steven.damage;
                    cout << "Stinger mob's health: " << Stinger.health << endl;

                    if(Stinger.health <= 0){
                        cout << "Enemy defeated. You may Proceed" << endl;
                        hero_win =true;

                    }

                    if (Stinger.health > 0){
                        Steven.health = Steven.health - Stinger.damage;
                        cout << "Steven's health: " << Steven.health << endl;
                        cout << "\nWrite Fight again" << endl;
                        fightOrDie ="";
                        hero_win = false;
                    }

                }
                else if(fightOrDie == "Flee" || fightOrDie == "flee"){
                    cout << "You just lost the game, idiot." << endl;
                    system("pause");
                    exit(1);
                }
            }
        }

        if(Steven.x == 14 && Steven.y == 11){
            cout << "write Fight to fight the enemy or write flee to run from the enemy and lose\n" << endl;
            for(Hitter.health =25; Hitter.health > 0; Hitter.health){
                cin >> fightOrDie;
                if (fightOrDie == "Fight" || fightOrDie == "fight"){
                    Hitter.health = Hitter.health - Steven.damage;
                    cout << "Hitter mob's health: " << Hitter.health << endl;

                    if(Hitter.health <= 0){
                        cout << "Enemy defeated. You may Proceed" << endl;
                        hero_win =true;

                    }

                    if (Hitter.health > 0){
                        Steven.health = Steven.health - Hitter.damage;
                        cout << "Steven's health: " << Steven.health << endl;
                        cout << "\nWrite Fight again" << endl;
                        fightOrDie ="";
                        hero_win = false;
                    }

                }
                else if(fightOrDie == "Flee" || fightOrDie == "flee"){
                    cout << "You just lost the game, idiot." << endl;
                    system("pause");
                    exit(1);
                }
            }
        }








    }
return 0;
}