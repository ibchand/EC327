#include "Model.h"

Model::Model() {
    this -> time = 0;

    Point2D Pokemon1LOC = Point2D(5,1);
    Point2D Pokemon2LOC = Point2D(10,1);
    //Pokemon(string in_name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int in_id, char in_code, Point2D in_loc);
    Pokemon* Pokemon1 = new Pokemon("Pikachu",2,20,5,4,15,1,'P',Pokemon1LOC);
    Pokemon* Pokemon2 = new Pokemon("Bulbasaur",1,20,5,4,15,2,'P',Pokemon2LOC);

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

    Point2D Arena1LOC=Point2D(15,12); //Found in the Sample Output, 
    //BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_Id, Point2D in_loc);
    BattleArena* Arena1 = new BattleArena(3, 3, 2.5, 1, Arena1LOC);
    //Rival(string name, double hp, double phys_dmg, double magic_dmg, double def, int id, Point2D in_loc, BattleArena* in_arena);
    Rival* Rival1 = new Rival("John", 16, 3, 7.2, 10, 1, Arena1LOC, Arena1);
    Rival* Rival2 = new Rival("Ben", 29, 4, 5.2, 10, 2, Arena1LOC, Arena1);
    Rival* Rival3 = new Rival("Jen", 24, 4, 4.2, 10, 3, Arena1LOC, Arena1);

    //Add Objects to object_ptrs list
    this -> object_ptrs.push_back(Pokemon1);
    this -> object_ptrs.push_back(Pokemon2);
    this -> object_ptrs.push_back(Rival1);
    this -> object_ptrs.push_back(Rival2);
    this -> object_ptrs.push_back(Rival3);
    this -> object_ptrs.push_back(Center1);
    this -> object_ptrs.push_back(Center2);
    this -> object_ptrs.push_back(Gym1);
    this -> object_ptrs.push_back(Gym2);
    this -> object_ptrs.push_back(Arena1);

    this -> active_ptrs.push_back(Pokemon1);
    this -> active_ptrs.push_back(Pokemon2);
    this -> active_ptrs.push_back(Rival1);
    this -> active_ptrs.push_back(Rival2);
    this -> active_ptrs.push_back(Rival3);
    this -> active_ptrs.push_back(Center1);
    this -> active_ptrs.push_back(Center2);
    this -> active_ptrs.push_back(Gym1);
    this -> active_ptrs.push_back(Gym2);
    this -> active_ptrs.push_back(Arena1);

    //Add Pokemon to pokemon_ptrs list
    this -> pokemon_ptrs.push_back(Pokemon1);
    this -> pokemon_ptrs.push_back(Pokemon2);

    //Add Centers to center_ptrs list
    this -> center_ptrs.push_back(Center1);
    this -> center_ptrs.push_back(Center2);

    //Add Gyms to gym_ptrs list
    this -> gym_ptrs.push_back(Gym1);
    this -> gym_ptrs.push_back(Gym2);

    //Add Arena to arena_ptrs list
    this -> arena_ptrs.push_back(Arena1);

    //Add Rivals to rival_ptrs list
    this -> rival_ptrs.push_back(Rival1);
    this -> rival_ptrs.push_back(Rival2);
    this -> rival_ptrs.push_back(Rival3);

    cout << "Model default constructed" << endl;
}

Model::~Model(){
    //Make an iterator, it, that is set to the start of object_ptrs and traverses the list deleting each object
    list <GameObject*>::iterator it;
    for (it= this -> object_ptrs.begin(); it != this -> object_ptrs.end(); it++) {
        delete (*it);
    }
    cout << "Model destructed." << endl;
}

Pokemon* Model::GetPokemonPtr(int id) {
    //cout << "Test 4" << endl;
    list <Pokemon*>::iterator it;
    //cout << "Test 5" << endl;
    for (it = this -> pokemon_ptrs.begin(); it != this -> pokemon_ptrs.end(); it++) {
        if ((*it) -> GetId() == id) {
            return (*it);
        }
    }
    //cout << "Test 6" << endl;
    return 0;
}

PokemonCenter* Model::GetPokemonCenterPtr(int id) {
    list <PokemonCenter*>::iterator it;
    for (it = this -> center_ptrs.begin(); it != this -> center_ptrs.end(); it++) {
        if ((*it) -> GetId() == id) {
            return (*it);
        }
    }
    return 0;
}

PokemonGym* Model::GetPokemonGymPtr(int id) {
    list <PokemonGym*>::iterator it;
    for (it = this -> gym_ptrs.begin(); it != this -> gym_ptrs.end(); it++) {
        if ((*it) -> GetId() == id) {
            return (*it);
        }
    }
    return 0;
}

BattleArena* Model::GetBattleArenaPtr(int id) {
    list <BattleArena*>::iterator it;
    for (it = this -> arena_ptrs.begin(); it != this -> arena_ptrs.end(); it++) {
        if ((*it) -> GetId() == id) {
            return (*it);
        }
    }
    return 0;
}

Rival* Model::GetRivalPtr(int id) {
    list <Rival*>::iterator it;
    for (it = this -> rival_ptrs.begin(); it != this -> rival_ptrs.end(); it++) {
        if ((*it) -> GetId() == id) {
            return (*it);
        }
    }
    return 0;
}

bool Model::Update() {
    int numGymBeaten=0; //Counting Variable for number of gyms beaten
    int numArenaBeaten=0; //Counting Variable for number of arena beaten
    int numExhausted=0; //Counting Variable for number of Pokemon exhausted
    this -> time++; //Increments time by 1
    
    //Counts the number of gyms beaten
    for (list <PokemonGym*>::iterator it = this -> gym_ptrs.begin(); it != gym_ptrs.end(); it++) {
        if ((*it) -> IsBeaten()) {
            numGymBeaten++;
        }
    //If the number of gyms beaten equals the number of gyms, GAME OVER
    } if (numGymBeaten == this -> gym_ptrs.size()) {
        cout << "All Pokemon Gyms beaten!" << endl; 
        //exit(0);
    }

    //Counts the number of arenas beaten
    for (list <BattleArena*>::iterator it = this -> arena_ptrs.begin(); it != arena_ptrs.end(); it++) {
        if ((*it) -> IsBeaten()) {
            numArenaBeaten++;
        }
    //If the number of gyms beaten equals the number of gyms, GAME OVER
    } if (numArenaBeaten == this -> arena_ptrs.size()) {
        cout << "All Battle Arenas beaten!" << endl; 
        //exit(0);
    }

    //You've got to beat all the gyms and arenas so only exit(0) should be in here for victory condition
    if ((numArenaBeaten == this -> arena_ptrs.size()) && (numGymBeaten == this -> gym_ptrs.size())) {
        cout << "GAME OVER: You Win! All Pokemon Gyms and All Battle Arenas beaten!" << endl;
        exit(0);
    }
    
    //Counts the number of Pokemon exhausted
    for (list <Pokemon*>::iterator it = this -> pokemon_ptrs.begin(); it != this -> pokemon_ptrs.end(); it++) {
        if ((*it) -> IsExhausted()) {
            numExhausted++;
        }
    //If the number of Pokemon exhausted equals the number of Pokemon, GAME OVER
    } if (numExhausted == this -> pokemon_ptrs.size()) {
        cout << "GAME OVER: You lose! All of your Pokemon are tired!" << endl;
        exit(0);
    }

    //Traverse active array and remove inactive objects. Test after failure conditions, but before Update
    vector <GameObject*> springCleaning;
    for (list <GameObject*>::iterator it = this -> active_ptrs.begin(); it != this -> active_ptrs.end(); it++) {
        if (!((*it) -> ShouldBeVisible())) {
            springCleaning.push_back(*it);
            cout << "Inactive Object Removed" << endl;
        }
    }

    //Calls update for each object, if one returns true, then return true
    int count=0;
    for (list <GameObject*>::iterator it = this -> object_ptrs.begin(); it != this -> object_ptrs.end(); it++) {
        if ((*it) -> Update()) {
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
    list <GameObject*>::iterator it;
    for (it = this -> active_ptrs.begin(); it != this -> active_ptrs.end(); it++) {
        view.Plot(*it);
    }
    view.Draw(); //Draw the objects
}

void Model::ShowStatus() {
    list <GameObject*>::iterator it;
    for (it = this -> object_ptrs.begin(); it != this -> object_ptrs.end(); it++) {
        (*it) -> ShowStatus();
    }
}

void Model::NewCommand(char type, int in_id, Point2D in_loc) {
    switch(type) {
        case 'G': {
            PokemonGym* NewGym = new PokemonGym(15,2,3.5,5,in_id,in_loc);
            this -> object_ptrs.push_back(NewGym);
            this -> active_ptrs.push_back(NewGym);
            this -> gym_ptrs.push_back(NewGym);
            break;
        }
        case 'C': {
            PokemonCenter* NewCenter = new PokemonCenter(in_id,1,100,in_loc);
            this -> object_ptrs.push_back(NewCenter);
            this -> active_ptrs.push_back(NewCenter);
            this -> center_ptrs.push_back(NewCenter);
            break;
        }
        case 'P': {
            Pokemon* NewPokemon = new Pokemon("NewPokemon",2,20,5,4,15,in_id,'P',in_loc);
            this -> object_ptrs.push_back(NewPokemon);
            this -> active_ptrs.push_back(NewPokemon);
            this -> pokemon_ptrs.push_back(NewPokemon);
            break;
        }
        case 'R': {
            BattleArena* Arena = this -> arena_ptrs.front();
            Rival* NewRival = new Rival("NewRival",10,2,3,10,in_id,Arena -> GetLocation(),Arena);
            Arena -> AddOneRival();
            this -> object_ptrs.push_back(NewRival);
            this -> active_ptrs.push_back(NewRival);
            this -> rival_ptrs.push_back(NewRival);
            break;
        }
        case 'A': {
            BattleArena* NewArena = new BattleArena(3,3,2.5,in_id,in_loc);
            this -> object_ptrs.push_back(NewArena);
            this -> active_ptrs.push_back(NewArena);
            this -> arena_ptrs.push_back(NewArena);
            break;
        }
    }
}
