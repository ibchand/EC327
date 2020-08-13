#ifndef RIVAL_H
#define RIVAL_H
#include "GameObject.h"
#include "BattleArena.h"
#include <iostream>
#include <cstdlib>
using namespace std;

enum RivalStates {
    ALIVE_RIVAL=0,
    FAINTED_RIVAL=1
};

class Rival:public GameObject {
public:
    Rival();
    Rival(string name, double hp, double phys_dmg, double magic_dmg, double def, int id, Point2D in_loc, BattleArena* in_arena);
    void TakeHit(double phys_damage, double magic_damage, double def);
    double get_phys_dmg();
    double get_magic_dmg();
    double get_defense();
    double get_health();
    bool Update();
    void ShowStatus();
    bool IsAlive();
    string GetName();
    BattleArena*  getArena();
    bool ShouldBeVisible();

protected:
    double health; //Initial=20
    double physical_damage; //Initial=5
    double magical_damage; //Initial=4
    double defense; //Initial=15
    //double stamina_cost_per_fight;
    bool is_in_arena;
    BattleArena* current_arena;
    string name;
    //double speed;
};

#endif