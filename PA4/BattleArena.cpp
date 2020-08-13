#include "BattleArena.h"

BattleArena::BattleArena():Building() {
    this -> display_code = 'A';
    this -> pokemon_count = 0;
    this -> max_num_rivals = 3;
    this -> num_rivals_remaining = max_num_rivals;
    this -> dollar_cost_per_fight = 4;
    this -> stamina_cost_per_fight = 3;
    this -> state = RIVALS_AVAILABLE;
    cout << "BattleArena default constructed" << endl;
}

BattleArena::BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_Id, Point2D in_loc):Building('A',in_Id,in_loc) {
    this -> pokemon_count = 0;
    this -> max_num_rivals = 3;
    this -> num_rivals_remaining = max_num_rivals;
    this -> dollar_cost_per_fight = 4;
    this -> stamina_cost_per_fight = 3;
    this -> state = RIVALS_AVAILABLE;
    cout << "BattleArena constructed" << endl;
}

unsigned int BattleArena::GetNumRivalsRemaining() {
    return this -> num_rivals_remaining;
}

bool BattleArena::HasEnoughRivals() {
    if (this -> num_rivals_remaining >= 1) {
        return true;
    }
    else {
        return false;
    }
}

double BattleArena::GetDollarCost() {
    return this -> dollar_cost_per_fight;
}

unsigned int BattleArena::GetStaminaCost() {
    return this -> stamina_cost_per_fight;
}

bool BattleArena::IsAbleToFight(double budget, unsigned int stamina) {
    if ((budget >= (this -> dollar_cost_per_fight)) && (stamina >= (this -> stamina_cost_per_fight))) {
        //cout << "If in BattleArena IsAbleToFight" << endl;
        return true;
    }
    else {
        //cout << "Else in BattleArena IsAbleToFight" << endl;
        return false;
    }
}

bool BattleArena::Update() {
//To make sure it does not keep returning false, it checks if the state has already been changed
    if (this -> state == RIVALS_AVAILABLE && this -> IsBeaten()) {
        this -> state = NO_RIVALS_AVAILABLE;
        return true;
    }
    else {
        return false;
    }
}

bool BattleArena::IsBeaten() {
    if (this -> num_rivals_remaining == 0) {
        return true;
    }
    else {
        return false;
    }
}

void BattleArena::ShowStatus() {
    cout << "Battle Arena Status: ";
    Building::ShowStatus(); //Will call GameObject.Showstatus();
    //cout << "       Max number of rivals: " << this -> max_num_rivals << endl;
    cout << "       Stamina Cost per Fight: " << this -> stamina_cost_per_fight << endl;
    cout << "       Pokemon Dollar Cost per Fight: " << this -> dollar_cost_per_fight << endl;
    cout << "       Number of Rivals Remaining: " << this -> num_rivals_remaining << endl;
}

void BattleArena::RemoveOneRival() {
    this -> num_rivals_remaining--;
}

void BattleArena::AddOneRival() {
    this -> num_rivals_remaining++;
}

bool BattleArena::ShouldBeVisible() {
    return true;
}