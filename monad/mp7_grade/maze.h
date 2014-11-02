#ifndef _MAZE_H_
#define _MAZE_H_

#include "dsets.h"

class SquareMaze{
public:
    // empty ctor
    SquareMaze();
    
    // make a maze of given h and w
    void makeMaze(int width, int height);
    
    // check if can move in current dir at given coordinate
    bool canTravel(int x, int y, int dir) const;
    
    // set wall or no wall
    void setWall(int x, int y, int dir, bool exists);
    
    // solve the maze
    vector<int> solveMaze();
    
    // draw the maze without the solution
    PNG * drawMaze() const;
    
    // draw maze with solution
    PNG * drawMazeWithSolution();
    
    // destructor since using array on heap.
    ~SquareMaze();
    
    
private:
    
    bool ** down;
    bool ** right;
    int h;
    int w;
    int n;
    DisjointSets check;
    vector<int> path;
	vector<int> solution;
	int exit;
	int longest;
    // clear helper.
    void clear();
	// solve maze helper
	void travel(int curr, int length, int prev);

};


#endif
