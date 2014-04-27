/*
 * Node.cpp
 *
 *  Created on: 24/04/2014
 *      Author: leonardo
 */

#include "Node.h"

int node::count =0;

node::node(bool a):id(count++),airport(a)
{
	count++;
}

int node::dist()
{
	if(airport)
		return 0;
	else
		return edges[0].get_weight();
}

int node::dist(node* l)
{
	for (int i = 0; i < edges.size(); ++i) {
		if(edges[i].get_target()==l)
			return edges[i].get_weight();
	}
	return -1;
}

bool node::visitable(int t)
{
	for (int i = 0; i < clients.size(); ++i) {
		if(clients[i]->get_p_time()>t)
			return false;
	}
	return true;
}

vector<client*> node::get_clients()
{
	return clients;
}
