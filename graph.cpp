#include "graph.h"
#include "qdebug.h"

Graph::Graph(std::vector<Vertex> array, QWidget *mWidget)
{
    rootVertexes = array;
    widget = mWidget;
    numOfResults = array.size();
}

void Graph::createTree()
{
    Vertex temp1, temp2;
    node tempNode;

    QProgressDialog progress("Creating tree...", "Abort", 0, rootVertexes.size() - 1, widget);
    progress.setWindowModality(Qt::WindowModal);
    int n = 0;
    while(rootVertexes.size() != 1)
        {
        if(progress.wasCanceled())
            break;
        temp1 = findSmallest();
        temp2 = findSmallest();

        tempNode.children1 = temp1;
        tempNode.children2 = temp2;

        tempNode.parent.setValue(temp1.getValue() + temp2.getValue());
        tempNode.parent.setName(temp1.getName() + temp2.getName());

        graph.push_back(tempNode);
        rootVertexes.push_back(tempNode.parent);
        n++;
        progress.setValue(n);
        }
}

std::vector<Vertex> Graph::codding()
{
    rootVertexes.clear();

    node* tempNode;

    int i = graph.size()-1;
    QProgressDialog progress("Encoding...", "Abort", 0, numOfResults, widget);
    progress.setWindowModality(Qt::WindowModal);

    while (i >= 0)
    {
        if(progress.wasCanceled())
            break;

        tempNode = &graph.at(i);

        for(int j = 0; j < graph.size(); j++)
        {
            if(tempNode->parent.getName() == graph.at(j).children1.getName())
                tempNode->parent.setCode(graph.at(j).children1.getCode());
            if(tempNode->parent.getName() == graph.at(j).children2.getName())
                tempNode->parent.setCode(graph.at(j).children2.getCode());

        }

        tempNode->children1.setCode(tempNode->parent.getCode() + "0");
        tempNode->children2.setCode(tempNode->parent.getCode() + "1");

        if(tempNode->children1.isRoot())
        {
            rootVertexes.push_back(tempNode->children1);
        }

        if(tempNode->children2.isRoot())
        {
            rootVertexes.push_back(tempNode->children2);
        }
        progress.setValue(rootVertexes.size());
            i--;
    }

    return rootVertexes;
}

Vertex Graph::findSmallest()
{
    Vertex temp;
    temp = (*rootVertexes.begin());
    for(int i = 0; i < rootVertexes.size(); i++)
    {
        if(temp.getValue() > rootVertexes.at(i).getValue())
        {
            temp = rootVertexes.at(i);
        }
    }

    bool flag = true;
    for(int i = 0; i < rootVertexes.size(); i++)
    {
        if(flag && temp.getValue() == rootVertexes.at(i).getValue())
        {
            rootVertexes.erase(rootVertexes.begin() + i);
            flag = false;
        }
    }

    return temp;
}
