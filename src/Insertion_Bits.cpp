//============================================================================
// Name        : to_StringTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
using namespace std;


int insertionBit(int N,int M, int i, int j)
{

	cout << "base NUM: "<< std::bitset<15>(N) << endl;
	cout << "num to insert: " << std::bitset<15>(M) << endl;

	//check if bit range is fit with M .

	int bitRange = (j - i) + 1;
	int maxBit = std::pow(bitRange, 2);

	cout << "maxbit: " <<  maxBit << endl;

	//cout << std::bitset<16>(N);
	//cout << x << endl;
	//cout << std::bitset<16>(M);

	if( M > maxBit )
	{
		cout << "not enough buffer to keep bits" << endl;
		return 0;
	}


	int allOnes = ~0;
	//cout << std::bitset<10>(allOnes);

	//left side
	int leftSide = ( allOnes << (j+1) ) & ( N);
	cout << "leftSide: " << std::bitset<15>(leftSide) << endl;

	int rightSide = ( (1 << (i + 1)) -  1) & N;
	cout << "right Side: " << std::bitset<15>(rightSide) << endl;

	int clearNum = (leftSide | rightSide);
	cout << "clearNUM: " << std::bitset<15>(clearNum) << endl;

	//number to insert.
	int numberToinsert = (M << i);
	cout << "numberToinsert: " << std::bitset<15>(numberToinsert) << endl;

	int result = (clearNum | numberToinsert);

	return result;

}



int main()
{

	//insertionBit(10000000000, 10011, 2, 6);
	cout << "result: " << bitset<15>( insertionBit(1024, 19, 2, 6) ) << endl;



	return 0;
}
