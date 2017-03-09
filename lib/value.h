// -*- mode: c++; -*-

#pragma once

#include <cstdint>

#include "math_defs.h"
#include "module.h"

namespace Noise
{
    class Value : public virtual Module
    {
    public:

        Value( uint64_t seed = 0 ) : seed( seed )
        {}
        
        virtual real_t getValue( real_t x )                               const override;
        virtual real_t getValue( real_t x, real_t y )                     const override;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        uint64_t seed;

        static const uint64_t X_NOISE_PRIME     = 6'343;
        static const uint64_t Y_NOISE_PRIME     = 31'337;
        static const uint64_t Z_NOISE_PRIME     = 22'807;
        static const uint64_t A_NOISE_PRIME     = 50'581;
        static const uint64_t SEED_NOISE_PRIME  = 39'479;

        real_t getGridValue( uint64_t x,
                             uint64_t y = 0,
                             uint64_t z = 0,
                             uint64_t a = 0 ) const;
    };
}
