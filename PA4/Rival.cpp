#include "Rival.h"

Rival::Rival():GameObject('R') {
    cout << "Default Rival constructed" << endl;
}

Rival::Rival(string in_name, double in_hp, double phys_dmg, double magic_dmg, double def, int in_id, Point2D in_loc, BattleArena* in_arena):GameObject(in_loc, in_id, 'R') {
    this -> name = in_name;
    //this -> speed = in_speed;
    this -> health = in_hp;
    this -> physical_damage = phys_dmg;
    this -> magical_damage = magic_dmg;
    this -> defense = def;
    this -> state = ALIVE_RIVAL;
    this -> current_arena = in_arena;
    cout << "Rival Contructed" << endl;
}

void Rival::TakeHit(double phys_damage, double magic_damage, double def) {
    srand(time(NULL));
    int type = rand() & 1; // 0 or 1
    double damage;
    if (type == 0) {
        //physical
        damage = (100 - def) / 100 * phys_damage;
        cout << this -> name << " took " << damage << " points of physical damage!" << endl;
    }
    else {
        //magical
        damage = (100 - def) / 100 * magic_damage;
        cout << this -> name << " took " << damage << " points of magical damage!" << endl;
    }
    this -> health -= damage;
    cout << this -> name << " Health: " << this -> health << endl;
}

double Rival::get_phys_dmg() {
    return this -> physical_damage;
}

double Rival::get_magic_dmg() {
    return this -> magical_damage;
}

double Rival::get_defense() {
    return this -> defense;
}

double Rival::get_health() {
    return this -> health;
}

bool Rival::Update() {
    if (!(this -> IsAlive()) && this -> state == ALIVE_RIVAL) {
        this -> state = FAINTED_RIVAL;
        //this -> current_arena -> RemoveOneRival();
        return true;
    }
    else {
        return false;
    }
}

void Rival::ShowStatus() {
    cout << "Rival " << this -> name << " Status: ";
    GameObject::ShowStatus();
    switch (this -> state) {
        case ALIVE_RIVAL:
            //cout << "       It's alive inside Arena " << this -> current_arena -> GetId() << endl;
            cout << "       Health: " << this -> health << endl;
            cout << "       Physical Damage: " << this -> physical_damage << endl;
            cout << "       Magical Damage: " << this -> magical_damage << endl;
            cout << "       Defense: "  << this -> defense << endl;
            break;
        case FAINTED_RIVAL:
            cout << "       It's fainted inside Arena " << this -> current_arena -> GetId() << endl;
            cout << "       Health: " << this -> health << endl;
            break;
        default:
            break;
    }
}

bool Rival::IsAlive() {
    if (this -> health > 0) {
        return true;
    }
    else {
        return false;
    }
}

string Rival::GetName() {
    return this -> name;
}

bool Rival::ShouldBeVisible() {
    return true;
}

BattleArena*  Rival::getArena() {
    return this -> current_arena;
}
