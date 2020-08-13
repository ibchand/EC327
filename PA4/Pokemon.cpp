#include "Pokemon.h"

//Do we just choose a random char to pass to GameObject()?
Pokemon::Pokemon():GameObject('D') {
    this -> speed = 5;
    this -> state =STOPPED;
    cout << "Pokemon default constructed." << endl;
    this -> is_in_gym=false;
    this -> is_in_center=false;
    this -> stamina=20; //idk
    this -> experience_points=0;
    this -> pokemon_dollars=0;
    this -> training_units_to_buy=0;
    this -> stamina_points_to_buy=0;
    this -> name="Default";
    this -> current_center=NULL;
    this -> current_gym=NULL;
}
Pokemon::Pokemon(char in_code):GameObject(in_code) {
    this -> speed = 5;
    this -> state = STOPPED;
    this -> display_code = in_code;
    cout << "Pokemon constructed." << endl;
    this -> is_in_gym=false;
    this -> is_in_center=false;
    this -> stamina=20; //idk
    this -> experience_points=0;
    this -> pokemon_dollars=0;
    this -> training_units_to_buy=0;
    this -> stamina_points_to_buy=0;
    this -> name="Default";
    this -> current_center=NULL;
    this -> current_gym=NULL;
}

Pokemon::Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc):GameObject(in_loc, in_id, in_code) {
    this -> speed = in_speed;
    this -> name = in_name;
    cout << "Pokemon constructed." << endl;
    this -> state = STOPPED;
    this -> is_in_gym = false;
    this -> is_in_center = false;
    this -> stamina = 20;
    this -> experience_points = 0;
    this -> pokemon_dollars = 0;
    this -> training_units_to_buy = 0;
    this -> stamina_points_to_buy = 0;
    this -> current_center = NULL;
    this -> current_gym = NULL;
}

Pokemon::Pokemon(string in_name, double in_speed, double hp, double phys_dmg, double magic_dmg, double def, int in_id, char in_code, Point2D in_loc):GameObject(in_loc,in_id,'P') {
    this -> speed = in_speed;
    this -> name = in_name;
    this -> state = STOPPED;
    this -> is_in_gym = false;
    this -> is_in_center = false;
    this -> stamina = 20;
    this -> experience_points = 0;
    this -> pokemon_dollars = 0;
    this -> training_units_to_buy = 0;
    this -> stamina_points_to_buy = 0;
    this -> current_center = NULL;
    this -> current_gym = NULL;
    this -> health = hp;
    this -> physical_damage = phys_dmg;
    this -> magical_damage = magic_dmg;
    this -> defense = def;
    this -> is_in_arena =false;
    this -> target = NULL;
    this -> current_arena = NULL;
    cout << "Pokemon constructed." << endl;
}

//Description on page 16
void Pokemon::StartMoving(Point2D dest) {
    //Passes dest to SetupDestination() to save destination and calculate delta value
    Pokemon::SetupDestination(dest);
    if ((this -> location.x == dest.x) && (this -> location.y == dest.y)) {
        this -> state = STOPPED;
        cout << this -> display_code << this -> id_num << ": I'm already there. See?" << endl;
    }
    //Would this be an if or an else if?
    else if (IsExhausted()) {
        this -> state = EXHAUSTED;
        cout << this -> display_code << this -> id_num << ": I am exhausted. I may move but you cannot see me." << endl;
    }
    else {
        this -> state = MOVING;
        cout << this -> display_code << this -> id_num << ": On my way." << endl;
        if (this -> is_in_gym) {
            this -> is_in_gym=false;
            this -> current_gym -> RemoveOnePokemon();
        }
        if (this -> is_in_center) {
            this -> is_in_center=false;
            this -> current_center -> RemoveOnePokemon();
        }
        if (this -> is_in_arena) {
            this -> is_in_arena=false;
            this -> current_arena -> RemoveOnePokemon();
        }
    }
}

void Pokemon::StartMovingToCenter(PokemonCenter* center) {
    SetupDestination(center -> GetLocation()); //Do I do this regardless of conditions?
    Point2D cenLoc=center -> GetLocation();
    if ((this -> location.x == cenLoc.x) && (this -> location.y == cenLoc.y)) {
        cout << this -> display_code << this -> id_num << ": I am already at the Pokemon Center!" << endl;
        this -> state = STOPPED; //I think I should update this
    }
    else if (IsExhausted()) {
        cout << this -> display_code << this -> id_num << ": I am exhausted so I can't move to recover stamina..." << endl;
        this -> state = EXHAUSTED; //I think I should update this
    }
    else {
        this -> state = MOVING_TO_CENTER;
        this -> current_center = center;
        cout << this -> display_code << this -> id_num << ": on my way to center " << center -> GetId() << "." << endl;
        if (this -> is_in_gym) {
            this -> is_in_gym=false;
            this -> current_gym -> RemoveOnePokemon();
        }
        if (this -> is_in_center) {
            this -> is_in_center=false;
            this -> current_center -> RemoveOnePokemon();
        }
        if (this -> is_in_arena) {
            this -> is_in_arena=false;
            this -> current_arena -> RemoveOnePokemon();
        }
    }
}

void Pokemon::StartMovingToGym(PokemonGym* gym) {
    Point2D gymLoc = gym -> GetLocation();
    if ((this -> location.x == gymLoc.x) && (this -> location.y == gymLoc.y)) {
        // x and y coordinates are the same as the destination
        cout << this -> display_code << this -> id_num << ": I am already at the Pokemon Gym!" << endl;
        this -> state = IN_GYM;
    }
    else if (this -> IsExhausted()) {
        cout << this -> display_code << this -> id_num << ": I am exhausted so I shouldn't be going to the gym." << endl;
        this -> state = EXHAUSTED;
    }
    else {
        this -> SetupDestination(gym -> GetLocation());
        //cout << "IT'S BEING SET TO MOVING" << endl;
        this -> state = MOVING_TO_GYM;
        cout << this -> display_code << this -> id_num << ": On my way to the gym " << gym -> GetId() << "." << endl;
        this -> current_gym=gym;
        if (this -> is_in_gym) {
            this -> is_in_gym=false;
            this -> current_gym -> RemoveOnePokemon();
        }
        if (this -> is_in_center) {
            this -> is_in_center=false;
            this -> current_center -> RemoveOnePokemon();
        }
        if (this -> is_in_arena) {
            this -> is_in_arena=false;
            this -> current_arena -> RemoveOnePokemon();
        }
    }
}

void Pokemon::StartTraining(unsigned int num_training_units) {
    if (IsExhausted()) {
        cout << this -> display_code << this -> id_num << ": I am exhausted so no more training for me." << endl;
        this -> state = EXHAUSTED;
    }
    else if (! this -> is_in_gym) {
        cout << this -> display_code << this -> id_num << ": I can only train in a Pokemon Gym!" << endl;
    }
    else if (!(this -> current_gym -> IsAbleToTrain(num_training_units, this -> pokemon_dollars, this -> stamina))) {
        cout << this -> display_code << this -> id_num << ": Not enought stamina and/or money for training" << endl;
    }
    else if (this -> current_gym -> IsBeaten()) {
        cout << this -> display_code << this -> id_num << ": Cannot train! This Pokemon Gym is already beaten!" << endl;
    }
    else {
        this -> state=TRAINING_IN_GYM;
        this -> training_units_to_buy = min(this -> current_gym -> GetNumTrainingUnitsRemaining(), num_training_units);
        cout << this -> display_code << ": Started to train " << num_training_units << " at Pokemon Gym " << this -> current_gym -> GetId() << " with " << this -> current_gym -> GetNumTrainingUnitsRemaining() << " training units" << endl;
    }
}

void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points) {
    if (!(this -> current_center -> CanAffordStaminaPoints(num_stamina_points,this -> pokemon_dollars))) {
        cout << this -> display_code << this -> id_num << ": Not enough money to recover stamina." << endl;
    }
    else if (this -> current_center -> GetNumStaminaPointsRemaining() < 1) {
        cout << this -> display_code << this -> id_num << ": Cannot recover! No stamina points remaining in this Pokemon Center" << endl;
    }
    else if (!is_in_center) {
        cout << this -> display_code << this -> id_num << ": I can only recover stamina at a Pokemon Center!" << endl;
    }
    else {
        this -> state = RECOVERING_STAMINA;
        this -> stamina_points_to_buy = min(num_stamina_points, this -> current_center -> GetNumStaminaPointsRemaining());
        cout << this -> display_code << this -> id_num << ": Started recovering (" << stamina_points_to_buy << " stamina points(s) at Pokemon Center " << this -> current_center -> GetId() << endl;
    }
}

void Pokemon::Stop() {
    this -> state = STOPPED;
    cout << this -> display_code << this -> id_num << ": Stopping.." << endl;
}

bool Pokemon::IsExhausted() {
    if (this -> stamina == 0) {
        return true;
    }
    else {
        return false;
    }
}

bool Pokemon::ShouldBeVisible() {
    if (!(this -> IsExhausted())) {
        return true;
    }
    else {
        return false;
    }
}

bool Pokemon::Update() {
    switch (this -> state) {
        case STOPPED: 
        {
            return false;
            break;
        }
        case MOVING:
        {
            return this -> UpdateLocation();
            break;
        }
        case MOVING_TO_CENTER:
        {
            //this -> ShowStatus();
            if (this -> UpdateLocation()) {
                this -> state = IN_CENTER;
                this -> is_in_center = true;
                this -> current_center -> AddOnePokemon();
                return true;
            }
            else {
                return false;
            }
            break;
        }
        case MOVING_TO_GYM:
        {
            if (this -> UpdateLocation()) {
                this -> state = IN_GYM;
                this -> is_in_gym = true;
                this -> current_gym -> AddOnePokemon();
                return true;
            }
            else {
                return false;
            }
            break;
        }
        case IN_CENTER:
        {
            return false;
            break;
        }
        case IN_GYM:
        {
            return false;
            break;
        }
        case TRAINING_IN_GYM:
        {
            cout << "**" << this -> name << " completed " << this -> training_units_to_buy << " training unit(s)!**" << endl;
            cout << "**" << this -> name << " gained " << this -> current_gym -> TrainPokemon(this -> training_units_to_buy) << " experience point(s)!**" << endl;
            this -> stamina -= this -> current_gym -> GetStaminaCost(this -> training_units_to_buy);
            this -> pokemon_dollars -= this -> current_gym -> GetDollarCost(this -> training_units_to_buy);
            this -> experience_points += this -> current_gym -> TrainPokemon(this -> training_units_to_buy);
            this -> state = IN_GYM;
            return true;
            break;
        }
        case RECOVERING_STAMINA:
        {
            cout << "**" << this -> name << " recovered " << this -> current_center -> DistributeStamina(this -> stamina_points_to_buy) << " stamina point(s)!**" << endl;
            this -> stamina += this -> current_center -> DistributeStamina(this -> stamina_points_to_buy);
            this -> pokemon_dollars -= this -> current_center -> GetDollarCost(this -> stamina_points_to_buy);
            this -> state = IN_CENTER;
            return true;
            break;
        }
        case EXHAUSTED: 
        {
            return false;
            break;
        }
        case FAINTED:
        {
            this -> state = FAINTED;
            return false;
            break;
        }
        case MOVING_TO_ARENA:
        {
            if (this -> UpdateLocation()) {
                state = IN_ARENA;
                this -> is_in_arena = true;
                this -> current_arena -> AddOnePokemon();
                return true;
            }
            else {
                return false;
            }
            break;
        }
        case IN_ARENA:
        {
            return false;
            break;
        }
        case BATTLE:
        {
            this -> stamina -= this -> current_arena -> GetStaminaCost();
            this -> pokemon_dollars -= this -> current_arena -> GetDollarCost();
            cout << "THIS RUNS" << endl;
            if (StartBattle()) {

                //If true, that means pokemon won
                this -> health = this -> store_health;
                this -> state = IN_ARENA;
                this -> target -> IsAlive();
            }
            else {
                this -> state = FAINTED;
                this -> target -> IsAlive();
                this -> health = 0;
            }
            break;
        }
        default:
        {
            cout << "Default in Pokemon::Update() triggered!" << endl;
            return false;
            break;
        }
    }
    //cout << "Error: End in Pokemon::Update() reached!" << endl;
    return false;
}

void Pokemon::ShowStatus() {
    //cout << "#1 CP" << endl;
    cout << this -> name << " status: ";
    GameObject::ShowStatus();

    switch (this -> state) {
        case STOPPED:
            cout << "       Stopped" << endl;
            cout << "       Health: " << this -> health << endl;
            cout << "       Physical Damage: " << this -> physical_damage << endl;
            cout << "       Magical Damage: " << this -> magical_damage << endl;
            cout << "       Defense: " << this -> defense << endl;
            cout << "       Stamina: " << this -> stamina << endl;
            cout << "       Pokemon Dollars: " << this -> pokemon_dollars << endl;
            cout << "       Experience Points: " << this -> experience_points << endl;
            break;
        case MOVING:
            cout << "       Moving at a speed of " << this -> speed << " to destination " << this -> destination << " at each step of " << this -> delta << endl;
            cout << "       Health: " << this -> health << endl;
            cout << "       Physical Damage: " << this -> physical_damage << endl;
            cout << "       Magical Damage: " << this -> magical_damage << endl;
            cout << "       Defense: " << this -> defense << endl;
            cout << "       Stamina: " << this -> stamina << endl;
            cout << "       Pokemon Dollars: " << this -> pokemon_dollars << endl;
            cout << "       Experience Points: " << this -> experience_points << endl;
            break;
        case MOVING_TO_CENTER:
            cout << "       Heading to Pokemon Center " << this -> current_center -> GetId() << " at a speed of " << this -> speed << " at each step of " << this -> delta << endl;
            cout << "       Health: " << this -> health << endl;
            cout << "       Physical Damage: " << this -> physical_damage << endl;
            cout << "       Magical Damage: " << this -> magical_damage << endl;
            cout << "       Defense: " << this -> defense << endl;
            cout << "       Stamina: " << this -> stamina << endl;
            cout << "       Pokemon Dollars: " << this -> pokemon_dollars << endl;
            cout << "       Experience Points: " << this -> experience_points << endl;
            break;
        case MOVING_TO_GYM:
            cout << "       Heading to Pokemon Gym " << this -> current_gym -> GetId() << " at a speed of " << this -> speed << " at each step of " << this -> delta << endl;
            cout << "       Health: " << this -> health << endl;
            cout << "       Physical Damage: " << this -> physical_damage << endl;
            cout << "       Magical Damage: " << this -> magical_damage << endl;
            cout << "       Defense: " << this -> defense << endl;
            cout << "       Stamina: " << this -> stamina << endl;
            cout << "       Pokemon Dollars: " << this -> pokemon_dollars << endl;
            cout << "       Experience Points: " << this -> experience_points << endl;
            break;
        case IN_CENTER:
            cout << "       inside Pokemon Center " << this -> current_center -> GetId() << endl;
            cout << "       Health: " << this -> health << endl;
            cout << "       Physical Damage: " << this -> physical_damage << endl;
            cout << "       Magical Damage: " << this -> magical_damage << endl;
            cout << "       Defense: " << this -> defense << endl;
            cout << "       Stamina: " << this -> stamina << endl;
            cout << "       Pokemon Dollars: " << this -> pokemon_dollars << endl;
            cout << "       Experience Points: " << this -> experience_points << endl;
            break;
        case IN_GYM:
            cout << "       inside Pokemon Gym " << this -> current_gym -> GetId() << endl;
            cout << "       Health: " << this -> health << endl;
            cout << "       Physical Damage: " << this -> physical_damage << endl;
            cout << "       Magical Damage: " << this -> magical_damage << endl;
            cout << "       Defense: " << this -> defense << endl;
            cout << "       Stamina: " << this -> stamina << endl;
            cout << "       Pokemon Dollars: " << this -> pokemon_dollars << endl;
            cout << "       Experience Points: " << this -> experience_points << endl;
            break;
        case TRAINING_IN_GYM:
            cout << "       training in Pokemon Gym " << this -> current_gym -> GetId() << endl;
            cout << "       Health: " << this -> health << endl;
            cout << "       Physical Damage: " << this -> physical_damage << endl;
            cout << "       Magical Damage: " << this -> magical_damage << endl;
            cout << "       Defense: " << this -> defense << endl;
            cout << "       Stamina: " << this -> stamina << endl;
            cout << "       Pokemon Dollars: " << this -> pokemon_dollars << endl;
            cout << "       Experience Points: " << this -> experience_points << endl;
            break;
        case RECOVERING_STAMINA:
            cout << "       Recovering stamina in Pokemon Center " << this -> current_center -> GetId() << endl;
            cout << "       Health: " << this -> health << endl;
            cout << "       Physical Damage: " << this -> physical_damage << endl;
            cout << "       Magical Damage: " << this -> magical_damage << endl;
            cout << "       Defense: " << this -> defense << endl;
            cout << "       Stamina: " << this -> stamina << endl;
            cout << "       Pokemon Dollars: " << this -> pokemon_dollars << endl;
            cout << "       Experience Points: " << this -> experience_points << endl;
            break;
        case MOVING_TO_ARENA:
            cout << "       Heading to Battle Arena " << this -> current_arena -> GetId() << " at a speed of " << this -> speed << " at each step of " << this -> delta << endl;
            cout << "       Health: " << this -> health << endl;
            cout << "       Physical Damage: " << this -> physical_damage << endl;
            cout << "       Magical Damage: " << this -> magical_damage << endl;
            cout << "       Defense: " << this -> defense << endl;
            cout << "       Stamina: " << this -> stamina << endl;
            cout << "       Pokemon Dollars: " << this -> pokemon_dollars << endl;
            cout << "       Experience Points: " << this -> experience_points << endl;
            break;
        case IN_ARENA:
            cout << "       inside Battle Arena " << this -> current_arena -> GetId() << endl;
            cout << "       Health: " << this -> health << endl;
            cout << "       Physical Damage: " << this -> physical_damage << endl;
            cout << "       Magical Damage: " << this -> magical_damage << endl;
            cout << "       Defense: " << this -> defense << endl;
            cout << "       Stamina: " << this -> stamina << endl;
            cout << "       Pokemon Dollars: " << this -> pokemon_dollars << endl;
            cout << "       Experience Points: " << this -> experience_points << endl;
            break;
        case FAINTED:
            cout << "       Fainted!" << endl;
            cout << "       Health: " << this -> health << endl;
            cout << "       Physical Damage: " << this -> physical_damage << endl;
            cout << "       Magical Damage: " << this -> magical_damage << endl;
            cout << "       Defense: " << this -> defense << endl;
            cout << "       Stamina: " << this -> stamina << endl;
            cout << "       Pokemon Dollars: " << this -> pokemon_dollars << endl;
            cout << "       Experience Points: " << this -> experience_points << endl;
            break;
        case BATTLE:
            cout << "       Battling!" << endl;
            cout << "       Health: " << this -> health << endl;
            cout << "       Physical Damage: " << this -> physical_damage << endl;
            cout << "       Magical Damage: " << this -> magical_damage << endl;
            cout << "       Defense: " << this -> defense << endl;
            cout << "       Stamina: " << this -> stamina << endl;
            cout << "       Pokemon Dollars: " << this -> pokemon_dollars << endl;
            cout << "       Experience Points: " << this -> experience_points << endl;
            break;
        default:
            cout << "Default in Pokemon::ShowStatus() tripped!" << endl;
            break;
    }
}


bool Pokemon::UpdateLocation() {
    //Check if it's exhausted
    if (IsExhausted()) {
        this -> state = STOPPED;
        cout << this -> name <<" is Exhausted!" << endl;
        //this -> state = EXHAUSTED;
        return false;
    }
    else {
        //Check to see if the destination is within one step of current location (location)
        //In order for this to be true, the difference between the x and y coordinates must be less than delta
        //ABS means Anti-Lock Breaking System, a safety anti-skit breaking system used on aircraft and land vehicles, 
        //such as cars, motorcycles, trucks and busses. It operates by preventing the wheel from locking up during 
        //braking, thereby maintaining tractive constact with the road surface
        double DiffXABS = fabs(this -> location.x - this -> destination.x);
        double DiffYABS = fabs(this -> location.y - this -> destination.y);
        double DxABS=fabs(this -> delta.x);
        double DyABS=fabs(this -> delta.y);
        
        //Decreases stamina each time it moves

        if ((DiffXABS <= DxABS) && (DiffYABS <= DyABS)) {
            this -> state = STOPPED;
            this -> location = this -> destination;
            cout << this -> display_code << this -> id_num << ": I'm there!" << endl;
            return true; //Return true when the destination has been reached
        }
        else {
            this -> stamina--;
            this -> pokemon_dollars += GetRandomAmountOfPokemonDollars();
            //cout << "THIS RAN" << endl;
            this -> location = this -> location + this -> delta;
            cout << this -> display_code << this -> id_num << ": step..." << endl;
            return false; //Return false when the destinaion has not been reached
        }
    }
}

void Pokemon::SetupDestination(Point2D dest) {
    //Sets the destination to the provided input destination
    this -> destination=dest;
    //Delta is a Point2D object, so it has X and Y coordinates
    this -> delta = (dest - this -> location) * (this -> speed / GetDistanceBetween(dest,this ->location));
}

double GetRandomAmountOfPokemonDollars() {
    srand(time(NULL));
    return (rand() % 21) / 10.00;
}

Pokemon::~Pokemon() {
    cout << "Pokemon destructed." << endl;
}

string Pokemon::GetName() {
    return this -> name;
}


//PA4
bool Pokemon::IsAlive() {
    if (this -> state == FAINTED) {
        return false;
    }
    else {
        return true;
    }
}

void Pokemon::TakeHit(double phys_damage, double magic_damage, double def) {
    srand(time(NULL));
    int type = rand() & 1;
    double damage;
    if (type == 0) {
        //physical
        damage = (100 - def) / 100 * phys_damage;
            cout << this -> name << " took " << damage << " points of physical damage!" << endl;
        }
        else {
            //magical
            damage = (100 - def) / 100 * magic_damage;
            cout << this -> name << " took " << damage << " points of magic damage!" << endl;
        }
        this -> health -= damage;
        cout << this -> name << " Health: " << this -> health << endl;
}

void Pokemon::ReadyBattle(Rival* in_target) {
    if (!(this -> is_in_arena)) {
        cout << "Can Only Battle in an Arena!" << endl;
    }
    else if (!(this -> current_arena -> IsAbleToFight(this -> pokemon_dollars, this -> stamina))) {
        cout << "Cannot Fight! Not enough Money or Stamina" << endl;
        this -> state = IN_ARENA;
    }
    else if (this -> current_arena -> IsBeaten()) {
        cout << "This Arena have been beaten" << endl;
                this -> state = IN_ARENA;
        this -> state = IN_ARENA;
    }
    else if (!(in_target -> IsAlive())) {
        cout << "This Rival has been beaten" << endl;
        this -> state = IN_ARENA;
    }
    else {
        this -> target=in_target;
        this -> state=BATTLE;
    }
}

bool Pokemon::StartBattle() {
    this -> state = BATTLE; //I think, idk
    while ((this -> health > 0) || (this -> target -> get_health() > 0)) {
        //Rival Hits first
        this -> TakeHit(this -> target -> get_phys_dmg(), this -> target -> get_magic_dmg(), this -> defense);
        //You Hit
        //cout << this -> physical_damage << "    " << this -> magical_damage << endl;
        this -> target -> TakeHit(this -> physical_damage, this -> magical_damage, this -> target -> get_defense());
    }
    if (this -> health == 0) {
        cout << "Pokemon " << this -> name << " Lost!" << endl;
        this -> state = FAINTED;
        this -> target -> IsAlive();
        return false;
    }
    else {
        cout << "Pokemon " << this -> name << " Won!" << endl;
        this -> health = this -> store_health;
        this -> state = IN_ARENA;
        this -> target -> IsAlive();
        this -> target -> getArena() -> RemoveOneRival();
        return true;
    }
}

void Pokemon::StartMovingToArena(BattleArena* arena) {
    Point2D arenaLoc=arena -> GetLocation();
    Point2D thisLoc = this -> GetLocation();
    if ((thisLoc.x == arenaLoc.x) && (thisLoc.y == arenaLoc.y)) {
        cout << this -> display_code << this -> id_num << ": I am already at the Pokemon Center!" << endl;
        this -> state = IN_ARENA; //I think I should update this
    }
    else if (IsExhausted()) {
        cout << this -> display_code << this -> id_num << ": I am exhausted so I can't move to recover stamina..." << endl;
        this -> state = EXHAUSTED; //I think I should update this
    }
    else {
        this -> SetupDestination(arenaLoc);
        this -> state = MOVING_TO_ARENA;
        this -> current_arena = arena;
        cout << this -> display_code << this -> id_num << ": on my way to arena " << arena -> GetId() << "." << endl;
        if (this -> is_in_gym) {
            this -> is_in_gym=false;
            this -> current_gym -> RemoveOnePokemon();
        }
        if (this -> is_in_center) {
            this -> is_in_center=false;
            this -> current_center -> RemoveOnePokemon();
        }
        if (this -> is_in_arena) {
            this -> is_in_arena=false;
            this -> current_arena -> RemoveOnePokemon();
        }
    }
}