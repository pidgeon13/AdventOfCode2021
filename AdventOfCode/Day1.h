#pragma once
#include "stdIncludes.h"

namespace Day1
{
  int NumberOfIncreases(std::vector<std::string>& measurements);
  int NumberOfWindow3Increases(std::vector<std::string>& measurements);
  int NumberOfGenericIncreases(std::vector<std::string>& measurements, int windowSize);
};

