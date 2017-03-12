// -*- mode: c++; -*-

#pragma once

#include <cstdint>

#include <array>

#include "module.h"
#include "vector.h"

namespace Noise
{
    class Perlin1D : public Module1D
    {
    public:

        Perlin1D( uint64_t seed = 0 ) : seed( seed )
        {}
        
        virtual real_t getValue( real_t x )                               const override;
    private:

        uint64_t seed;

        real_t getGridValue( const Noise::VectorN<1>& pos,
                             const Noise::VectorN<1>& gridpos ) const;
    };
    
    class Perlin2D : public Module2D
    {
    public:

        Perlin2D( uint64_t seed = 0 ) : seed( seed )
        {}
        
        virtual real_t getValue( real_t x, real_t y )                     const override;

    private:

        uint64_t seed;

        real_t getGridValue( const Noise::VectorN<2>& pos,
                             const Noise::VectorN<2>& gridpos ) const;
    };
    
    class Perlin3D : public Module3D
    {
    public:

        Perlin3D( uint64_t seed = 0 ) : seed( seed )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;

    private:

        uint64_t seed;

        real_t getGridValue( const Noise::VectorN<3>& pos,
                             const Noise::VectorN<3>& gridpos ) const;
    };
    
    class Perlin4D : public Module4D
    {
    public:

        Perlin4D( uint64_t seed = 0 ) : seed( seed )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        uint64_t seed;

        real_t getGridValue( const Noise::VectorN<4>& pos,
                             const Noise::VectorN<4>& gridpos ) const;
    };
}
