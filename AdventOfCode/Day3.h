#pragma once
#include "stdIncludes.h"

namespace Day3
{
  typedef std::map <char,int> CumulativeInfo;
  void AddCurrentInfo(const std::string& binary, std::vector<CumulativeInfo>& cumulative);
  void GetGammaEpsilon(const std::vector<CumulativeInfo>& cumulative, std::string& gamma, std::string& epsilon);
  int ConvertBinaryToDecimal(const std::string& binary);
  int GetPower(const std::vector<std::string>& readings);
  void TrimReadings(std::vector<std::string>& readings, size_t i, char target);
  int GetLifeSupport(const std::vector<std::string>& readings);
  char GetTarget(const CumulativeInfo& info, bool bOxygen);
  int GetRating(const std::vector<std::string>& readings, bool bOxygen);
};

