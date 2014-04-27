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
	node a(true);
	node b(false);
	nodes.push_back(a);
	nodes.push_back(b);
	nodes.push_back(b);
	nodes.push_back(b);
	nodes.push_back(b);
	nodes.push_back(b);

	edge e1(&nodes[0], &nodes[1], 1);
	edge e2(&nodes[0], &nodes[2], 1.25);
	edge e3(&nodes[0], &nodes[3], 1.25);
	edge e4(&nodes[0], &nodes[4], 1.25);
	edge e5(&nodes[0], &nodes[5], 1);
	nodes[0].add_edge(e1);
	nodes[0].add_edge(e2);
	nodes[0].add_edge(e3);
	nodes[0].add_edge(e4);
	nodes[0].add_edge(e5);

	edge e6(&nodes[1], &nodes[0], 1);
	edge e7(&nodes[1], &nodes[2], 0.25);
	edge e8(&nodes[1], &nodes[3], 0.5);
	edge e9(&nodes[1], &nodes[4], 0.75);
	edge e10(&nodes[1], &nodes[5], 1);
	nodes[1].add_edge(e6);
	nodes[1].add_edge(e7);
	nodes[1].add_edge(e8);
	nodes[1].add_edge(e9);
	nodes[1].add_edge(e10);

	edge e11(&nodes[2], &nodes[0], 1.25);
	edge e12(&nodes[2], &nodes[1], 0.25);
	edge e13(&nodes[2], &nodes[3], 0.25);
	edge e14(&nodes[2], &nodes[4], 0.5);
	edge e15(&nodes[2], &nodes[5], 0.75);
	nodes[2].add_edge(e11);
	nodes[2].add_edge(e12);
	nodes[2].add_edge(e13);
	nodes[2].add_edge(e14);
	nodes[2].add_edge(e15);

	edge e16(&nodes[3], &nodes[0], 1.25);
	edge e17(&nodes[3], &nodes[1], 0.5);
	edge e18(&nodes[3], &nodes[2], 0.25);
	edge e19(&nodes[3], &nodes[4], 0.25);
	edge e20(&nodes[3], &nodes[5], 0.5);
	nodes[3].add_edge(e16);
	nodes[3].add_edge(e17);
	nodes[3].add_edge(e18);
	nodes[3].add_edge(e19);
	nodes[3].add_edge(e20);

	edge e21(&nodes[4], &nodes[0], 1.25);
	edge e22(&nodes[4], &nodes[1], 0.75);
	edge e23(&nodes[4], &nodes[2], 0.5);
	edge e24(&nodes[4], &nodes[3], 0.25);
	edge e25(&nodes[4], &nodes[5], 0.25);
	nodes[4].add_edge(e21);
	nodes[4].add_edge(e22);
	nodes[4].add_edge(e23);
	nodes[4].add_edge(e24);
	nodes[4].add_edge(e25);

	edge e26(&nodes[5], &nodes[0], 1.25);
	edge e27(&nodes[5], &nodes[1], 1);
	edge e28(&nodes[5], &nodes[2], 0.75);
	edge e29(&nodes[5], &nodes[3], 0.5);
	edge e30(&nodes[5], &nodes[4], 0.25);
	nodes[5].add_edge(e26);
	nodes[5].add_edge(e27);
	nodes[5].add_edge(e28);
	nodes[5].add_edge(e29);
	nodes[5].add_edge(e30);

	client c1(&nodes[1], 10, 1);
	client c2(&nodes[2], 10, 1);
	client c3(&nodes[3], 10.5, 1);
	client c4(&nodes[4], 11, 1);
	client c5(&nodes[5], 11, 1);
	clients.push_back(c1);
	nodes[1].add_client(&c1);
	clients.push_back(c2);
	nodes[2].add_client(&c2);
	clients.push_back(c3);
	nodes[3].add_client(&c3);
	clients.push_back(c4);
	nodes[4].add_client(&c4);
	clients.push_back(c5);
	nodes[5].add_client(&c5);

	shuttle s(5);
	shuttles.push_back(s);
}

node* graph::get_airport() {
	return &nodes[0];
}

bool graph::solved() {
	return false;
}

const int graph::get_last_client_time() {
	cout << clients.size();
	int t = clients[clients.size() - 1].get_d_time();
	for (int i = 0; i < (int) clients.size() - 1; ++i) {
		if (t > clients[i].get_d_time())
			t = clients[i].get_d_time();
	}
	return t;
}

bool graph::solve(int time, node* l) {

	for (int i = 0; i < (int) clients.size(); ++i) {
		if (!clients[i].boarded())
			if (time - l->dist(clients[i].get_origin()) < clients[i].get_p_time())
				return false;
	}

	if (shuttles[0].full())
		return true;

	for (int i = 1; i < (int) nodes.size(); ++i) {
		if (nodes[i].visitable(time-l->dist(&nodes[i]))) {

			shuttles[0].visit(&nodes[i]);

			cout << "\nespaço livre " << shuttles[0].free_space << "\ntempo: " << time << "\n";
			if (solve(time-l->dist(&nodes[i]), &nodes[i]))
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
