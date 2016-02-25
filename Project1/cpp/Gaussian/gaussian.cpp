#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <sys/types.h>
#include <sys/time.h>

using namespace std;
ofstream output;

void gaussian(double **a, int numb, double *b);

double sol(double x) {return 1.0-(1-exp(-10))*x-exp(-10*x);}
double f(double x) {return 100*exp(-10*x);}

int main()
{
	double **A;
	double *b,*x,*u;
	int N;

	cout << "Size of the Matrix: ";
	cin >> N;
	
	// Initialization
	A = new double *[N];
	for (int i=0; i<N; i++)
		A[i] = new double [N];
	b = new double [N];
	u = new double [N];
	x = new double [N];
	double h = 1/(N+1.0);

	// Generate the Tridiagnal Matrix A with (-1,2,-1) and b
	for (int i=0; i<N; i++) {
		x[i] = (i+1.0)*h;
		b[i] = h*h*f(x[i]);
		u[i] = sol(x[i]);
		for (int j=0; j<N; j++) {
			if (i == j) {
				A[i][j] = 2.0;
			}
			else if ((i == (j-1)) || (i == (j+1)) ) {
				A[i][j] = -1.0;
			}
			else{ 
				A[i][j]= 0.0;
			}
		}
	}
	
	// Call function for Gaussian elimination
	gaussian(A, N, b);	

	output.open("out.dat");
	output << setiosflags(ios::showpoint | ios::uppercase);
	output << "       x:             u(x):          v(x):  " << endl;
	for (int i=1;i<=N;i++) {
	  output << setw(15) << setprecision(8) << x[i];
		output << setw(15) << setprecision(8) << u[i];
		output << setw(15) << setprecision(8) << b[i] << endl;
	}
	output.close();

	return 0;
} //end of main

void gaussian(double **a, int numb, double *b) {
	int j, maxnumb;
	double maxrow;
	double at;
	struct timeval tStart, tEnd;
	double t;

	gettimeofday (&tStart, 0);
	for (int i=0; i < numb-1; i++) {
		//working on i-th column:
		//pivoting: make sure the a[i+1][i+1] is non-zero
		//picking the largest element in this column is the cheapst way to get that
		maxrow = a[i][i];
		maxnumb = i;
		for ( j=i+1; j< numb; j++) {
			if (a[j][i] > maxrow) {
				maxnumb = j;
				maxrow = a[j][i];
			}
		}
		if  (maxrow != i) {
			// exchange the rows
			for (j=i; j<numb; j++) {
				at = a[i][j];
				a[i][j] = a[maxnumb][j];
				a[maxnumb][j] = at;
			}
			// change the b
			double bt = b[i];
			b[i] = b[maxnumb];
			b[maxnumb] = bt;
		}
		//end of pivoting

		//Make a[i][i] = 1
		b[i] = b[i]/a[i][i];
		for (j=i+1; j<numb; j++) {
			a[i][j] = a[i][j]/a[i][i];
		}
		a[i][i] = 1.0;
		
		//working on every row
		for (int row=i+1; row < numb; row++) {
			//c is the multiplier of the current row, when a[i][i]=1
			double c=a[row][i];  
			a[row][i] = 0.0;
			for (int col=i+1; col < numb; col++) { // get new value for thisrow
				a[row][col] -= c*a[i][col];
			}
			b[row] -= c*b[i];
		}
	}//end of forward substitution

	//backward substitution
	for (int i=numb-2; i >= 0; i--) { 
		for (int j=numb-1; j > i; j--) { 
			b[i] -= b[j]*a[i][j]; 
		}
	}
	gettimeofday( &tEnd, 0);
	t = (tEnd.tv_sec - tStart.tv_sec) + 
	    1.0e-6 * (tEnd.tv_usec - tStart.tv_usec);
	cout << "Gaussian Elimination: t = " << t << endl;	
} // end of function gaussian
