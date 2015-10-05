#ifndef VERTEX_H
#define VERTEX_H

#include "qstring.h"

class Vertex
{
public:
    Vertex();

    void setRoot();
    void setValue(float val);
    void setCode(QString str);
    void setName(QString str);

    bool isRoot();
    float getValue();
    QString getName();
    QString getCode();

private:
    bool rootFlag;
    float value;
    QString name;
    QString code;
};

#endif // VERTEX_H
