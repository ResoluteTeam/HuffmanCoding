#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include "qstatusbar.h"

class Graph
{
public:
    Graph(std::vector<Vertex> array, QStatusBar* sbar);
    void createTree();
    std::vector<Vertex> codding();
    Vertex findSmallest();

private:

    struct node {
        Vertex parent;
        Vertex children1, children2;
    };

    QStatusBar* bar;
    std::vector<Vertex> rootVertexes;
    std::vector<Vertex> vertexes;
    std::vector<node> graph;
};

#endif // GRAPH_H
