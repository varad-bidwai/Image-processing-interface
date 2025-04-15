// Node.h
#pragma once
#include <QGraphicsItem>
#include <vector>

class NodeSocket; // Forward declaration

class Node : public QGraphicsItem {
public:
    Node(const QString& title, int numInputs, int numOutputs);
    virtual ~Node();
    
    QRectF boundingRect() const override;
    void paint(QPainter* painter, 
              const QStyleOptionGraphicsItem* option,
              QWidget* widget) override;
    
    virtual cv::Mat getResult() const { return cv::Mat(); }
    virtual void process() = 0;

    std::vector<NodeSocket*> inputs;
    std::vector<NodeSocket*> outputs;
    QString title;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;

private:
    QPointF dragStart;
};
