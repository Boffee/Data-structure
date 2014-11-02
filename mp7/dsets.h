#ifndef _DSETS_H_
#define _DSETS_H_

#include "png.h"

#include <vector>

using std::vector;

class DisjointSets{
public:

	// create n unconnected root at the back of the vector
	void addelements(int num);

	// find the set of the elem and compress the set
	int find(int elem);

	// union by size
	void setunion(int a, int b);

private:

	vector< int > dSets;
};

#endif