#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include "Model.hpp"

class TexModel : public Model
{
public:
    TexModel( float vPoints[], int nValues )
        :
        Model( vPoints, nValues )
    {

    }
    TexModel( std::string file_path )
    {
        std::vector<float> vec;
        float aux;
        std::fstream file( file_path, std::fstream::in );
        if(!file.is_open())
        {
            throw("failed to open model file!");
        }
        while( file.good() )
        {
            file >> aux;
            vec.emplace_back( aux );
        }
        nValues = vec.size();
        nVertex = nValues / 5;
        vertexData = new float[ nValues ];
        for( int i = 0; i < nValues; i++ )
        {
            vertexData[i] = vec[i];
        }
        file.close();
    }
    ~TexModel()
    {
        
    }
};