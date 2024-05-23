#include<iostream>
#include<vector>
#include<tuple>
#include <algorithm>
#include<cmath>
#include<opencv2/opencv.hpp>
#include"./imports/functions.hpp"
std::vector<std::vector<int>> kernelx={
                                        {-1,0,1},
                                        {-2,0,2},
                                        {-1,0,1}
                                      };
std::vector<std::vector<int>> kernely={
                                        {-1,-2,-1},
                                        {0,0,0},
                                        {1,2,1}
                                      };





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

    std::vector<std::vector<uint8_t>> image2D(image.rows, std::vector<uint8_t>(image.cols));
    std::vector<std::vector<uint8_t>> LevelMap(image.rows, std::vector<uint8_t>(image.cols));
    std::vector<std::vector<uint8_t>> ColorMap(image.rows, std::vector<uint8_t>(image.cols));
    std::vector<std::vector<float>> DegreeMap(image.rows, std::vector<float>(image.cols));

    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            image2D[i][j] = image.at<uint8_t>(i, j);
        }
    }
    int n_row=image.rows;
    int n_col=image.cols;
    int Gx;
    int Gy;
    float mg;
    float degree;
    std::tie(n_row,n_col)=F::applyPadding(image2D,n_row,n_col);

    
    for (int i = 1; i < n_row-1; ++i) {
        for (int j = 1; j < n_col-1 ; ++j) {
            std::tie(Gx,Gy)=F::applyKernel(image2D,kernelx,kernely,n_row,n_col,i,j);
            std::tie(mg,degree)=F::degree_and_mag(Gx,Gy);
            LevelMap[i-1][j-1]=F::setLevel(100,150,mg);
            DegreeMap[i-1][j-1]=degree;
            
        }
    }
    F::checkNighbers(LevelMap, ColorMap,image.rows,image.cols);
    cv::Mat reconstructedImage(image.rows, image.cols, CV_8UC1);
    for (int i = 0; i < image.rows; ++i) {
        for (int j = 0; j < image.cols; ++j) {
            reconstructedImage.at<uint8_t>(i, j) = ColorMap[i][j];
        }
    }

    // Display the image
    cv::imshow("Reconstructed Image", reconstructedImage);
    cv::waitKey(0); // Wait for a keystroke in the window

    return 0;
}