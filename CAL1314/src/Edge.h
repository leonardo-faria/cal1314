/*
 * Edge.h
 *
 *  Created on: 24/04/2014
 *      Author: leonardo
 */

#ifndef EDGE_H_
#define EDGE_H_

#include "includer.h"


class edge {
public:
	edge(node* source,node* target,int w);
	static void start();
	static int count;
private:
	const node* source;
	const node* target;
	const int weight;
};



#endif /* EDGE_H_ */
