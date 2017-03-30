// -*- mode: c++; -*-

#pragma once

#include <cmath>
#include <cstdint>

#include <array>
#include <limits>

#include "noise.h"

namespace Noise
{
    namespace Util
    {
        // These functions produce a hash of the input values using the FNV-1A algorithm.
        uint64_t Hash( uint64_t x );
        uint64_t Hash( uint64_t x, uint64_t y );
        uint64_t Hash( uint64_t x, uint64_t y, uint64_t z );
        uint64_t Hash( uint64_t x, uint64_t y, uint64_t z, uint64_t w );
        uint64_t Hash( uint64_t x, uint64_t y, uint64_t z, uint64_t w, uint64_t r );

        // This function generates a random 64-bit integer using XORShift128+.
        uint64_t RNG( uint64_t& s0, uint64_t& s1 );

        // This function normalizes a 64-bit unsigned integer between -1.0 and 1.0.
        real_t U64ToReal( uint64_t x );

        // This function normalizes a 64-bit unsigned integer between 0.0 and 1.0.
        real_t U64ToNormReal( uint64_t x );

        uint64_t I64ToU64( int64_t x );

        uint64_t RealToU64( real_t x );

        uint64_t NormRealToU64( real_t x );

        real_t Lerp( real_t t, real_t a, real_t b );

        void InsertionSort( Noise::Vector<real_t>& vec );

        void InsertAndSort( real_t* arr, std::size_t n, real_t val );

        int64_t Wrap( int64_t val, int64_t low, int64_t high );

        uint64_t Factorial( uint64_t x );

        namespace Interpolation
        {
            real_t SmoothStep( real_t t );

            real_t SmootherStep( real_t t );
        }
    }
}
