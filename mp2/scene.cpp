#include "scene.h"

using namespace std;

//_____________________________________CONSTRUCTORS_________________________________________//
//create a array of image pointers
Scene::Scene(int max)
:imageCap(max) //make image cap equal to max
{
    pics = new Image * [max]; //new pics array of size max
    for (int i = 0; i < max; i++)
        pics[i] = NULL;
}


//destructor
Scene::~Scene()
{
    clear();
}


//copy constructor
Scene::Scene(const Scene & source)
{
    copy(source);
}


//__________________________________ASSIGNMENT_OPERATOR_______________________________________//
//assignment operator for Scene class
const Scene & Scene::operator= (const Scene & source)
{
    if(this != &source) //check for self assignment by comparing this with the address of source
    {
        clear(); //delete the current pics array this is pointing to
        copy(source); //copy the pics array from source to this.
    }
    return *this; // return the
}


//__________________________________METHOD_IMPLEMENTATION_______________________________________//
//modify the size of the pics array
void Scene::changemaxlayers(int newmax)
{
    if (newmax < 0){
        cout << "invalid newmax" << endl;
        return;
    }
    if (newmax < imageCap){ //if newmax is less than current imageCap, go through check
        for (int i = newmax; i < imageCap; i++){ //loop from new max to max-1
            if(pics[i] != NULL){ //see if any image pointer afer newmax is non NULL
                cout << "invalid newmax" << endl;
                return; //If NULL, end method
            }
        }
    }
    //if no NULL, copy
    Image ** temp = new Image * [newmax]; //create a temporary array
    //assign pointers in pics array to temp
    for (int i = 0; i < imageCap; i++){
        temp[i] = pics[i];
    }
    if (newmax > imageCap)
        for (int i = imageCap; i < newmax; i ++)
            temp[i] = NULL;
    delete [] pics; //delete the images in the pic arrays
    //assign temp array to pics
    imageCap = newmax;
    pics = new Image * [imageCap];
    for (int i = 0; i < imageCap; i ++){
        pics[i] = temp[i];
    }
    delete [] temp; //delete the temp array before it goes out of scope
}


//add a picture to the specicified index and coordinate
void Scene::addpicture(const char * FileName, int index, int x, int y){
    //check if specified index is withing the length of the pics array
    if (index >= imageCap || index < 0){
        cout << "index out of bounds" << endl;
        return;
    }
    delete pics[index]; //remove current pointer's pointee located at the index, might be unnecessary.
    pics[index] = new Image();
    pics[index]->readFromFile(FileName); //overwrite the current PNG
    //assign x and y to Image (not pointer of Image)
    pics[index]->xc = x;
    pics[index]->yc = y;
}


//moves image from index to newindex
void Scene::changelayer(int index, int newindex){
    if (index == newindex){ //make sure the new index is different form the old index
        return;
    }
    if (index >= imageCap || newindex >= imageCap || index < 0 || newindex < 0){ // check if index and new index are valid
        cout << "invalid index" << endl;
        return;
    }
    if (pics[newindex] != NULL) { //if there is a image in the new index, delete it.
        delete pics[newindex];
    }
    pics[newindex] = pics[index]; //make image pointer at new index point to the old index's pointee
    pics[index] = NULL; //set the pointer at index to NULL
}


//change the x and y coord of the image pointed to by the image pointer at the indicated index
void Scene::translate(int index, int xcoord, int ycoord){
    if (pics[index] == NULL || index >= imageCap || index < 0){
        cout << "invalid index" <<endl;
        return;
    }
    pics[index]->xc = xcoord;
    pics[index]->yc = ycoord;
}

//delete the Image at the specified index
void Scene::deletepicture(int index){
    if (pics[index] == NULL || index >= imageCap || index < 0){
        cout << "invalid index" <<endl;
        return;
    }
    delete pics[index];
    pics[index] = NULL;
}


//return a pointer to the image at the specified index
Image * Scene::getpicture(int index) const{
    if (pics[index] == NULL || index >= imageCap || index < 0){
        cout << "invalid index" <<endl;
        return NULL;
    }
    return pics[index];
}


//draw the whole scene on one image and reurn the image by value
Image Scene::drawscene() const{
    //find the maximum value of the bottom left corner
    size_t maxX = 0;
    size_t maxY = 0;
    for (int i = 0; i < imageCap; i++){
        if (pics[i] != NULL){
            if (pics[i]->width() + pics[i]->xc >= maxX){
                maxX = pics[i]->width() + pics[i]->xc;
            }
            if (pics[i]->height() + pics[i]->yc >= maxY){
                maxY = pics[i]->height() + pics[i]->yc;
            }
        }
    }
    //fill pixels in mix with the images in the array
    Image mix;
    mix.resize(maxX,maxY);
    for (int i = 0; i < imageCap; i++){
        if (pics[i] != NULL){
            for (size_t x = 0; x < pics[i]->width(); x++){
                for (size_t y = 0; y < pics[i]->height(); y++){
                    *(mix)(x + pics[i]->xc,y + pics[i]->yc) = *(*pics[i])(x,y);
                }
            }
        }
    }
    return mix;

}

//________________________________________HELPERS___________________________________________//
//constructor helper
void Scene::copy(const Scene & source){
    //set the imageCap equal to the imageCap of the source
    imageCap = source.imageCap;
    pics = new Image * [imageCap]; //set up the pics array
    for(int i = 0; i < imageCap; i++){ //loop through each image pointer in the source array
        if (source.pics[i] == NULL)
            pics[i] = NULL;
        if (source.pics[i] != NULL){ //if the pointer in the source array does not equal to NULL, proceed to copy
            pics[i] = new Image(*(source.pics[i]));
            //pics[i] = new Image();
            //pics[i]->resize(source.pics[i]->width(), source.pics[i]->height());
            pics[i]->xc = (source.pics[i])->xc;
            pics[i]->yc = (source.pics[i])->yc;
            /*for (size_t x = 0; x < source.pics[i]->width(); x++){
                for (size_t y = 0; y < source.pics[i]->height(); y++){
                    *(*pics[i])(x,y) = *(*source.pics[i])(x,y);
                }
            }*/
        }
    }
}


//destructor helper
void Scene::clear()
{
    if (pics != NULL){
        delete [] pics;
    }
}





