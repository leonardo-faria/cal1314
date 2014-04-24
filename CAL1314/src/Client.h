/*
 * Client.h
 *
 *  Created on: 24/04/2014
 *      Author: leonardo
 */

#ifndef CLIENT_H_
#define CLIENT_H_

class client {
public:
	client(node* location, int arrival_time);
private:
	static int count;
	const int id;
	node* location;
	const int arrival_time;
};

#endif /* CLIENT_H_ */
