#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;
const int N = 4;

void etk(double X, double x[N], double y[N])
{ 
  	for(int j = 1; j < N; j++)
	{
		for (int k = 0; k < N - j; ++k)
		{
			int l = k + j;
			y[k] = ((y[k]*(X - x[l]) - y[k+1] * (X - x[k])) / (x[k] - x[l]));
			printf("\ny = %.4f ", y[k]);
		}
		cout <<  "\n"; 
	}
}

void Etken()
{
	double x[N], y[N];
	double  P, X;
    cout << "ETKEN\nInput X: ";
    cin >> X;
    cout<< "X  |  Y\n";
    
    for (int i = 0; i < N; i++)

	{
        x[i] = i+1;
        y[i] = sqrt(x[i]);
        cout << x[i] << "  |  " << y[i] << "\n";
    }
	
	etk(X, x, y);
}

int main()
{
	Etken();
}

