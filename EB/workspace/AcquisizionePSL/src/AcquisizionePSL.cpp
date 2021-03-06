//============================================================================
// Name        : AcquisizionePSL.cpp
// Author      : Andrea Zerbini
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <util/labeled-index.h>
#include <iostream>
#include <point_set/point-set-list.h>
#include <point_set/point.h>
#include <point_set/point-set.h>
#include <point_set/mutable-point-set-list.h>
#include <fstream>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <util/distance-computer.h>
#include <stdlib.h>
#include <stdio.h>


string const _FileFeatures="features128.mat";



using namespace std;
using namespace libpmk;
//using namespace libpmk_util;

struct PSLClass{
public:
	PointSetList* PSL;
	string nomeClasse;
};
struct AssociationClass{
public:
	int indexClass;
	string nomeClasse;

};

void captureVector(vector<float>* vettoreAppoggio, char* vettoreStringa);
void stampaPointSet(PointSet* immagine);
int componiPointSet(string address,PointSet* immagineInsiemePunti); //ritorna il numero di punti letti
int leggerePointSetList(MutablePointSetList* PSL,string directorySource); //ritorna il numero di pointSet letti (cioè il numero di immagini, cioè il numero di "*.features.mat" files)
void stampaPSL(PointSetList* PSL);
void salvarePointSetList(PointSetList* PSL, string destinationDir, string nomeClasse);
int leggereInteroDataset(string directoryPrincipale,vector<PSLClass*>* dataSetVector); //ritorna il numero di PSL letti (cioè il numero di sotto-Directory)
void salvareInteroDataset(vector<PSLClass*>* dataSetVector, string directoryDestination);
void ConcatenaPSLs(MutablePointSetList* dataSetUnico,MutablePointSetList* PSLAggiuntivo);
void salvareInteroDatasetInUnFile(vector<PSLClass*>* dataSetVector, string directoryDestination);
int generaLeClassInfo(vector<PSLClass*>* dataSet,vector<LabeledIndex*>* labeledIndexList, vector<AssociationClass*>* associationClassList);
void salvaClassInfo(int numImmaginiTotali,vector<LabeledIndex*>* labeledIndexList, vector<AssociationClass*>* associationClassList, string directoryDestination);
int leggereLabeledIndexFile( vector<LabeledIndex*>* labeledIndexList,string pathENomeFile);
int LeggiEScriviDatasetInUnPSL(string directoryPrincipale,string directoryDestination);
double calcolaMinDistanzaTraPoints(string directoryDelPSL);


/*int main() {


	//int numImmaginiTotali= LeggiEScriviDatasetInUnPSL("/home/andrea/Scrivania/Progetto/DATASET_101/sift","/home/andrea/Scrivania/Progetto/DATASET_101/PSL");
/*
	vector<LabeledIndex*>* labeledIndexList= new vector<LabeledIndex*>();
	leggereLabeledIndexFile(labeledIndexList,"/home/andrea/Scrivania/Progetto/DATASET_101/PSL/Classi.txt");





	return 0;

}*/

void stampaPointSet(PointSet* immagine){
	for(int i=0;i<immagine->size();i++){
		for(int j=0; j<immagine->point(i).point_dim();j++){
			cout<<immagine->point(i).feature(j)<<";";
		}
		cout<<"\n";

	}
	return;

}

int componiPointSet(string address,PointSet* immagineInsiemePunti){

	Point* puntoAppoggio= new Point(128);

		 ifstream myReadFile;
		 myReadFile.open(address.c_str());
		 char vettoreStringa[2048];
		 int j=0;
		 char stringaProssimoPasso[2048];

		 if (myReadFile.is_open()) {

			 if(!myReadFile.eof())  myReadFile>>stringaProssimoPasso;
		 while (!myReadFile.eof()) {

			 for(int kk=0;kk<2048;kk++){
				 vettoreStringa[kk]=stringaProssimoPasso[kk];
			 }


		    myReadFile >> stringaProssimoPasso;




		    vector<float>* vettoreAppoggio= new vector<float>();

		    captureVector(vettoreAppoggio, vettoreStringa);

		    int i=0;
		    for (vector<float>::iterator it = vettoreAppoggio->begin(); it!=vettoreAppoggio->end(); ++it) {
		    //    cout << *it << "; ";
		    	float temp=*it;
		        puntoAppoggio->set_feature(i,temp); //fine lettura della singola feature---
		       // cout<<puntoAppoggio->feature(i)<<";";
		        //cout.flush();


		        i++;
		    }
		    j++;
		   // cout<<"\n";

		    immagineInsiemePunti->add_point(*puntoAppoggio);//fine lettura del singolo point (point:vettore di features)---


		}
		// immagineInsiemePunti->set_point_dim(128); //Dimensione di un SINGOLO POINT!
		// cout<<"\n point_dim():"<<immagineInsiemePunti->point_dim()<<"\n";
		 //cout<<"\n size():"<<immagineInsiemePunti->size()<<"\n";

		myReadFile.close();

		}
		 // fine lettura del singolo file immagine (pointSet:insieme di point)---
		 return j;

}


void captureVector(vector<float>* vettoreAppoggio, char* vettoreStringa){


		    int pointPassato=0;//no
		    int i=0;
		    int posNegative=+1; //1 se positivo. -1 se negativo.
		    float pastPoint=1;
		    float valoreAttuale=0;
				while(i< 2048 && vettoreStringa[i]!=0){
					//cout<<"ENTRATO----"<<endl;

					if(vettoreStringa[i]=='-'){i++; posNegative=-1;}

					if(!((vettoreStringa[i]<58 && vettoreStringa[i]>47)|| vettoreStringa[i]==44 || vettoreStringa[i]==46))
								cerr<<"è stato calcolato un valore fuori dal range nel file vettore-stringa";

					if(pointPassato==0){
						if(vettoreStringa[i]=='.')
							pointPassato=1;
						else{
							if(vettoreStringa[i]==','|| vettoreStringa[i]==0){
														//cout<<"\n Numero percepito: "<< valoreAttuale<<"\n";
														posNegative=+1;

														vettoreAppoggio->push_back(valoreAttuale);
														pointPassato=0;
														valoreAttuale=0;
														pastPoint=1;


													}
							else{
								valoreAttuale*=10;
								valoreAttuale+=posNegative*(vettoreStringa[i]-48);
								//cout<<" ";
							}
						}
					}
					else{

						if(vettoreStringa[i]==','|| vettoreStringa[i]==0){
							//cout<<"\n Numero percepito: "<< valoreAttuale<<"\n";
							posNegative=+1;

							vettoreAppoggio->push_back(valoreAttuale);
							pointPassato=0;
							valoreAttuale=0;
							pastPoint=1;


						}
						else{
							pastPoint/=10;
							float temp= (pastPoint*(vettoreStringa[i]-48));
							valoreAttuale+=posNegative*(temp);
							//cerr<<"\n past Point= "<<pastPoint<<" valoreAttuale= "<<valoreAttuale<<"vettoreStringa[i]= "<<vettoreStringa[i]<<"\n";
						}

					}
					//cout<<"\n Numero percepito: "<< valoreAttuale<<"\n";




		    	//cout<<i<<"th"<<" "<<vettoreStringa[i]<<"\n";
		    	i++;


		 }

		vettoreAppoggio->push_back(valoreAttuale);


}

int leggerePointSetList(MutablePointSetList* PSL,string directoryPSL){
	int numImmaginiLette=0;
	PointSet* immagineInsiemePunti;
//	MutablePointSetList* PSL= &PSL1;
	DIR *dp;
	    struct dirent *dirp;
	    if((dp  = opendir(directoryPSL.c_str())) == NULL) {
	        cout << "Error(" << errno << ") opening " << directoryPSL << endl;
	        return errno;
	    }

	    while ((dirp = readdir(dp)) != NULL) {
	    	string name=dirp->d_name;
	    	cout<<"subdir..readingFile: "<<name<<"   ...\n";

	       if( dirp->d_type ==DT_REG){    //d_type=DT_REG       file.   DT_DIR directory


	    	   if(name.find(_FileFeatures,0)!=string::npos){//E' un file Features.mat
	    		   cout<<"OK...\n";


	    		 //  cout<<"\nSONO ENTRATO..\n";
	    		 int numPuntiLetti=0;

	    		   	 immagineInsiemePunti = new PointSet(128);
	    		   	 string directoryTotale=directoryPSL+"/"+name;
	    		   	 numPuntiLetti=componiPointSet(directoryTotale,immagineInsiemePunti);
	    		   	// cout<<"\nimmagineInsiemePuntiAddress:"<<immagineInsiemePunti<<"\n";
	    		   	 //cout<<"\n-----PATH: "<<directoryTotale<<"\n";
	    		   	// stampaPointSet(immagineInsiemePunti);
	    		   	 PSL->add_point_set(*immagineInsiemePunti);
	    		   	 numImmaginiLette++;
	    	   }

	       }
	    }
	    closedir(dp);
	    return numImmaginiLette;

}


void stampaPSL(PointSetList* PSL){

	cout<<"\nStampa del PSL(dei pointSetList):\n";
	for(int k=0;k<PSL->point_set_size();k++){
		cout<<"\n----STAMPA DEL POINT_SET "<<k<<"esimo\n";

		for(int i=0;i<PSL->point_set(k).size();i++){
				for(int j=0; j<PSL->point_set(k).point(i).point_dim();j++){
					cout<<PSL->point_set(k).point(i).feature(j)<<";";
				}
				cout<<"\n";

			}
			cout<<"-------------------------------------------------\n";



	}



}





void salvarePointSetList(PointSetList* PSL, string destinationDir,string nomeClasse){

	string totalDirectory= destinationDir+"/"+nomeClasse+".psl";
	//stampaPSL(PSL);

	PSL->WriteToFile(totalDirectory.c_str());



}

int leggereInteroDataset(string directoryPrincipale,vector<PSLClass*>* dataSetVector){

	int numCartelleAnalizzate=0;
	MutablePointSetList* tempPSL;
	PSLClass* tempPSLC;

	DIR *dp;
		    struct dirent *dirp;
		    if((dp  = opendir(directoryPrincipale.c_str())) == NULL) {
		        cout << "Error(" << errno << ") opening " << directoryPrincipale << endl;
		        return -1;
		    }

		    while ((dirp = readdir(dp)) != NULL) {
		    	string name=dirp->d_name;
		        cout<<"DIR..reading File or Dir: "<<name<<"\n";
		       if( (dirp->d_type ==DT_DIR) && (name.find("..",0)==string::npos) && (name.find(".DS_Store",0)==string::npos)&& (name.compare(".")!=0)){    //d_type=DT_REG       file.   DT_DIR directory
		    	   string subDirectory= directoryPrincipale+"/"+name;

		    	   tempPSL =new MutablePointSetList();
		    	   leggerePointSetList(tempPSL,subDirectory);
		    	   tempPSLC= new PSLClass();
		    	   tempPSLC->PSL=tempPSL;
		    	   tempPSLC->nomeClasse=name;
		    	   dataSetVector->push_back(tempPSLC);
		    	   numCartelleAnalizzate++;
		    	  // cout<<"\ntempPSLC->PSL: "<<tempPSLC->PSL<<"\n";
		    	   cout.flush();
		    	  // stampaPSL(tempPSLC->PSL); //FIN QUI FUNZIONA
		    	   cout.flush();
		       }
		    }



		    return numCartelleAnalizzate;
}

void salvareInteroDataset(vector<PSLClass*>* dataSetVector, string directoryDestination){
	cout<<"\nSize: "<< dataSetVector->size();

	for(vector<PSLClass*>::iterator it = dataSetVector->begin(); it!=dataSetVector->end(); ++it) {
		cout.flush();

			      //  cout << *it << "; ";
			    	PSLClass* temp=*it;


	salvarePointSetList((temp)->PSL,directoryDestination, (temp)->nomeClasse);
	//stampaPSL((temp)->PSL);

	}
}

void salvareInteroDatasetInUnFile(vector<PSLClass*>* dataSetVector, string directoryDestination){
	//cout<<"\nSize: "<< dataSetVector->size();
	cout<<"\nSaving the dataset in the following directory: "<<directoryDestination<<"\n";
	PointSetList* PSLTemp;
	MutablePointSetList* dataSetUnico= new MutablePointSetList();
	int indexClass=1;




	for(vector<PSLClass*>::iterator it = dataSetVector->begin(); it!=dataSetVector->end(); ++it) {
		cout.flush();

			      //  cout << *it << "; ";
			    	PSLClass* temp=*it;
			    	PSLTemp=(temp)->PSL;
			    	ConcatenaPSLs(dataSetUnico,(MutablePointSetList*)PSLTemp);

	}

	salvarePointSetList(dataSetUnico,directoryDestination, "dataSetIntero");
	//stampaPSL(dataSetUnico);
}


void ConcatenaPSLs(MutablePointSetList* dataSetUnico,MutablePointSetList* PSLAggiuntivo){


	for(int i=0; i< PSLAggiuntivo->point_set_size();i++){

	dataSetUnico->add_point_set(PSLAggiuntivo->point_set(i));

	}

}

int generaLeClassInfo(vector<PSLClass*>* dataSet,vector<LabeledIndex*>* labeledIndexList, vector<AssociationClass*>* associationClassList){

PointSetList* PSLTemp;
int numPSL=0;
int numImmaginiTotali=0;
LabeledIndex* labInd;
AssociationClass* assCla;


	for(vector<PSLClass*>::iterator it = dataSet->begin(); it!=dataSet->end(); ++it) {




				    	PSLClass* temp=*it;
				    	PSLTemp=(temp)->PSL;
				    	for(int i=0;i<PSLTemp->point_set_size();i++){
				    		labInd= new LabeledIndex();
				    		labInd->index=numImmaginiTotali;
				    		labInd->label=numPSL;
				    		labeledIndexList->push_back(labInd);
				    	//	cerr<<"\nindex: "<<labInd->index<<"label: "<<labInd->label;

				    		numImmaginiTotali++;
				    	}
				    	assCla= new AssociationClass();
				    	assCla->indexClass=numPSL;
				    	assCla->nomeClasse= temp->nomeClasse;
				    	associationClassList->push_back(assCla);


				    	numPSL++;
		}
	return numImmaginiTotali;

}

void salvaClassInfo(int numImmaginiTotali, vector<LabeledIndex*>* labeledIndexList, vector<AssociationClass*>* associationClassList, string directoryDestination){


		ofstream myFile;
		string totalDirectory=directoryDestination+"/Classi.txt";
		cout<<"\nSaving Classes info in directory: "<<directoryDestination<<"\n";

		myFile.open(totalDirectory.c_str());
		 if (myFile.is_open()) {
			 myFile<<numImmaginiTotali<<"\n";
			// cout<<numImmaginiTotali<<"\n";
			 for(vector<LabeledIndex*>::iterator it = labeledIndexList->begin(); it!=labeledIndexList->end(); ++it) {
				 myFile<< (*it)->label<<"\n";
				// cout<<(*it)->label<<"\n";

			 }
		 }
		myFile.close();

		totalDirectory=directoryDestination+"/AssociationClass.txt";

				myFile.open(totalDirectory.c_str());
				 if (myFile.is_open()) {
					 for(vector<AssociationClass*>::iterator it = associationClassList->begin(); it!=associationClassList->end(); ++it) {
						 myFile<< (*it)->indexClass<<" "<<(*it)->nomeClasse<<"\n";
					 }
				 }
				myFile.close();
}


int leggereLabeledIndexFile( vector<LabeledIndex*>* labeledIndexList,string pathENomeFile){

	LabeledIndex* labInd;
	ifstream myFile;
	int numImmagini;
	cout<<"Reading the file info: "<<pathENomeFile<<"\n";
	myFile.open(pathENomeFile.c_str());

	if (myFile.is_open()) {
		myFile>>numImmagini;
		cout<< numImmagini<<"\n";
		for(int i=0;i<numImmagini;i++){

			labInd=new LabeledIndex();
			labInd->index=i;
			myFile>>labInd->label;
			labeledIndexList->push_back(labInd);

						 cout<<labInd->label<<"\n";

		}
	}
	else cerr<<"\nFILE NON TROVATO: "<<pathENomeFile<<"\n";
	myFile.close();

	return numImmagini;
}


int LeggiEScriviDatasetInUnPSL(string directoryPrincipale,string directoryDestination){

	vector<LabeledIndex*>* labeledIndexList= new vector<LabeledIndex*>();
		vector<AssociationClass*>* associationClassList= new vector<AssociationClass*>();
		int numImmaginiTotali;



		vector<PSLClass*>* dataSet= new vector<PSLClass*>();
		leggereInteroDataset(directoryPrincipale,dataSet);
		salvareInteroDatasetInUnFile(dataSet,directoryDestination);
		numImmaginiTotali= generaLeClassInfo(dataSet,labeledIndexList, associationClassList);
		salvaClassInfo(numImmaginiTotali,labeledIndexList, associationClassList, directoryDestination);

		return numImmaginiTotali;


}



double calcolaMinDistanzaTraPoints(string directoryDelPSL){

	PointSetList* psl= new MutablePointSetList();
		((MutablePointSetList*) psl)->ReadFromFile(directoryDelPSL.c_str());
		cout<<"PointSetSize: "<< psl->point_set_size()<<"\nPointDim: "<<psl->point_dim()<<"\nPointSize: "<<psl->point_size();
		double minDistance;
		double distanzaAttuale;

		DistanceComputer* distanzaCalcolatore= new L1DistanceComputer();
		minDistance=distanzaCalcolatore->ComputeDistance(psl->point(0),psl->point(1));
		for(int i=psl->point_size()-2; i>=0;i--){
			 cout.clear();cout<<"\n esecuzione"<<i<<", MIN DISTANZA: "<<minDistance;cout.flush();
			for(int j=i+1;j<psl->point_size();j++){




				distanzaAttuale=distanzaCalcolatore->ComputeDistance(psl->point(i),psl->point(j));

				if (distanzaAttuale<minDistance && distanzaAttuale!=0) minDistance= distanzaAttuale;

			}

		}
		cout<<"\n\n\n\n\nBABAAAAM....\n";
		cerr<<"MIN DISTANZA: "<<minDistance;
		cout<<"\n MIN DISTANZA: "<<minDistance;

		return minDistance;


}

