/*
 * Shuttle.cpp
 *
 *  Created on: 24/04/2014
 *      Author: leonardo
 */

#include "Shuttle.h"

int shuttle::count = 0;

shuttle::shuttle(int c) :
		capacity(c), id(count++) {
	free_space = c;
}

bool shuttle::full() {
	if (free_space == 0)
		return true;
	return false;
}
/*
 void shuttle::visit(node *l)
 {
 vector<client*> c;
 for (int i = 0; i < (int) l->get_clients().size(); ++i) {
 passengers.push_back(l->get_clients()[i]);
 c.push_back(l->get_clients()[i]);
 --free_space;
 l->get_clients()[i]->board();
 }
 l->get_clients().clear();
 stop s(l,c);
 trajectory.push(s);
 }

 void shuttle::undo()
 {
 for (int i = 0; i < (int) trajectory.top().c.size(); ++i) {
 for (int j = 0; j < (int) passengers.size(); ++j) {
 if(passengers[i]==trajectory.top().c[i])
 passengers.erase(passengers.begin()+j);
 }
 trajectory.top().c[i]->drop();
 ++free_space;
 }
 trajectory.pop();
 }
 */

void shuttle::visit(node* vertex) {
	for (int i = 0; i < (int) vertex->get_clients().size(); ++i) {
		passangers.push_back(vertex->get_clients()[i]);
		--free_space;
	}
	vertex->remove_clients();
	trajectory.push(vertex);
}

void shuttle::undo() {
	for (int i = 0; i < passangers.size(); ++i) {
		if (passangers[i]->get_origin() == trajectory.top()) {
			passangers[i]->get_origin()->add_client(passangers[i]);
			++free_space;
			passangers.erase(passangers.begin() + i);
			--i;
		}
	}
	trajectory.pop();
}

void shuttle::print()
{
	while(trajectory.size())
	{

		cout << trajectory.top()->get_id() << "\n";
		trajectory.pop();
	}
}

