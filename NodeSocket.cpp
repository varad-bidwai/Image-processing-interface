// NodeSocket.cpp
#include "NodeSocket.h"
#include "Connection.h"
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QGraphicsScene>

NodeSocket::NodeSocket(QGraphicsItem* parent, bool isOutput) 
    : QGraphicsItem(parent), isOutput(isOutput) {
    setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
}

QRectF NodeSocket::boundingRect() const {
    return QRectF(-5, -5, 10, 10);
}

void NodeSocket::paint(QPainter* painter,
                      const QStyleOptionGraphicsItem*,
                      QWidget*) {
    painter->setBrush(isOutput ? Qt::green : Qt::red);
    painter->drawEllipse(-5, -5, 10, 10);
}

void NodeSocket::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    QGraphicsItem::mousePressEvent(event);
    dragStart = event->scenePos();
    
    tempConnection = new QGraphicsPathItem();
    tempConnection->setPen(QPen(Qt::white, 2));
    scene()->addItem(tempConnection);
}

void NodeSocket::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
    if(tempConnection) {
        QPainterPath path;
        path.moveTo(dragStart);
        path.lineTo(event->scenePos());
        tempConnection->setPath(path);
    }
}

void NodeSocket::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    QGraphicsItem::mouseReleaseEvent(event);
    
    if(tempConnection) {
        scene()->removeItem(tempConnection);
        delete tempConnection;
        tempConnection = nullptr;
    }

    auto items = scene()->items(event->scenePos());
    foreach(QGraphicsItem* item, items) {
        if(auto target = dynamic_cast<NodeSocket*>(item)) {
            if(target != this && target->isOutput != isOutput) {
                auto connection = new Connection(this, target);
                connections.push_back(connection);
                target->connections.push_back(connection);
                scene()->addItem(connection);
                connection->updatePath();
            }
        }
    }
}
