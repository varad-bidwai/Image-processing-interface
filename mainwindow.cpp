// mainwindow.cpp
#include "MainWindow.h"
#include "Nodes.h"
#include <QMenuBar>
#include <QAction>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene);
    setCentralWidget(view);  // Directly set as central widget
    resize(800, 600);
    setupMenu();
    setupNodes();
}

void MainWindow::setupNodes() {
    InputNode *input = new InputNode();
    BlurNode *blur = new BlurNode();
    OutputNode *output = new OutputNode();
    
    input->setPos(-300, 0);
    blur->setPos(-100, 0);
    output->setPos(100, 0);
    
    scene->addItem(input);
    scene->addItem(blur);
    scene->addItem(output);
}

void MainWindow::setupMenu() {
    QMenu *fileMenu = menuBar()->addMenu("File");
    QAction *processAct = new QAction("Process", this);
    fileMenu->addAction(processAct);
    
    connect(processAct, &QAction::triggered, [this](){
        // Process all nodes
        for(auto item : scene->items()) {
            if(auto node = dynamic_cast<Node*>(item)) {
                node->process();
            }
        }
    });
}
