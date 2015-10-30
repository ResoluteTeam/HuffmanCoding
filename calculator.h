#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "vector"
#include "math.h"
#include "qdebug.h"
#include "cstdlib"
#include "cmath"
#include "vertex.h"
#include "graph.h"
#include "mainwindow.h"
#include "qstatusbar.h"
#include "encodethread.h"

class Calculator
{
public:
    Calculator(std::vector<Vertex> array, QWidget* mainWidget);
    float entropy();
    std::vector<Vertex> codding();
private:
    std::vector<Vertex> arrayOfVertexes;
    QWidget* widget;

};

#endif // CALCULATOR_H
