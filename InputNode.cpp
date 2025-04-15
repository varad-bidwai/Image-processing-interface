#include "InputNode.h"
#include "Socket.h"
#include <QGraphicsSceneMouseEvent>
#include <QFileDialog>
#include <QImageReader>

InputNode::InputNode() : NodeBase("Input Node") {
    outputs.append(new Socket(Socket::Output, this, 0));
}

void InputNode::process() {
    QString path = QFileDialog::getOpenFileName(nullptr, "Open Image", "", "Images (*.png *.jpg *.bmp)");
    if (!path.isEmpty()) {
        image = QImage(path);
        for (auto* out : outputs) {
            if (out->connection)
                out->connection->node->onInputChanged(out->connection);
        }
    }
}
