#include<iostream>
#include<vector>

int main()
{
    std::vector<std::vector<int>> ls={{1,2,3,4},{5,6,7,8},{1,2,3,4}};
    std::vector<std::vector<int>>l=std::vector<std::vector<int>(ls[0].begin(),ls[0].end())>(ls.begin(),ls.end());

}