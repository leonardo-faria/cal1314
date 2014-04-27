/*
 * Edge.cpp
 *
 *  Created on: 24/04/2014
 *      Author: leonardo
 */

#include "Edge.h"
int edge::count = 0;

edge::edge(node* s, node* t, double w) :
		source(s), target(t), weight(w) {
	count++;
}

const double edge::get_weight() {
	return weight;
}

const node* edge::get_target()
{
	return target;
}

const node* edge::get_sorce()
{
	return source;
}

