#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool decreasing_correctly(const std::vector<int>& report, int i)
{
    if(i+1 == report.size())
      return true;
    if(report[i] - report[i+1] <=3 && report[i] - report[i+1] >= 1)
      return (decreasing_correctly(report, i+1));
    return false;
}

bool increasing_correctly(const std::vector<int>& report, int i)
{
    if(i+1 == report.size())
      return true;
    if(report[i+1] - report[i] <=3 && report[i+1] - report[i] >= 1)
      return (increasing_correctly(report, i+1));
    return false;
}

bool is_safe(const std::vector<int>& report)
{
    if(decreasing_correctly(report, 0))
        return true;
    else if(increasing_correctly(report, 0))
        return true;
    return false;
}

bool could_be_safed(std::vector<int>& report)
{
    for(std::size_t i = 0; i < report.size(); ++i)
    {
        std::vector<int> report_copy = report;

        report_copy.erase(report_copy.begin() + i);
        if(is_safe(report_copy))
            return true;
    }
    return false;
}

int main(int argc, char* argv[])
{
    std::ifstream input(argv[1]);

    std::vector<int> report;
    std::vector<std::vector<int>> unsafe_reports;
    int safe_reports;

    std::string line;
    while(std::getline(input, line))
    {
        std::string level;
        for(char c : line)
        {
            if(c == ' ')
            {
                report.push_back(std::stoi(level));
                level.clear();
            }
            else
            {
                level.push_back(c);
            }
        }
        report.push_back(std::stoi(level));
        level.clear();

        if(is_safe(report))
            ++safe_reports;
        else
            unsafe_reports.push_back(report);
        
        report.clear();
    }

    for(std::vector<int> report : unsafe_reports)
    {
        if(could_be_safed(report))
            ++safe_reports;
    }

    std::cout<<"Valid Reports: "<<safe_reports;
}