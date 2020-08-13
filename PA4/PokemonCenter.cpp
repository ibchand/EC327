#include "PokemonCenter.h"

PokemonCenter::PokemonCenter():Building(){
    this -> display_code='C';
    this -> stamina_capacity=100;
    this -> num_stamina_points_remaining=this->stamina_capacity;
    this -> dollar_cost_per_stamina_point=5;
    this -> state=STAMINA_POINTS_AVAILABLE; //Why do I not include apostrophes?
    cout << "PokemonCenter default constructed" << endl;
}

PokemonCenter::PokemonCenter(int in_id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc):Building('C',in_id,in_loc){
    this -> id_num=in_id;
    this -> location=in_loc;
    this -> dollar_cost_per_stamina_point=stamina_cost;
    this -> stamina_capacity=stamina_cap;
    this -> num_stamina_points_remaining=this->stamina_capacity;
    cout << "PokemonCenter constructed" << endl;
}

bool PokemonCenter::HasStaminaPoints() {
    if (this -> num_stamina_points_remaining > 0) {
        return true;
    }
    else {
        return false;
    }
}

unsigned int PokemonCenter::GetNumStaminaPointsRemaining() {
    return this -> num_stamina_points_remaining;
}

bool PokemonCenter::CanAffordStaminaPoints(unsigned int stamina_points, double budget) {
    if (budget >= (stamina_points * this -> dollar_cost_per_stamina_point)) {
        return true;
    }
    else {
        return false;
    }
}

double PokemonCenter::GetDollarCost(unsigned int stamina_points) {
    return stamina_points * this -> dollar_cost_per_stamina_point;
}

unsigned int PokemonCenter::DistributeStamina(unsigned int points_needed) {
    if ((this -> num_stamina_points_remaining) >= points_needed) {
        this -> num_stamina_points_remaining-=points_needed;
        return points_needed;
    }
    else {
        unsigned int temp=this -> num_stamina_points_remaining;
        this -> num_stamina_points_remaining=0;
        return temp;
    }
}

bool PokemonCenter::Update() {
    //This if statement checks if this function has already been called
    if (this -> state != NO_STAMINA_POINTS_AVAILABLE) {
        if (this -> num_stamina_points_remaining == 0) {
            this -> state=NO_STAMINA_POINTS_AVAILABLE; //Why do I not include apostrophes?
            this -> display_code='c';
            cout << "PokemonCenter " << this -> id_num << " has ran out of stamina points." << endl;
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

void PokemonCenter::ShowStatus() {
    cout << "Pokemon Center Status: ";
    Building::ShowStatus();
    cout << "       Pokemon dollars per stamina point: " << this -> dollar_cost_per_stamina_point << endl;
    if (num_stamina_points_remaining==1) {
        cout << "       Has " << this -> num_stamina_points_remaining << " stamina point remaining." << endl;
    }
    else {
        cout << "       Has " << this -> num_stamina_points_remaining << " stamina points remaining." << endl;
    }
}

PokemonCenter::~PokemonCenter(){
    cout << "PokemonCenter destructed." << endl;
}