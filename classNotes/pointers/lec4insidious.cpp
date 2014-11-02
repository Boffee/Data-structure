#include<iostream>
using namespace std;

int main() {

	int *q, *p; //pointer is set to garbage, not NULL.
	
	p = new int(5);
	q = p;
	cout << "1 *q: " << *q << endl;
	delete p; // both p and q looses its target. (same as delete q, but can't delete both)
	p = q = NULL; //without this, variable would be invalid.

	cout << "2 *q: "<< *q << endl; //will now get an error since set to NULL.
	
	int * r = new int(7);
	cout << "3 *q: " << *q << endl; // insidious bug. will outp *r if not set ot NULL.
	return 0;
}
