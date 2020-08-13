#ifndef BUILDING_H
#define BUILDING_H
#include <iostream>
#include "GameObject.h"
using namespace std;

class Building:public GameObject
{
public:
    Building();
    Building(char in_code, int in_id, Point2D in_loc);
    void AddOnePokemon();
    void RemoveOnePokemon();
    void ShowStatus();
    bool ShouldBeVisible();

private:
    unsigned int pokemon_count;
};

#endif