/*
 * Client.cpp
 *
 *  Created on: 24/04/2014
 *      Author: leonardo
 */

#include "Client.h"

int client::count = 0;

client::client(node* l, double t, double o) :
		arrival_time(t), id(count), overhead(o), origin(l), min_pickup_time(
				arrival_time - l->dist() - overhead) {
	arrived = false;
	count++;
}

double client::get_d_time() {
	return arrival_time;
}

double client::get_p_time() {
	return min_pickup_time;
}

node* client::get_origin() {
	return origin;
}

int client::get_id() {
	return id;
}
