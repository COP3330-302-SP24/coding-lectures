#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main()
{

    ifstream input_file;
    ofstream output_file;
    string text;
    string encoding_text=" ";
    int key = 10, encoding_letter;


    input_file.open("msn.txt");

    if(!input_file)
    {
       cout<<"The given file does not exits or incorrect path."<<endl;
       exit(1);
    }

    getline(input_file,text); //reading the file

    for(int i=0;i<text.length();i++)
    {
        if(isupper(text[i]))
        {
            encoding_letter = (int(text[i])+key-65)%25+65; //uppercase
        }
        else if (islower(text[i]))
        {
            encoding_letter = (int(text[i])+key-97)%25+97;  //lowecase
        }
        else if(int(text[i])==32)
        {
            encoding_letter = int(text[i]);
        }

        string encode_letter(1,char(encoding_letter));
        encoding_text.append(encode_letter);
        
    }

    input_file.close();
    output_file.open("encoding_msn.txt");

    //cout<<"Original msn: "<<text<<endl;
    output_file<<encoding_text<<endl;
    output_file.close();

    return 0;
}