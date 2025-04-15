#include "Connection.h"
#include "Socket.h"
#include<QPen>

Connection::Connection(Socket* from, Socket* to)
    : QGraphicsLineItem(), fromSocket(from), toSocket(to) {
    setPen(QPen(Qt::darkGray, 2));
    updatePosition();

    from->connectTo(to);
    to->connectTo(from);
}

void Connection::updatePosition() {
    if (fromSocket && toSocket) {
        QPointF p1 = fromSocket->scenePos();
        QPointF p2 = toSocket->scenePos();
        setLine(QLineF(p1, p2));
    }
}
