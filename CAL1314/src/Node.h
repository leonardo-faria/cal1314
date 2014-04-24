/*
 * Node.h
 *
 *  Created on: 24/04/2014
 *      Author: leonardo
 */

#ifndef NODE_H_
#define NODE_H_

#include "includer.h"
using namespace std;

class node {
public:
	node();
private:
	static int count;
	const int id;
	vector<client*> clients;
	vector<edge> edges;
};



#endif /* NODE_H_ */
