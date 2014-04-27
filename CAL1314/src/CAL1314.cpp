//============================================================================
// Name        : CAL1314.cpp
// Author      : 
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <iostream>
#include "includer.h"
using namespace std;

int main() {
	graph g1(1,"input1.txt","output1.txt");

	//g1.read();
	//Mode 1

	if(g1.solve(g1.get_last_client_time(),g1.get_airport()))
	{
		cout << "Dá\n";
		g1.print();
	}
	else
		cout << "Não dá\n";
}

