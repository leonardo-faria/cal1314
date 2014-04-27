/*
 * Node.cpp
 *
 *  Created on: 24/04/2014
 *      Author: leonardo
 */

#include "Node.h"

int node::count =0;

node::node(bool a):id(count),airport(a)
{
	count++;
}

double node::dist()
{
	if(airport)
		return 0;
	else
		return edges[0].get_weight();
}

double node::dist(const node* l)
{
	if (l == this)
		return 0.0;
	for (int i = 0; i < (int) edges.size(); ++i) {
		if(edges[i].get_target()->id==l->id)
			return edges[i].get_weight();
	}
	return -1;
}

bool node::visitable(double t)
{
	if (clients.size()==0)
		return false;

	for (int i = 0; i < (int) clients.size(); ++i) {
		if(clients[i]->get_p_time()>t)
			return false;
	}
	return true;
}

vector<client*> node::get_clients()
{
	return clients;
}

void node::add_edge(edge e)
{
	edges.push_back(e);
}

void node::add_client(client* c)
{
	clients.push_back(c);
}
