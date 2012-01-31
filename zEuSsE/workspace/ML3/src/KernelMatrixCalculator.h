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

public:
	KernelMatrixCalculator(vector<MultiResolutionHistogram *> multiResolutionHistograms);

	virtual ~KernelMatrixCalculator();

	void kernelMatrixGenerate();



};

#endif /* KERNELMATRIXCALCULATOR_H_ */
