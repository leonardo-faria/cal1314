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
	edge(node* source,node* target,double w);
	const double get_weight();
	const node* get_sorce();
	const node* get_target();
private:
	static int count;
	const node* source;
	const node* target;
	double weight;
};



#endif /* EDGE_H_ */
