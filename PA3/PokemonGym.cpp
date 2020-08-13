#include "PokemonGym.h"

PokemonGym::PokemonGym():Building() {
    this -> display_code='G';
    this -> state=NOT_BEATEN;
    this -> max_number_of_training_units=10;
    this -> num_training_units_remaining=this -> max_number_of_training_units;
    this -> stamina_cost_per_training_unit=1;
    this -> dollar_cost_per_training_unit=1.0;
    this -> experience_points_points_per_training_unit=2;
    cout << "PokemonGym default constructed" << endl;
}

PokemonGym::PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, unsigned int exp_points_per_unit, int in_id, Point2D in_loc):Building('G',in_id,in_loc) {
    this -> id_num=in_id;
    this -> max_number_of_training_units=max_training_units;
    this -> stamina_cost_per_training_unit=stamina_cost;
    this -> experience_points_points_per_training_unit=exp_points_per_unit;
    this -> dollar_cost_per_training_unit=dollar_cost;
    this -> location=in_loc;
    this -> num_training_units_remaining=this -> max_number_of_training_units;
    cout << "PokemonGym constructed" << endl;
}

double PokemonGym::GetDollarCost(unsigned int unit_qty) {
    return unit_qty * this -> dollar_cost_per_training_unit;
}
 
unsigned int PokemonGym::GetStaminaCost(unsigned int unit_qty) {
    return unit_qty * this -> stamina_cost_per_training_unit;
}

unsigned int PokemonGym::GetNumTrainingUnitsRemaining() {
    return this -> num_training_units_remaining;
}

bool PokemonGym::IsAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina) {
    if ((budget >= unit_qty * this -> dollar_cost_per_training_unit) &&
        (stamina >= unit_qty * this -> stamina_cost_per_training_unit)) {
            return true;
    }
    else {
        return false;
    }
}

//Returns # of experience points gained
unsigned int PokemonGym::TrainPokemon(unsigned int training_units) {
    if (this -> num_training_units_remaining >= training_units) {
        this -> num_training_units_remaining-=training_units;
        return training_units*this -> experience_points_points_per_training_unit;
    }
    else {
        return num_training_units_remaining*this -> experience_points_points_per_training_unit;
    }
}

bool PokemonGym::Update() {
    if (this -> state != BEATEN) {
        if (this -> num_training_units_remaining == 0) {
            this -> state=BEATEN; //Why do I not include apostrophes?
            this -> display_code='g';
            cout << "(" << this -> display_code << ")(" << this -> id_num << ") has been beaten" << endl;
            return true; //I'm not sure if this line is rigth
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

bool PokemonGym::IsBeaten() {
    if (this -> num_training_units_remaining == 0) {
        return true; //I'm not sure if this line is rigth
    }
    else {
        return false; //It doesn't say this specifically, I'm just assuming
    }
}

void PokemonGym::ShowStatus() {
    cout << "Pokemon Gym Status: ";
    Building::ShowStatus(); //What happens when you format it like this
    cout << "       Max number of training units: " << this -> max_number_of_training_units << endl;
    cout << "       Stamina cost per training unit: " << this -> stamina_cost_per_training_unit << endl;
    cout << "       Pokemon dollar per training unit: " << this -> dollar_cost_per_training_unit << endl;
    cout << "       Experience points per training unit: " << this -> experience_points_points_per_training_unit << endl;
    if (this -> num_training_units_remaining ==1) {
        cout << "       " << num_training_units_remaining << " training unit is remaining for this gym" << endl;
    }
    else {
        cout << "       " << num_training_units_remaining << " training units are remaining for this gym" << endl;
    }
}

PokemonGym::~PokemonGym(){
    cout << "PokemonGym destructed." << endl;
}