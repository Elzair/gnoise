// -*- mode: c++; -*-

#pragma once

#if defined( REAL_T_IS_DOUBLE )

typedef double real_t;

#else

typedef float real_t;

#endif

#include <vector>

namespace Noise
{
    template<typename T>
    using Vector = std::vector<T>;

    enum class Distance
    {
        Euclidian,
        Manhattan,
        Chebyshev
    };

    enum class Interp
    {
        Smooth,
        Smoother
    };
}
