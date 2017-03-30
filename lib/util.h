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
        uint64_t HashFNV1A( uint64_t x, uint64_t y );
        uint64_t HashFNV1A( uint64_t x, uint64_t y, uint64_t z );
        uint64_t HashFNV1A( uint64_t x, uint64_t y, uint64_t z, uint64_t w );
        uint64_t HashFNV1A( uint64_t x, uint64_t y, uint64_t z, uint64_t w, uint64_t s );

        uint64_t XORShift128Plus( uint64_t& s0, uint64_t& s1 );

        // This function normalizes a 64-bit unsigned integer between -1.0 and 1.0.
        real_t NormalizeU64( uint64_t x );

        // This function normalizes a 64-bit unsigned integer between 0.0 and 1.0.
        real_t Normalize2U64( uint64_t x );

        uint64_t MakeRealU64Range( real_t x );

        uint64_t MakeNormRealU64Range( real_t x );

        real_t Quintic( real_t t );

        real_t Lerp( real_t t, real_t a, real_t b );

        void InsertionSort( Vector<real_t>& vec );

        void InsertAndSort( real_t arr[], std::size_t n, real_t val );

        int64_t Wrap( int64_t val, int64_t low, int64_t high );

        uint64_t Factorial( uint64_t x );

        uint64_t I64ToU64( int64_t x );
    }
}
