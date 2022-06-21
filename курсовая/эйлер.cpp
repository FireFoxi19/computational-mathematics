#include <cmath>
#include <iomanip>
#include <array>
#include <iostream>
#define EPS  pow(10,-4)

using namespace std;

const int n = 2;
const double h = 0.1;

double function(double x, double y[n], int i)
{
	if(i == 0)
		return y[n-1];
	else	
	{
		double function = (exp(x) + y[0] + y[1]) / 3;
		return function;
	}	
}

void Eyler(double x, double y[n], double h)
{
	double Y[n];
	for(int i = 0; i < n; i++)
	{
		Y[i] = y[i];
	}
	for(int i = 0; i < n; i++)
	{
		Y[i] = y[i] + h * function(x, y, i);
	}
	for(int i = 0; i < n; i++)
	{
		y[i] = Y[i];
	}
		
}

int main()
{
	double x = 0;
	double y[n] = {1, 1};
	cout<<"y'' = ((e^x + y + y')/3)\n h = 0.1\n EPS = 10^-4\n";
	cout << "|\tX\t|" << "\tY\t|" <<"\tY'\t|\n";
	cout<<"|_______________|_______________|_______________|\n";
	printf("|%.7f\t|", x);
	printf("%.7f\t|", y[0]);
	printf("%.7f\t|\n", y[1]);
	
	while (x < (1 - h + EPS))
	{
		Eyler(x, y, h);
		x += h;
		printf("|%.7f\t|", x);
		printf("%.7f\t|", y[0]);
		printf("%.7f\t|", y[1]);
		cout<< "\n";
	}
	system("pause");
	return 0;
}
