#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
    std::ifstream input(argv[1]);

    std::vector<int> first_list;
    std::vector<int> second_list;

    int one, two;
    while(input >> one >> two)
    {
        first_list.push_back(one);
        second_list.push_back(two);
    }

    std::sort(first_list.begin(), first_list.end());
    std::sort(second_list.begin(), second_list.end());
    
    int sum = 0;
    for(int i = 0; i < second_list.size(); ++i)
    {
        if(first_list[i] < second_list[i])
            sum = sum + second_list[i] - first_list[i];
        else
            sum = sum + first_list[i] - second_list[i];
    }

    std::cout<<"SUM: "<<sum;
}