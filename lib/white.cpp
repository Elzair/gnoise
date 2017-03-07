#include "math_defs.h"
#include "util.h"
#include "white.h"

namespace Noise
{
    real_t White::getValue( real_t x ) const
    {
        auto xr  = XORShift128Plus( this->seed, this->convertRealToU64( x ) );
        auto res = NormalizeU64( xr );

        return res;
    }

    real_t White::getValue( real_t x, real_t y ) const
    {
        auto xr  = XORShift128Plus( this->seed, this->convertRealToU64( x ) );
        auto yr  = XORShift128Plus( this->seed, this->convertRealToU64( y ) );
        auto res = NormalizeU64( xr ^ yr );

        return res;
    }

    real_t White::getValue( real_t x, real_t y, real_t z ) const
    {
        auto xr  = XORShift128Plus( this->seed, this->convertRealToU64( x ) );
        auto yr  = XORShift128Plus( this->seed, this->convertRealToU64( y ) );
        auto zr  = XORShift128Plus( this->seed, this->convertRealToU64( z ) );
        auto res = NormalizeU64( xr ^ yr ^ zr );

        return res;
    }

    real_t White::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto xr  = XORShift128Plus( this->seed, this->convertRealToU64( x ) );
        auto yr  = XORShift128Plus( this->seed, this->convertRealToU64( y ) );
        auto zr  = XORShift128Plus( this->seed, this->convertRealToU64( z ) );
        auto ar  = XORShift128Plus( this->seed, this->convertRealToU64( a ) );
        auto res = NormalizeU64( xr ^ yr ^ zr ^ ar );

        return res;
    }

    uint64_t White::convertRealToU64( real_t x ) const
    {
        uint64_t X = 0;

        #ifdef REAL_T_IS_DOUBLE
        // Use the bits of the 64-bit floating point number as a 64-bit unsigned integer.
        X            = *( reinterpret_cast<uint64_t*>( &x ) );
        #else
        // If the floating point number is only 32-bit, we need to copy it into a
        // 32-bit unsigned integer before copying it to the 64-bit unsigned integer.
        // This way we avoid copying 32-bits of random data after x in memory.
        uint32_t  X1  = *( reinterpret_cast<uint32_t*>( &x ) );
        X             = ( uint64_t )X1;
        #endif

        return X;
    }
}
