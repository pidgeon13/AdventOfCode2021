#pragma once
#include "stdIncludes.h"

namespace Day1
{
  int NumberOfIncreases(const std::vector<std::string>& measurements);
  int NumberOfWindow3Increases(const std::vector<std::string>& measurements);
  int NumberOfGenericIncreases(const std::vector<std::string>& measurements, int windowSize);
};

