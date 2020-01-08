//
//  FeatureVector.hpp
//  Classifier
//
//  Created by Léa Gand on 18/11/2019.
//

#ifndef FeatureVector_h
#define FeatureVector_h

#include <stdio.h>
#include <vector>
#include "Data.h"

class FeatureVector
{
public:
    FeatureVector();
    ~FeatureVector();

    int size();

    int getNorme();
    int getVector();

private:
    int _norme;
    vector<int> _vector(70);
};

#endif /* FeatureVector_hpp */
