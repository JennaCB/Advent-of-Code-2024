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
            if(grid[i][j] == 'X')
            {
                if(j+3 < grid[i].size() && grid[i][j+1] == 'M') // right
                {
                    if(grid[i][j+2] == 'A')
                    {
                        if(grid[i][j+3] == 'S')
                            ++xmas_counter;
                    }
                }
                if(j+3 < grid[i].size() && i+3 < grid.size() && grid[i+1][j+1] == 'M') // right down
                {
                    if(grid[i+2][j+2] == 'A')
                    {
                        if(grid[i+3][j+3] == 'S')
                            ++xmas_counter;
                    }
                }
                if(i+3 < grid.size() && grid[i+1][j] == 'M') // down
                {
                    if(grid[i+2][j] == 'A')
                    {
                        if(grid[i+3][j] == 'S')
                            ++xmas_counter;
                    }
                }
                if(j-3 >= 0 && i+3 < grid.size() && grid[i+1][j-1] == 'M') // left down
                {
                    if(grid[i+2][j-2] == 'A')
                    {
                        if(grid[i+3][j-3] == 'S')
                            ++xmas_counter;
                    }
                }
                if(j-3 >= 0 && grid[i][j-1] == 'M') // left
                {
                    if(grid[i][j-2] == 'A')
                    {
                        if(grid[i][j-3] == 'S')
                            ++xmas_counter;
                    }
                }
                if(j-3 >= 0 && i-3 >= 0 && grid[i-1][j-1] == 'M') // left up
                {
                    if(grid[i-2][j-2] == 'A')
                    {
                        if(grid[i-3][j-3] == 'S')
                            ++xmas_counter;
                    }
                }
                if(i-3 >= 0 && grid[i-1][j] == 'M') // up
                {
                    if(grid[i-2][j] == 'A')
                    {
                        if(grid[i-3][j] == 'S')
                            ++xmas_counter;
                    }
                }
                if(j+3 < grid[i].size() && i-3 >= 0 && grid[i-1][j+1] == 'M') // right up
                {
                    if(grid[i-2][j+2] == 'A')
                    {
                        if(grid[i-3][j+3] == 'S')
                            ++xmas_counter;
                    }
                }
            }
        }
    }

    std::cout<<"SUM: "<<xmas_counter;
}