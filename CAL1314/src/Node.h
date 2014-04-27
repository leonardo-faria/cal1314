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

	double dist();
	double dist(const node* l);
	bool visitable(double t);
	vector<client*> get_clients();
	void remove_clients()
	{
		while(clients.size())
			clients.pop_back();
	}

	int get_id()
	{
		return id;
	}

	void add_client(client* c);
	void add_edge(edge e);

	bool operator==(node* n) {
		return this->id == n->id;
	}
private:

	int id;
	static int count;
	bool airport;
	vector<client*> clients;
	vector<edge> edges;
};

#endif /* NODE_H_ */
