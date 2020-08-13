#ifndef BATTLEARENA_H
#define BATTLEARENA_H
#include <iostream>
#include "Building.h"
using namespace std;

class BattleArena:public Building {
public:
    BattleArena(); //Default constructor
    BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_Id, Point2D in_loc);
    unsigned int GetNumRivalsRemaining();
    bool HasEnoughRivals();
    double GetDollarCost();
    unsigned int GetStaminaCost();
    bool IsAbleToFight(double budget, unsigned int stamina);
    bool Update();
    bool IsBeaten(); //If num_rivals_remaining==0, return true
    void ShowStatus();
    void RemoveOneRival();
    void AddOneRival();
    bool ShouldBeVisible();

private:
    unsigned int max_num_rivals; //Max # of rivals this Arena can hold, Intial Value=3
    unsigned int num_rivals_remaining; //Num Rivals in Arena, Initial Value=max_num_rivals
    double dollar_cost_per_fight; //Per fight cost
    unsigned int stamina_cost_per_fight; //Stamina cost per fight
    unsigned int pokemon_count; //Num of Pokemon in Arena
};

enum BattleArenaStates {
    RIVALS_AVAILABLE = 0,
    NO_RIVALS_AVAILABLE = 1
};

#endif