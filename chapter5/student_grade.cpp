#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>


using namespace std;

int main()
{
    string students_name[4];
    double first_test[4], second_test[4], third_test[4], final_grade[4];
    ifstream input_file;
    int option;
    string given_name; 
    input_file.open("student_list.txt");

    if(!input_file)
    {
       cout<<"The given path does not extis or incorrect file name. "<<endl;
       exit(1); 
    }

    int i =0;
    while (!input_file.eof())
    {
        input_file >> students_name[i] >> first_test[i] >> second_test[i] >> third_test[i];
    }
    
    cout<<right<<setfill('#')<<setw(20)<<" Menu "<<setfill('#')<<setw(20)<<"#"<<endl;
    cout<<right<<"1. Find the student in the list."<<endl;
    cout<<right<<"2. Compute the final grade of one student. "<<endl;
    cout<<right<<"3. Compute the final grade of all student. "<<endl;
    cout<<right<<"4. quit. "<<endl;

    cout<<"Provide the selected option: ";
    cin >> option;

    switch (option)
    {
    case 1:
        /* Find the student in the list */
        cout<<"provide student's name:  ";
        cin >> given_name;
        for(int index=0; index< 4; index++)
        {
            if(given_name == students_name[index])
            {
                cout<<"first test: "<< first_test[index] <<", second test: "<<second_test[index]<<", third test: "<<third_test[index];
                break;
            }
        }       
        break;
    case 2:
        /* Compute the final grade of one student */
        break;  
    case 3:
        /* Compute the final grade of all student */
        break; 
    case 4:
        /* quit */
        break;         
    
    default:
        break;
    }

    return 0;
}