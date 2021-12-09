#pragma once
#include "stdIncludes.h"

namespace Day2
{

  bool ParseString(const std::string& command, double& depth, double& horz);
  double MultiplyDepthHorz(const std::vector<std::string>& commands);

};

