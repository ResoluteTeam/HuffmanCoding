#include "encodethread.h"

EncodeThread::EncodeThread(std::vector<Vertex> array, QStatusBar* sbar)
{
    arrayOfVertex = array;
    bar = sbar;
}


void EncodeThread::run()
{
//    Graph graph(arrayOfVertex, bar);
//    graph.createTree();

//    return graph.codding();
}
