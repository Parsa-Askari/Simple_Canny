#include<tuple>
#include<vector>
#include<iostream>
#include<cmath>
#include"functions.hpp"
#include<algorithm>
std::tuple<int,int> F::applyKernel(std::vector<std::vector<uint8_t>> &image2D , 
    std::vector<std::vector<int>> kernelx ,std::vector<std::vector<int>> kernely,int row,int col,int x,int y)
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

std::tuple<int,int> F::applyPadding(std::vector<std::vector<uint8_t>> & image2D,int n_row,int n_col)
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

std::tuple<float,float> F::degree_and_mag(int Gx,int Gy)
{
    float delta=std::atan(Gy/(Gx+0.0001));
    float mg=std::sqrt(std::pow(Gx,2)+std::pow(Gy,2));
    return std::tuple(mg,delta);
}

int F::setLevel(int thresh1,int thresh2, int mg)
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

void F::checkNighbers(std::vector<std::vector<uint8_t>> LevelMap,std::vector<std::vector<uint8_t>> & ColorMap,int n_rows,int n_cols)
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