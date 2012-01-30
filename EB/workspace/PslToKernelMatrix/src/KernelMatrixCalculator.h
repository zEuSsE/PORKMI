/*
 * KernelMatrixCalculator.h
 *
 *  Created on: 26/gen/2012
 *      Author: andrea
 *  Description: Una volta settato il vettore con i MRH di tutte le immagini,
 * 				 crea un file contenente la matrice di Kernel (utile per il backup)
 */

#include "histograms/multi-resolution-histogram.h"
#include "pyramids/pyramid-matcher.h"
#include "kernel/kernel-matrix.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#ifndef KERNELMATRIXCALCULATOR_H_
#define KERNELMATRIXCALCULATOR_H_

using namespace libpmk;
using namespace libpmk_util;

class KernelMatrixCalculator {
private:
	vector <MultiResolutionHistogram *> vectorMRH;
	KernelMatrix *kernelMatrix;
	string pathDestination;
	string nameFile;
	KernelMatrixCalculator();

public:
	KernelMatrixCalculator(vector<MultiResolutionHistogram *> multiResolutionHistograms,string path,string name);

	virtual ~KernelMatrixCalculator();

	void kernelMatrixGenerate();



};

#endif /* KERNELMATRIXCALCULATOR_H_ */
