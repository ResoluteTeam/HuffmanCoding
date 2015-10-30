#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"
#include "qstatusbar.h"
#include "qprogressdialog.h"

class Graph
{
public:
    Graph(std::vector<Vertex> array, QWidget* mWidget);
    void createTree();
    std::vector<Vertex> codding();
    Vertex findSmallest();

private:

    struct node {
        Vertex parent;
        Vertex children1, children2;
    };

    int numOfResults;

    QWidget* widget;
    std::vector<Vertex> rootVertexes;
    std::vector<Vertex> vertexes;
    std::vector<node> graph;
};

#endif // GRAPH_H
