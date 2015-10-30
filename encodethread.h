#ifndef ENCODETHREAD_H
#define ENCODETHREAD_H

#include <QThread>
#include <graph.h>
#include <vertex.h>

class EncodeThread : public QThread
{

public:
    EncodeThread(std::vector<Vertex> array, QStatusBar *sbar);

protected:
        void run();
        std::vector<Vertex> arrayOfVertex;
        QStatusBar* bar;
};

#endif // ENCODETHREAD_H
