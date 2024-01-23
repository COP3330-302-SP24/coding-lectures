#include <cmath>
#include <iostream>

using namespace std;


int main()
{
    double a, b, c;
    double x_1, x_2;

    cout<<"Provide the coefficients of your quadratic equation: ";
    cin >> a >> b >> c;

    double desc = pow(b,2)-4*a*c;

    if(desc < 0)
    {
        cout<<"There is none real solution."<<endl;
    }
    else
    {
        x_1 = (-b + sqrt(desc))/(2*a);
        x_2 = (-b - sqrt(desc))/(2*a);
        cout<<"The two real solution are: "<< x_1 <<" and  "<<x_2<<endl;
    }

  return 0;
}

