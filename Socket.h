#pragma once
#include <QGraphicsEllipseItem>

class NodeBase;

class Socket : public QGraphicsEllipseItem {
public:
    enum Type { Input, Output };
    Socket(Type type, NodeBase* parentNode, int index);

    Type socketType;
    NodeBase* node;
    int index;

    void connectTo(Socket* other);
    Socket* connection = nullptr;
};
