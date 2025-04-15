#include "OutputNode.h"
#include "Socket.h"
#include <QFileDialog>

OutputNode::OutputNode() : NodeBase("Output Node") {
    inputs.append(new Socket(Socket::Input, this, 0));
}

void OutputNode::onInputChanged(Socket* socket) {
    if (socket->connection) process();
}

void OutputNode::process() {
    if (inputs[0]->connection) {
        image = inputs[0]->connection->node->image;
        QString path = QFileDialog::getSaveFileName(nullptr, "Save Image", "", "PNG Files (*.png)");
        if (!path.isEmpty()) {
            image.save(path);
        }
    }
}
