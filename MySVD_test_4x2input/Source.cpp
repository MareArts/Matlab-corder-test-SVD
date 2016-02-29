#include <iostream>
#include "MySVD.h"
using namespace std;


void main()
{
	double X[]={1, 3, 5, 7, 2, 4, 6, 8};
	double U[16]; //4x4
	double S[8]; //4x2
	double V[4]; //2x2

	//extern void MySVD(const real_T X[8], real_T U[16], real_T S[8], real_T V[4]);
	
	MySVD(X, U, S, V);

	cout << "U out" << endl;
	for(int i=0; i< 4; ++i) //row
	{
		for(int j=0; j< 4; ++j) //col
			cout << U[i+j*4] << " ";
		cout << endl;
	}
	cout << endl;

	cout << "S out" << endl;
	for(int i=0; i< 4; ++i) //row
	{
		for(int j=0; j< 2; ++j) //col
		{
			cout << S[i+j*4] << " ";
			
		}
		cout << endl;
	}
	cout << endl;

	

	cout << "V out" << endl;
	for(int i=0; i< 2; ++i) //row
	{
		for(int j=0; j< 2; ++j) //col
		{
			cout << V[i+j*2] << " ";
			
		}
		cout << endl;
	}
	cout << endl;

}