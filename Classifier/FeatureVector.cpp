//
//  FeatureVector.cpp
//  Classifier
//
//  Created by Léa Gand on 18/11/2019.
//

#include "FeatureVector.hpp"

class FeatureVector
{
public:
    FeatureVector();
    ~FeatureVector();

    void size();

    int getNorme();
    int getVector();

private:
    int m_norme;
    int m_vector[71];
};

FeatureVector::FeatureVector()
{
    
}

FeatureVector::~FeatureVector()
{
    
}

int FeatureVector::getNorme()
{
    return 0;
}

void FeatureVector::size()
{
    
}


int FeatureVector::getVector()
{
    return 0;
}

