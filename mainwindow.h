#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vertex.h>
#include <QtConcurrent/QtConcurrent>
#include <calculator.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_2_clicked();

    void on_textEdit_selectionChanged();

    void on_horizontalSlider_sliderMoved(int position);

    void on_pushButton_3_clicked();

    void encodingEnd();

    void progressChanged(int i);

    void on_MainWindow_destroyed();

private:

    float entropy;
    bool calculateEntropy = false;
    QFutureWatcher<std::vector<Vertex>> watcher;
    Ui::MainWindow *ui;
    void createVertexArray();
    std::vector<Vertex> arrayOfVertexes;
};

#endif // MAINWINDOW_H
