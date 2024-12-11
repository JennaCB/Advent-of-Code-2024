#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<char>> load_grid(std::ifstream& input)
{
    std::vector<std::vector<char>> grid;

    std::string line;
    while(std::getline(input, line))
        grid.push_back(std::vector<char>(line.begin(), line.end()));

    return grid;
}

int main(int argc, char* argv[])
{
    std::ifstream input(argv[1]);

    std::vector<std::vector<char>> grid = load_grid(input);
    int xmas_counter = 0;

    for(int i = 0; i < grid.size(); ++i)
    {
        for(int j = 0; j < grid[i].size(); ++j)
        {
            if(grid[i][j] == 'A' && i-1 >= 0 && j-1 >= 0 && i+1 < grid.size() && j+1 < grid[i].size())
            {
                if(grid[i+1][j+1] == 'S')
                {
                    if(grid[i+1][j-1] == 'M' && grid[i-1][j-1] == 'M' && grid[i-1][j+1] == 'S')
                        ++xmas_counter;
                    else if(grid[i+1][j-1] == 'S' && grid[i-1][j-1] == 'M' && grid[i-1][j+1] == 'M')
                        ++xmas_counter;
                }
                else if(grid[i+1][j+1] == 'M')
                {
                    if(grid[i+1][j-1] == 'M' && grid[i-1][j-1] == 'S' && grid[i-1][j+1] == 'S')
                        ++xmas_counter;
                    else if(grid[i+1][j-1] == 'S' && grid[i-1][j-1] == 'S' && grid[i-1][j+1] == 'M')
                        ++xmas_counter;
                }
            }
        }
    }

    std::cout<<"SUM: "<<xmas_counter;
}