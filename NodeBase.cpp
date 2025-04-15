#include "NodeBase.h"
#include "Socket.h"
#include <QPainter>

NodeBase::NodeBase(QString t) : title(std::move(t)) {
    setFlags(ItemIsMovable | ItemIsSelectable);
}

QRectF NodeBase::boundingRect() const {
    return QRectF(0, 0, 180, 100);
}

void NodeBase::paint(QPainter* painter, const QStyleOptionGraphicsItem*, QWidget*) {
    painter->setBrush(isSelected() ? Qt::lightGray : Qt::white);
    painter->drawRoundedRect(boundingRect(), 10, 10);
    painter->setPen(Qt::black);
    painter->drawText(10, 20, title);
}
