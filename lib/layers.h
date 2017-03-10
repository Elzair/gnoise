// -*- mode: c++; -*-

#pragma once

#include <cstdint>

#include "module.h"

namespace Noise
{ 
    class Octave : public Module
    {
    public:

        Octave( Module&  source,
                uint32_t numOctaves  = 6,
                real_t   lacunarity  = 1.5,
                real_t   persistence = .75 ) :
            source( source ),
            numOctaves( numOctaves ),
            lacunarity( lacunarity ),
            persistence( persistence )
        {}
        
        virtual real_t getValue( real_t x )                               const override;
        virtual real_t getValue( real_t x, real_t y )                     const override;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        Module&  source;
        uint32_t numOctaves;
        real_t   lacunarity;
        real_t   persistence;
    };

    class RidgedMultiFractal : public Module
    {
    public:

        RidgedMultiFractal( Module&  source,
                            uint32_t numOctaves = 6,
                            real_t   lacunarity = 1.5,
                            real_t   h          = 1.0,
                            real_t   offset     = 1.0,
                            real_t   gain       = 2.0 );        

        virtual real_t getValue( real_t x )                               const override;
        virtual real_t getValue( real_t x, real_t y )                     const override;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        Module&  source;
        uint32_t numOctaves;
        real_t   lacunarity;
        real_t   h;
        real_t   offset;
        real_t   gain;

        Vector<real_t> spectralWeights;
    };
}
