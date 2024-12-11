#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    std::ifstream input(argv[1]);

    int sum = 0;

    std::regex reg_sequence("(mul\\([0-9]{1,3},[0-9]{1,3}\\))");
    std::regex reg_number("([0-9]{1,3})");

    std::string line;
    while(std::getline(input, line))
    {
        std::smatch matches_sequences;
        while(std::regex_search(line, matches_sequences, reg_sequence))
        {
            std::string sequence = matches_sequences.str(1);

            std::vector<int> numbers;

            std::smatch matches_numbers;
            while(std::regex_search(sequence, matches_numbers, reg_number))
            {
                numbers.push_back(std::stoi(matches_numbers.str(1)));
                sequence = matches_numbers.suffix().str();
            }
            sum = sum + (numbers[0] * numbers[1]);
            numbers.clear();

            line = matches_sequences.suffix().str();
        }
    }
    std::cout<<"SUM: "<<sum;
}