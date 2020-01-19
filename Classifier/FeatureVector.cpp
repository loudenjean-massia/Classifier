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

FeatureVector::FeatureVector(): _norme(0), _vector(), _scalar(0)
{
    
}

FeatureVector::~FeatureVector()
{
    
}

void FeatureVector::splitLine(const string &chaine, char delimiteur, std::vector<string> &elements){
    
    stringstream ss(chaine);
    string sousChaine;
    
    while(getline(ss,sousChaine, delimiteur)){
        elements.push_back(sousChaine);
    }
}

void FeatureVector::vector(Data& data, int lineNb)
{
   if (lineNb < data.getNbSamples())
   {
        std::vector<string> features;
        splitLine(data._data[lineNb], ' ', features);
        for(int i = 1; i < features.size(); i++)
        {
            _vector.push_back(stof(features[i].c_str()));
            //cout << "This the feature " << i << " of the sample " << lineNb << ": " << _vector[i-1] << endl;
        }
   }
   else
   {
        cout << "This sample doesn't exit" << endl;
   }
    
}

float FeatureVector::getNorme()
{
    return _norme;
}

int FeatureVector::getSize()
{
    return 70;
}

vector<float> FeatureVector::getVector() const 
{
    return _vector;
}

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
   
    /*for (int i = 0; i < 70; i++)
    {
        if (_vector[i] > 1)
        {
            _vector[i] = ;
        }
    }*/
    //cout << "The max is " << max << " and the min is " << min << endl;
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
    //cout << "La norme est : " << _norme << endl;
}

/*long double FeatureVector::scalarProduct(FeatureVector featureA)
{
    long double scalar = 0;
    std::vector<float> vectorA(70);
    vectorA = featureA.getVector();
    
    for (int i = 0; i < _vector.size(); i++)
    {
        cout << vectorA[i] << endl;
        //scalar += _vector[i] * vectorA[i];
    }
    return scalar;
    //cout << "Le produit scalaire est : " << _scalar << endl;
}*/
