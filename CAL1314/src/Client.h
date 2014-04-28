/*
 * Client.h
 *
 *  Created on: 24/04/2014
 *      Author: leonardo
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "includer.h"

class node;
using namespace std;

class client {
public:
	client(node* location, double arrival_time, double o);
	double get_d_time();
	double get_p_time();
	int get_id();
	 node* get_origin();
	void set_location(node* l);
	void print() {
		cout << " arrival_time=" << arrival_time
				<< "id=" << id
				<< " min_pickup_time=" << min_pickup_time;
	}
	bool operator==(client* c) {
		return this->id == c->id;
	}

private:

	double arrival_time;
	int id;
	double overhead;
	 node* origin;
	double min_pickup_time;
	bool arrived;
	static int count;
};

#endif /* CLIENT_H_ */
