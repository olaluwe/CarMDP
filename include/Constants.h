#ifndef __CONSTANTS__H__
#define __CONSTANTS__H__

#include <vector>

class Constants {
  public:
    const double THRESHOLD = 0.001;
    const std::vector<double> V_INITIAL = {0.0, 0.0};
    const int MAX_ITERATIONS = 1000;
};

#endif  //!__CONSTANTS__H__