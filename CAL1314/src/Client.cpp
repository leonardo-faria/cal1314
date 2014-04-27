/*
 * Client.cpp
 *
 *  Created on: 24/04/2014
 *      Author: leonardo
 */

#include "Client.h"

int client::count = 0;

client::client(node* l, int t, int o) :
		arrival_time(t), id(count++), overhead(o), origin(l), min_pickup_time(
				arrival_time - l->dist() - overhead) {
	arrived = false;
	aboard=false;
}

int client::get_d_time() {
	return arrival_time;
}

int client::get_p_time() {
	return min_pickup_time;
}

const node* client::get_origin() {
	return origin;
}

void client::drop()
{
	aboard=false;
}
void client::board()
{
	aboard=true;
}

bool client::boarded()
{
	return aboard;
}
