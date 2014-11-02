#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "png.h"

using namespace std;

int main(){
    
    PNG image;
    image.readFromFile("image.png");
    cout <<image.width()<<endl;
    cout <<image.height()<<endl;
    for (int i = 0; i < 256; i++){
        for (int j = 0; j < 256; j++){
            if(isalpha(image(i,j)->red)){
                if (islower(image(i,j)->red)){
                    cout << image(i,j)->red;
                }
            }
            if(isalpha(image(i,j)->blue)){
                if (islower(image(i,j)->blue)){
                    cout << image(i,j)->blue;
                }
            }
            if(isalpha(image(i,j)->green)){
                if (islower(image(i,j)->green)){
                    cout << image(i,j)->green;
                }
            }
            //if (image(i,j)->red >= 20 && image(i,j)->red < 40 ) cout << image(i,j)->red << image(i,j)->green << image(i,j)->blue;
            //cout << "red: " << (image(i,j)->red) << " blue: "<< (image(i,j)->blue)<< " green: " << (image(i,j)->green) << " address: " << image(i,j) << endl;
        }
    }
    cout << endl;
    return 0;
}