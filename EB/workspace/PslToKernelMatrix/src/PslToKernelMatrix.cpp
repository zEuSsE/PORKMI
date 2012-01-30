//============================================================================
// Name        : PslToKernelMatrix.cpp
// Author      : Andrea Zerbini
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
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
#include <sstream>




using namespace std;
using namespace libpmk;




//possibili tipi di PyramidMaker
#define UNIFORM_PYRAMID_MAKER 1
#define GLOBAL_VGP_PYRAMID_MAKER 2
#define INPUT_SPECIFIC_VGP_PYRAMID_MAKER 3


void loadPSL(string);
void makePyramids(double finest_side_length, double side_factor, int discretize_factor, bool do_translations, bool global_translation);
void makeKernelMatrix(int fsl, int sf, int df, bool dt, bool gt, string destinazionePath);
int main(int, char* []);




PyramidMaker *ptrPyramidMaker;
PointSetList *ptrPSL;
vector<MultiResolutionHistogram *> vectorMRH;
int MAKE_PYRAMID_TYPE  =  UNIFORM_PYRAMID_MAKER;



int main(int argc,char *argv[]) {


	loadPSL("/home/andrea/Scrivania/Progetto/DATASET_ETH80/GridSIFT/ETH80_GridSIFT.psl");
	makeKernelMatrix(10,20,0,true,true,"/home/andrea/Scrivania/Progetto/DATASET_ETH80/GridSIFT/Kernel");

	/*//-----------------------------------------------
	fsl=1000;
	sf=20;
	df=0;

	makePyramids(fsl,sf,df,dt,gt);
	nomeFileDestinazione1="";
	nomeFileDestinazione1="KM"+fsl;
	nomeFileDestinazione1+="_"+sf;
	nomeFileDestinazione1+="_"+df;
	kmc=new KernelMatrixCalculator(vectorMRH,"/home/andrea/Scrivania/Progetto/DATASET_101/KernelMatrix",nomeFileDestinazione1);
	kmc->kernelMatrixGenerate();

	//-----------------------------------------------


	//-----------------------------------------------
	fsl=1000;
	sf=20;
	df=2;

	makePyramids(fsl,sf,df,dt,gt);
	nomeFileDestinazione1="";
	nomeFileDestinazione1="KM"+fsl;
	nomeFileDestinazione1+="_"+sf;
	nomeFileDestinazione1+="_"+df;
	kmc=new KernelMatrixCalculator(vectorMRH,"/home/andrea/Scrivania/Progetto/DATASET_101/KernelMatrix",nomeFileDestinazione1);
	kmc->kernelMatrixGenerate();

	//-----------------------------------------------


	//-----------------------------------------------
	fsl=100;
	sf=2;
	df=1;

	makePyramids(fsl,sf,df,dt,gt);
	nomeFileDestinazione1="";
	nomeFileDestinazione1="KM"+fsl;
	nomeFileDestinazione1+="_"+sf;
	nomeFileDestinazione1+="_"+df;
	kmc=new KernelMatrixCalculator(vectorMRH,"/home/andrea/Scrivania/Progetto/DATASET_101/KernelMatrix",nomeFileDestinazione1);
	kmc->kernelMatrixGenerate();

	//-----------------------------------------------*/


	return 0;
}



void loadPSL(string filePSL){
		cout << "Carico file PSL: "<< filePSL << endl;
		ptrPSL=new OnDiskPointSetList(filePSL);

}


void makePyramids(double finest_side_length, double side_factor, int discretize_factor, bool do_translations, bool global_translation){
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


void makeKernelMatrix(int fsl, int sf, int df, bool dt, bool gt, string destinazionePath){



		dt=true;
		gt=true;
		string s;
		stringstream out;








		string nomeFileDestinazione1;
		KernelMatrixCalculator *kmc;


		fsl=200;
		sf=10;
		df=0;
		dt=true;
		gt=true;

		makePyramids(fsl,sf,df,dt,gt);
		nomeFileDestinazione1="";
		out <<"KM_"<< fsl<<"_"<<sf<<"_"<<df<<"_"<<dt<<"_"<<gt;
		out.clear();
		nomeFileDestinazione1 = out.str();
		//cout<<"\nFileDestinazione1: "<<nomeFileDestinazione1<<"\n";

		kmc=new KernelMatrixCalculator(vectorMRH,destinazionePath,nomeFileDestinazione1);
		kmc->kernelMatrixGenerate();


}


