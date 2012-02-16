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
	firsPiramidDone=1;
	nameFile=name;
	vectorMRH=multiResolutionHistograms;
	for ( int i = 0; i < vectorMRH.size(); i++) {
				for (int j = 0; j <= i; j++) {

					this->kernelMatrix->at(i,j)=0;
				}
	}
}

KernelMatrixCalculator::KernelMatrixCalculator(string destinazionePath,string nomeFileDestinazione, int kernelDimension){
	pathDestination=destinazionePath;
		nameFile=nomeFileDestinazione;
		firsPiramidDone=0;
		kernelMatrix=new KernelMatrix(kernelDimension);

		/*for ( int i = 0; i < vectorMRH.size(); i++) {
						for (int j = 0; j <= i; j++) {

							this->kernelMatrix->at(i,j)=0;
						}
			}*/

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

KernelMatrix* KernelMatrixCalculator::kernelMatrixIncrementAndReturnKernel(){

	cout << "Inizio Generazione Matrice Kernel Incrementale"<< endl;

		int size=vectorMRH.size();

		BinWeightScheme binWeightScheme=BIN_WEIGHT_GLOBAL; //TODO  capire che è sto BinWeightScheme
		double similarity;
		cout<<"\n vectorMRH size: "<<vectorMRH.size();
		for ( int i = 0; i < ((int) vectorMRH.size()); i++) {
			for (int j = 0; j <= i; j++) {

				similarity=PyramidMatcher::GetPyramidMatchSimilarity
						(*(vectorMRH[i]),*(vectorMRH[j]),binWeightScheme);
				if(i==34 && j==17){ cout<<" in debug_mode:similarity di "<<i<<"; "<<j<<" ::"<<similarity<<"\n";}

				cout.flush();
				if(firsPiramidDone==0){this->kernelMatrix->at(i,j)=similarity;}
				else{	this->kernelMatrix->at(i,j)+=similarity;}
			//			this->kernelMatrix->at(j,i)=similarity;}
				if(i==34 && j==17) {cout<<"\n ----- similarity aggiornata: "<<this->kernelMatrix->at(i,j)<<"\n";}
				cout.flush();

			}
			if (i%200==0) cout << "Finita riga: "<< i <<endl;
		}
		firsPiramidDone=1;

		return this->kernelMatrix;




}

void KernelMatrixCalculator::saveKernelMatrix(){

	cout << "Inizio Generazione Matrice Kernel"<< endl;
		string pathTotale= pathDestination+"/"+nameFile+".ker";
		ofstream kernelMatrix (pathTotale.c_str(), ios::out| ios::binary);
		int size=vectorMRH.size();
		kernelMatrix.write((char *) &size, sizeof( size ));
		BinWeightScheme binWeightScheme=BIN_WEIGHT_GLOBAL; //TODO  capire che è sto BinWeightScheme

		for ( int i = 0; i < vectorMRH.size(); i++) {
			for (int j = 0; j <= i; j++) {


				kernelMatrix.write((char *) &this->kernelMatrix->at(i,j), sizeof( this->kernelMatrix->at(i,j) ));
			}
			if (i%200==0) cout << "Finita riga: "<< i <<endl;
		}
		kernelMatrix.close();
		cout << "Matrice di Kernel salvata in "<<pathTotale << endl;

}









