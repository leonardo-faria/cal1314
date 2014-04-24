/*
 * Shuttle.h
 *
 *  Created on: 24/04/2014
 *      Author: leonardo
 */

#ifndef SHUTTLE_H_
#define SHUTTLE_H_

#include <vector>
#include "Client.h"
using namespace std;

class shuttle {
public:
	shuttle(int capacity);
	int add_passanger(client* passanger);
	int dropoff();
private:
	static int count;
	const int id;
	vector<client*> passengers;
	node* location;
	const int capacity;
	int free_space;
};



#endif /* SHUTTLE_H_ */
