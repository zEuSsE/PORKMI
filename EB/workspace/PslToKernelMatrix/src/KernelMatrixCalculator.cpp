/*
 * KernelMatrixCalculator.cpp
 *
 *  Created on: 26/gen/2012
 *      Author: andrea
 */

#include "KernelMatrixCalculator.h"



KernelMatrixCalculator::KernelMatrixCalculator(vector<MultiResolutionHistogram*> multiResolutionHistograms,string path, string name)
{
	pathDestination=path;
	nameFile=name;
	vectorMRH=multiResolutionHistograms;
}

KernelMatrixCalculator::~KernelMatrixCalculator() {
	// TODO Auto-generated destructor stub
}

void KernelMatrixCalculator::kernelMatrixGenerate(){
	cout << "Inizio Generazione Matrice Kernel"<< endl;
	string pathTotale= pathDestination+"/"+nameFile+".ker";
	ofstream kernelMatrix (pathTotale.c_str(), ios::out| ios::binary);
	int size=vectorMRH.size();
	kernelMatrix.write((char *) &size, sizeof( size ));
	BinWeightScheme binWeightScheme=BIN_WEIGHT_GLOBAL; //TODO  capire che è sto BinWeightScheme
	double similarity;
	for ( int i = 0; i < vectorMRH.size(); i++) {
		for (int j = 0; j <= i; j++) {
			similarity=PyramidMatcher::GetPyramidMatchSimilarity
					(*(vectorMRH[i]),*(vectorMRH[j]),binWeightScheme);
			kernelMatrix.write((char *) &similarity, sizeof( similarity ));
		}
		if (i%200==0) cout << "Finita riga: "<< i <<endl;
	}
	kernelMatrix.close();
	cout << "Matrice di Kernel salvata in "<<pathTotale << endl;
}






