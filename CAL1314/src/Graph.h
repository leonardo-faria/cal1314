/*
 * Graph.h
 *
 *  Created on: 24/04/2014
 *      Author: leonardo
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include "includer.h"

class client;
class edge;
class node;
class shuttle;
using namespace std;

class graph {
public:
	graph(int mode, string filename);
	int move(shuttle* s, node* target);
	bool solved();
private:
	int mode;
	vector<client> clients;
	vector<node> nodes;
	vector<shuttle> shuttles;
};

#endif /* GRAPH_H_ */
