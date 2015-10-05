#include "calculator.h"


Calculator::Calculator(std::vector<Vertex> array, QStatusBar *sbar)
{
    arrayOfVertexes = array;
}

float Calculator::entropy()
{
    float entropy = 0;

    for(int i = 0; i < arrayOfVertexes.size(); i++)
        {
            entropy += arrayOfVertexes.at(i).getValue() * log2(arrayOfVertexes.at(i).getValue());
        }
    entropy = -entropy;

    return entropy;
}

std::vector<Vertex> Calculator::codding()
{

    Graph graph(arrayOfVertexes, bar);
    graph.createTree();

    return graph.codding();
}
