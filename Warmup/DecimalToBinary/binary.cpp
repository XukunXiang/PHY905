using namespace std;

#include <iostream>
#include <math.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int i;
	int j = 0;
	int terms[32]; // storage of a0, a1 up to 32 bits
	int terms2[32];
	int number = atoi(argv[1]);
	int number2 = number;
	// initialise the term a0, a1 etc
	for (i=0; i<32; i++){	terms[i] = 0;	}
	for (i=0; i<32; i++){
		terms[i] = number%2;
		number /= 2;
	} 
	// while loop
	i = 0;
	while (number2 > 0){
		terms2[i] = number2%2;
		number2 /= 2;
		j += 1;
		i++; 
	} 

	// write out result
	cout << "Number of bytes used = " << sizeof(number) << endl;
	for (i=0; i<j; i++){	
		cout << "Term nr :" << i << "Value = " << terms2[i];
		cout << endl;
	}
	cout << endl;
	for (i=0; i<32; i++){	
		cout << "Term nr :" << i << "Value = " << terms[i];
		cout << endl;
	}
	return 0;
}
