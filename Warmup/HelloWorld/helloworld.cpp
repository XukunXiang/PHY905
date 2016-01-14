//This is the HelloWorld code for warmup with C++
using namespace std;

#include <iostream> //input and output headfile
#include <math.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
	//covert the text argv[1] to double using atof
	double r = atof(argv[1]);
	double s = sin(r);
	cout << "Hello, World!  sin(" << r << ")=" << s  << '\n';
	// success
	return 0;
}
