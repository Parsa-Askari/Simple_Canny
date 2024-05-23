#pragma once
#include<tuple>
#include<vector>
#include<iostream>
#include<algorithm>
namespace F{
    std::tuple<int,int> applyKernel(std::vector<std::vector<uint8_t>> &image2D , 
        std::vector<std::vector<int>> kernelx ,std::vector<std::vector<int>> kernely,int row,int col,int x,int y);

    std::tuple<int,int> applyPadding(std::vector<std::vector<uint8_t>> & image2D,int n_row,int n_col);

    std::tuple<float,float> degree_and_mag(int Gx,int Gy);

    int setLevel(int thresh1,int thresh2, int mg);

    void checkNighbers(std::vector<std::vector<uint8_t>> LevelMap,std::vector<std::vector<uint8_t>> & ColorMap,int n_rows,int n_cols);
};