#include "Socket.h"
#include "NodeBase.h"
#include <QPen>

Socket::Socket(Type type, NodeBase* parentNode, int idx)
    : QGraphicsEllipseItem(-5, -5, 10, 10, parentNode), socketType(type), node(parentNode), index(idx) {
    setBrush(type == Input ? Qt::blue : Qt::green);
    setPen(QPen(Qt::black));
    setPos(type == Input ? 0 : 180, 30 + index * 20);
}

void Socket::connectTo(Socket* other) {
    connection = other;
    if (socketType == Input) node->onInputChanged(this);
}
