#include<iostream>

using namespace std;

int main() {

	int * p; int x = 5;
	p = &x; // p points to x
	*p=6;
	cout<< "p: " << p << endl;
	cout<< "x: " << x << endl;

}