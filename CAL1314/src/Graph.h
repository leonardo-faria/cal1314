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
	graph(int mode, string input, string output);
	int move(shuttle* s, node* target);
	bool solved();
	const int get_last_client_time();
	bool solve(int t, node* l);
private:
	int arrived;
	const int mode;
	const string input;
	const string output;
	vector<client> clients;
	vector<node> nodes;
	vector<shuttle> shuttles;
};

#endif /* GRAPH_H_ */
