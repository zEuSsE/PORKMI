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

using namespace libpmk;
using namespace std;

vector<MultiResolutionHistogram *> vectorMRH;
PointSetList pointSetList;


void loadPSL(){

}

void makePyramids(){
	PyramidMaker * pyramidMaker;
	pyramidMaker=new UniformPyramidMaker();
//	pyramidMaker=new InputSpecificVGPyramidMaker(); da mettere apposto
//	pyramidMaker=new GlobalVGPyramidMaker();
	vectorMRH=pyramidMaker.MakePyramids(pointSetList);



}



int main ( int argc, char *argv[] )
{
	loadPSL();
	makePyramids();
	return EXIT_SUCCESS;
}





