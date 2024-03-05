#ifndef CLASS_CAR
#define CLASS_CAR

#include <string>

using namespace std;

class Car
{
    private:
        string model;
        int year;
        string made;
        string color;
    public:
        Car();
        Car(string model, string made, string color, int year);
        ~Car();
        void set_model(string modl);
        void set_year(int);
        void set_made(string mad);
        void set_color(string col);
        void set_all(string, string, string, int);

        string get_model();
        int get_year();
        string get_made();
        string get_color();
        void get_all(string & mod, string &mad, string &col, int &yr);

        void print_information();
        
};

#endif