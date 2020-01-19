//
//  KnnCosine.cpp
//  Classifier
//
//  Created by Lou Denjean-Massia on 12/01/2020.
//

#include "KnnCosine.h"

using namespace std;


KnnCosine::KnnCosine(): _cosine(0)
{
    
}

long double KnnCosine::getCosine(FeatureVector featureA, FeatureVector featureB)
{
    float scalarProduct = 0;
    std::vector<float> vectorA(70);
    vectorA = featureA.getVector();
    
    std::vector<float> vectorB(70);
    vectorB = featureB.getVector();

    for (int i = 0; i < vectorB.size(); i++)
    {
        scalarProduct += vectorA[i] * vectorB[i];
        //norme += (vectorB[i] - vectorA[i])*(vectorB[i] - vectorA[i]);
    }
    return _cosine = scalarProduct / (featureA.norme() * featureB.norme()); //scalarProduct(featureA, featureB)
   // return _cosine = sqrt(scalarProduct);
}

vector<int> KnnCosine::similarity(int k, string apprFile, string testFile)
{
    int apprSize, testSize;
    vector<long double> cosine;
    
    vector<float> max(k,0);
    vector<int> indiceMax(k,0);
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
        //cout << "Tag du " << i << "eme sample appr : " << sampleAppr[i]->getTag() << endl;
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
           cosine.push_back(getCosine(sampleTest[j]->getFeatures(), sampleAppr[i]->getFeatures()));
       }

        indiceMax = getMaxs(max, cosine);
        for (int i = 0; i < k; i++)
        {
            tag.push_back(sampleAppr[indiceMax[i]]->getTag());
            //cout << "tag du " << i << "eme point est : " << tag[i] << endl;
        }

        resultTag.push_back(getTag(tag));
        cosine.clear();
        tag.clear();
    }
    return resultTag;
}

vector<int> KnnCosine::getMaxs(vector<float> max, vector<long double> cosine)
{
    vector<int> indexCosine(max.size(), 0);
    
    for (int i = 0; i < max.size(); i++)
    {
        for (int j = 0; j < cosine.size(); j++)
        {
            if (cosine[j] > max[i])
            {
                max[i] = cosine[j];
                indexCosine[i] = j;
                cosine.erase(cosine.begin()+j);
            }
        }
    }
    return indexCosine;
}
    
float KnnCosine::getKnn()
{
    return _cosine;
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
    //cout << "Le tag est : " << tagMax << endl;
    return tagMax;
}
