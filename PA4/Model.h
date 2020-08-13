#ifndef MODEL_H
#define MODEL_H
#include "Pokemon.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "View.h"
#include "BattleArena.h"
#include "Rival.h"
#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
using namespace std;

class Model {
public:
    Model();
    ~Model();
    Pokemon* GetPokemonPtr(int id);
    PokemonCenter* GetPokemonCenterPtr(int id);
    PokemonGym* GetPokemonGymPtr(int id);
    bool Update();
    void Display(View& view);
    void ShowStatus();
    //PA4
    BattleArena* GetBattleArenaPtr(int id);
    Rival* GetRivalPtr(int id);
    void NewCommand(char type, int in_id, Point2D in_loc);


private:
    int time;
    //Linked Lists
    list <GameObject*>  object_ptrs;
    list <GameObject*> active_ptrs;
    list <Pokemon*> pokemon_ptrs;
    list <PokemonCenter*> center_ptrs;
    list <PokemonGym*> gym_ptrs;
    list <BattleArena*> arena_ptrs;
    list <Rival*> rival_ptrs;
};

#endif