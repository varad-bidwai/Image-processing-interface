#pragma once
#include <QGraphicsItem>
#include <QImage>

class Socket;

class NodeBase : public QGraphicsItem {
public:
    NodeBase(QString title);
    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) override;

    virtual void process() = 0;
    virtual void onInputChanged(Socket* socket) = 0;

    QList<Socket*> inputs;
    QList<Socket*> outputs;
    QImage image;
    QString title;
};
