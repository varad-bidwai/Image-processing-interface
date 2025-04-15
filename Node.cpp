// Node.cpp
#include "Node.h"
#include "NodeSocket.h"
#include <QGraphicsSceneMouseEvent>


Node::Node(const QString &title, int numInputs, int numOutputs) : title(title) {
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    
    // Create input sockets
    for(int i = 0; i < numInputs; i++) {
        inputs.push_back(new NodeSocket(this, false));
    }
    
    // Create output sockets
    for(int i = 0; i < numOutputs; i++) {
        outputs.push_back(new NodeSocket(this, true));
    }
}

Node::~Node() {
    for(auto socket : inputs) delete socket;
    for(auto socket : outputs) delete socket;
}

QRectF Node::boundingRect() const {
    return QRectF(0, 0, 120, 80);
}

void Node::paint(QPainter *painter, 
                const QStyleOptionGraphicsItem *,
                QWidget *) {
    painter->setBrush(QColor(60, 60, 60));
    painter->drawRoundedRect(boundingRect(), 5, 5);
    
    painter->setPen(Qt::white);
    painter->drawText(QRectF(0, 0, 120, 20), Qt::AlignCenter, title);
}

void Node::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    dragStart = event->pos();
    QGraphicsItem::mousePressEvent(event);
}

void Node::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mouseMoveEvent(event);
}

// Socket implementation
NodeSocket::NodeSocket(Node *parent, bool isOutput) 
    : QGraphicsItem(parent), parentNode(parent), isOutput(isOutput) {}

QRectF NodeSocket::boundingRect() const { 
    return QRectF(-5, -5, 10, 10); 
}

void NodeSocket::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *,
                     QWidget *) {
    painter->setBrush(isOutput ? Qt::green : Qt::red);
    painter->drawEllipse(boundingRect());
}

void NodeSocket::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    event->accept();
}

void NodeSocket::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);
}

void NodeSocket::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);
}
void NodeSocket::addConnection(Connection* conn) {
    connections.push_back(conn);
}

void NodeSocket::removeConnection(Connection* conn) {
    auto it = std::find(connections.begin(), connections.end(), conn);
    if(it != connections.end()) {
        connections.erase(it);
    }
}
