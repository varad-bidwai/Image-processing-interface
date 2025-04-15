// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Node.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    
    void setupNodes();
    void setupMenu();
};

#endif // MAINWINDOW_H
