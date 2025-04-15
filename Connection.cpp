#include "Connection.h"
#include "NodeSocket.h"

Connection::Connection(NodeSocket* start, NodeSocket* end) 
    : startSocket(start), endSocket(end) {
    updatePath();
}

void Connection::updatePath() {
    QPointF startPos = startSocket->scenePos();
    QPointF endPos = endSocket->scenePos();
    
    QPainterPath path;
    path.moveTo(startPos);
    qreal dx = endPos.x() - startPos.x();
    qreal dy = endPos.y() - startPos.y();
    path.cubicTo(startPos.x() + dx * 0.5, startPos.y(),
                startPos.x() + dx * 0.5, endPos.y(),
                endPos.x(), endPos.y());
    
    setPath(path);
}
