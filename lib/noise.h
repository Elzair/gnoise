// -*- mode: c++; -*-

#pragma once

#if defined( GODOT_MODULE )
#else

#if defined( REAL_T_IS_DOUBLE )

typedef double real_t;

#else

typedef float real_t;

#endif

#include <vector>

#endif

namespace Noise
{
    #if defined( GODOT_MODULE )
    #else
    
    template<typename T>
    using Vector = std::vector<T>;
    
    #endif

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
