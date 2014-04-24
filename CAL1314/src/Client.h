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
	client(node* location, int arrival_time);
	static int count;
private:
	node* location;
	const int arrival_time;
	const int id;
};

#endif /* CLIENT_H_ */
