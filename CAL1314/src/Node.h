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
	node(bool airport);
	const bool is_airport();
	int dist();
	int dist(node* l);
	bool visitable(int t);
	vector<client*> get_clients();
private:
	static int count;
	const int id;
	const bool airport;
	vector<client*> clients;
	vector<edge> edges;
};



#endif /* NODE_H_ */
