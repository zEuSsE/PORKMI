/*
 * =====================================================================================
 *
 *       Filename:  main.cc
 *
 *    Description:
 *
 *
 *        Version:  1.0
 *        Created:  24/01/2012 09:30:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andrea Mazzeschi (AM), andrea.mazzeschi@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <../PORKMI/libpmk-2.5/libpmk2/pyramids/pyramid-maker.h>
#include <vector>
#include <histograms/multi-resolution-histogram.h>
#include <pyramids/uniform-pyramid-maker.h>
#include <pyramids/global-vg-pyramid-maker.h>
#include <pyramids/input-specific-vg-pyramid-maker.h>

#include <point_set/on-disk-point-set-list.h>

using namespace libpmk;
using namespace std;

vector<MultiResolutionHistogram *> vectorMRH;
PointSetList * pointSetList;

//~/Scrivania/PORKMI/libpmk-2.5/libpmk2/pyramids/testdata/testpointsets.psl

void loadPSL(){
	pointSetList=new OnDiskPointSetList("~/Scrivania/PORKMI/libpmk-2.5/libpmk2/pyramids/testdata/testpointsets.psl");
	cout << pointSetList;
}

void makePyramids(){
	PyramidMaker * pyramidMaker;
<<<<<<< HEAD
	pyramidMaker=new UniformPyramidMaker();
//	pyramidMaker=new InputSpecificVGPyramidMaker(); da mettere apposto
//	pyramidMaker=new GlobalVGPyramidMaker();
	vectorMRH=pyramidMaker.MakePyramids(pointSetList);
=======
	pyramidMaker=new UniformPyramidMaker();	
//	pyramidMaker=new InputSpecificVGPyramidMaker(); da mettere apposto 
//	pyramidMaker=new GlobalVGPyramidMaker(); 
//	vectorMRH=pyramidMaker.MakePyramids(pointSetList);
>>>>>>> 7c4c2e54cbdb990748fc4ee0143df79079f08449



}



int main ( int argc, char *argv[] )
{
	loadPSL();
	makePyramids();
	return EXIT_SUCCESS;
}





