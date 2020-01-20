//
//  Data.cpp
//  Classifier
//
//  Created by Léa Gand on 18/11/2019.
//

#include "Data.h"


/**
 @brief Data constructor
*/
Data::Data()
{
    _nbSamples = 0;
    _nbFeatures = 0;
}

/**
 @brief This method allows to load the file
 @param filename String reprenseting the name of the file to manage
*/
void Data::load(string filename) //Open the file
{
    
    ifstream digitFile(filename);
    
    if (digitFile)
    {
        string line;
        int i = 0;

        while (getline(digitFile, line))
        {
            if(i==0)
            {
                _nbSamples = stoi(line);
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
        
//        for(int j = 0; j < _nbSamples; j++){
//             //cout << "Line " << j+1 << " : \n" << _data[j] << endl;
//        }
//        
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
}


/**
 @brief This method allows to get the number of samples
 @return _nbSamples
*/
int Data::getNbSamples()
{
    return _nbSamples;
}


//void Data::add() 
//{
//    
//}

//string toString()
//{
//    return 0;
//}
