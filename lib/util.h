// -*- mode: c++; -*-

#pragma once

#include <cstdint>

#include "math_defs.h"

namespace Noise
{
    static inline int64_t FastWrapIfNumPow2( int64_t x, int64_t num = 256 )
    {
        return x & ( num - 1 );
    }

    static inline uint64_t XORShift128Plus( uint64_t s0, uint64_t s1 )
    {
        uint64_t       x = s0;
        const uint64_t y = s1;
        s0               = y;
        x               ^= x << 23;
        s1               = x ^ y ^ ( x >> 17 ) ^ ( y >> 26 );
        return s1 + y;
    }

    // This function normalizes a 64-bit unsigned integer between -1.0 and 1.0.
    static inline real_t NormalizeU64( uint64_t x )
    {
        const     uint64_t mask        = 0x7fffffffffffffff;             // i.e. 2^63
        constexpr real_t   inv_max_val = 1.0 / 4.611686018427387904e+18; // i.e. 1 / 2^62

        // First, strip the 2 most significant bits from the input value.
        uint64_t step1 = x & mask;
        // Current Range: 0 ... 2^63 - 1

        // Next, divide value by 2^62.
        real_t step2 = static_cast<real_t>( step1 ) * inv_max_val;
        // Current Range: 0.0 ... 2.0

        // Finally, subtract value from 1.0 to normalize it.
        real_t xnorm = 1.0 - step2;
        // Current Range: -1.0 ... 1.0

        return xnorm;
    }

    static inline real_t Quintic( real_t t )
    {
        return t * t * t * ( t * ( t * 6 - 15 ) + 10 );
    }

    static inline real_t Lerp( real_t t, real_t a, real_t b )
    {
        return a + t * ( b - a );
    }

    static inline real_t InvSqrt( real_t num )
    {
        constexpr real_t threehalfs = 3.0 / 2.0;

        real_t x2, y;

        x2 = num * 0.5;
        y  = num;

        #if REAL_T_IS_DOUBLE
        uint64_t     i;
        const real_t weird_constant = 0x5fe6eb50c7b537a9;

        i = *( reinterpret_cast<uint64_t*>( &y ) );
        #else
        uint32_t     i;
        const real_t weird_constant = 0x5f3759df;

        i = *( reinterpret_cast<uint32_t*>( &y ) );
        #endif

        i = weird_constant - ( i >> 1 );
        
        y = *( reinterpret_cast<real_t*>( &i ) );
        
        y = y * ( threehalfs - ( x2 * y * y ) );

        return y;
    }
}
