//
//  FeatureVector.hpp
//  Classifier
//
//  Created by Léa Gand on 18/11/2019.
//

#ifndef FeatureVector_h
#define FeatureVector_h

#include <stdio.h>
#include "Data.h"

class FeatureVector
{
public:
    FeatureVector();
    ~FeatureVector();

    void size();

    int getNorme();
    int getVector();

private:
    int _norme;
    int _vector[71];
};

#endif /* FeatureVector_hpp */
