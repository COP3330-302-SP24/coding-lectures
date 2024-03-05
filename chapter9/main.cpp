#include "Car.h"
#include <iostream>
#include <string>


using namespace std;


int main()
{
    Car my_car;
    Car your_car("Turbo","Infinity","Gray", 2024);

    my_car.set_color("Red");
    my_car.set_made("Nissan");
    my_car.set_model("Centra");
    my_car.set_year(2024);

    cout<<"My Car information: "<<"\n"
          "Model: "<<my_car.get_model()<<"\n"
          "Made: "<<my_car.get_made()<<"\n"
          "Color: "<<my_car.get_color()<<"\n"
          "Year: "<<my_car.get_year()<<endl;

    cout<<"Your Car information: "<<"\n"
          "Model: "<<your_car.get_model()<<"\n"
          "Made: "<<your_car.get_made()<<"\n"
          "Color: "<<your_car.get_color()<<"\n"
          "Year: "<<your_car.get_year()<<endl;

    your_car.set_all("CX5","Mazda","White",2024);     
    cout<<"My Car information: "<<"\n"
          "Model: "<<your_car.get_model()<<"\n"
          "Made: "<<your_car.get_made()<<"\n"
          "Color: "<<your_car.get_color()<<"\n"
          "Year: "<<your_car.get_year()<<endl;

    my_car.print_information();      

}

