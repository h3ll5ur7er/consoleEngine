#pragma once

#include <string>

#include "math/vector/vec2i.hpp"
#include "math/vector/vec2f.hpp"
#include "math/vector/vec3f.hpp"
#include "math/vector/vec4f.hpp"

#include "math/matrix/mat2f.hpp"
#include "math/matrix/mat3f.hpp"
#include "math/matrix/mat4f.hpp"

const float PI = 3.14159265358979323846f;

std::string toFixed(float f, int precision=2);
