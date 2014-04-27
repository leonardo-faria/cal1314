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
	client(node* location, int arrival_time,int o);
	node* get_location();
	int get_d_time();
	int get_p_time();
	const node* get_origin();
	void set_location(node* l);
	bool boarded();
	void drop();
	void board();
private:

	const int arrival_time;
	const int id;
	const int overhead;
	const node* origin;
	const int min_pickup_time;
	bool aboard;
	bool arrived;
	static int count;
};

#endif /* CLIENT_H_ */
