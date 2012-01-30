/*
 * provaEsecuzione.cpp
 *
 *  Created on: 30/gen/2012
 *      Author: andrea
 */

#include <kernel/kernel-matrix.h>
#include <kernel/matrix.h>
#include <util/labeled-index.h>
#include <iostream>
#include <fstream>
#include <experiment/random-selector.h>
#include <vector>
#include <svm/svm.h>
#include <experiment/svm-experiment.h>



using namespace libpmk;
using namespace libpmk_util;
using namespace std;

int leggereLabeledIndexFileI( vector<int>* labeledIndexList,string pathENomeFile);

/*int main() {

	KernelMatrix* matriceKernel= new KernelMatrix();
	matriceKernel->ReadFromFile("/home/andrea/Scrivania/Progetto/DATASET_ETH80/GridSIFT/Kernel/kernelMatrix_eth80.ker");
	/*for(int i=0;i<matriceKernel->size();i++){
		for(int j=0; j<matriceKernel->size();j++){
		cout<<matriceKernel->at(i,j)<<" ";
		}
		cout<<"\n";
	}
	vector<int>* labels= new vector<int>();
	int numIm=leggereLabeledIndexFileI(labels,"/home/andrea/Scrivania/Progetto/DATASET_ETH80/ETH80_labels.txt" );
	//cout<<"\n\n" <<numIm;
	RandomSelector rS(*labels, 40);
	vector<LabeledIndex>* liv=new vector<LabeledIndex>();
	*liv=rS.GetTrainingExamples();
	for(vector<LabeledIndex>::iterator it = liv->begin(); it!=liv->end(); ++it) {
		cout<<(*it).index<<" "<<(*it).label<<"\n";
	}

	SVMExperiment* svme=new SVMExperiment(rS.GetTrainingExamples(), rS.GetTestingExamples(),*matriceKernel,0.000000000001);
	svme->Train();
	int numCorrect=svme->Test();
	cout<<"numCorrect= "<<numCorrect<<";\n Accuratezza:"<<svme->GetAccuracy();


}*/


int leggereLabeledIndexFileI( vector<int>* labeledIndexList,string pathENomeFile){

	int* labInd;
	ifstream myFile;
	int numImmagini;
	cout<<"Reading the file info: "<<pathENomeFile<<"\n";
	myFile.open(pathENomeFile.c_str());

	if (myFile.is_open()) {
		myFile>>numImmagini;
		//cout<< numImmagini<<"\n";
		for(int i=0;i<numImmagini;i++){

			labInd=new int();

			myFile>>*labInd;
			labeledIndexList->push_back(*labInd);

					//	 cout<<*labInd<<"\n";

		}
	}
	else cerr<<"\nFILE NON TROVATO: "<<pathENomeFile<<"\n";
	myFile.close();

	return numImmagini;
}
