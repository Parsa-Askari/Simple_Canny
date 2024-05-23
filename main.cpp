#include<iostream>
#include<vector>
#include<tuple>
#include <algorithm>
#include<cmath>
#include<opencv2/opencv.hpp>
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
std::tuple<int,int> applyKernel(std::vector<std::vector<uint8_t>> &image2D ,int row,int col,int x,int y)
{
    int Gx=0;
    int Gy=0;
    for(size_t i=x-1;i<x+2;++i)
    {
        for(size_t j=y-1;j<y+2;++j)
        {
            Gx+=kernelx[i-(x-1)][j-(y-1)]*static_cast<int>(image2D[i][j]);
            Gy+=kernely[i-(x-1)][j-(y-1)]*static_cast<int>(image2D[i][j]);
        }
    }
    return std::make_tuple(Gx,Gy);
}
std::tuple<int,int> applyPadding(std::vector<std::vector<uint8_t>> & image2D,int n_row,int n_col)
{
    for(size_t i=0;i<n_row;++i)
    {
        image2D[i].push_back(0);
        image2D[i].insert(image2D[i].begin(),0);
    }
    std::vector<uint8_t> up(n_col,0);
    std::vector<uint8_t> down(n_col,0);
    image2D.push_back(down);
    image2D.insert(image2D.begin(),up);
    return std::make_tuple(n_row+2,n_col+2);
}
std::tuple<float,float> degree_and_mag(int Gx,int Gy)
{
    float delta=std::atan(Gy/(Gx+0.0001));
    float mg=std::sqrt(std::pow(Gx,2)+std::pow(Gy,2));
    return std::tuple(mg,delta);
}
int setLevel(int thresh1,int thresh2, int mg)
{

    if(mg<thresh1)
    {
        return 0;
    }
    else if(mg>=thresh2)
    {
        return 255;
    }
    return 1;
}
void checkNighbers(std::vector<std::vector<uint8_t>> LevelMap,std::vector<std::vector<uint8_t>> & ColorMap,int n_rows,int n_cols)
{
    for(int i=0;i<n_rows;++i)
    {
        for(int j=0;j<n_cols;++j)
        {
            
            if(LevelMap[i][j]==1)
            {
                int co=0;
                for(int k1=std::max(i-1,0);k1<std::min(i+2,n_rows);++k1)
                {
                    for(int k2=std::max(j-1,0);k2<std::min(j+2,n_cols);++k2)
                    {
                        if(k1!=i && k2!=j)
                        {
                            co+=LevelMap[k1][k2];
                        }
                    }
                }
                if(co>=255)
                {
                    ColorMap[i][j]=255;
                }
                else
                {
                    ColorMap[i][j]=0;
                }
            }
            else
            {
                ColorMap[i][j]=LevelMap[i][j];
            }
        }
    }
}
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
    std::tie(n_row,n_col)=applyPadding(image2D,n_row,n_col);

    
    for (int i = 1; i < n_row-1; ++i) {
        for (int j = 1; j < n_col-1 ; ++j) {
            std::tie(Gx,Gy)=applyKernel(image2D,n_row,n_col,i,j);
            std::tie(mg,degree)=degree_and_mag(Gx,Gy);
            LevelMap[i-1][j-1]=setLevel(100,150,mg);
            DegreeMap[i-1][j-1]=degree;
            
        }
    }
    checkNighbers(LevelMap, ColorMap,image.rows,image.cols);
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