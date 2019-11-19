//
//  Data.hpp
//  Classifier
//
//  Created by Léa Gand on 18/11/2019.
//

#ifndef Data_hpp
#define Data_hpp

#include <stdio.h>

namespace classifier {

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
        
        //string toString();

        int getNbSamples();
        ~Data();
        
    //All privates attributes/methods
    private:
        //std::string m_data[];
        int m_nbFeatures;
        int m_nbSamples;
    };
}

#endif /* Data_hpp */
