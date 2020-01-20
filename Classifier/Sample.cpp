//
//  Sample.cpp
//  Classifier
//
//  Created by Léa Gand on 28/11/2019.
//

#include "Sample.h"

Sample::Sample()
{

}

void Sample::splitLine(const string &chaine, char delimiteur, vector<string> &elements){
    
    stringstream ss(chaine);
    string sousChaine;
    
    while(getline(ss,sousChaine, delimiteur)){
        elements.push_back(sousChaine);
    }
}

void Sample::setFeatureVector(Data data, int lineNb)
{
    _features.vector(data, lineNb);
}

void Sample::tag(Data& data, int lineNb)
{
   if (lineNb < data.getNbSamples())
   {   
        vector<string> features;
        splitLine(data._data[lineNb], ' ', features);

        for(int i = 0; i < (signed)features.size(); i++)
        {
            if (i == 0)
            {
                _tag = stoi(features[i]);
                //cout << "The tag is : " << _tag << endl;
            }
        }
   }
   else
   {
        cout << "This sample doesn't exit" << endl;   
   }
}

void Sample::setTag(int tag)
{
    _tag = tag;
}

int Sample::getTag()
{
    return _tag;
}

FeatureVector Sample::getFeatures()
{
    return _features;
}
