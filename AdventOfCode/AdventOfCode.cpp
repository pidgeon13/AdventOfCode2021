
#include "stdIncludes.h"
#include "Utils.h"
#include "Day1.h"

int main()
{
  std::vector<std::string> measurements;
  measurements.reserve(2000); //Cheating as I know the file length.
  std::string filename = "input1.txt";
  Utils::Import(filename, measurements);
  std::cout << Day1::NumberOfGenericIncreases(measurements, 3);
  return 0;
}