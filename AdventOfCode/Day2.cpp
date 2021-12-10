#include "Day2.h"

bool Day2::ParseString(const std::string& command, double& depth, double& horz)
{
  bool bCorrectCommandFound = false;
  const std::string forward = "forward";
  const std::string down = "down";
  const std::string up = "up";
  size_t pos = command.find(forward);
  if (pos != std::string::npos)
  {
    std::string substring = command.substr(forward.size());
    double move = std::stod(substring);
    horz += move;
    bCorrectCommandFound = true;
  }
  pos = command.find(down);
  if (pos != std::string::npos)
  {
    std::string substring = command.substr(down.size());
    double move = std::stod(substring);
    depth += move;
    bCorrectCommandFound = true;
  }
  pos = command.find(up);
  if (pos != std::string::npos)
  {
    std::string substring = command.substr(up.size());
    double move = std::stod(substring);
    depth -= move;
    bCorrectCommandFound = true;
  }
  return bCorrectCommandFound;
}

bool Day2::ParseString2(const std::string& command, double & depth, double & horz, double & aim)
{
  bool bCorrectCommandFound = false;
  const std::string forward = "forward";
  const std::string down = "down";
  const std::string up = "up";
  size_t pos = command.find(forward);
  if (pos != std::string::npos)
  {
    std::string substring = command.substr(forward.size());
    double move = std::stod(substring);
    horz += move;
    depth += (aim*move);
    bCorrectCommandFound = true;
  }
  pos = command.find(down);
  if (pos != std::string::npos)
  {
    std::string substring = command.substr(down.size());
    double move = std::stod(substring);
    aim += move;
    bCorrectCommandFound = true;
  }
  pos = command.find(up);
  if (pos != std::string::npos)
  {
    std::string substring = command.substr(up.size());
    double move = std::stod(substring);
    aim -= move;
    bCorrectCommandFound = true;
  }
  return bCorrectCommandFound;
}

double Day2::MultiplyDepthHorz(const std::vector<std::string>& commands)
{
  size_t nCommands = commands.size();
  double depth = 0;
  double horz = 0;
  double aim = 0;
  for (size_t i = 0; i < nCommands; ++i)
  {
    ParseString2(commands[i], depth, horz, aim);
  }
  return depth * horz;
}
