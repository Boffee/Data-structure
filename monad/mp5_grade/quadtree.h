// **************************************************************
// *		   
// *  quadtree.h
// *		   
// *  Quadtree class
// *		   
// *  CS 225 Spring 2008
// *		   
// **************************************************************

#ifndef QUADTREE_H
#define QUADTREE_H

#include "png.h"

class Quadtree
{
	public:
	
    //empty ctor
    Quadtree();
    
    //ctor with input
    Quadtree(const PNG & source, int resolution);
    
    //cctor
    Quadtree(const Quadtree & other);
    
    //dtor
    ~Quadtree();
    
    // = operator
    Quadtree const & operator=(Quadtree const & other);
    
    //delete current content of quadtree and build a new one
    void buildTree(PNG const & source, int resolution);
    
    //get RGBAPixel at x, y
    RGBAPixel getPixel(int x, int y) const;
    
    //return the PNG represented by the quadtree
    PNG decompress() const;
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~5.1~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
    void clockwiseRotate ();
 	//Rotates the Quadtree object's underlying image clockwise by 90 degrees.
    
    void prune (int tolerance);
 	//Compresses the image this Quadtree represents.
    
    int pruneSize (int tolerance) const;
 	//This function is similar to prune; however, it does not actually prune the Quadtree.
    
    int idealPrune (int numLeaves) const;
 	//Calculates and returns the minimum tolerance necessary to guarantee that upon pruning the tree, no more than numLeaves leaves remain in the Quadtree.
    /*
    void printTree (std::ostream &out=std::cout) const;
    //Given: prints the leaves of the Quadtree using a preorder traversal.
    
    bool operator== (Quadtree const &other) const;
    //Given: compares the current Quadtree with the parameter Quadtree, and determines whether or not the two are the same.
     */
	private:

	// A simple class representing a single node of a Quadtree.
	// You may want to add to this class; in particular, it could probably
	// use a constructor or two...
	class QuadtreeNode
	{
		public:
		QuadtreeNode* nwChild;  // pointer to northwest child
		QuadtreeNode* neChild;  // pointer to northeast child
		QuadtreeNode* swChild;  // pointer to southwest child
		QuadtreeNode* seChild;  // pointer to southeast child
        
        //empty ctor
        QuadtreeNode();
        
        //ctor
        QuadtreeNode(RGBAPixel const & pix);
        
        int size;

		RGBAPixel element;  // the pixel stored as this node's "data"
	};
	
	QuadtreeNode* root;    // pointer to root of quadtree
    
    int res;
    
    int height;
    
	//build tree helper function, x and y are the start points
	QuadtreeNode * buildTree(PNG const & source, int resolution, int x, int y);
    
    //dtor helper
    void clear(QuadtreeNode * curr);
    
    //cctor helper
    QuadtreeNode * copy(QuadtreeNode * curr);
    
    //rotate helper
    void clockwiseRotate (QuadtreeNode * curr);
    
    bool prune(int tolerance, QuadtreeNode * curr);
    
    void pruneTest(int tolerance, QuadtreeNode * curr);
    
    int tolerate(RGBAPixel const & curr, RGBAPixel const & next) const;
    
    bool pruneCheck( int tolerance, QuadtreeNode * curr, RGBAPixel const & prune) const;
    
    void pruneClear( QuadtreeNode * curr);
    
    int pruneSize(int tolerance, QuadtreeNode * curr) const;
    
    int idealPrune(int numLeaves, int lo, int mid, int hi) const;
	
	/**** Functions added for testing/grading                ****/
	/**** Do not remove this line or copy its contents here! ****/
	#include "quadtree_given.h"
};

#endif
