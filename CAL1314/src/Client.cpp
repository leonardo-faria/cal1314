/*
 * Client.cpp
 *
 *  Created on: 24/04/2014
 *      Author: leonardo
 */

#include "Client.h"

int client::count=0;

client::client(node* l,int t):arrival_time(t),id(count++)
{
	this->location=l;
}
