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
    bool flag = true;
    input_file.open("student_list.txt");
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

        cout<<right<<setfill('#')<<setw(20)<<" Menu "<<setfill('#')<<setw(20)<<"#"<<endl;
        cout<<right<<"1. Find the student in the list."<<endl;
        cout<<right<<"2. Compute the final grade of one student. "<<endl;
        cout<<right<<"3. Compute the final grade of all students. "<<endl;
        cout<<right<<"4. Quit. "<<endl;

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
                    flag = false;
                    break;
                }

            }   
            if(flag)
            {
                cout<<"The student "<<given_name<<" is not in the list."<<endl; 
            }  
    
            break;
        case 2:
            /* Compute the final grade of one student */
            cout<<"provide student's name:  ";
            cin >> given_name;
            for(int index=0; index< 4; index++)
            {
                if(given_name == students_name[index])
                {
                    cout<<"Final grade: "<< (first_test[index] + second_test[index] + third_test[index])/3;
                    flag = false;
                    break;
                }

            }   
            if(flag)
            {
                cout<<"The student "<<given_name<<" is not in the list."<<endl; 
            }  
            break;  
        case 3:
            /* Compute the final grade of all student */
            for(int i=0; i<4; i++)
            {
            cout<<students_name[i]<<"--- Final grade: "<< (first_test[i] + second_test[i] + third_test[i])/3<<endl; 
            }
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