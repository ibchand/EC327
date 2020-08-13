// #include <iostream>
#include "GameCommand.h"
#include "Model.h"
#include "Input_Handling.h"
#include <cstdlib>
using namespace std;
int main() {
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2019" << endl;
    cout << "Programming Assignment 4" << endl;
    cout << "Ibrahim Chand" << endl;
    Model model;
    View view;
    char command;
    char TYPE;
    int id1=0;
    int id2=0;
    int numUnits;
    double x=0;
    double y=0;
    Point2D point;

    model.ShowStatus();
    model.Display(view);
    
    while (true) {
        bool InputIsValid=true;
        cout << "Enter Command: ";
        /*Swtich statement checks for which command is entered, then asks for appropriate
        inputs. Brackets are just for organization*/
        try{
            command=getCheck_Command();
            switch(command) {
                case 'm': {
                    
                    id1=getCheck_intID(model,'P');
                    x=getCheck_double();
                    y=getCheck_double();
                    point=checkPoint(x,y);
                    DoMoveCommand(model,id1,point);
                    break;
                }
                case 'g': {
                    id1=getCheck_intID(model,'P');
                    id2=getCheck_intID(model,'G');
                    DoMoveToGymCommand(model,id1,id2);
                    break;
                }
                case 'c': {
                    id1=getCheck_intID(model,'P');
                    id2=getCheck_intID(model,'C');
                    DoMoveToCenterCommand(model,id1,id2);
                    break;
                }
                case 's': {
                    id1=getCheck_intID(model,'P');
                    DoStopCommand(model,id1);
                    break;
                }
                case 'r': {
                    id1=getCheck_intID(model,'P');
                    numUnits=getCheck_int();
                    DoRecoverInCenterCommand(model,id1,numUnits);
                    break;
                }
                case 't': {
                    id1=getCheck_intID(model,'P');
                    numUnits=getCheck_int();
                    DoTrainInGymCommand(model,id1,numUnits);
                    break;
                }
                case 'v': {
                    DoGoCommand(model,view);
                    model.Update();
                    model.ShowStatus();
                    break;
                }
                case 'q': {
                    cout << "Quitting Program" << endl;
                    model.~Model();
                    exit(0);
                    break;
                }
                case 'x': {
                    DoRunCommand(model,view);
                    //Runs 5 times or until Update() function returns true
                    for (int i=0; i<5; i++) {
                        if(model.Update()) {
                            break;
                        }
                    }
                    //cout << "THIS HAPPENS" << endl;
                    model.ShowStatus();
                    break;
                }
                case 'b': {
                    //cin >> id1 >> id2;
                    id1=getCheck_intID(model,'P');
                    id2=getCheck_intID(model,'R');
                    //cout << "Test" << endl;
                    DoBattleCommand(model,id1,id2);
                    break;
                }
                case 'a': {
                    //cin >> id1 >> id2;
                    id1=getCheck_intID(model,'P');
                    id2=getCheck_intID(model,'A');
                    DoMoveToArenaCommand(model,id1,id2);
                    break;
                }
                case 'n': {
                    TYPE=getCheck_charType();
                    id1=getCheck_intNewID(model,TYPE); //Is not checking if ID is already present, checks if it's new
                    x=getCheck_double();
                    y=getCheck_double();
                    point=checkPoint(x,y);
                    model.NewCommand(TYPE, id1, point);
                    model.ShowStatus();
                    break;
                }
                // default: {
                //     cout << "Please Enter Valid Input!" << endl;
                //     InputIsValid=false;
                //     break;
                // }
            }
            if(InputIsValid) {
                model.Display(view);
            }
        }
        catch (Invalid_Input& except) {
            cout << "Invalid Input - " << except.msg_ptr << endl;
            //Actions to be taken if the input is wrong
        }

    }
}