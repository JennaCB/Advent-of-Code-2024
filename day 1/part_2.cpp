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
    for(std::size_t i = 0; i <first_list.size(); ++i)
    {
        int amount = 0;
        for(std::size_t j = 0; second_list[j] < first_list[i]+1; ++j)
        {
            if(first_list[i] == second_list[j])
                ++amount;
        }
        sum = sum + (first_list[i] * amount);
    }

    std::cout<<"SUM: "<<sum;
}