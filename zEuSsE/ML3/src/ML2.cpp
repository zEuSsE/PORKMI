//============================================================================
// Name        : ML2.cpp
// Author      : Andrea Mazzeschi
// Version     :
// Copyright   : Your copyright notice
// Description : Prende in input un file .psl e calcola
//				 il vettore di MultiResolution Histograms
//============================================================================

#include "point_set/on-disk-point-set-list.h"
#include "point_set/point-set-list.h"
#include "pyramids/pyramid-maker.h"
#include "pyramids/uniform-pyramid-maker.h"
#include "pyramids/global-vg-pyramid-maker.h"
#include "pyramids/input-specific-vg-pyramid-maker.h"
#include "histograms/multi-resolution-histogram.h"
#include "clustering/clusterer.h"
#include "util/distance-computer.h"
#include "KernelMatrixCalculator.h"
#include <iostream>
#include <fstream>

//libreria boost c++
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem.hpp>




using namespace std;
using namespace libpmk;
using namespace boost::filesystem;


//possibili tipi di caricamente file PSL
#define ON_DISK_POINT_SET_LIST  1
#define MUTABLE_POINT_SET_LIST  2


//possibili tipi di PyramidMaker
#define UNIFORM_PYRAMID_MAKER 1
#define GLOBAL_VGP_PYRAMID_MAKER 2
#define INPUT_SPECIFIC_VGP_PYRAMID_MAKER 3



void makePyramids();
void makeKernelMatrix();
int main(int, char* []);

PyramidMaker *ptrPyramidMaker;
PointSetList *ptrPSL;
vector<MultiResolutionHistogram *> vectorMRH;
int PSLTYPE  =  ON_DISK_POINT_SET_LIST;
int MAKE_PYRAMID_TYPE  =  UNIFORM_PYRAMID_MAKER;







void loadPSL(string filePSL){
		cout << "Carico file PSL: "<< filePSL << endl;
			switch (PSLTYPE) { //TODO forse il mutable è eliminabile
						case ON_DISK_POINT_SET_LIST:
							ptrPSL=new OnDiskPointSetList(filePSL);
						break;
						case MUTABLE_POINT_SET_LIST:
							//TODO
						break;
			}
}


void makePyramids(){
	switch (MAKE_PYRAMID_TYPE) {
		case UNIFORM_PYRAMID_MAKER:
		//	cout << "		Uniform Pyramid Maker Selected";
			//TODO deve essere inizializzato tutto per bene
			ptrPyramidMaker=new UniformPyramidMaker();
			((UniformPyramidMaker *)ptrPyramidMaker)->Preprocess(
						*ptrPSL,10,20,0,true,true);//TODO
			break;
		case GLOBAL_VGP_PYRAMID_MAKER:
			cout << "		Global VGP Pyramid Maker Selected";
			//TODO deve essere inizializzato tutto per bene
		/*	Clusterer *clusterer;
			DistanceComputer *distance;
			GlobalVGPyramidMaker gpm(
					clusterer,distance);
			break;
		case INPUT_SPECIFIC_VGP_PYRAMID_MAKER:
			cout << "Input Specific VGP Pyramid Maker Selected";
			//TODO
			Clusterer *clusterer;
			DistanceComputer *distance;
			InputSpecificVGPyramidMaker *ptrPyramidMaker(
					clusterer,distance);*/
			break;
	}
	vectorMRH=ptrPyramidMaker->MakePyramids(*ptrPSL);
	cout <<  "vectorMRH Creato	" << endl;

}


void makeKernelMatrix(){
	KernelMatrixCalculator *kmc=new KernelMatrixCalculator(vectorMRH);
	kmc->kernelMatrixGenerate();
}

/*void showFiles(const path &directoryPSL){
	if (exists(directoryPSL)) {
		directory_iterator iter(directoryPSL),end;
		for (iter; iter!=end; ++iter) {
			cout << (*iter).path().stem().string();
			//string s=*iter;
			//cout << s;
			//std::ofstream s ();
			//s << "Cicciapera" ;
			//s.close();
		}
	}
	else {
		cout << "Directory Inesistente!" << endl;
	}

}*/

int main(int argc,char *argv[]) {
//	showFiles("/home/andrea/txt");
	loadPSL("/home/andrea/Scaricati/ETH80_GridSIFT.psl");
	makePyramids();
	makeKernelMatrix();
	return 0;
}
