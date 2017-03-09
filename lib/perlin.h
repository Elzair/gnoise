// -*- mode: c++; -*-

#pragma once

#include <cstdint>

#include <array>

#include "module.h"
#include "vector.h"

namespace Noise
{
    class Perlin : public virtual Module
    {
    public:

        Perlin( uint64_t seed = 0 ) : seed( seed )
        {}
        
        virtual real_t getValue( real_t x )                               const override;
        virtual real_t getValue( real_t x, real_t y )                     const override;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        uint64_t seed;

        real_t getGridValue( const Vector<1>& pos, const Vector<1>& gridpos ) const;
        real_t getGridValue( const Vector<2>& pos, const Vector<2>& gridpos ) const;
        real_t getGridValue( const Vector<3>& pos, const Vector<3>& gridpos ) const;
        real_t getGridValue( const Vector<4>& pos, const Vector<4>& gridpos ) const;
    };
}
