#include<iostream>
using namespace std;

int myfun(){
	int x = 32;
	cout << "x: " << x << endl;
	return x;
}

int main() {

	int * p; int *q;
	*p = 6; // this works. :(
	cout<< "p: " << *p << endl;

	*q = myfun();

	cout << "p: " << *p << endl;

	return 0;
}
