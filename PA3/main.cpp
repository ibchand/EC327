// #include <iostream>
#include "GameCommand.h"
#include "Model.h"
#include <cstdlib>
using namespace std;
int main() {
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2019" << endl;
    cout << "Programming Assignment 3" << endl;
    cout << "Ibrahim Chand" << endl;
    Model model;
    View view;
    char command;
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
        cin >> command;
        command = tolower(command);
        /*Swtich statement checks for which command is entered, then asks for appropriate
        inputs. Brackets are just for organization*/
        switch(command) {
            case 'm': {
                cin >> id1 >> x >> y;
                point=Point2D(x,y);
                DoMoveCommand(model,id1,point);
                break;
            }
            case 'g': {
                cin >> id1 >> id2;
                DoMoveToGymCommand(model,id1,id2);
                break;
            }
            case 'c': {
                cin >> id1 >> id2;
                DoMoveToCenterCommand(model,id1,id2);
                break;
            }
            case 's': {
                cin >> id1;
                DoStopCommand(model,id1);
                break;
            }
            case 'r': {
                cin >> id1 >> numUnits;
                DoRecoverInCenterCommand(model,id1,numUnits);
                break;
            }
            case 't': {
                cin >> id1 >> numUnits;
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
                cout << "THIS HAPPENS" << endl;
                model.ShowStatus();
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
}