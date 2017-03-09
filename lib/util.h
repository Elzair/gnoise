// -*- mode: c++; -*-

#pragma once

#include <cmath>
#include <cstdint>

#include <limits>

#include "standalone_defs.h"

namespace Noise
{
    namespace Util
    {
        static inline int64_t FastWrapIfNumPow2( int64_t x, int64_t num = 256 )
        {
            return x & ( num - 1 );
        }

        static inline uint64_t HashFNV1A( uint64_t x )
        {
            const uint64_t prime = 1099511628211; // i.e. 2^40 + 2^8 + 179
            uint64_t       hash  = 14695981039346656037;

            for ( auto i = 0; i < sizeof( uint64_t ); i++ )
            {
                hash = ( hash ^ ( x & 0xff ) ) * prime;
                x    = x >> 8;
            }

            return hash;
        }

        // This function normalizes a 64-bit unsigned integer between -1.0 and 1.0.
        static inline real_t NormalizeU64( uint64_t x )
        {
            constexpr real_t invHalfMaxU64 = 2.0 / static_cast<real_t>( std::numeric_limits<uint64_t>::max() );

            // Divide the number by half the maximum uint64_t.
            real_t step1 = x * invHalfMaxU64;
            // Current Range: 0.0 ... 2.0
        
            // Subtract 1 to normalize the value.
            real_t res = step1 - 1.0;
            // Current Range: -1.0 ... 1.0

            return res;
        }

        static inline uint64_t MakeRealU64Range( real_t x )
        {
            real_t low  = static_cast<real_t>( std::numeric_limits<int64_t>::min() );
            real_t high = static_cast<real_t>( std::numeric_limits<int64_t>::max() );

            // First, clamp to int64_t range.
            if ( x < low )
            {
                x = low;
            }
            else if ( x > high )
            {
                x = high;
            }

            // Now, convert to uint64_t range.
            real_t val = x + std::abs( low ); 

            // Finally, convert number to uint64_t.
            uint64_t res = static_cast<uint64_t>( val );

            return res;
        }

        static inline real_t Quintic( real_t t )
        {
            return t * t * t * ( t * ( t * 6 - 15 ) + 10 );
        }

        static inline real_t Lerp( real_t t, real_t a, real_t b )
        {
            return a + t * ( b - a );
        }
    }
}
