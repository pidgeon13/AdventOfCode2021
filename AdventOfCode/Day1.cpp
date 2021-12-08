#include "Day1.h"

int Day1::NumberOfIncreases(std::vector<std::string>& measurements)
{
  size_t nMeasurements = measurements.size();
  if (nMeasurements < 2)
  {
    return 0;
  }
  int nIncreases = 0;
  double currentMeasurement = std::stod(measurements[0]);
  for (size_t i = 1; i < nMeasurements; ++i)
  {
    double nextMeasurement = std::stod(measurements[i]);
    if (nextMeasurement > currentMeasurement)
    {
      ++nIncreases;
    }
    currentMeasurement = nextMeasurement;
  }
  return nIncreases;
}

int Day1::NumberOfWindow3Increases(std::vector<std::string>& measurements)
{
  size_t nMeasurements = measurements.size();
  if (nMeasurements < 4)
  {
    return 0;
  }
  int nIncreases = 0;
  double currentMeasurement = std::stod(measurements[0]);
  for (size_t i = 1; i < nMeasurements - 2; ++i)
  {
    double futureMeasurement = std::stod(measurements[i + 2]);
    if (futureMeasurement > currentMeasurement)
    {
      ++nIncreases;
    }
    currentMeasurement = std::stod(measurements[i]);
  }
  return nIncreases;
}

int Day1::NumberOfGenericIncreases(std::vector<std::string>& measurements, int windowSize)
{
  size_t nMeasurements = measurements.size();
  if (nMeasurements < windowSize + 1)
  {
    return 0;
  }
  int nIncreases = 0;
  double currentMeasurement = std::stod(measurements[0]);
  int stepForward = windowSize - 1;
  for (size_t i = 1; i < nMeasurements - stepForward; ++i)
  {
    double futureMeasurement = std::stod(measurements[i + stepForward]);
    if (futureMeasurement > currentMeasurement)
    {
      ++nIncreases;
    }
    currentMeasurement = std::stod(measurements[i]);
  }
  return nIncreases;
}
