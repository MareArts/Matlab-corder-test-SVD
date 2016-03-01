#include <iostream>
#include "MySVD.h"
#include "MySVD_emxAPI.h"

using namespace std;

void main()
{
	double X[] = { 1, 3, 5, 7, 2, 4, 6, 8, 1, 2, 3, 4};
	double U[16]; //4x4
	double S[12]; //4x3
	double V[9]; //3x3



	emxArray_real_T *inputX, *outputV, *outputS, *outputU;
	inputX = emxCreateWrapper_real_T(&(X[0]), 4, 3);
	outputU = emxCreateWrapper_real_T(&(U[0]), 4, 4);
	outputS = emxCreateWrapper_real_T(&(S[0]), 4, 3);
	outputV = emxCreateWrapper_real_T(&(V[0]), 3, 3);

	//extern void MySVD(const emxArray_real_T *X, emxArray_real_T *U, emxArray_real_T *S, emxArray_real_T *V);
	MySVD(inputX, outputU, outputS, outputV);

	cout << "U out" << endl;
	for (int i = 0; i< 4; ++i) //row
	{
		for (int j = 0; j< 4; ++j) //col
			cout << U[i + j * 4] << " ";
		cout << endl;
	}
	cout << endl;

	cout << "S out" << endl;
	for (int i = 0; i< 4; ++i) //row
	{
		for (int j = 0; j< 3; ++j) //col
		{
			cout << S[i + j * 4] << " ";

		}
		cout << endl;
	}
	cout << endl;


	cout << "V out" << endl;
	for (int i = 0; i< 3; ++i) //row
	{
		for (int j = 0; j< 3; ++j) //col
		{
			cout << V[i + j * 3] << " ";

		}
		cout << endl;
	}
	cout << endl;
}