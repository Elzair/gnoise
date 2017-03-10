// -*- mode: c++; -*-

#pragma once

#ifdef REAL_T_IS_DOUBLE

typedef double real_t;

#else

typedef float real_t;

#endif

#include <vector>

template<typename T>
using Vector = std::vector<T>;
