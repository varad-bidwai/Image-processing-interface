#include "NodeCanvas.h"
#include "InputNode.h"
#include "BlurNode.h"
#include "OutputNode.h"

NodeCanvas::NodeCanvas(QObject* parent) : QGraphicsScene(parent) {
    setSceneRect(0, 0, 2000, 2000);

    auto* inputNode = new InputNode();
    inputNode->setPos(100, 100);
    addItem(inputNode);

    auto* blurNode = new BlurNode();
    blurNode->setPos(350, 100);
    addItem(blurNode);

    auto* outputNode = new OutputNode();
    outputNode->setPos(600, 100);
    addItem(outputNode);
}
