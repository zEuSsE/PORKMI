/*
 * KernelMatrixCalculator.cpp
 *
 *  Created on: 26/gen/2012
 *      Author: andrea
 *   Description: Fornito un vector<MultiResolutionHistogram*>, crea un file rappresentante
 *   			  la matrice di Kernel, ovvero un file nel formato:
 *   			  (int) Numero di righe (colonne) della matrice
 *   			  (double) K[0][0]
 *   			  (2xdouble) K[1][0] K[1][1] (row 1)
 *   			  ......
 *   			  (N x double) row N
 */

#include "KernelMatrixCalculator.h"




KernelMatrixCalculator::KernelMatrixCalculator(vector<MultiResolutionHistogram*> multiResolutionHistograms)
{
	vectorMRH=multiResolutionHistograms;
}

KernelMatrixCalculator::~KernelMatrixCalculator() {
	// TODO Auto-generated destructor stub
}

void KernelMatrixCalculator::kernelMatrixGenerate(){
	cout << "Inizio Generazione Matrice Kernel"<< endl;
	ofstream kernelMatrix ("kernelMatrix_eth80.ker", ios::out| ios::binary);
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
	cout << "Matrice di Kernel salvata in /path/to/workspace/kernelMatrix.ker" << endl;
}






