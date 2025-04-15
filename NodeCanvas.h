#pragma once
#include <QGraphicsScene>

class NodeCanvas : public QGraphicsScene {
    Q_OBJECT
public:
    NodeCanvas(QObject* parent = nullptr);
};
