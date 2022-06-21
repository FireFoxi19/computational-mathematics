#include <iostream>
#include <windows.h>
#include <math.h>



using namespace std;

const int N = 4;

double lagr(double X, double x[N], double y[N]) {
	
    double P = 0, q;
    for (int j = 0; j < N; j++)
  
	{
        q = 1;
       
        for (int i = 0; i < N; i++)
            if (i != j)
				q *= ((X - x[i])/(x[j] - x[i]));
        P += y[j] * q;
    }
    return P;
}

void Lagrange()
{
	double x[N], y[N];
	double  P, X;
    cout << "Lagrange\nInput X: ";
    cin >> X;
    cout<< "Y = sqrt(X)\n";
    cout<<"X  |  "<< "Y\n";
    l
    for (int i = 0; i < N; i++) //>nan
	{
		
        x[i] = i+1;
        y[i] = sqrt(x[i]); 
        cout << x[i] <<"  |  " << y[i] << "\n";
    }
    P = lagr(X, x, y);
    cout << "\nOtvet:";
    printf("\nP = %.5f\n", P);
    
}


int main()
{
	Lagrange();
}

