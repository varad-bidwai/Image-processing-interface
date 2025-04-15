// NodeSocket.h
#pragma once
#include <QGraphicsItem>
#include <vector>

class Connection; // Forward declaration

class NodeSocket : public QGraphicsItem {
public:
    NodeSocket(QGraphicsItem* parent, bool isOutput);
    
    QRectF boundingRect() const override;
    void paint(QPainter* painter,
              const QStyleOptionGraphicsItem* option,
              QWidget* widget) override;
    
    void addConnection(Connection* conn);
    void removeConnection(Connection* conn);

    bool isOutput;
    std::vector<Connection*> connections;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

private:
    QPointF dragStart;
    QGraphicsPathItem* tempConnection = nullptr;
};
