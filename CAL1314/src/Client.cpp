/*
 * Client.cpp
 *
 *  Created on: 24/04/2014
 *      Author: leonardo
 */

#include "Client.h"

int client::count=0;

client::client(node* l,int t,int o):arrival_time(t),id(count++),overhead(o),min_pickup_time(arrival_time-l->dist()-overhead)
{
	this->location=l;
	arrived=false;
}

node* client::get_location()
{
	return location;
}

int client::get_d_time()
{
	return arrival_time;
}

int client::get_p_time()
{
	return min_pickup_time;
}

void client::set_location(node* l)
{
	location=l;
}
