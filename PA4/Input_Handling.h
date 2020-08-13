#ifndef INPUT_HANDLING_H
#define INPUT_HANDLING_H
#include "Model.h"
#include "Point2D.h"
#include <string>
#include <iostream>
using namespace std;

class Invalid_Input {
public:
    Invalid_Input(string in_ptr) : msg_ptr (in_ptr) { }
    const string msg_ptr;
private:
    Invalid_Input();
};


char getCheck_Command() {
    char Command;
    if (!(cin >> Command)) {
        cin.clear();
        throw Invalid_Input("Error: Expecting a Char");
    }
    Command=tolower(Command);
    string commands="mgcsrtvqxban";
    for (int i=0;i<commands.size();i++) {
        if (Command==commands[i]) {
            return Command;
        }
    }
    cin.clear();
    throw Invalid_Input("Error: Invalid Command");
}

//Checks that input is int and valid ID value depending on type
int getCheck_intID(Model& mod, char typeID) {
    int ID;
    if (!(cin >> ID)) {
        cin.clear();
        throw Invalid_Input("Error: Expecting an Integer");
    }
    else {
        switch(typeID) {
            //Pokemon: 'P'
            case 'P':
                if(!(mod.GetPokemonPtr(ID))) {
                    throw Invalid_Input("Error: Pokemon ID is Invalid");
                }
                break;
            //Gym: 'G'
            case 'G':
                if(!(mod.GetPokemonGymPtr(ID))) {
                    throw Invalid_Input("Error: PokemonGym ID is Invalid");
                }
                break;
            //Center: 'C'
            case 'C':
                if(!(mod.GetPokemonCenterPtr(ID))) {
                    throw Invalid_Input("Error: PokemonCenter ID is Invalid");
                }
                break;
            //Arena: 'A'
            case 'A':
                if(!(mod.GetBattleArenaPtr(ID))) {
                    throw Invalid_Input("Error: BattleArena ID is Invalid");
                }
                break;
            //Rival: 'R'
            case 'R':
                if(!(mod.GetRivalPtr(ID))) {
                    throw Invalid_Input("Error: Rival ID is Invalid");
                }
                break;
        }
    }
    return ID;
}

int getCheck_int() {
    int valueInt;
    if (!(cin >> valueInt)) {
        cin.clear();
        throw Invalid_Input("Error: Expecting an Int");
    }
    return valueInt;
}

//Checks if input was a double
double getCheck_double() {
    double valueDouble;
    if (!(cin >> valueDouble)) {
        cin.clear();
        throw Invalid_Input("Error: Expecting a Double");
    }
    return valueDouble;
}

Point2D checkPoint(double xC, double yC) {
    if(xC>20 || yC>20 || xC<0 || yC<0) {
        throw Invalid_Input("Error: Coordinates lie outside of the Display Area");
    }
    Point2D point=Point2D(xC,yC);
    return point;
}

char getCheck_charType() {
    char type;
    if (!(cin >> type)) {
        cin.clear();
        throw Invalid_Input("Error: Expecting a Char");
    }
    type=toupper(type);
    string types="GCPRA";
    for (int i=0;i<types.size();i++) {
        if (type==types[i]) {
            return type;
        }
    }
    cin.clear();
    throw Invalid_Input("Error: Invalid TYPE");
}

int getCheck_intNewID(Model& mod, char TYPE) {
    int NewID;
    if (!(cin >> NewID)) {
        cin.clear();
        throw Invalid_Input("Error: Expecting an Integer");
    }
    else {
        if (NewID > 9 || NewID < 0) {
            throw Invalid_Input("Error: ID values must be between 0 and 9, inclusive");
        }
        switch(TYPE) {
            //Pokemon: 'P'
            case 'P':
                if((mod.GetPokemonPtr(NewID))) {
                    throw Invalid_Input("Error: This Pokemon ID already exists");
                }
                break;
            //Gym: 'G'
            case 'G':
                if((mod.GetPokemonGymPtr(NewID))) {
                    throw Invalid_Input("Error: This PokemonGym ID already exists");
                }
                break;
            //Center: 'C'
            case 'C':
                if((mod.GetPokemonCenterPtr(NewID))) {
                    throw Invalid_Input("Error: This PokemonCenter ID already exists");
                }
                break;
            //Arena: 'A'
            case 'A':
                if((mod.GetBattleArenaPtr(NewID))) {
                    throw Invalid_Input("Error: This BattleArena ID already exists");
                }
                break;
            //Rival: 'R'
            case 'R':
                if((mod.GetRivalPtr(NewID))) {
                    throw Invalid_Input("Error: This Rival ID already exists");
                }
                break;
        }
    }
    return NewID;
}

#endif