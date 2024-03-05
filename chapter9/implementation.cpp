#include "Car.h"
#include <iostream>

/**************CONSTRUCTORS****************/
Car::Car(){}

Car::Car(string model, string made, string color, int year)
{
  this->model = model;
  this->color = color;
  this->made = made;
  this->year = year;
}

Car::~Car(){}

/*Implementing the setter or muteators*/

void Car::set_model(string modl)
{
   model = modl;
}

void Car::set_year(int year)
{
    this->year = year;
}

void Car::set_made(string mad)
{
    made = mad;
}
void Car::set_color(string col)
{
    color = col;
}

void Car::set_all(string mod, string mad, string col, int yr){
    year = yr;
    model = mod;
    made = mad;
    color = col;
}

/*Implementing the getters or accessor*/

string Car::get_model()
{
    return model;
}

int Car::get_year()
{
    return year;
}

string Car::get_made()
{
    return made;
}

string Car::get_color()
{
    return color;
}

void Car::get_all(string & mod, string &mad, string &col, int &yr)
{
   mod = model;
   mad = made;
   col = color;
   yr = year;
}

void Car::print_information()
{
    cout<<"My Car information: "<<"\n"
          "Model: "<<model<<"\n"
          "Made: "<<made<<"\n"
          "Color: "<<color<<"\n"
          "Year: "<<year<<endl;
}


