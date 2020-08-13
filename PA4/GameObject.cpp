#include "GameObject.h"

GameObject::GameObject(char in_code)
{
    this -> display_code=in_code;
    this -> id_num=1;
    this -> state='0';
    cout << "GameObject constructed" << endl;
}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code)
{
    this -> display_code=in_code;
    this -> id_num=in_id;
    this -> location=in_loc;
    this -> state='0';
    cout << "GameObject constructed" << endl;
}

Point2D GameObject::GetLocation()
{
    return this -> location;
}

int GameObject::GetId()
{
    return this -> id_num;
}

char GameObject::GetState()
{
    return this -> state;
}

void GameObject::ShowStatus()
{
    cout << this -> display_code << this -> id_num << " at " << this -> location << endl;
}

GameObject::~GameObject(){
    cout << "GameObject destructed." << endl;
}

void GameObject::DrawSelf(char* ptr) {
    *ptr= this -> display_code;
    *(ptr+1)= '0' + this -> id_num;
}

bool GameObject::Update() {
    return false;
}

bool GameObject::ShouldBeVisible() {
    return true;
}