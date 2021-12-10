
#include "stdIncludes.h"
#include "Utils.h"
#include "Day3.h"

int main()
{
  std::vector<std::string> inputs;
  inputs.reserve(1000); //Cheating as I know the file length.
  std::string filename = "input3.txt";
  //std::string filename = "mini.txt";
  Utils::Import(filename, inputs);
  double x = Day3::GetLifeSupport(inputs);
  std::cout << std::setprecision(10);
  std::cout << x;
  return 0;
}