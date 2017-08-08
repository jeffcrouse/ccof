#include <iostream>
#include <math.h>
#include <time.h>
#include <unistd.h>
using namespace std;


#define PI 3.14159265
#define MAX_X 70
#define MAX_Y 900000


int main() {
	// Outer Y loop just goes from 0 to MAX_Y
	for(int y=0; y<MAX_Y; y++) {
		
		float fx = 0.5 + sin(y*PI/180.0) / 2;
		
		// The inner loop goes from 0 to MAX_X
		// and it does it MAX_Y times
		for(int x=0; x<MAX_X; x++) {
		
		    if(round(fx * MAX_X) == x) {
				cout << 1;
			} else {
				cout << 0;
			}
		}
		cout << endl;
        usleep(0.015 * 1000000); 
	}
}
