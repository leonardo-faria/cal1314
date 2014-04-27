/*
 * Shuttle.cpp
 *
 *  Created on: 24/04/2014
 *      Author: leonardo
 */

#include "Shuttle.h"


int shuttle::count = 0;

shuttle::shuttle(int c):capacity(c),id(count++)
{
	free_space=c;
}


bool shuttle::full()
{
	if(free_space==0)
		return true;
	return false;
}




