/*
 * Graph.cpp
 *
 *  Created on: 24/04/2014
 *      Author: leonardo
 */

#include "Graph.h"

graph::graph(int m, string i, string o) :
		mode(m), input(i), output(o) {
	arrived = 0;
}

bool graph::solved() {
	return false;
}

const int graph::get_last_client_time() {
	int t = clients[clients.size() - 1].get_d_time();
	for (int i = 0; i < clients.size() - 1; ++i) {
		if (t > clients[i].get_d_time())
			t = clients[i].get_d_time();
	}
	return t;
}

bool graph::solve(int time, node* l) {
	for (int i = 0; i < clients.size(); ++i) {
		if (time - l->dist(clients[i].get_location()) < clients[i].get_p_time())
			return false;
	}

	if (shuttles[0].full())
		return true;

	for (int i = 1; i < nodes.size(); ++i) {
		if (nodes[i].visitable(l->dist(&nodes[i]))) {
			shuttles[0].visit(&nodes[i]);

			if(solve(l->dist(&nodes[i]),&nodes[i]))
				return true;

			shuttles[0].undo();

		}

	}

	return false;
}

