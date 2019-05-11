#pragma once
#include <vector>

class Model
{
public:
    Model( float vPoints[], int nValues )
        :
        nValues( nValues ),
        nVertex( nValues / 3 )
    {
        vertexData = new float[nValues];
        for( int i = 0; i < nValues; i++ )
        {
            vertexData[i] = vPoints[i];
        }
    }
    Model() = default;

    ~Model()
    {
        delete vertexData;
    }
public:
    float* vertexData;
    int nValues;
    int nVertex;
};