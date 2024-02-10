#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>


using namespace std;

const int NUM_PERCENTAGE;


void print_menu();
int find_student(string given_name, string student_list[], int length);
void compute_student_average(string given_name, string student_list[], int length, double first_test[], double second_test[], double third_test[]);
void print_student_test_score(string given_name, string student_list[], int length, double first_test[], double second_test[], double third_test[]);
void compute_all_final_grade(string student_list[], int length, double first_test[], double second_test[], double third_test[]);

int main()
{
    string students_name[4];
    double first_test[4], second_test[4], third_test[4], final_grade[4];
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
        input_file >> students_name[i] >> first_test[i] >> second_test[i] >> third_test[i];
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
            print_student_test_score(given_name,students_name,length, first_test, second_test,  third_test);   
            break;
        case 2:
            /* Compute the final grade of one student */
            cout<<"provide student's name:  ";
            cin >> given_name;
            compute_student_average(given_name,students_name,length, first_test, second_test, third_test);
            break;  
        case 3:
            /* Compute the final grade of all student */
            compute_all_final_grade(students_name ,length, first_test, second_test,  third_test);
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

int find_student(string given_name, string student_list[], int length)
{
    bool flag = true;
    int index;
        for(index=0; index< 4; index++)
            {
                if(given_name == student_list[index])
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

void print_student_test_score(string given_name, string student_list[], int length, double first_test[], double second_test[], double third_test[])
{
    int index = find_student(given_name, student_list, length);
    
    if(index != -1){
      cout<<student_list[index]<<setw(9); 
      cout<<" first test: "<< first_test[index] <<", second test: "<<second_test[index]<<", third test: "<<third_test[index]; } 
}

void compute_student_average(string given_name, string student_list[], int length, double first_test[], double second_test[], double third_test[])
{
    int index = find_student(given_name, student_list, length);
    
    if(index !=-1){
         cout<<student_list[index]<<setw(9);
        cout<<" Final grade: "<< (first_test[index] + second_test[index] + third_test[index])/3;}
    
}

void compute_all_final_grade( string student_list[], int length, double first_test[], double second_test[], double third_test[])
{
            for(int i=0; i<4; i++)
            {
             cout<<student_list[i]<<"--- Final grade: "<< (first_test[i] + second_test[i] + third_test[i])/3<<endl; 
            }
}