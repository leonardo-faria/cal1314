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
	bool full();
	void visit(node* l);
	void undo();

	int getCapacity() const {
		return capacity;
	}

	int getPassagerNumber() const{
		return passangers.size();
	}

	int getFreeSpace() const {
		return free_space;
	}

	int getId() const {
		return id;
	}

	void print();

private:
	static int count;
	int capacity;
	int id;
	int free_space;
	stack<node*> trajectory;
	vector<client*> passangers;
};

#endif /* SHUTTLE_H_ */
