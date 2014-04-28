/*
 * Graph.cpp
 *
 *  Created on: 24/04/2014
 *      Author: leonardo
 */

#include "Graph.h"

graph::graph(int m, string i, string o) :
		mode(m), input(i), output(o) {
	arrived = 0;
	node a(true);
	node b(false);
	node c(false);
	node d(false);
	node e(false);
	node f(false);
	nodes.push_back(a);
	nodes.push_back(b);
	nodes.push_back(c);
	nodes.push_back(d);
	nodes.push_back(e);
	nodes.push_back(f);

	edge e1(&nodes[0], &nodes[1], 1);
	edge e2(&nodes[0], &nodes[2], 1.25);
	edge e3(&nodes[0], &nodes[3], 1.25);
	edge e4(&nodes[0], &nodes[4], 1.25);
	edge e5(&nodes[0], &nodes[5], 1);
	nodes[0].add_edge(e1);
	nodes[0].add_edge(e2);
	nodes[0].add_edge(e3);
	nodes[0].add_edge(e4);
	nodes[0].add_edge(e5);

	edge e6(&nodes[1], &nodes[0], 1);
	edge e7(&nodes[1], &nodes[2], 0.25);
	edge e8(&nodes[1], &nodes[3], 0.5);
	edge e9(&nodes[1], &nodes[4], 35.0 / 60.0);
	edge e10(&nodes[1], &nodes[5], 40.0 / 60.0);
	nodes[1].add_edge(e6);
	nodes[1].add_edge(e7);
	nodes[1].add_edge(e8);
	nodes[1].add_edge(e9);
	nodes[1].add_edge(e10);

	edge e11(&nodes[2], &nodes[0], 1.25);
	edge e12(&nodes[2], &nodes[1], 0.25);
	edge e13(&nodes[2], &nodes[3], 0.25);
	edge e14(&nodes[2], &nodes[4], 0.5);
	edge e15(&nodes[2], &nodes[5], 35.0 / 60.0);
	nodes[2].add_edge(e11);
	nodes[2].add_edge(e12);
	nodes[2].add_edge(e13);
	nodes[2].add_edge(e14);
	nodes[2].add_edge(e15);

	edge e16(&nodes[3], &nodes[0], 1.25);
	edge e17(&nodes[3], &nodes[1], 0.5);
	edge e18(&nodes[3], &nodes[2], 0.25);
	edge e19(&nodes[3], &nodes[4], 0.25);
	edge e20(&nodes[3], &nodes[5], 0.5);
	nodes[3].add_edge(e16);
	nodes[3].add_edge(e17);
	nodes[3].add_edge(e18);
	nodes[3].add_edge(e19);
	nodes[3].add_edge(e20);

	edge e21(&nodes[4], &nodes[0], 1.25);
	edge e22(&nodes[4], &nodes[1], 35.0 / 60.0);
	edge e23(&nodes[4], &nodes[2], 0.5);
	edge e24(&nodes[4], &nodes[3], 0.25);
	edge e25(&nodes[4], &nodes[5], 0.25);
	nodes[4].add_edge(e21);
	nodes[4].add_edge(e22);
	nodes[4].add_edge(e23);
	nodes[4].add_edge(e24);
	nodes[4].add_edge(e25);

	edge e26(&nodes[5], &nodes[0], 1);
	edge e27(&nodes[5], &nodes[1], 40.0 / 60.0);
	edge e28(&nodes[5], &nodes[2], 35.0 / 60.0);
	edge e29(&nodes[5], &nodes[3], 0.5);
	edge e30(&nodes[5], &nodes[4], 0.25);
	nodes[5].add_edge(e26);
	nodes[5].add_edge(e27);
	nodes[5].add_edge(e28);
	nodes[5].add_edge(e29);
	nodes[5].add_edge(e30);

	client *c1 = new client(&nodes[1], 10, 1);
	client *c2 = new client(&nodes[2], 10, 1);
	client *c3 = new client(&nodes[3], 10.5, 1);
	client *c4 = new client(&nodes[4], 11, 1);
	client *c5 = new client(&nodes[5], 11, 1);

	clients.push_back(*c1);
	nodes[1].add_client(c1);
	clients.push_back(*c2);
	nodes[2].add_client(c2);
	clients.push_back(*c3);
	nodes[3].add_client(c3);
	clients.push_back(*c4);
	nodes[4].add_client(c4);
	clients.push_back(*c5);
	nodes[5].add_client(c5);

	shuttle s(5);
	shuttles.push_back(s);

	//solve(get_last_client_time(),get_airport());
}

node* graph::get_airport() {
	return &nodes[0];
}

bool graph::solved() {
	return false;
}

const double graph::get_last_client_time() {
	int n = 0;
	double t = 0.0;
	for (int i = 0; i < (int) nodes.size(); ++i) {
		for (int j = 0; j < (int) nodes[i].get_clients().size(); ++j) {
			if (n == 0 || nodes[i].get_clients()[j]->get_d_time() < t)
				t = nodes[i].get_clients()[j]->get_d_time();
			n++;
		}
	}
	return t;
}

bool graph::solve(double time, node* l, double tc) {
//TODO MUDAR
	//falha: dist, devolve sempre -1, e get_p_time
//	for (int i = 0; i < (int) nodes.size(); ++i) {
//		for (int j = 0; j < (int) nodes[i].get_clients().size(); ++j) {
//			if (time - l->dist(&nodes[i])
//					< nodes[i].get_clients()[j]->get_p_time())
//				return false;
//		}
//	}
	if (l->get_id() == 0) {
		stringstream ss;
		ss << "\nArrives at the the airport at ";
		double t = time - l->dist();
		int n = t;
		t = t - (double) n;
		t = t * 60;
		ss << n << ":" << t;
		if (t == 0)
			ss << 0;
		ss << endl;
		result.push_back(ss.str());
	}
	if (shuttles[0].getPassagerNumber() == (int) clients.size()) {
		stringstream ss;
		ss << "\Leaves the the airport at ";
		double t = time - l->dist();
		int n = t;
		t = t - (double) n;
		t = t * 60;
		ss << n << ":" << t;
		if (t == 0)
			ss << 0;
		result.push_back(ss.str());
		return true;
	}
	for (int i = 1; i < (int) nodes.size(); ++i) {
		if (nodes[i].get_clients().size() == 0)
			continue;
		if (nodes[i].visitable(time - l->dist(&nodes[i]))) {
			vector<int> v;
			shuttles[0].visit(&nodes[i]);
			if (solve(time - l->dist(&nodes[i]), &nodes[i], tc)) {
				string str;
				stringstream ss;
				ss << "\nStops in " << i << " at ";
				double t = time - l->dist(&nodes[i]);
				int n = t;
				t = t - (double) n;
				t = t * 60;
				ss << n << ":" << t;
				if (t == 0)
					ss << 0;
				ss << "\nPicks up clients: ";
				for (int k = 0; k < (int) clients.size(); ++k) {
					if (clients[k].get_origin()->get_id() == i)
						ss << k << ", ";
				}
				str = ss.str();
				str.resize(str.size() - 2);
				result.push_back(str);
				return true;
			}
			shuttles[0].undo();
		} else {
			double new_time = get_last_client_time();
			if (new_time - get_airport()->dist(&nodes[i])
					< tc + get_airport()->dist(&nodes[i]))
				continue;

			if (solve(new_time, get_airport(), new_time)) {
				return true;
			}
		}
	}

	return false;
}

void graph::read() {
	int nLines, targetID, width, arrivalTime, overhead;
	string s, line, sTargetID, sWidth, sArrivalTime, sOverhead;
	stringstream ss;
	ifstream infile;

	infile.open(input.c_str());

	//generate nodes
	node a(1);
	node b(0);
	nodes.push_back(a);
	getline(infile, line);
	nLines = atoi(line.c_str());
	for (int i = 0; i < nLines; ++i) {
		nodes.push_back(b);
	}
	//load clients
	getline(infile, line); //numero de clientes
	nLines = atoi(line.c_str());
	for (int i = 0; i < nLines; ++i) {
		getline(infile, line);
		getline(ss, sTargetID, ';');
		targetID = atoi(sTargetID.c_str());
		getline(ss, sArrivalTime, ';');
		arrivalTime = atoi(sArrivalTime.c_str());
		getline(ss, sOverhead, ';');
		overhead = atoi(sTargetID.c_str());
		clients.push_back(client(&nodes[targetID], arrivalTime, overhead));
		nodes[targetID].add_client(&clients.back());
	}
	//load nodes/edges
	while (!infile.eof()) {
		int j = 1; //node id
		getline(infile, line); //numero de edges no node
		nLines = atoi(line.c_str());
		for (int i = 0; i < nLines; ++i) {
			getline(infile, line);
			getline(ss, sTargetID, ';');
			targetID = atoi(sTargetID.c_str());
			getline(ss, sWidth, ';');
			width = atoi(sWidth.c_str());
			nodes[j].add_edge(edge(&nodes[j], &nodes[targetID], width));
		}
		++j;
	}

	infile.close();
}

void graph::print() {
	ofstream ss;
	ss.open(output.c_str());
	for (int i = 1; i < result.size(); ++i) {
		ss << result[i];
	}
	ss << result[0];
}
