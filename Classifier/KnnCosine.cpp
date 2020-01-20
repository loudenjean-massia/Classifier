//
//  KnnCosine.cpp
//  Classifier
//
//  Created by Lou Denjean-Massia on 12/01/2020.
//

#include "KnnCosine.h"
#include <math.h>

/**
 @brief KnnCosine constructor
*/
KnnCosine::KnnCosine(): _cosine(0)
{
}

/**
 @brief This method allows to get the Cosine between to vector of features
 @param featureA First vector of feature
 @param featureB Seconde vector of feature
 @return norme
*/
void KnnCosine::cosine(FeatureVector featureA, FeatureVector featureB)
{
    //float scalarProduct = 0;
    float norme = 0;
    std::vector<float> vectorA(70);
    vectorA = featureA.getVector();
    
    std::vector<float> vectorB(70);
    vectorB = featureB.getVector();

    for (int i = 0; i < vectorB.size(); i++)
    {
        scalarProduct += vectorA[i] * vectorB[i];
    }
    _cosine = scalarProduct / (featureA.norme() * featureB.norme());
}

/**
 @brief This method allows to compare compare the cosine of two vectors
 @param featureA First vector of feature
 @param featureB Seconde vector of feature
*/
vector<int> KnnCosine::similarity(int k, string apprFile, string testFile)
{
    int apprSize, testSize;
    vector<long double> cosineTab;
    
    vector<float> max(k, 0);
    vector<int> tag;
    vector<int> resultTag;
    
    /* Chargement des fichiers*/
    _appr.load(apprFile);
    _test.load(testFile);
    
    apprSize = _appr.getNbSamples();
    testSize = _test.getNbSamples();
    
    vector<float> tagTest(testSize);
    
    Sample *sampleAppr[apprSize];
    for(int i = 0; i < apprSize; i++)
    {
        sampleAppr[i] = new Sample();
        sampleAppr[i]->setFeatureVector(_appr, i);
        
        sampleAppr[i]->tag(_appr, i);
    }
    
    Sample *sampleTest[testSize];
    for(int i = 0; i < testSize; i++)
    {
        sampleTest[i] = new Sample();
        sampleTest[i]->setFeatureVector(_test, i);
    }
    
    for(int j = 0; j < testSize; j++)
    {
       for(int i = 0; i < apprSize; i++)
       {
           cosine(sampleTest[j]->getFeatures(), sampleAppr[i]->getFeatures());
           cosineTab.push_back(_cosine);
       }

        max = getMaxs(max, cosineTab);
        
        for (int n = 0; n < k; n++)
        {
            for (int i = 0; i < apprSize; i++)
            {
                if (max[n] == cosineTab[i])
                {
                    tag.push_back(sampleAppr[i]->getTag());
                }
            }
        }

        resultTag.push_back(getTag(tag));
        cosineTab.clear();
        tag.clear();
    }
    return resultTag;
}

vector<int> KnnCosine::getMaxs(vector<float> /*max*/ min, vector<long double> /*cosine*/ norme)
{
    //vector<int> indexCosine(max.size(), 0);
    vector<int> indexNorme(min.size(), 0);
    
    //getnormeMin
    
    for(int i =0 ; i<min.size(); i++){
        for(int j=0; j < norme.size(); j++){
            if(norme[j] < min[i]){
                min[i] = norme[j];
                indexNorme[i]=j;
                norme.erase(norme.begin()+j);
            }
            
        }
        
    }
    //return indexCosine;
    return indexNorme;
}

int KnnCosine::getTag(vector<int> tag)
{
    vector<int> nbRepet(10,0);
    int maxRepet = 0;
    int tagMax = 0;
    
    //cout << "size de tag " << tag.size() << endl;
    for (int j = 0; j < tag.size(); j++)
    {
        for (int i = 0; i < 10; i++)
        {
            if (tag[j] == i)
            {
                nbRepet[i]++;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            if (nbRepet[i] > maxRepet)
            {
                maxRepet = nbRepet[i];
                tagMax = i;
            }
        }
    }
    return tagMax;
}
