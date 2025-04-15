#include "NodeEditor.h"
#include "NodeCanvas.h"
#include <QGraphicsView>

NodeEditor::NodeEditor(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle("Node-Based Image Editor");
    resize(1000, 700);

    canvas = new NodeCanvas(this);
    auto* view = new QGraphicsView(canvas);
    view->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(view);
}
