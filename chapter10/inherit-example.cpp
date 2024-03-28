#include <string>
#include <iostream>

using namespace std;

class Person{
    private:
        string name;
        int age;
        int id;
    public:   
       Person(){};
       
       void set_age(int ag){age = ag;}
       void set_id(int id_person){id = id_person;}
       void set_name(string nam){name = nam;}

       string get_name(){return name;}
       int get_age(){return age;}
       int get_id(){return id;}
};


class Student:public Person{
    private:
        string classification;
        string major;
        string course;
    public:
        Student(){};
        Student(string class_, string maj, string cour){classification = class_; major = maj; course = cour;};
        void print()
        {
            cout<<"Classification: "<<classification<<"\n"
                <<"Major: "<<major<<"\n"
                <<"course: "<<course<<endl;
        }
};

class Staff:private Person{
    private:
        string role;
        string dept;
        int year_serv;

    public:
        Staff(){};
        Staff(string r, string d, int y){role = r; dept = d; year_serv =y;}
        void SetPerson_info(string nam, int ag, int id)
        {
            set_name(nam);
            set_age(ag);
            set_id(id);
        };

        void print_personInfo()
        {
            cout<<get_age()<<"\n"
                <<get_name()<<"\n"
                <<get_id()<<"\n"<<endl;
            
        }
};


int main()
{
    Student my_student("Junior","Computer Science","Cop3330");

    my_student.set_name("Carlos Theran");
    my_student.set_id(12345);
    my_student.set_age(32);

    cout<<my_student.get_name()<<"\n" <<
          my_student.get_id()<<"\n" <<
          my_student.get_age()<<endl;

   my_student.print();

   Staff my_staff;

   my_staff.SetPerson_info("Andres",27,654);
   my_staff.print_personInfo();

}