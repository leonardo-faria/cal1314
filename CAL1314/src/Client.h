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
	int get_d_time();
	int get_p_time();
	const node* get_origin();
	void set_location(node* l);
	bool boarded();
	void drop();
	void board();
	bool operator==(client* c) {
		return this->id==c->id;
	}

private:

	 double arrival_time;
	 int id;
	 double overhead;
	const node* origin;
	 int min_pickup_time;
	bool aboard;
	bool arrived;
	static int count;
};

#endif /* CLIENT_H_ */
