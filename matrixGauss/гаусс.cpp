#include <iostream>
#include <math.h>

using namespace std;
const int N = 3;

void print_matrix(double A[N][N+1])	
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j <= N; j++)
			cout << A[i][j] << "\t";
		cout <<"\n";
	}
}
						
void count_gauss(double A[N][N+1], double B[N])
{
	int count = 0;
	double temp;
	for(int i = 0; i < N; i++)
		for(int j = i + 1; j < N; j++)
		{
			temp =- A[i][i] / A[j][i];
			for(int k = i; k <= N; k++) 
				A[j][k] = A[j][k] * temp + A[i][k];
		count += 1;
		cout <<"Step "<< count;
		
		if(count == 2)
		{
			cout<<"zanulen 1 col\n";
		}
		
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
				printf("\t%1.2f",A[i][j]);
			
				printf("\n\n");
		}	
		}
    int k = N - 1;    
	for(int i = N-1; k >= 0; i--)
	{
		B[k] = A[k][N] / A[k][i];
		for(int j = 0; j < k + 1; j++)
			A[k - j][N] -= A[k - j][i] * B[k];
		k--;
	}
		count += 1;
		cout <<"Step "<< count;
		if(count == 4)
		{
			cout<< "zanulen 2 col\n";
		}
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
				printf("\t%1.2f",A[i][j]);
			
				printf("\n\n");
		}	
}

void count_modified_gauss(double A[N][N+1], double B[N])
{
	int count = 0;
	int tt;
	double temp, temp_matrix[N+1];
	for(int i = 0; i < N; i++)
		for(int j = i + 1; j < N; j++)
		{
			for(int t = 0; t < N; ++t)
			if (fabs(A[i][i]) < fabs(A[t][i]))
				tt = t;
							
			for (int k = 0; k < N+1; ++k)
			{
				temp_matrix[k] = A[i][i];
				A[i][i] = A[tt][i];
				A[tt][i] = temp_matrix[k];
			}
			
			temp =- A[i][i] / A[j][i];
			for(int k = i; k <= N; k++) 
				A[j][k] = A[j][k] * temp + A[i][k];
				
		count += 1;
		cout <<"Step "<< count;
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
				printf("\t%1.2f",A[i][j]);
			
				printf("\n\n");
		}	
		}
    int k = N - 1;    
	for(int i = N-1; k >= 0; i--)
	{
		B[k] = A[k][N] / A[k][i];
		for(int j = 0; j < k + 1; j++)
			A[k - j][N] -= A[k - j][i] * B[k];
		k--;
	}
		for(int i=0; i<3; i++)
		{
			for(int j=0; j<3; j++)
				cout<<"\t"<<A[i][j];
				cout<<"\t"<<B[i];
				printf("\n");
		}
	
}

void gauss()
{
	double B[N];
	double A[N][N + 1] = 
	{	{-2, -2, 1, 0}, 
		{1, -2, 1, 3}, 
		{-3, 1, 1, -1}
	};
	
	print_matrix(A);
	count_gauss(A, B);
	for(int i = 0; i < N; ++i)                              
		cout <<"\n x" << i+1 <<" = " << B[i];   
}

void modified_gauss()
{
	double B[N];
	double A[N][N + 1] = 
	{	{-2, -2, 1, 0}, 
		{1, -2, 1, 3}, 
		{-3, 1, 1, -1}
	};
	
	print_matrix(A);
	count_modified_gauss(A, B);
	for(int i = 0; i < N; ++i)                              
		cout <<"\n x" << i+1 <<" = " << B[i];   
}




int main()
{
	gauss();
//	cout <<"\n";
//	modified_gauss();
	return 0;
}


