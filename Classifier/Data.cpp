//
//  Data.cpp
//  Classifier
//
//  Created by Léa Gand on 18/11/2019.
//

#include "Data.h"

Data::Data()
{
    _nbSamples = 0;
    _nbFeatures = 0;
}

void Data::load(string filename) //Open the file
{
    
    ifstream digitFile(filename);  //Ouverture d'un fichier en lecture
    //"/Users/leagand/Desktop/Homework/digitAppr.svm"
    
    if (digitFile)
    {
        string line; //Une variable pour stocker les lignes lues
        int i = 0;

        while (getline(digitFile, line)) //Tant qu'on n'est pas ‡ la fin, on lit
        {
            if(i==0)
            {
                _nbSamples = stoi(line);
               // cout << "Sample number : " << _nbSamples << endl;
            }
            else if(i==1)
            {
                _nbFeatures = stoi(line);
            }
            else{
                _data.push_back(line);
               
            }
            i++;
        }
        
        //Display the data
        for(int j = 0; j < _nbSamples; j++){
             //cout << "Line " << j+1 << " : \n" << _data[j] << endl;
        }
        
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
}



int Data::getNbSamples()
{
    return _nbSamples;
}


void Data::add() //Add a sample
{
    
}

string toString()
{
    return 0;
}
