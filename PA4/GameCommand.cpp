#include "GameCommand.h"

void DoMoveCommand(Model& model, int pokemon_id, Point2D p1) {
    //Checks to see if pokemon_id is valid
    if (model.GetPokemonPtr(pokemon_id) == 0) {
        //Checks to see if p1 is valid (Within bounds of the display)
        //if ((p1.x <= 20) && (p1.y <= 20 ) && (p1.x >=0) && (p1.y) >=0)
        cout << "Error: Please enter a valid command!" << endl;
    }
    else {
        model.GetPokemonPtr(pokemon_id) -> StartMoving(p1);
        cout << "Moving " << model.GetPokemonPtr(pokemon_id) -> GetName() << " to " << p1 << endl;
    }
}

void DoMoveToCenterCommand(Model& model, int pokemon_id, int center_id) {
    if ((model.GetPokemonCenterPtr(center_id) == 0) || (model.GetPokemonPtr(pokemon_id) == 0)) {
        cout << "Error: Please enter a valid command!" << endl;
    }
    else {
        model.GetPokemonPtr(pokemon_id) -> StartMovingToCenter(model.GetPokemonCenterPtr(center_id));
        cout << "Moving " << model.GetPokemonPtr(pokemon_id) -> GetName() << " to center " << center_id << endl;
    }
}

void DoMoveToGymCommand(Model& model, int pokemon_id, int gym_id) {
    if ((model.GetPokemonGymPtr(gym_id) == 0) && (model.GetPokemonPtr(pokemon_id) == 0)){
        cout << "Error: Please enter a valid command!" << endl;
    }
    else {
        model.GetPokemonPtr(pokemon_id) -> StartMovingToGym(model.GetPokemonGymPtr(gym_id));
        cout << "Moving " << model.GetPokemonPtr(pokemon_id) -> GetName() << " to gym " << gym_id << endl;
    }
}

void DoStopCommand(Model& model, int pokemon_id) {
    if (model.GetPokemonPtr(pokemon_id) == 0) {
        cout << "Error: Please enter a valid command!" << endl;
    }
    else {
        model.GetPokemonPtr(pokemon_id) -> Stop();
        cout << "Stopping " << model.GetPokemonPtr(pokemon_id) -> GetName() << " " << pokemon_id <<  endl;
    }
}

void DoTrainInGymCommand(Model& model, int pokemon_id, unsigned int training_units) {
    if (model.GetPokemonPtr(pokemon_id) == 0) {
        cout << "Error: Please enter a valid command!" << endl;
    }
    else {
        cout << "Training " << model.GetPokemonPtr(pokemon_id) -> GetName() << endl;
        model.GetPokemonPtr(pokemon_id) -> StartTraining(training_units);
    }
}

void DoRecoverInCenterCommand(Model& model, int pokemon_id, unsigned int stamina_points) {
    if (model.GetPokemonPtr(pokemon_id) == 0) {
        cout << "Error: Please enter a valid command!" << endl;
    }
    else {
        model.GetPokemonPtr(pokemon_id) -> StartRecoveringStamina(stamina_points);
        cout << "Recovering " << model.GetPokemonPtr(pokemon_id) -> GetName() << "'s stamina" << endl;
    }
}

void DoGoCommand(Model& model, View& view) {
    cout << "Advancing one tick." << endl;
}

void DoRunCommand(Model& model, View& view) {
    cout << "Advancing one tick." << endl;
}

//PA4
void DoBattleCommand(Model& model, int pokemon_id, int rival_id) {
    cout << model.GetPokemonPtr(pokemon_id) -> GetName() << " is getting ready to battle " << model.GetRivalPtr(rival_id) -> GetName() << endl;
    model.GetPokemonPtr(pokemon_id) -> ReadyBattle(model.GetRivalPtr(rival_id));
}

void DoMoveToArenaCommand(Model& model, int pokemon_id, int arena_id) {
    if ((model.GetBattleArenaPtr(arena_id) == 0) && (model.GetPokemonPtr(pokemon_id) == 0)){
        cout << "Error: Please enter a valid command!" << endl;
    }
    else {
        model.GetPokemonPtr(pokemon_id) -> StartMovingToArena(model.GetBattleArenaPtr(arena_id));
        cout << "Moving " << model.GetPokemonPtr(pokemon_id) -> GetName() << " to arena " << arena_id << endl;
    }
}