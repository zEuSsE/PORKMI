/*
 * KernelMatrixCalculator.cpp
 *
 *  Created on: 30/gen/2012
 *      Author: andrea
 *   Description: Preso un file nel formato:
 *   			  (int) size
 *   			  (int) label
 *   			    .....
 *   			  (int) label
 *   			   rappresentante tutti gli esempi con relativa classe del nostro
 *   			   dataset, fornisce le funzioni per:
 *   			   + dividerlo in due parti di dimensione selezionabile -dataSetSplit()-
 *   			   + creare i dataSet per il kFold -kFold()-
 *   			   + leggere i file .set creati dalle funzioni precedenti -leggiFileSet()-
 *
 *   			   I file .set sono nel formato
 *   			   (int) index (int) label
 *   			   (int) index (int) label
 *   			   ......................
 */
#include <string>
#include <util/labeled-index.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>



using namespace std;
using namespace libpmk;

void creaTraingeTestSetDaKFold(string pathToDirectory);
void dataSetSplit(string labelsFile,int percentTrain,int percentTest,string pathToSave,string dataSetName);
void kFold(int k,string pathToSave,string dataSetName);
vector<LabeledIndex> leggiFileSET(string);  //passa da file.set a vector<labeledindex>
vector<vector<LabeledIndex*> > separaEsempiPerClasseDaFileTxt(string);



vector<vector < LabeledIndex* > > dataSetDivisoPerClassi;	//viene riempito dalla funzione separaEsempiPerClasse




int main(){
	//CREAZIONE DATASET PER ETH_80
	string pathToDataSetFormatoTXT="/home/andrea/Scrivania/PORKMI/ETH_80/ETH80_labels.txt";
	string saveDataSetAt="/home/andrea/Scrivania/PORKMI/ETH_80/";
	string nomeDataSet="ETH_80";
	dataSetSplit(pathToDataSetFormatoTXT,75,25,saveDataSetAt,nomeDataSet);
	kFold(3,saveDataSetAt,nomeDataSet);
	kFold(5,saveDataSetAt,nomeDataSet);
	kFold(10,saveDataSetAt,nomeDataSet);


	//CREAZIONE DATASET PER DS__101
/*	pathToDataSetFormatoTXT="/home/andrea/Scrivania/PORKMI/DS_101/DS_101_labels.txt";
	saveDataSetAt="/home/andrea/Scrivania/PORKMI/DS_101/";
	nomeDataSet="DS_101";
	dataSetSplit(pathToDataSetFormatoTXT,75,25,saveDataSetAt,nomeDataSet);
	kFold(3,saveDataSetAt,nomeDataSet);
	kFold(5,saveDataSetAt,nomeDataSet);
	kFold(10,saveDataSetAt,nomeDataSet);*/

//	creaTraingeTestSetDaKFold("/home/andrea/Scrivania/PORKMI/ETH_80/3Fold");
//	creaTraingeTestSetDaKFold("/home/andrea/Scrivania/PORKMI/ETH_80/5Fold");
//	creaTraingeTestSetDaKFold("/home/andrea/Scrivania/PORKMI/ETH_80/10Fold");

	creaTraingeTestSetDaKFold("/home/andrea/Scrivania/PORKMI/DS_101/3Fold");
	creaTraingeTestSetDaKFold("/home/andrea/Scrivania/PORKMI/DS_101/5Fold");
	creaTraingeTestSetDaKFold("/home/andrea/Scrivania/PORKMI/DS_101/10Fold");



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
			cout << "Indice:"<<index<<" Label:"<<label<< endl;
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



void dataSetSplit(string labelsFile,int percentTrain,int percentTest,string pathToSave,string dataSetName){

		dataSetDivisoPerClassi=separaEsempiPerClasseDaFileTxt(labelsFile);
		vector<LabeledIndex*> *classe;
		ofstream testSet ((pathToSave+"finalTestSet"+dataSetName+".set").c_str(), ios::out);
		//crea testSetFinale
		cout <<"Creo dataSet di Test Finale per "<<dataSetName<<endl;
		cout << "Numero Classi:"<< dataSetDivisoPerClassi.size()<<endl;
		for (int i = 0; i <((int) dataSetDivisoPerClassi.size()); i++) {
			classe=&(dataSetDivisoPerClassi.at(i));
			int percentualeClasse =(int) (((classe->size())*percentTest)/100);
			cout <<"Percentuale di test per classe "<<i<<" ="<<percentualeClasse<<endl;
			int out[percentualeClasse];
			int k;
			bool foundEqual;
			for (int j = 0; j < percentualeClasse ; ++j) {
				do{
					foundEqual=false;
					k=(int) rand()%(classe->size());
					int p=0;
					while (p<=j && (foundEqual==false) && (p<sizeof(out)) ) {
						if (out[p]==k) foundEqual=true;
						p++;
					}
				}while(foundEqual==true);
				out[j]=k;
				//Scrive nel file test.set e cancella gli elementi dal dataSet rimanente
				testSet << classe->at(k)->index<< " "<<classe->at(k)->label<<endl;
				classe->erase(classe->begin()+k);
			}
		}
		testSet.close();
		//crea TrainingSet con tutti gli esempi rimanenti
		cout  <<"Creo dataSet di Training Finale per "<<dataSetName<<endl;
		ofstream traingSet ((pathToSave+"trainingSet"+dataSetName+".set").c_str(), ios::out);
		for (int i = 0; i <((int) dataSetDivisoPerClassi.size()); ++i) {
			classe=&(dataSetDivisoPerClassi.at(i));
			for (int j = 0; j < classe->size() ; ++j) {
				traingSet << classe->at(j)->index<< " "<<classe->at(j)->label<<endl;
			}
		}
		traingSet.close();
		cout <<"File salvati in "<<pathToSave<<endl;
}

void kFold(int k,string pathToSave,string dataSetName){
	vector<vector < LabeledIndex* > > tmpDataSetDivisoPerClassi(dataSetDivisoPerClassi);
	cout <<endl<< "Creo kFold del dataSet"<<dataSetName<<" con k="<<k<<endl;
	int numeroEsempiPerClasse[tmpDataSetDivisoPerClassi.size()];
	for (int i = 0; i < tmpDataSetDivisoPerClassi.size(); ++i) {
		numeroEsempiPerClasse[i]=(int) ((tmpDataSetDivisoPerClassi.at(i).size())/k);
	}
	for (int i = 0; i < k; ++i) {
		//crea un file kFold alla volta
		char numstr[i];
		sprintf(numstr,"%d",i);
		char numstr2[k];
		sprintf(numstr2,"%d",k);
		string nomeFile=pathToSave+ numstr2 + "Fold/" +numstr2+ "FoldDataSet_"+ numstr+".set";
		ofstream kFoldDataSet(nomeFile.c_str(),ios::out);
		for (int j = 0; j <((int) tmpDataSetDivisoPerClassi.size()); ++j) {
			vector<LabeledIndex*> *classe=&(tmpDataSetDivisoPerClassi.at(j));
			if(i==k-1) numeroEsempiPerClasse[j]=classe->size();//l'ultimo fold prende tutti gli esempi rimanenti
			for (int n = 0; n < numeroEsempiPerClasse[j] ; ++n) {
				int v=(int) (rand()%(classe->size()));
				kFoldDataSet<<classe->at(v)->index<< " "<<classe->at(v)->label<<endl;
				classe->erase(classe->begin()+v);
			}
		}
	}
	cout << "File salvati in: "<<pathToSave<<endl;
}






vector<vector<LabeledIndex*> > separaEsempiPerClasseDaFileTxt(string pathENomeFile){

	vector<vector<LabeledIndex*> > classVector;
	vector<LabeledIndex*> classTmp;
	LabeledIndex* labIndtmp;
	ifstream myFile;
	int numImmagini;
	myFile.open(pathENomeFile.c_str());
	if (myFile.is_open()) {
		cout<<"Reading the file: "<<pathENomeFile<<endl;
		myFile>>numImmagini;
		int oldLabel,newLabel;
		myFile>>newLabel;
		oldLabel=newLabel;
		for(int i=0;i<=numImmagini;++i){
			if (myFile.eof()==true){
				newLabel=-1;
			}
			labIndtmp=new LabeledIndex;
			labIndtmp->index=i;
			labIndtmp->label=newLabel;
			if(newLabel==oldLabel){
				classTmp.push_back(labIndtmp);
			}
			else{
				cout << "Per Classe "<<oldLabel<<"inseriti "<<classTmp.size()<<" elementi."<<endl;
				classVector.push_back(classTmp);
				classTmp.clear();
				classTmp.push_back(labIndtmp);
				oldLabel=newLabel;
			}
			myFile>>newLabel;
		}
	}
	else cerr<<"\nFILE NON TROVATO: "<<pathENomeFile<<"\n";
	myFile.close();
	return classVector;
}


void creaTraingeTestSetDaKFold(string pathToDirectory){
	ifstream fin;
	  string dir, filepath;
	  DIR *dp;
	  struct dirent *dirp;
	  struct stat filestat;
	  dir=pathToDirectory;
	  dp = opendir( dir.c_str() );
	  cout <<"Avvio creazione dataSet Train Test per kFold: "<< pathToDirectory<<endl;
	    if (dp == NULL)
	      {
	      cout << "Error opening " << dir << endl;
	      }
	    else{
	    	vector<string> files;
			while ((dirp = readdir( dp ))){
				filepath = dir + "/" + dirp->d_name;
				// If the file is a directory (or is in some way invalid) we'll skip it
				if (stat( filepath.c_str(), &filestat )) continue;
				if (S_ISDIR( filestat.st_mode ))         continue;
				files.push_back(filepath);
			  }
			int swapVar=0;
			for (int i = 0; i < files.size(); ++i) {
				char numstr[i];
				sprintf(numstr,"%d",i);
				string pathDataSet=dir+"/dataSet"+numstr+"/";
				string pathDirNew="mkdir "+pathDataSet;
				system(pathDirNew.c_str());
				string trainingSetFile=pathDataSet+"TrainingSet.set";
				cout << trainingSetFile<<endl;
				ofstream trainingSet (trainingSetFile.c_str(),ios::out|fstream::trunc|fstream::binary);
				for (int j = 1; j < files.size(); ++j) {
					string file;
					file=files.at(j);
					ifstream tmp(file.c_str(),fstream::binary);
					trainingSet << tmp.rdbuf();
					tmp.close();
				}
				string testSetFile=pathDataSet+"testSet.set";
				ofstream testSet(testSetFile.c_str(),ios::out|fstream::trunc|fstream::binary);
				ifstream tmpTest(files[0].c_str(),fstream::binary);
				testSet << tmpTest.rdbuf();
				tmpTest.close();
				testSet.close();
				trainingSet.close();
				if (swapVar<files.size()){
					swapVar++;
					swap (files[0],files[swapVar]);
				}
			  }
			closedir( dp );
	    }


}

