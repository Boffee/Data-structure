/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */
	 			
#include <iostream>
#include <map>
#include "maptiles.h"

using namespace std;

MosaicCanvas * mapTiles(SourceImage const & theSource, vector<TileImage> const & theTiles)
{
    /**
     * @todo Implement this function!
     */
	int h = theSource.getRows();
	int w = theSource.getColumns();
	if ( h == 0 || w == 0 ) return NULL;
	MosaicCanvas * canv = new MosaicCanvas(h, w);
	vector< Point<3> > list;
	map< Point<3>,TileImage > album;

	for (int i = 0; i < theTiles.size(); i++)
	{
		RGBAPixel currPix = theTiles[i].getAverageColor();
		Point<3> curr(currPix.red, currPix.blue, currPix.green);
		list.push_back(curr);
		album.insert(std::pair< Point<3>,TileImage > (curr, theTiles[i]) );
	}

	KDTree<3> tree(list);
	for (int i = 0; i < h; i++)
	{
		for( int j = 0; j < w; j++)
		{
			RGBAPixel curr = theSource.getRegionColor(i,j);
			Point<3> currPix(curr.red, curr.blue, curr.green);
			Point<3> find = tree.findNearestNeighbor(currPix);
			canv->setTile(i,j,album[find]);
		}
	}
	return canv;

}
