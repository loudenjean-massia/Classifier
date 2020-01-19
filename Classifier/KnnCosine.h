//
//  KnnCosine.h
//  Classifier
//
//  Created by Lou Denjean-Massia on 12/01/2020.
//

#ifndef KnnCosine_h
#define KnnCosine_h

#include <stdio.h>
#include <vector>
#include "Knn.h"
#include "Data.h"
#include "Sample.h"
#include "FeatureVector.h"

using std::vector;

class KnnCosine {

public:
    KnnCosine();
    
    vector<int> similarity(int k, string apprFile, string testFile);
    float getKnn();
    
private:
    long double _cosine;
    Data _appr;
    Data _test;
    
    long double getScalarProduct(FeatureVector featureA, FeatureVector featureB);
    long double getCosine(FeatureVector featureA, FeatureVector featureB);
    vector<int> getMaxs(vector<float> max, vector<long double> cosine);
    int getTag(vector<int> tag);
};
#endif /* KnnCosine_h */
