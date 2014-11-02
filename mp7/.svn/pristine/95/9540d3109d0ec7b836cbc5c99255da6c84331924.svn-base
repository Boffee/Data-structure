#include "dsets.h"

// add root elememts
void DisjointSets::addelements(int num)
{
	for (int i = 0; i < num; i ++){
		dSets.push_back(-1);
	}
}

// find the root of the set and cmpress
int DisjointSets::find(int elem)
{
	if (dSets[elem] < 0) return elem;
	else return dSets[elem] = find(dSets[elem]);
}

// combinet two sets
void DisjointSets::setunion(int a, int b)
{
	int roota = find(a);
	int rootb = find(b);
	int newSize = dSets[roota] + dSets[rootb];
	// check if roota size is smaller than rootb size
	if( dSets[roota] > dSets[rootb] ) // negative, so bigger is smaller height
	{
		// put set containing a under rootb
		dSets[roota] = rootb;
		dSets[rootb] = newSize;
	}
	else
	{
		// put set containing b under roota
		dSets[rootb] = roota;
		dSets[roota] = newSize;
	}
}	
