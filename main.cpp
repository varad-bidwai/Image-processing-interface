#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <memory>

using namespace cv;
using namespace std;

class node {
    public:
        virtual ~node() = default;
        vector<std::shared_ptr<node>> inputs;
        vector<cv::Mat> outputs;
        virtual cv::Mat process() = 0;
};
    
class InputNode : public node {
    private:
        cv::Mat image;
    public:
        InputNode(const std::string& path) {
            image = cv::imread(path);
        }
        
        cv::Mat process() override {
            outputs = {image};
            return image;
        }
};

class OutputNode : public node {
    private:
        std::string outputPath;

    public:
        OutputNode(const std::string& path) : outputPath(path) {}

        cv::Mat process() override {
            CV_Assert(!inputs.empty());
            cv::Mat result = inputs[0]->process();
            cv::imwrite(outputPath, result);
            return result;
        }
};

class BrightnessContrastNode : public node {
    private:
        double alpha, beta;
    public:
        BrightnessContrastNode() : alpha(1.0), beta(0) {}

        cv::Mat process() override {
            CV_Assert(!inputs.empty());
            cv::Mat input = inputs[0]->process();
            
            cv::Mat adjusted;
            input.convertTo(adjusted, -1, alpha, beta);
            
            outputs = {adjusted};
            return adjusted;
        }

        // For GUI slider integration
        void setParameters(double contrast, double brightness) {
            alpha = contrast;
            beta = brightness;
        }

};

class GaussianBlurNode : public node {
    private:
        int kernelSize;
    public:
        GaussianBlurNode(int ksize = 3) : kernelSize(ksize) {}
    
        cv::Mat process() override {
            CV_Assert(!inputs.empty());
            cv::Mat input = inputs[0]->process();
            
            cv::Mat blurred;
            cv::GaussianBlur(input, blurred, {kernelSize,kernelSize}, 0);
            
            outputs = {blurred};
            return blurred;
        }
    
};

// Node connection system
class NodeGraph {
    public:
        void connectNodes(std::shared_ptr<node> src, std::shared_ptr<node> dst, int port=0) {
            if(port < dst->inputs.size()) {
                dst->inputs[port] = src;
            }
        }
    
        cv::Mat executeGraph(std::shared_ptr<node> endNode) {
            return endNode->process();
        }
};
    
int main() {

    // Getting familiar with OpenCV usage
    std::cout << " Here I am!" << std::endl;
    std::string path = "C:/Users/varad/OneDrive/Pictures/Screenshots/fbnd.png";
    Mat image = imread(path);
    if (!image.data) {
        std::cout << " Could not load image at path: " << path << std::endl;
        return -1;
    }
    
    Mat edges;
    std::cout << "Image Channels: " << image.channels() << std::endl;
    std::cout << "Image Type: " << image.type() << std::endl;
    
    std::cout << " Image loaded successfully!" << std::endl;
    Canny(image,edges,100,200);
    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    imshow("Display edges", edges);
    waitKey(0);

    // The main for writing workflow for the image processing.
    auto input = std::make_shared<InputNode>("C:/Users/varad/OneDrive/Pictures/Screenshots/fbnd.png");
    auto bcAdjust = std::make_shared<BrightnessContrastNode>();
    auto blur = std::make_shared<GaussianBlurNode>(5);
    auto output = std::make_shared<OutputNode>("C:/Users/varad/OneDrive/Pictures/Screenshots/fbnd1.png");

    // The processing pipeline
    NodeGraph graph;
    graph.connectNodes(input, bcAdjust);
    graph.connectNodes(bcAdjust, blur);
    graph.connectNodes(blur, output);

    // Set parameters (could be connected to GUI sliders)
    bcAdjust->setParameters(1.2, 20); // Contrast=1.2, Brightness=20

    // Backward Execution, i.e. output(the OutputNode pointer) triggers the process() function which is then called recursively until it reaches the input node class.
    // Once there the processing of image starts and a processed version is catched at the end.
    graph.executeGraph(output);
    return 0;
}
