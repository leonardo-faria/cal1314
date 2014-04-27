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

node* graph::get_airport()
{
	return &nodes[0];
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
		//TODO arranjar forma de ver se consegue calcular distancias de cada pessoa
		if (!clients[i].boarded())
			if (time - l->dist(clients[i].get_origin())
					< clients[i].get_p_time())
				return false;
	}

	if (shuttles[0].full())
		return true;

	for (int i = 1; i < nodes.size(); ++i) {
		if (nodes[i].visitable(l->dist(&nodes[i]))) {
			shuttles[0].visit(&nodes[i]);

			if (solve(l->dist(&nodes[i]), &nodes[i]))
				return true;

			shuttles[0].undo();

		}

	}

	return false;
}

void graph::read() {
	//podes mudar a ordem disto se quiseres mas as edges e pessoas têm de ser depois dos nodes

	//lê tudo do ficheiro

	//cria os nodes e faz push para o vector nodes (começa pelo aeroporto)

	//acrescenta as edges a cada node

	//cria os clientes e vai colocando cada um no seu node

}
