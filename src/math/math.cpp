#include "math.h"

#include <iomanip>
#include <sstream>

std::string toFixed(float f, int precision=2) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(precision) << f;
    return  ss.str();
}
