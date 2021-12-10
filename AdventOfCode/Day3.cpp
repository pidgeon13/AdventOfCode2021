#include "Day3.h"

void Day3::AddCurrentInfo(const std::string& binary, std::vector<CumulativeInfo>& cumulative)
{
  size_t size = binary.size();
  for (int i = 0; i < size; ++i)
  {
    cumulative[i][binary[i]]++;
  }
}

void Day3::GetGammaEpsilon(const std::vector<CumulativeInfo>& cumulative, std::string& gamma, std::string& epsilon)
{
  gamma.clear();
  epsilon.clear();
  for (const CumulativeInfo& info : cumulative)
  {
    bool bContainsZero = info.find('0') != info.end();
    bool bContainsOne = info.find('1') != info.end();
    if (!bContainsZero || (bContainsOne && info.at('1') > info.at('0')))
    {
      gamma.append("1");
      epsilon.append("0");
    }
    else
    {
      gamma.append("0");
      epsilon.append("1");
    }
  }
}

int Day3::ConvertBinaryToDecimal(const std::string& binary)
{
  int decimal = 0;
  size_t size = binary.size();
  for (size_t i = 0; i < size; ++i)
  {
    if (binary[size - 1 - i] == '1')
    {
      decimal += std::pow(2,i);
    }
  }
  return decimal;
}

int Day3::GetPower(const std::vector<std::string>& readings)
{
  if (readings.empty())
  {
    return 0;
  }
  size_t binaryDigits = readings[0].size();
  std::vector<CumulativeInfo> cumulative(binaryDigits);
  for (const std::string& reading : readings)
  {
    AddCurrentInfo(reading, cumulative);
  }
  std::string gamma;
  std::string epsilon;
  GetGammaEpsilon(cumulative, gamma, epsilon);
  int gam = ConvertBinaryToDecimal(gamma);
  int eps = ConvertBinaryToDecimal(epsilon);
  return  gam*eps;
}

void Day3::TrimReadings(std::vector<std::string>& readings, size_t i, char target)
{
  std::vector<std::string> newReadings;
  newReadings.reserve(readings.size());
  for (const std::string& reading : readings)
  {
    if (reading[i] == target)
    {
      newReadings.push_back(reading);
    }
  }
  readings = newReadings;
}

int Day3::GetLifeSupport(const std::vector<std::string>& readings)
{
  return GetRating(readings, true)* GetRating(readings, false);
}

char Day3::GetTarget(const CumulativeInfo& info, bool bOxygen)
{
  bool bContainsZero = info.find('0') != info.end();
  bool bContainsOne = info.find('1') != info.end();
  char ret = '0';
  if (bOxygen)
  {
    if (!bContainsZero || (bContainsOne && info.at('1') >= info.at('0')))
    {
      ret = '1';
    }
    else
    {
      ret = '0';
    }
  }
  else
  {
    if (!bContainsZero || (bContainsOne && info.at('1') >= info.at('0')))
    {
      ret = '0';
    }
    else
    {
      ret = '1';
    }
  }
  return ret;
}

int Day3::GetRating(const std::vector<std::string>& readings, bool bOxygen)
{
  if (readings.empty())
  {
    return 0;
  }
  std::vector<std::string> readingsCopy = readings;
  size_t binaryDigits = readingsCopy[0].size();
  for (size_t i = 0; i < binaryDigits; ++i)
  {
    std::vector<CumulativeInfo> cumulative(binaryDigits);
    for (const std::string& reading : readingsCopy)
    {
      AddCurrentInfo(reading, cumulative);
    }
    char target = GetTarget(cumulative[i], bOxygen);
    TrimReadings(readingsCopy, i, target);
    if (readingsCopy.size() == 1)
    {
      break;
    }
  }
  return ConvertBinaryToDecimal(readingsCopy[0]);
}
