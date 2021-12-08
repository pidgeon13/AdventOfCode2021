#include "Utils.h"

void Utils::Import(std::string& filename, std::vector<std::string>& lines)
{
  std::ifstream inputFile(filename);
  if (inputFile.is_open())
  {
    while (inputFile.good())
    {
      std::string line;
      std::getline(inputFile, line);
      lines.push_back(line);
    }
  }
}
