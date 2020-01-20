//
//  Sample.cpp
//  Classifier
//
//  Created by Léa Gand on 28/11/2019.
//

#include "Sample.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::ifstream;
using std::vector;
using std::cout;
using std::stringstream;
using std::endl;

//Sample::Sample()
//{
//
//}
//
//Sample::~Sample()
//{
//
//}

/**
 @brief This method allows to split the lines of the data file (each sample)
 @param chaine   ??????
 @param delimiter A char to delimit each sample of the data file
 @param elements A vector of element to store a sample
*/
void Sample::splitLine(const string &chaine, char delimiter, vector<string> &elements){
    
    stringstream ss(chaine);
    string sousChaine;
    
    while(getline(ss,sousChaine, delimiter)){
        elements.push_back(sousChaine);
    }
    
}

/**
 @brief This method allows to set the vector of features
 @param data The data file of Data type
 @param lineNb Int representing the number of line
*/
void Sample::setFeatureVector(Data data, int lineNb)
{
    _features.vector(data, lineNb);
}

/**
 @brief This method allows to
 @param data The data file of Data type
 @param lineNb Int representing the number of line
*/
void Sample::tag(Data& data, int lineNb)
{
   if (lineNb < data.getNbSamples())
   {   
        vector<string> features;
        splitLine(data._data[lineNb], ' ', features);

        for(int i = 0; i < features.size(); i++)
        {
            if (i == 0)
            {
                _tag = stoi(features[i]);
            }

        }
   }
   else
   {
        cout << "This sample doesn't exit" << endl;   
   }
}

/**
 @brief This method allows to associate the tag to features
 @param tag Int representing the tag
*/
void Sample::setTag(int tag)
{
    _tag = tag;
}

/**
 @brief This method allows to get the tag of each sample
 @return _tag
*/
int Sample::getTag()
{
    return _tag;
}

/**
 @brief This method allows to get the coordinates vectore (features)
 @return _features
*/
FeatureVector Sample::getFeatures()
{
    return _features;
}
