#include "vertex.h"

Vertex::Vertex()
{
    rootFlag = false;
}

bool Vertex::isRoot()
{
    return rootFlag;
}

float Vertex::getValue()
{
    return value;
}

QString Vertex::getName()
{
    return name;
}

QString Vertex::getCode()
{
    return code;
}

void Vertex::setRoot()
{
    rootFlag = true;
}

void Vertex::setValue(float val)
{
    value = val;
}

void Vertex::setCode(QString str)
{
    code = str;
}

void Vertex::setName(QString str)
{
    name = str;
}
