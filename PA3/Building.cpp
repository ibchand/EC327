#include "Building.h"

//So this creates an object of GameObject and then it 
//inherits from that class to create Building object
Building::Building():GameObject('B')
{
    this -> pokemon_count=0;
    cout << "Building default constructed" << endl;
}

Building::Building(char in_code, int in_id, Point2D in_loc):GameObject(in_loc, in_id, in_code)
{
    this -> pokemon_count=0;
    cout << "Building constructed" << endl;
}

void Building::AddOnePokemon()
{
    this -> pokemon_count+=1;
}

void Building::RemoveOnePokemon()
{
    this -> pokemon_count-=1;
}

void Building::ShowStatus()
{
    GameObject::ShowStatus();
    if(pokemon_count>1 || pokemon_count<1) {
        cout << "       " << this -> pokemon_count << " pokemon are in this building" << endl;
    }
    else {
        cout << "       " << this -> pokemon_count << " pokemon is in this building" << endl;
    }
}

bool Building::ShouldBeVisible()
{
    return true;
}