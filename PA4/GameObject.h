#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include "Point2D.h"
using namespace std;

class GameObject {
public: 
    GameObject(char in_code);
    GameObject(Point2D in_loc, int in_id, char in_code);
    Point2D GetLocation();
    int GetId();
    char GetState();
    virtual ~GameObject(); //Defined in CP4
    virtual void ShowStatus();
    virtual bool Update();
    virtual bool ShouldBeVisible();
    void DrawSelf(char* ptr);

protected:
    Point2D location;
    int id_num;
    char display_code;
    char state;
};

#endif