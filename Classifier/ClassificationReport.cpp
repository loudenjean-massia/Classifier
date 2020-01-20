//
//  ClassificationReport.cpp
//  Classifier
//
//  Created by Léa Gand on 19/01/2020.
//

#include "ClassificationReport.h"


/**
 @brief Classification Report constructor
*/
ClassificationReport::ClassificationReport(): _confusion(0), _nbTags(0), _nok(0), _ok(0)
{

}

/**
 @brief This method allows the good tag estimation percentage
 @param realTag  Vector of int representing the real tag vector
 @param resultTag Vector of int representing the tag estimated by the program
*/
void ClassificationReport::tagValidation(vector<int> realTag, vector<int> resultTag){
    
       for (int i = 0; i < realTag.size(); i++)
       {
           if(resultTag[i] == realTag[i])
           {
               _ok++;
           }
           else
           {
               _nok++;
           }
       }
}

/**
 @brief This method allows to compute the good estimation percentage
 @param realTag  Vector of int representing the real tag vector
 @param resultTag Vector of int representing the tag estimated by the program
 @return percentage
 */
float ClassificationReport::computePercentage(vector<int> realTag, vector<int> resultTag)
{
    if (realTag.size() == resultTag.size())
    {
        float percentage = 0;
        
        tagValidation(realTag, resultTag);
        percentage = ((float)_ok / realTag.size()) * 100;
            
        return percentage;
    }
    return -1;
}

/**
 @brief This method allows to compute the confusion Matrix
 @param realTag  Vector of int representing the real tag vector
 @param resultTag Vector of int representing the tag estimated by the program
 @return matrix
 */
vector<vector <int> > ClassificationReport::confusionMatrix(vector<int> realTag, vector<int> resultTag)
{
    vector<vector <int> > matrix(10 , vector<int> (10, 0));
    
    if(realTag.size() == resultTag.size()){
                
        for (int n = 0; n < resultTag.size(); n++)
        {
            if(resultTag[n] != realTag[n])
            {
                matrix[resultTag[n]][realTag[n]]++;
            }
        }
    }
    return matrix;
}

/**
 @brief This method allows to display the confusion Matrix
 @param matrix A vector of vector confusion matrix
 */
void ClassificationReport::displayMatrix(vector<vector <int> > matrix)
{
    cout << "    0 1 2 3 4 5 6 7 8 9" << endl;
    cout << "   --------------------" << endl;
    int nb = 0;
        
    for(int i = 0; i<10; i++)
    {
        cout << i << " | ";
        for (int j = 0; j < 10; j++)
        {
            nb++;
            cout<< matrix[i][j] << " ";
        }
        cout << endl;
    }
}
