#include<iostream>
#include<vector>
#include<opencv2/opencv.hpp>

int main(int argc,char** argv)
{
    std::string image_path=argv[1];
    cv::Mat image =cv::imread(image_path,cv::IMREAD_GRAYSCALE);
    if(image.empty())
    {
        std::cerr <<"Could not find image"<<std::endl;
        return 1;
    }
    else
    {
        std::cout<<"found it !"<<std::endl;
    }

    std::vector<uint8_t> imageVector;
    if (image.isContinuous()) {
        imageVector.assign(image.data, image.data + image.total() * image.channels());
        std::cout<<"here"<<std::endl;
    } else {
        for (int i = 0; i < image.rows; ++i) {
            imageVector.insert(imageVector.end(), image.ptr<uint8_t>(i), image.ptr<uint8_t>(i) + image.cols * image.channels());
        }
    }
    std::cout<<image.data <<std::endl;
    std::cout << "Image vector size: " << imageVector.size() << std::endl;
    std::cout << "First 10 elements: ";
    for (size_t i = 0; i < 10 && i < imageVector.size(); ++i) {
        std::cout << static_cast<int>(imageVector[i]) << " ";
    }
    std::cout << std::endl;
    return 0;
}