/*
 * Shuttle.cpp
 *
 *  Created on: 24/04/2014
 *      Author: leonardo
 */

#include "Shuttle.h"

bool shuttle::full()
{
	if(free_space==0)
		return true;
	return false;
}

void shuttle::visit(node *l)
{
	vector<client*> c;
	for (int i = 0; i < (int) l->get_clients().size(); ++i) {
		passengers.push_back(l->get_clients()[i]);
		c.push_back(l->get_clients()[i]);
		--free_space;
	}
	stop s(l,c);
	trajectory.push(s);
	for (int i = 0; i < (int) passengers.size(); ++i) {
		passengers[i]->set_location(l);
	}
	location=l;
}

void shuttle::undo()
{
	for (int i = 0; i < (int) trajectory.top().c.size(); ++i) {
		trajectory.top().c[i]->set_location(trajectory.top().l);
		for (int j = 0; j < (int) passengers.size(); ++j) {
			if(passengers[i]==trajectory.top().c[i])
				passengers.erase(passengers.begin()+j);
		}
		++free_space;
	}
	trajectory.pop();
	location=trajectory.top().l;
}


