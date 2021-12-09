
#include "stdIncludes.h"
#include "Utils.h"
#include "Day2.h"

int main()
{
  std::vector<std::string> commands;
  commands.reserve(1000); //Cheating as I know the file length.
  std::string filename = "input2.txt";
  Utils::Import(filename, commands);
  double x = Day2::MultiplyDepthHorz(commands);
  std::cout << std::setprecision(10);
  std::cout << x;
  return 0;
}