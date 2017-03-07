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

        static const uint64_t X_NOISE_GEN     = 1619;
        static const uint64_t Y_NOISE_GEN     = 31337;
        static const uint64_t Z_NOISE_GEN     = 6971;
        static const uint64_t A_NOISE_GEN     = 9067;
        static const uint64_t SEED_NOISE_GEN  = 1013;
        static const uint64_t SHIFT_NOISE_GEN = 8;

        real_t getGridValue( uint64_t x,
                             uint64_t y = 0,
                             uint64_t z = 0,
                             uint64_t a = 0 ) const;
    };
}
