#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

// function to perform one step of the explicit method
double* explstep(double xn[2], double dt, double zw){ 
	zw = xn[0];	
	xn[0] += dt*xn[1];
	xn[1] -= dt*zw;

	return xn;
}

// function to perform one step in the implicit method
double* implstep(double xn[2], double dt, double zw){
	zw = xn[0];
	xn[0] = (xn[0]-dt*xn[1])/(1+dt*dt);
	xn[1] = (xn[1]+dt*zw)/(1+dt*dt);
	
	return xn;
}



int main(){
	
	double dt = M_PI/100;

	double x[2];
	x[0] = 1;
	x[1] = 0;

	double zw;	
	double* xn = x; // pointer to x

	ofstream explout("explicit.txt");
	explout << 0 << "\t" << xn[0] << endl;

	// generating output file for explicit method	

	for(int i = 1; i*dt <= 20*M_PI; i++){
		
		xn = explstep(xn,dt,zw);
		explout << i*dt << "\t" << xn[0] << endl;
		}
	explout.close();

	// generating output file for implicit method

	x[0] = 1;
	x[1] = 0;

	ofstream implout("implicit.txt");
	implout << 0 << "\t" << xn[0] << endl;

	for(int i = 1; i*dt <= 20*M_PI; i++){
		
		xn = implstep(xn,dt,zw);
		implout << i*dt << "\t" << xn[0] << endl;
		}
	implout.close();
}




	
