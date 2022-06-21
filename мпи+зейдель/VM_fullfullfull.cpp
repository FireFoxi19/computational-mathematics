#include <iostream>
#include <windows.h>
#include <math.h>
#define EPS 0.0001

using namespace std;
const int N = 3;

void print_matrix(double A[N][N+1])	
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j <= N; j++)
			printf("\t%2.2f ", A[i][j]);
		cout <<"\n";
	}
}

double maxmC(double A[N][N+1], double maxC[N+1])
{
	maxC[N]=0;
    for(int i = 0; i < N; i++)
    {	
        for(int j = 0; j < N; j++) 
        {
        	if(A[i][j] < 0)
    			A[i][j] = -A[i][j];
        	maxC[i] += A[i][j]; 
		}
                    
        if(maxC[N] < maxC[i])
            maxC[N] = maxC[i];            
    }
	if(maxC[N] >= 1) {
        printf("\nError");
        return 0;
    }
    printf("||C|| = %4.3f\n", maxC[N]);
    
    return maxC[N];
}

double maxmB(double A[N][N+1])
{
	double maxB = 0;
    for(int i = 0; i < N; i++) 
	{
		if(A[i][N] < 0)
			A[i][N] = -A[i][N];
        if(maxB < A[i][N]) 
            maxB = A[i][N];
    }
    printf("||B|| = %4.3f\n", maxB);
    return maxB;
}

void MPI()
{
	cout << "MPI:\n";
    double temp, maxC[N+1], maxB = 0, B[N], C[N][N], YM[N] = {0, 0, 0}, X[N] = {0,0,0};
  
    double A[N][N+1]={
		{10, -3, 1, -1},
        {2, -10, 3, -4},
        {4, 1, 10, 21}
	}; 
    print_matrix(A);
    
    for(int i = 0, j = 0; i < N; i++, j++)	
    {   
        temp = A[i][j];
        for(int k = 0; k <= N; k++)  
        {
            A[i][k] = A[i][k] / temp;
        }
        A[i][j] = 0;
    }
      
    printf("\nMatrix: \n\n");
    print_matrix(A);
    for(int i = 0; i < N; i++) 
    	for(int j = 0; j < N; j++)
        	C[i][j] = A[i][j];
    for(int i = 0; i < N; i++) 
        B[i] = A[i][N];
    
    
    maxC[N] = maxmC(A, maxC); 
	maxB = maxmB(A); 
    int shagINT = (log((EPS * (1 - maxC[N])) / maxB ) / log(maxC[N]))+1;   
    printf("N = %d\n",shagINT);
    
    int count = 0;
    for(int k = 0; k < shagINT; k++) 
	{   
		count += 1;
        cout<<"\n";
        cout<<"step: "<< count;
        cout<< "\n";
        for(int i = 0; i < N; i++)
        	for(int j = 0; j < N; j++) 
				YM[i] = YM[i] + C[i][j] * X[j];
        		
        for(int i = 0; i < N; i++) 
		{
            X[i] = B[i] - YM[i];
            YM[i] = 0;
            printf("\nX = \t%2.10f", X[i]);
        }
        cout << "\n"; 
    }
	
    cout << "\nAnswer:\n";
    for(int i = 0; i < N; i++) 
        printf("\nX%d = \t%2.3f", i, X[i]);
    cout << "\n";    
         
}

void ZEID()
{
	cout << "ZEIDEL:\n";
	
	double maxC[N+1], maxB = 0, X[N] = {0,0,0};
	double temp, B[N], C[N][N];
	 
	double A[N][N+1]=
	{
		{10, -3, 1, -1},
        {2, -10, 3, -4},
        {4, 1, 10, 21}
	}; 
    print_matrix(A);
    
    for(int i = 0,j = 0 ; i < N; i++, j++)	
    {   
        temp = A[i][j];
        for(int k = 0; k <= N; k++)  
            A[i][k] = A[i][k] / temp;
            
        A[i][j] = 0;
    }
    
    for(int i = 0; i < N; i++) 
//    for(int i = N-1; i >=0; i--)
//    for(int j = N-1; j <=0; j--)
    for(int j = 0; j < N; j++)
        C[i][j] = A[i][j];
        
    for(int i = 0; i < N; i++) 
        B[i] = A[i][N];
    
    printf("\nMatrix: \n");
    print_matrix(A);

	maxC[N] = maxmC(A, maxC); 
	maxB = maxmB(A);
	int shagINT = (log((EPS * (1 - maxC[N])) / maxB ) / log(maxC[N]))+1; 
	printf("N = %d\n",shagINT);
	
	int sum = 0;
    for(int k = 0; k < shagINT; k++)
	for(int i = 0; i < N; i++) 
	{   
        X[i] = B[i];
        for(int j = 0; j < N; j++) 
		{
            if(j == i)  continue; 
            X[i] = X[i] - C[i][j] * X[j];
        }  
        sum++;
        if(sum%3==0)
        {
        for(int j = 0; j <= N; j++)
        	printf("\nX = \t%2.10f", X[j]);
 
        cout << "\n";
		}
    } 
    
    cout << "\nAnswer:\n";
    for(int i = 0; i < N; i++) 
        printf("\nX%d = \t%2.3f", i, X[i]);  
    cout << "\n";   
}

///////////////////////////////////////////////////////////////////////////////


int main()
{
	MPI();
	ZEID();
	
}

