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

class stop {
public:
	stop(node* l, vector<client*> c) {
		this->l = l;
		this->c = c;
	}
	node* l;
	vector<client*> c;
};

class shuttle {
public:
	shuttle(int capacity);
	void add_passanger(client* passanger);
	void drop_passanger(client* passanger);
	bool full();
	void visit(node* l);
	void undo();
private:
	static int count;
	const int id;
	vector<client*> passengers;
	const int capacity;
	int free_space;
	stack<stop> trajectory;
};

#endif /* SHUTTLE_H_ */
