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
class edge;
class node {
public:
	node(bool airport);
	const bool is_airport();
	int dist();
	int dist(const node* l);
	bool visitable(int t);
	vector<client*> get_clients();

	void add_client(client* c);
	void add_edge(edge e);

	bool operator==(node* n) {
		return this->id==n->id;
	}
	 int id;
private:
	static int count;
	 bool airport;
	vector<client*> clients;
	vector<edge> edges;
};

#endif /* NODE_H_ */
