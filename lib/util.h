// -*- mode: c++; -*-

#pragma once

#include <cmath>
#include <cstdint>

#include <limits>

#include "standalone_defs.h"

#include "glsl.h"

namespace Noise
{
    namespace Util
    {
        uint64_t HashFNV1A( uint64_t x );

        uint64_t XORShift128Plus( uint64_t& s0, uint64_t& s1 );

        // This function normalizes a 64-bit unsigned integer between -1.0 and 1.0.
        real_t NormalizeU64( uint64_t x );

        uint64_t MakeRealU64Range( real_t x );

        real_t Quintic( real_t t );

        real_t Lerp( real_t t, real_t a, real_t b );
    }
}
