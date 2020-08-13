#include "Model.h"

Model::Model() {
    this -> time = 0;
    this -> num_objects = 6;
    this -> num_pokemon = 2;
    this -> num_centers = 2;
    this -> num_gyms = 2;

    Point2D Pokemon1LOC = Point2D(5,1);
    Point2D Pokemon2LOC = Point2D(10,1);
    //Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc);
    Pokemon* Pokemon1 = new Pokemon("Pikachu",1,'P',2,Pokemon1LOC);
    Pokemon* Pokemon2 = new Pokemon("Bulbasaur",2,'P',1,Pokemon2LOC);

    Point2D Center1LOC = Point2D(1,20);
    Point2D Center2LOC = Point2D(10,20);
    //PokemonCenter(int in_id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc);
    PokemonCenter* Center1 = new PokemonCenter(1,1,100,Center1LOC);
    PokemonCenter* Center2 = new PokemonCenter(2,2,200,Center2LOC);
    
    Point2D Gym1LOC=Point2D(0,0);
    Point2D Gym2LOC=Point2D(5,5);
    //PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, unsigned int exp_points_per_units, int in_id, Point2D in_loc);
    PokemonGym* Gym1 = new PokemonGym(10,1,2.0,3,1,Gym1LOC);
    PokemonGym* Gym2 = new PokemonGym(20,5,7.5,8,2,Gym2LOC);

    //Add Objects to object_ptrs array
    this -> object_ptrs[0] = Pokemon1;
    this -> object_ptrs[1] = Pokemon2;
    this -> object_ptrs[2] = Center1;
    this -> object_ptrs[3] = Center2;
    this -> object_ptrs[4] = Gym1;
    this -> object_ptrs[5] = Gym2;

    this -> pokemon_ptrs[0] = Pokemon1;
    this -> pokemon_ptrs[1] = Pokemon2;

    this -> center_ptrs[0] = Center1;
    this -> center_ptrs[1] = Center2;

    this -> gym_ptrs[0] = Gym1;
    this -> gym_ptrs[1] = Gym2;

    cout << "Model default constructed" << endl;
}

Model::~Model(){
    for (int i=0; i< this -> num_objects; i++) {
        delete this -> object_ptrs[i];
    }
    cout << "Model destructed." << endl;
}

Pokemon* Model::GetPokemonPtr(int id) {
    for (int i=0; i < this -> num_pokemon; i++) {
        if ((this -> pokemon_ptrs[i] -> GetId()) == id) {
            return this -> pokemon_ptrs[i];
        }
    }
    return 0;
}

PokemonCenter* Model::GetPokemonCenterPtr(int id) {
    for (int i=0; i< this -> num_centers; i++) {
        if ((this -> center_ptrs[i] -> GetId()) == id) {
            return this -> center_ptrs[i];
        }
    }
    return 0;
}

PokemonGym* Model::GetPokemonGymPtr(int id) {
    for (int i=0; i< this -> num_gyms; i++) {
        if ((this -> gym_ptrs[i] -> GetId()) == id) {
            return this -> gym_ptrs[i];
        }
    }
    return 0;
}

bool Model::Update() {
    int numBeaten=0; //Counting Variable for number of gyms beaten
    int numExhausted=0; //Counting Variable for number of Pokemon exhausted
    this -> time++; //Increments time by 1
    
    //Counts the number of gyms beaten
    for (int i=0; i<num_gyms; i++) {
        if (gym_ptrs[i] -> IsBeaten()) {
            numBeaten++;
        }
    //If the number of gyms beaten equals the number of gyms, GAME OVER
    } if (numBeaten==num_gyms) {
        cout << "GAME OVER: You win! All Pokemon Gyms beaten!" << endl;   
        exit(0);
    }
    //Counts the number of Pokemon exhausted
    for (int i=0; i<num_pokemon; i++) {
        if (pokemon_ptrs[i] -> IsExhausted()) {
            numExhausted++;
        }
    //If the number of Pokemon exhausted equals the number of Pokemon, GAME OVER
    } if (numExhausted==num_pokemon) {
        cout << "GAME OVER: You lose! All of your Pokemon are tired!" << endl;
        exit(0);
    }

    //Calls update for each object, if one returns true, then return true
    int count=0;
    for (int i=0; i< this -> num_objects; i++) {
        if (this -> object_ptrs[i] -> Update()) {
            count++;
        }
    }
    if(count>0) {
        return true;
    }
    return false;
}

void Model::Display(View& view) {
    cout << "Time: " << this -> time << endl; //Displays the time
    view.Clear(); //Clears the display
    //This plots the objects
    for (int i=0; i<num_objects; i++) {
        view.Plot(object_ptrs[i]);
    }
    view.Draw(); //Draw the objects
}

void Model::ShowStatus() {
    for (int i=0; i<num_objects; i++) {
        object_ptrs[i] -> ShowStatus();
    }
}