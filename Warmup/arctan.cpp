//Program to compute first derivative of arctan(x) at $x = \sqrt(2)$ with two formulae
using namespace std;

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <stdio.h>

ofstream ofile;

// function to get derivative
void derivative(double x,int num,double initial_step,float *h_single,float *f2_single,double *h_double,double *f2_double)
{
	int loop;
	double h = initial_step;
	for (loop=0; loop < num; loop++) {
		h_single[loop] = h;
		f2_single[loop] = (atan(x+h) - atan(x-h))/(2*h);
		h_double[loop] = h;
		f2_double[loop] = (atan(x+h) - atan(x-h))/(2*h);
		h = h*0.5;
	}
}

// function for output
void output(double x,int num,float *h_single,float *f2_single,double *h_double,double *f2_double)
{
	int i;
	double epsilon = 1/(1+x*x);
	ofile << setiosflags(ios::showpoint | ios::uppercase);
	//for relative errors
	float err_single;
	double err_double;
	for (i=0; i<num; i++){
		err_single = log10(fabs((f2_single[i]-epsilon)/epsilon));
		ofile << setw(15) << setprecision(8) << log10(h_single[i]);
		ofile << setw(15) << setprecision(8) << err_single;
		err_double = log10(fabs((f2_double[i]-epsilon)/epsilon));
		ofile << setw(15) << setprecision(8) << log10(h_double[i]);
		ofile << setw(15) << setprecision(8) << err_double << endl;
	}
	
}


// ********** main program ***********
int main()
{
	int num; //number of steps 
	double x;
	const double initial_step = 0.1; // h_initial=0.1
	float *h_single, *f2_single;
	double *h_double, *f2_double;

	//Get the initial information
	cout << "x = " ;
	cin >> x;
	cout << "number of steps: ";
	cin >> num;

	//get the vector of h and corresponding derivatives
	h_single = new float[num];
	f2_single = new float[num];
	h_double = new double[num];
	f2_double = new double[num];
	
	//call the function to get the derivative
	derivative(x,num,initial_step,h_single,f2_single,h_double,f2_double);
	
	//output
	ofile.open("out-threepoint.dat");
	
	output(x,num,h_single,f2_single,h_double,f2_double);

	ofile.close();

	delete [] h_single;
	delete [] h_double;
	delete [] f2_single;
	delete [] f2_double;

	return 0;
} //end of main program
	
