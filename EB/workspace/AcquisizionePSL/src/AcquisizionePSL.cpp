//============================================================================
// Name        : AcquisizionePSL.cpp
// Author      : Andrea Zerbini
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <point_set/point-set-list.h>
#include <point_set/point.h>
#include <point_set/point-set.h>
#include <point_set/mutable-point-set-list.h>
#include <fstream>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

string const _FileFeatures="features.mat";



using namespace std;
using namespace libpmk;

void captureVector(vector<float>* vettoreAppoggio, char* vettoreStringa);
void stampaPointSet(PointSet* immagine);
int componiPointSet(string address,PointSet* immagineInsiemePunti); //ritorna il numero di punti letti
int leggerePointSetList(MutablePointSetList* PSL,string directorySource); //ritorna il numero di pointSet letti (cioè il numero di immagini, cioè il numero di "*.features.mat" files)
void stampaPSL(PointSetList* PSL);
void salvarePointSetList(PointSetList* PSL, string destinationDir, string nomeClasse);


int main() {

	int numImmagini=0;
	string subDirectory="/home/andrea/Scrivania";
	string directoryDestination="/home/andrea/Scrivania/DestinationDirectoryPSLExample";
	 PointSetList* PSL=new MutablePointSetList();

	 numImmagini=  leggerePointSetList((MutablePointSetList*)PSL,subDirectory);
	 cout<<"\n Numero immagini lette: "<<numImmagini;
	 //stampaPSL(PSL);

	salvarePointSetList(PSL,directoryDestination, "classeProva");

	MutablePointSetList* prova= new MutablePointSetList();
	prova->ReadFromFile("/home/andrea/Scrivania/DestinationDirectoryPSLExample/classeProva.psl");
	stampaPSL(prova);

	return 0;

}

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
		 myReadFile.open("/home/andrea/Scrivania/Esempio.jpg.features.mat");
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

	DIR *dp;
	    struct dirent *dirp;
	    if((dp  = opendir(directoryPSL.c_str())) == NULL) {
	        cout << "Error(" << errno << ") opening " << directoryPSL << endl;
	        return errno;
	    }

	    while ((dirp = readdir(dp)) != NULL) {
	    	string name=dirp->d_name;
	        cout<<name<<"\n";
	       if( dirp->d_type ==DT_REG){    //d_type=DT_REG       file.   DT_DIR directory


	    	   if(name.find(_FileFeatures,0)!=string::npos){//E' un file Features.mat


	    		 int numPuntiLetti=0;

	    		   	 PointSet* immagineInsiemePunti= new PointSet(128);
	    		   	 string directoryTotale=directoryPSL+"/"+name;
	    		   	 numPuntiLetti=componiPointSet(directoryTotale,immagineInsiemePunti);
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

	PSL->WriteToFile(totalDirectory.c_str());



}
