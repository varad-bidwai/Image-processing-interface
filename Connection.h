// Connection.h
#pragma once
#include <QGraphicsPathItem>
#include "NodeSocket.h"

class Connection : public QGraphicsPathItem {
public:
    Connection(NodeSocket* start, NodeSocket* end);
    void updatePath();

    NodeSocket* startSocket;
    NodeSocket* endSocket;
};
