//
//  KnnCosine.cpp
//  Classifier
//
//  Created by Lou Denjean-Massia on 12/01/2020.
//

#include "KnnNorme.h"

KnnNorme::KnnNorme(): _norme(0)
{
    
}

void KnnNorme::norme(FeatureVector featureA, FeatureVector featureB)
{
    float norme = 0;
    vector<float> vectorA(70);
    vectorA = featureA.getVector();
    
    vector<float> vectorB(70);
    vectorB = featureB.getVector();

    for (int i = 0; i < vectorA.size(); i++)
    {
        norme += (vectorA[i] - vectorB[i]) * (vectorA[i] - vectorB[i]);
    }
    _norme = sqrt(norme);
}

vector<int> KnnNorme::similarity(int k, string apprFile, string testFile)
{
    int apprSize, testSize;
    vector<long double> normeTab;
    
    vector<float> min(k, 100);
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
           norme(sampleTest[j]->getFeatures(), sampleAppr[i]->getFeatures());
           normeTab.push_back(_norme);
       }

        min = getMins(min, normeTab);
        
        for (int n = 0; n < k; n++)
        {
            for (int i = 0; i < apprSize; i++)
            {
                if (min[n] == normeTab[i])
                {
                    tag.push_back(sampleAppr[i]->getTag());
                }
            }
        }

        resultTag.push_back(getTag(tag));
        normeTab.clear();
        tag.clear();
    }
    return resultTag;
}

vector<float> KnnNorme::getMins(vector<float> min, vector<long double> norme)
{
    vector<int> indexNorme(min.size(), 0);

    for (int i = 0; i < min.size(); i++)
    {
        for (int j = 0; j < norme.size(); j++)
        {
            if (norme[j] <= min[i])
            {
                min[i] = norme[j];
                indexNorme[i] = j;
                norme.erase(norme.begin()+j);
            }
        }
    }
    return min;
}

int KnnNorme::getTag(vector<int> tag)
{
    vector<int> nbRepet(10,0);
    int maxRepet = 0;
    int tagMax = 0;
    
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
