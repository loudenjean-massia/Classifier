//
//  Data.cpp
//  Classifier
//
//  Created by Léa Gand on 18/11/2019.
//

#include "Data.hpp"
#include <fstream>
#include <iostream>
#include <string>

//using namespace classifier;
using namespace std;

class Data
{

//All public attributes/methods
public:
    void add();
    void aspire_data(FILE *f);
    Data();
    void load();
    //void operator[]();
    void scale();
    
    string toString();

    int getNbSamples();
    ~Data();
    
//All privates attributes/methods
private:
    //std::string m_data[];
    int m_nbFeatures;
    int m_nbSamples;
};

Data::Data()
{
    //_data;
    //return 0;
    
}

Data::~Data()
{
    
}

void Data::load()
{
    ifstream digitFile("../digitAppr.svm");  //Ouverture d'un fichier en lecture

    if (digitFile)
    {
        string line; //Une variable pour stocker les lignes lues

        while (getline(digitFile, line)) //Tant qu'on n'est pas ‡ la fin, on lit
        {
            cout << line << endl;
            //Et on l'affiche dans la console
            //Ou alors on fait quelque chose avec cette ligne
            //¿ vous de voir
        }
    }

    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
}


int Data::getNbSamples()
{
    return m_nbSamples;
}

void Data::add()
{
    
}

void Data::aspire_data(FILE *f)
{
    
}

void Data::scale()
{
    
}

string toString()
{
    return 0;
}
