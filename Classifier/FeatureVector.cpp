//
//  FeatureVector.cpp
//  Classifier
//
//  Created by Léa Gand on 18/11/2019.
//
#include "FeatureVector.h"

FeatureVector::FeatureVector()
{
    _norme = 0;
}

FeatureVector::~FeatureVector()
{
    
}

int FeatureVector::getNorme()
{
    return _norme;
}

int FeatureVector::size()
{
    return _vector.size();
}

int FeatureVector::getVector()
{
    return 0;
}

