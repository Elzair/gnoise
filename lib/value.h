// -*- mode: c++; -*-

#pragma once

#include <cstdint>

#include "module.h"

namespace Noise
{
    class Value1D : public Module1D
    {
    public:

        Value1D( uint64_t seed         = 0,
                 Interp   interpMethod = Interp::Smoother ) :
            seed( seed ),
            interpMethod( interpMethod )
        {}
        
        virtual real_t getValue( real_t x ) const override;

    private:

        uint64_t seed;
        Interp   interpMethod;

        static const uint64_t X_NOISE_PRIME    = 6343;
        static const uint64_t SEED_NOISE_PRIME = 39479;

        real_t getGridValue( uint64_t x ) const;
    };

    class Value2D : public Module2D
    {
    public:

        Value2D( uint64_t seed         = 0,
                 Interp   interpMethod = Interp::Smoother ) :
            seed( seed ),
            interpMethod( interpMethod )
        {}
        
        virtual real_t getValue( real_t x, real_t y ) const override;

    private:

        uint64_t seed;
        Interp   interpMethod;

        static const uint64_t X_NOISE_PRIME    = 6343;
        static const uint64_t Y_NOISE_PRIME    = 31337;
        static const uint64_t SEED_NOISE_PRIME = 39479;

        real_t getGridValue( uint64_t x,
                             uint64_t y ) const;
    };

    class Value3D : public Module3D
    {
    public:

        Value3D( uint64_t seed         = 0,
                 Interp   interpMethod = Interp::Smoother ) :
            seed( seed ),
            interpMethod( interpMethod )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z ) const override;

    private:

        uint64_t seed;
        Interp   interpMethod;

        static const uint64_t X_NOISE_PRIME    = 6343;
        static const uint64_t Y_NOISE_PRIME    = 31337;
        static const uint64_t Z_NOISE_PRIME    = 22807;
        static const uint64_t SEED_NOISE_PRIME = 39479;

        real_t getGridValue( uint64_t x,
                             uint64_t y,
                             uint64_t z ) const;
    };
    
    class Value4D : public Module4D
    {
    public:

        Value4D( uint64_t seed         = 0,
                 Interp   interpMethod = Interp::Smoother) :
            seed( seed ),
            interpMethod( interpMethod )
        {}

        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        uint64_t seed;
        Interp   interpMethod;

        static const uint64_t X_NOISE_PRIME    = 6343;
        static const uint64_t Y_NOISE_PRIME    = 31337;
        static const uint64_t Z_NOISE_PRIME    = 22807;
        static const uint64_t W_NOISE_PRIME    = 50581;
        static const uint64_t SEED_NOISE_PRIME = 39479;

        real_t getGridValue( uint64_t x,
                             uint64_t y,
                             uint64_t z,
                             uint64_t w ) const;
    };
}
