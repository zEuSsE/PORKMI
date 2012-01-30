#include <string>
#include <util/labeled-index.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>


using namespace std;
using namespace libpmk;


void kFold(int);
void dataSetSplit(string,int,int);
vector<vector<LabeledIndex*> *>* separaEsempiPerClasse(string);



vector<vector<LabeledIndex*> *> *dataSetDivisoPerClassi;





int main(){
	dataSetSplit("/home/andrea/Scaricati/ETH80_labels.txt",75,25);
	kFold(10);
}








void dataSetSplit(string labelsFile,int percentTrain,int percentTest){

		dataSetDivisoPerClassi=separaEsempiPerClasse(labelsFile);
		vector<LabeledIndex*> *classe;
		ofstream testSet ("finalTestSet.set", ios::out);
		for (int i = 0; i <((int) dataSetDivisoPerClassi->size()); i++) {
			classe=dataSetDivisoPerClassi->at(i);
			cout << endl << "Scelta dei vettori per la classe " << i<< endl;
			int percentualeClasse =(int) ((classe->size())*percentTest)/100;
			int out[percentualeClasse];
			int k;
			bool foundEqual;
			for (int j = 0; j < percentualeClasse ; j++) {
				do{
					foundEqual=false;
					k=(int) rand()%(classe->size());
					int p=0;
					while ((p<j) && (foundEqual==false) && (p<sizeof(out)) ) {
						if (out[p]==k) foundEqual=true;
						p++;
					}
				}while(foundEqual==true);
				out[j]=k;
				//Scrive nel file test.set e cancella gli elementi dal dataSet rimanente
				cout << classe->at(k)->index<<" ";
				testSet << classe->at(k)->index<< " "<<classe->at(k)->label<<endl;
				classe->erase(classe->begin()+k);
			}
		}
		testSet.close();
}

void kFold(int k){
	string kFoldDataSetName="kFoldDataSet_";
	int numeroEsempiPerClasse[dataSetDivisoPerClassi->size()];
	for (int i = 0; i < dataSetDivisoPerClassi->size(); ++i) {
		numeroEsempiPerClasse[i]=(int) (dataSetDivisoPerClassi->at(i)->size())/10;
	}
	for (int i = 0; i < k; ++i) {
		//crea un file kFold alla volta
		char numstr[i];
		sprintf(numstr,"%d",i);
		ofstream kFoldDataSet((kFoldDataSetName+numstr+".set").c_str(),ios::out);
		for (int j = 0; j <((int) dataSetDivisoPerClassi->size()); j++) {
			vector<LabeledIndex*> *classe=dataSetDivisoPerClassi->at(j);
			for (int n = 0; n < numeroEsempiPerClasse[n] ; ++n) {
				int k=(int) rand()%(classe->size());
				kFoldDataSet<<classe->at(k)->index<< " "<<classe->at(k)->label<<endl;
				classe->erase(classe->begin()+k);
			}
		}
		kFoldDataSet.close();
	}

}






vector<vector<LabeledIndex*> *>* separaEsempiPerClasse(string pathENomeFile){

	vector<vector<LabeledIndex*> *> *classVector=new vector<vector<LabeledIndex*> *>;
	vector<LabeledIndex*> *classTmp=new vector<LabeledIndex *>;
	LabeledIndex* labIndtmp;
	ifstream myFile;
	int numImmagini;
	myFile.open(pathENomeFile.c_str());
	if (myFile.is_open()) {
		cout<<"Reading the file: "<<pathENomeFile<<"\n";
		myFile>>numImmagini;
		int oldLabel,newLabel;		//TODO occhio nel DB_101 oldLabel deve essere 0
		myFile>>newLabel;
	//	cout << newLabel;
		oldLabel=newLabel;
		for(int i=0;i<numImmagini;i++){
			labIndtmp=new LabeledIndex;
			labIndtmp->index=i;
			labIndtmp->label=newLabel;
		//	cout << "index="<<labIndtmp->index<<" label="<<labIndtmp->label<<endl;
			if(newLabel==oldLabel){
				classTmp->push_back(labIndtmp);
				//cout<< "Dimensione vettore classe:"<<classTmp->size();
			}
			else{
				classVector->push_back(classTmp);
				classTmp=new vector<LabeledIndex *>;
				classTmp->push_back(labIndtmp);
				oldLabel=newLabel;
			}
			myFile>>newLabel;
		}
	}
	else cerr<<"\nFILE NON TROVATO: "<<pathENomeFile<<"\n";
	myFile.close();
	return classVector;
}
