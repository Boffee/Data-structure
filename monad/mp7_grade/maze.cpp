#include <ostream>
#include <cmath>
#include <time.h>

#include "maze.h"


SquareMaze::SquareMaze()
{
    h = 0;
    w = 0;
}

void SquareMaze::makeMaze(int width, int height)
{
    if (w != 0) clear();
    w = width;
    h = height;
    n = h*w;
    
    // create grid with all walls true.
    down = new bool*[w];
    right = new bool*[w];
    check.addelements(n);
    
    for (int i = 0; i < w; i++)
    {
        down[i] = new bool[h];
        right[i] = new bool[h];
        for (int j = 0; j < h; j++)
        {
            down[i][j] = true;
            right[i][j] = true;
        }
    }
    srand(time(NULL));
    int m = 0;
    while (m < n-1)
    {
        int wall = rand()%n;
        int y = wall/w;
        int x = wall%w;
        
        // 0 = right, 1 = down.
        int dir = rand()%2;
        
        // down
        if (dir == 1 && y < h-1 && check.find(wall) != check.find(wall+w))
        {
            setWall(x, y, 1, false);
            check.setunion(wall, wall+w);
            m++;
        }
        // right
        else if (dir == 0 && x < w-1 && check.find(wall) != check.find(wall+1))
        {
            setWall(x, y, 0, false);
            check.setunion(wall, wall+1);
            m++;
        }
    }
}

// not used
bool SquareMaze::canTravel(int x, int y, int dir) const
{
	// right
    if(dir == 0){
		if(x >= w-1) return false;
		else if(right[x][y] == false) return true;
		else return false;
	}
	// down
    if(dir == 1){
		if(y >= h-1) return false;
		else if(down[x][y] == false) return true;
		else return false;
	}
	// left
    if(dir == 2){
		if(x <= 0) return false;
		else if(right[x-1][y] == false) return true;
		else return false;
	}

	// up
    if(dir == 3){
		if(y <= 0) return false;
		else if(down[x][y-1] == false) return true;
		else return false;
	}
	return false;
}

void SquareMaze::setWall(int x, int y, int dir, bool exists)
{
    // 0 for right
    if(dir == 0 && right[x][y] != exists) right[x][y] = exists;
    // 1 for down
    if(dir == 1 && down[x][y] != exists) down[x][y] = exists;
    // 2 for left
    if(dir == 2 && right[x-1][y] != exists) right[x-1][y] = exists;
    // 3 for up
    if(dir == 3 && down[x][y-w] != exists) down[x][y-w] = exists;
}


void SquareMaze::clear()
{
    if(w != 0){
        for(int i = 0; i < w; i++)
        {
            delete [] right[i];
            delete [] down[i];
        }
        delete [] down;
        delete [] right;
    }
}

PNG * SquareMaze::drawMaze() const
{
    PNG * maze = new PNG(w*10+1, h*10+1);
    // coloring top wall excluding entrance
    for(int x = 10; x < maze->width(); x++){
        *(*maze)(x, 0) = RGBAPixel(0,0,0);
    }
    // color in left wall
    for(int y = 0; y < maze->height(); y++){
        *(*maze)(0,y) = RGBAPixel(0,0,0);
    }
    // color in walls
    for(int x = 0; x < w; x++){
        for(int y = 0; y < h; y++){
			// right wall
            if(right[x][y] == true){
                for (int k = 0; k <= 10; k++){
                    *(*maze)((x+1)*10,y*10+k) = RGBAPixel(0,0,0);
                }
            }
			// bottom wall
            if(down[x][y] == true){
                for (int k = 0; k <= 10; k++){
                    *(*maze)(x*10+k,(y+1)*10) = RGBAPixel(0,0,0);
                }
            }
        }
    }
    return maze;
}

PNG * SquareMaze::drawMazeWithSolution()
{
    PNG * maze = drawMaze();
	// open exit
	//for(int x = exit%w*10+1; x < exit%w*10+10; x++) *(*maze)(x,h*10) = RGBAPixel(255,255,255);
	// draw path
	int x = 0;
	int y = 0;
	for(int i = 0; i < longest; i++)
	{
		int dir = solution[i];
		int vert; // vertical
		int hor; // horizontal
		// right
		if (dir == 0){
			vert = 0;
			hor = 1;
		}
		// down
		if (dir == 1){
			vert = 1;
			hor = 0;
		}
		// left
		if (dir == 2){
			vert = 0;
			hor = -1;
		}
		// up
		if (dir == 3){
			vert = -1;
			hor = 0;
		}
		for (int k = 0; k <= 10; k++){
			*(*maze)(x*10+5+hor*k,y*10+5+vert*k) = RGBAPixel(255,0,0);
		}
		x = x+hor;
		y = y+vert;
	}
	return maze;
}

vector<int> SquareMaze::solveMaze()
{
	exit = 0;
	longest = 0;
	for (int i = 0; i < n; i++) path.push_back(-1);
	travel(0, 0, -1);
	int end = exit;
    down[exit%w][exit/w] = false;
	int dir;
	while (end > 0)
	{
		// right
		if(path[end] == end-1) dir = 0;
		// down
		if(path[end] == end-w) dir = 1;
		// left
		if(path[end] == end+1) dir = 2;
		// up
		if(path[end] == end+w) dir = 3;
		
		solution.insert(solution.begin(), dir);
		end = path[end];
	}
	return solution;
}

void SquareMaze::travel(int curr, int length, int prev)
{
	// right
	int x = curr%w;
	int y = curr/w;
	
	bool r = canTravel(x, y, 0) && prev != 0;
	bool d = canTravel(x, y, 1) && prev != 1;
	bool l = canTravel(x, y, 2) && prev != 2;
	bool u = canTravel(x, y, 3) && prev != 3;
	
	// if one of the directions is true, then keep going
	if (y == h-1 && !(r || l || u)){
		if (length > longest){
			longest = length;
			exit = curr;
		}
		if (length == longest && curr < exit){
			exit = curr;
		}
		return;
	}
	// right
	if (r){
		path[curr+1] = curr;
		travel(curr+1, length+1, 2);
	}
	// down
	if (d){
		path[curr+w] = curr;
		travel(curr+w, length+1, 3);
	}
	// left
	if (l){
		path[curr-1] = curr;
		travel(curr-1, length+1, 0);
	}
	// up
	if (u){
		path[curr-w] = curr;
		travel(curr-w, length+1, 1);
	}
}

SquareMaze::~SquareMaze()
{
    clear();
}
