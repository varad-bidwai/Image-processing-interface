#pragma once
#include <QGraphicsLineItem>

class Socket;

class Connection : public QGraphicsLineItem {
public:
    Connection(Socket* from, Socket* to);

    Socket* fromSocket;
    Socket* toSocket;

    void updatePosition();
};
