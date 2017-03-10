// -*- mode: c++; -*-

#pragma once

#include <cstdint>

#include "module.h"

namespace Noise
{ 
    class Worley : public Module
    {
    public:

        Worley( uint64_t seed ) :
            seed( seed )
        {}
        
        virtual real_t getValue( real_t x )                               const override;
        virtual real_t getValue( real_t x, real_t y )                     const override;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        uint64_t seed;
    };
}
