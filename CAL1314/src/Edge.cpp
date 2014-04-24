/*
 * Edge.cpp
 *
 *  Created on: 24/04/2014
 *      Author: leonardo
 */

#include "Edge.h"
int edge::count=0;

void edge::start()
{
	count=0;
}

edge::edge(node* s, node* t, int w) :
		source(s), target(t), weight(w) {
	count++;
}
