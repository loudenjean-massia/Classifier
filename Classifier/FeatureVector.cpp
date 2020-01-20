//
//  FeatureVector.cpp
//  Classifier
//
//  Created by Léa Gand on 18/11/2019.
//
#include "FeatureVector.h"
using std::string;
using std::ifstream;
using std::vector;
using std::cout;
using std::stringstream;
using std::endl;


/**
 @brief FeatureVector constructor
*/
FeatureVector::FeatureVector(): _norme(0), _vector()
{
    
}

//FeatureVector::~FeatureVector()
//{
//
//}

/**
 @brief This method allows to split the lines of the data file (each sample)
 @param chaine   ??????
 @param delimiter  A char to delimit each sample of the data file
 @param elements A vector of element to store a sample
*/
void FeatureVector::splitLine(const string &chaine, char delimiter, std::vector<string> &elements){
    
    stringstream ss(chaine);
    string sousChaine;
    
    while(getline(ss,sousChaine, delimiter)){
        elements.push_back(sousChaine);
    }
}

/**
 @brief This method allows to get only the vector of features
 @param data The data file of Data type
 @param lineNb Int representing the number of line
*/
void FeatureVector::vector(Data& data, int lineNb)
{
   if (lineNb < data.getNbSamples())
   {
        std::vector<string> features;
        splitLine(data._data[lineNb], ' ', features);
        for(int i = 1; i < features.size(); i++)
        {
            _vector.push_back(stof(features[i].c_str()));
            
        }
   }
   else
   {
        cout << "This sample doesn't exit" << endl;
   }
    
}

/**
 @brief This method allows to get the vector norme
 @return _norme
*/
float FeatureVector::getNorme()
{
    return _norme;
}

/**
 @brief This method allows to get the size of a vector of feature
 @return 70
*/
int FeatureVector::getSize()
{
    return 70;
}

/**
 @brief This method allows to get the vector
 @return _vector
*/
vector<float> FeatureVector::getVector() const 
{
    return _vector;
}


/**
 @brief This method allows to get only the vector of features
 @param data The data file of Data type
 @param lineNb Int representing the number of line
*/
void FeatureVector::scale()
{
    float max = _vector[0];
    float min = _vector[0];
    for (int i = 0; i < 70; i++)
    {
        if (_vector[i] > max)
        {
            max = _vector[i];
        }
        if (_vector[i] < min)
        {
            min = _vector[i];
        }
    }
}

float FeatureVector::norme()
{
    float norme = 0;
    for (int i = 0; i < _vector.size(); i++)
    {
        norme += _vector[i] * _vector[i];
    }
    norme = sqrt(norme);
    return norme;
}
