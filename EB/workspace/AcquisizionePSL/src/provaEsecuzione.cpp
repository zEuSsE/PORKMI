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
#include <sys/time.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>



using namespace libpmk;
using namespace libpmk_util;
using namespace std;

int leggereLabeledIndexFileI( vector<int>* labeledIndexList,string pathENomeFile);
vector<LabeledIndex > leggiFileSET(string dataSetPath);
double faiProvaSvmTornaAccuracy(string kernelMatrix, string trainingSet, string testSet);
void faiProveSvmSuCartella(string directoryDoveSonoIKernelMatrix, string pathTrainSet, string pathTestSet);

int main() {


	faiProveSvmSuCartella("/home/andrea/Scrivania/Progetto/DATASET_101/KernelMatrix","/home/andrea/Scrivania/Progetto/DATASET_101/suddivisioneDataset/trainingSetDS_101.set","/home/andrea/Scrivania/Progetto/DATASET_101/suddivisioneDataset/finalTestSetDS_101.set");




}


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



vector<LabeledIndex > leggiFileSET(string dataSetPath){
	vector<LabeledIndex > dataSet;
	LabeledIndex labeledIndextmp;
	ifstream dataSetFile (dataSetPath.c_str(), ios::in);
	if (dataSetFile.is_open()){
		int index;
		int label;
		dataSetFile >> index;
		dataSetFile >> label;
		while (dataSetFile.eof()!=true){
			//cout << "Indice:"<<index<<" Label:"<<label<< endl;
			labeledIndextmp.index=index;
			labeledIndextmp.label=label;
			dataSet.push_back(labeledIndextmp);
			dataSetFile >> index;
			dataSetFile >> label;
		}
	}

	else cout<< endl <<"File non trovato"<< endl;


	return dataSet;
}

double faiProvaSvmTornaAccuracy(string kernelMatrix, string trainingSet, string testingSet){


	cout<<"\n"<<kernelMatrix<<"\n";
	struct timeval start, end;

		long mtime, seconds, useconds;



	KernelMatrix* matriceKernel= new KernelMatrix();
		matriceKernel->ReadFromFile(kernelMatrix.c_str());

		/*
		vector<int>* labels= new vector<int>();
		int numIm=leggereLabeledIndexFileI(labels,"/home/andrea/Scrivania/Progetto/DATASET_ETH80/ETH80_labels.txt" );
		//cout<<"\n\n" <<numIm;
		RandomSelector rS(*labels, 40);

		vector<LabeledIndex>* liv=new vector<LabeledIndex>();
		*liv=rS.GetTrainingExamples();
		*/
		vector<LabeledIndex > trainSet=leggiFileSET(trainingSet);
		vector<LabeledIndex > testSet=leggiFileSET(testingSet);


		SVMExperiment* svme=new SVMExperiment(trainSet, testSet,*matriceKernel,0.000000000001);
		svme->Train();
		gettimeofday(&start, NULL);
		int numCorrect=svme->Test();
		gettimeofday(&end, NULL);

		cout<<"numCorrect= "<<numCorrect<<";\n Accuratezza:"<<svme->GetAccuracy();
		seconds  = end.tv_sec  - start.tv_sec;
		useconds = end.tv_usec - start.tv_usec;
		mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
		cout<<endl;
		printf("Elapsed time: %ld milliseconds ", mtime);
		cout<<"\n microsecond: "<<useconds<<"\n";
		cout<<"\n second: "<<seconds<<"\n";

		return svme->GetAccuracy();

}


void faiProveSvmSuCartella(string directoryDoveSonoIKernelMatrix, string pathTrainSet, string pathTestSet){

	string pathKer;
	char* b=".ker";
	DIR *dp;
	struct dirent *dirp;

			if((dp  = opendir(directoryDoveSonoIKernelMatrix.c_str())) == NULL) {
		        cout << "Error(" << errno << ") opening " << directoryDoveSonoIKernelMatrix << endl;
		        return;
			}

		    while ((dirp = readdir(dp)) != NULL) {
		    	string name=dirp->d_name;
		    	cout<<"\nreadingFile: "<<name<<"   ...\n";

		       if( dirp->d_type ==DT_REG){    //d_type=DT_REG       file.   DT_DIR directory


		    	   if(name.find(b,0)!=string::npos){//E' un file Features.mat
		    		   cout<<"OK...\n";

		    		   pathKer=directoryDoveSonoIKernelMatrix+"/"+name;

		    		   faiProvaSvmTornaAccuracy(pathKer,
		    		   							pathTrainSet,
		    		   							pathTestSet);


		    	   }
		       }
		    }







}
