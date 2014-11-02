#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int ** mat = new int*[0];
    int ** mat2 = new int*[10];
    mat = mat2;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            mat[i][j] = i*j;
        }
    }
    int i = 3;
    double j = 3.2;
    double x = i + 3.5;
    bool t = false && false;
    cout << i << endl;
    return 0;
}