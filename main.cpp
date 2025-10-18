#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>

int main() {
    // Load model files
    std::string modelFile = "res10_300x300_ssd_iter_140000.caffemodel";
    std::string configFile = "deploy.prototxt";

    // Load the neural network
    cv::dnn::Net net = cv::dnn::readNetFromCaffe(configFile, modelFile);

    // Load the input image
    cv::Mat image = cv::imread("faces/unknown.jpg");
    if (image.empty()) {
        std::cerr << "Failed to read image." << std::endl;
        return -1;
    }

    int h = image.rows;
    int w = image.cols;

    // Create a 4D blob from the image
    cv::Mat blob = cv::dnn::blobFromImage(image, 1.0, cv::Size(300, 300),
                                          cv::Scalar(104.0, 177.0, 123.0), false, false);

    // Set the blob as input to the network
    net.setInput(blob);

    // Run forward pass
    cv::Mat detections = net.forward();

    // Process detections
    cv::Mat detectionMat(detections.size[2], detections.size[3], CV_32F, detections.ptr<float>());

    for (int i = 0; i < detectionMat.rows; i++) {
        float confidence = detectionMat.at<float>(i, 2);

        if (confidence > 0.5) {
            int x1 = static_cast<int>(detectionMat.at<float>(i, 3) * w);
            int y1 = static_cast<int>(detectionMat.at<float>(i, 4) * h);
            int x2 = static_cast<int>(detectionMat.at<float>(i, 5) * w);
            int y2 = static_cast<int>(detectionMat.at<float>(i, 6) * h);

            cv::rectangle(image, cv::Point(x1, y1), cv::Point(x2, y2),
                          cv::Scalar(0, 255, 0), 2);

            std::string label = cv::format("%.2f%%", confidence * 100);
            int baseline = 0;
            cv::Size labelSize = cv::getTextSize(label, cv::FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseline);
            y1 = std::max(y1, labelSize.height);
            cv::rectangle(image, cv::Point(x1, y1 - labelSize.height),
                          cv::Point(x1 + labelSize.width, y1 + baseline),
                          cv::Scalar(0, 255, 0), cv::FILLED);
            cv::putText(image, label, cv::Point(x1, y1),
                        cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0), 1);
        }
    }

    // Display the image
    cv::imshow("Face Detection", image);
    cv::waitKey(0);
    return 0;
}
