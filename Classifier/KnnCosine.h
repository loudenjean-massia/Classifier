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
    
    void predictSingle();
    long double knnCosine(FeatureVector featureA, FeatureVector featureB);
    void similarity(int k, string apprFile, string testFile);
    float getKnn();
    vector<int> getMaxs(vector<float> max, vector<float> cosine);
    int getTag(vector<int> tag);
    
private:
    long double _cosine;
    Data _appr;
    Data _test;
};
#endif /* KnnCosine_h */
