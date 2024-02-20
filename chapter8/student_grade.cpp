#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>


using namespace std;

struct Cop3330
{
    string name;
    double test_1;
    double test_2;
    double test_3;
};



void print_menu();
int find_student(string given_name, Cop3330 student_list[], int length);
void compute_student_average(string given_name, Cop3330 student_list[], int length);
void print_student_test_score(string given_name, Cop3330 student_list[], int length);
void compute_all_final_grade( Cop3330 student_list[], int length);

int main()
{
    Cop3330 students_list[4];
  
    ifstream input_file;
    int option, length =4;
    string given_name; 
    input_file.open("../chapter5/student_list.txt");
    char answer = 'Y';

    if(!input_file)
    {
       cout<<"The given path does not extis or incorrect file name. "<<endl;
       exit(1); 
    }

    int i =0;
    while (!input_file.eof())
    {
        input_file >> students_list[i].name >> students_list[i].test_1 >> students_list[i].test_2 >> students_list[i].test_3;
        i++;
    }
    

    while( answer == 'Y')
    {

        print_menu();
        cout<<"Provide the selected option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            /* Find the student in the list */
            cout<<"provide student's name:  ";
            cin >> given_name;
            print_student_test_score(given_name,students_list,length);   
            break;
        case 2:
            /* Compute the final grade of one student */
            cout<<"provide student's name:  ";
            cin >> given_name;
            compute_student_average(given_name,students_list,length);
            break;  
        case 3:
            /* Compute the final grade of all student */
            compute_all_final_grade(students_list ,length);
            break; 
        case 4:
            /* quit */
            cout<<"Exit the program."<<endl;
            exit(1);
            break;         
        
        default:
            break;
        }

     cout<<"\nDo you want to do any other task, do Y or N: ";
     cin >> answer;

    }
    
    return 0;
}

/**************************************** MY FUNCTIONS ****************************************
***********************************************************************************/

void print_menu()
{
    cout<<right<<setfill('#')<<setw(20)<<" Menu "<<setfill('#')<<setw(20)<<"#"<<endl;
    cout<<right<<"1. Find the student in the list."<<endl;
    cout<<right<<"2. Compute the final grade of one student. "<<endl;
    cout<<right<<"3. Compute the final grade of all students. "<<endl;
    cout<<right<<"4. Quit. "<<endl;
}

int find_student(string given_name, Cop3330 student_list[], int length)
{
    bool flag = true;
    int index;
        for(index=0; index< 4; index++)
            {
                if(given_name == student_list[index].name)
                {
                    flag = false;
                    break;
                }

            }   
            if(flag)
            {
                cout<<"The student "<<given_name<<" is not in the list."<<endl; 
                index = -1;
            } 
     return index;       
}

void print_student_test_score(string given_name, Cop3330 student_list[], int length)
{
    int index = find_student(given_name, student_list, length);
    
    if(index != -1){
      cout<<student_list[index].name<<setw(9); 
      cout<<" first test: "<< student_list[index].test_1 <<", second test: "<<student_list[index].test_2<<", third test: "<<student_list[index].test_3; } 
}

void compute_student_average(string given_name, Cop3330 student_list[], int length)
{
    int index = find_student(given_name, student_list, length);
    
    if(index !=-1){
         cout<<student_list[index].name<<setw(9);
        cout<<" Final grade: "<< (student_list[index].test_1 + student_list[index].test_2 + student_list[index].test_3)/3;}
    
}

void compute_all_final_grade( Cop3330 student_list[], int length)
{
            for(int i=0; i<4; i++)
            {
             cout<<student_list[i].name<<"--- Final grade: "<< (student_list[i].test_2 + student_list[i].test_1 + student_list[i].test_3)/3<<endl; 
            }
}