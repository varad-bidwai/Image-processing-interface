#include "BlurNode.h"
#include "Socket.h"
#include <opencv2/opencv.hpp>

BlurNode::BlurNode() : NodeBase("Blur Node") {
    inputs.append(new Socket(Socket::Input, this, 0));
    outputs.append(new Socket(Socket::Output, this, 0));
}

void BlurNode::onInputChanged(Socket* socket) {
    if (socket->connection) process();
}

void BlurNode::process() {
    QImage input = inputs[0]->connection ? inputs[0]->connection->node->image : QImage();
    if (!input.isNull()) {
        cv::Mat mat(input.height(), input.width(), CV_8UC4, const_cast<uchar*>(input.bits()), input.bytesPerLine());
        cv::Mat result;
        cv::GaussianBlur(mat, result, cv::Size(9, 9), 5);

        QImage output((uchar*)result.data, result.cols, result.rows, result.step, QImage::Format_ARGB32);
        image = output.copy();
        for (auto* out : outputs) {
            if (out->connection)
                out->connection->node->onInputChanged(out->connection);
        }
    }
}
