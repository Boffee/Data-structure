#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "image.h"
class Scene{
public:
    //CTOR & DTOR
    //initialize this scene to hold "max" number of images.
    Scene(int max);
    
    //free all dynamically allocations by this Scene.
    ~Scene();
    
    //cctor
    Scene(const Scene &source);
    
    //MEMBER FUNCTIONS
    //asignment operator for the Scene class.
    const Scene & operator= (const Scene &source);
    
    //modify the size of the Scene array
    void changemaxlayers(int newmax);
    
    //add a image to scene array at the specified index and coordinate;
    void addpicture(const char *FileName, int index, int x, int y);
    
    //move image from one layer to another.
    void changelayer(int index, int newindex);
    
    //change coordinate of image in the specified layer.
    void translate(int index, int xcoord, int ycoord);
    
    //delete the image at the index.
    void deletepicture(int index);
    
    //constructor helper
    void copy(const Scene & source);
    
    //destructor helper
    void clear();
    
    //return a pointer to the image at the specified at the specified index.
    Image * getpicture(int index) const;
    
    //draw the whole scene array onto one image and return that image by value.
    Image drawscene() const;
    
    //array of image pointers
    Image ** pics;
    
    //capacity of array
    int imageCap;
};

#endif