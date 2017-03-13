// -*- mode: c++; -*-

#pragma once

#include <cstdint>

#include "module.h"

namespace Noise
{ 
    class Billow1D : public Module1D
    {
    public:

        Billow1D( Module1D& source,
                  uint32_t  numOctaves  = 6,
                  real_t    lacunarity  = 2.0,
                  real_t    persistence = 0.5 ) :
            source( source ),
            numOctaves( numOctaves ),
            lacunarity( lacunarity ),
            persistence( persistence )
        {}
        
        virtual real_t getValue( real_t x ) const override;

    private:

        Module1D& source;
        uint32_t  numOctaves;
        real_t    lacunarity;
        real_t    persistence;
    };

    class Billow2D : public Module2D
    {
    public:

        Billow2D( Module2D& source,
                  uint32_t  numOctaves  = 6,
                  real_t    lacunarity  = 2.0,
                  real_t    persistence = 0.5 ) :
            source( source ),
            numOctaves( numOctaves ),
            lacunarity( lacunarity ),
            persistence( persistence )
        {}
        
        virtual real_t getValue( real_t x, real_t y ) const override;

    private:

        Module2D& source;
        uint32_t  numOctaves;
        real_t    lacunarity;
        real_t    persistence;
    };

    class Billow3D : public Module3D
    {
    public:

        Billow3D( Module3D& source,
                  uint32_t  numOctaves  = 6,
                  real_t    lacunarity  = 2.0,
                  real_t    persistence = 0.5 ) :
            source( source ),
            numOctaves( numOctaves ),
            lacunarity( lacunarity ),
            persistence( persistence )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z ) const override;

    private:

        Module3D& source;
        uint32_t  numOctaves;
        real_t    lacunarity;
        real_t    persistence;
    };

    class Billow4D : public Module4D
    {
    public:

        Billow4D( Module4D& source,
                  uint32_t  numOctaves  = 6,
                  real_t    lacunarity  = 2.0,
                  real_t    persistence = 0.5 ) :
            source( source ),
            numOctaves( numOctaves ),
            lacunarity( lacunarity ),
            persistence( persistence )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        Module4D& source;
        uint32_t  numOctaves;
        real_t    lacunarity;
        real_t    persistence;
    };

    class Fractal1D : public Module1D
    {
    public:

        Fractal1D( Module1D& source,
                   uint32_t  numOctaves  = 6,
                   real_t    lacunarity  = 2.0,
                   real_t    persistence = 0.5 ) :
            source( source ),
            numOctaves( numOctaves ),
            lacunarity( lacunarity ),
            persistence( persistence )
        {}
        
        virtual real_t getValue( real_t x ) const override;

    private:

        Module1D& source;
        uint32_t  numOctaves;
        real_t    lacunarity;
        real_t    persistence;
    };

    class Fractal2D : public Module2D
    {
    public:

        Fractal2D( Module2D& source,
                   uint32_t  numOctaves  = 6,
                   real_t    lacunarity  = 2.0,
                   real_t    persistence = 0.5 ) :
            source( source ),
            numOctaves( numOctaves ),
            lacunarity( lacunarity ),
            persistence( persistence )
        {}
        
        virtual real_t getValue( real_t x, real_t y ) const override;

    private:

        Module2D& source;
        uint32_t  numOctaves;
        real_t    lacunarity;
        real_t    persistence;
    };

    class Fractal3D : public Module3D
    {
    public:

        Fractal3D( Module3D& source,
                   uint32_t  numOctaves  = 6,
                   real_t    lacunarity  = 2.0,
                   real_t    persistence = 0.5 ) :
            source( source ),
            numOctaves( numOctaves ),
            lacunarity( lacunarity ),
            persistence( persistence )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z ) const override;

    private:

        Module3D& source;
        uint32_t  numOctaves;
        real_t    lacunarity;
        real_t    persistence;
    };

    class Fractal4D : public Module4D
    {
    public:

        Fractal4D( Module4D& source,
                   uint32_t  numOctaves  = 6,
                   real_t    lacunarity  = 2.0,
                   real_t    persistence = 0.5 ) :
            source( source ),
            numOctaves( numOctaves ),
            lacunarity( lacunarity ),
            persistence( persistence )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        Module4D& source;
        uint32_t  numOctaves;
        real_t    lacunarity;
        real_t    persistence;
    };

    class MultiFractal1D : public Module1D
    {
    public:

        MultiFractal1D( Module1D& source,
                   uint32_t  numOctaves  = 6,
                   real_t    lacunarity  = 2.0,
                   real_t    persistence = 0.5 ) :
            source( source ),
            numOctaves( numOctaves ),
            lacunarity( lacunarity ),
            persistence( persistence )
        {}
        
        virtual real_t getValue( real_t x ) const override;

    private:

        Module1D& source;
        uint32_t  numOctaves;
        real_t    lacunarity;
        real_t    persistence;
    };

    class MultiFractal2D : public Module2D
    {
    public:

        MultiFractal2D( Module2D& source,
                   uint32_t  numOctaves  = 6,
                   real_t    lacunarity  = 2.0,
                   real_t    persistence = 0.5 ) :
            source( source ),
            numOctaves( numOctaves ),
            lacunarity( lacunarity ),
            persistence( persistence )
        {}
        
        virtual real_t getValue( real_t x, real_t y ) const override;

    private:

        Module2D& source;
        uint32_t  numOctaves;
        real_t    lacunarity;
        real_t    persistence;
    };

    class MultiFractal3D : public Module3D
    {
    public:

        MultiFractal3D( Module3D& source,
                   uint32_t  numOctaves  = 6,
                   real_t    lacunarity  = 2.0,
                   real_t    persistence = 0.5 ) :
            source( source ),
            numOctaves( numOctaves ),
            lacunarity( lacunarity ),
            persistence( persistence )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z ) const override;

    private:

        Module3D& source;
        uint32_t  numOctaves;
        real_t    lacunarity;
        real_t    persistence;
    };

    class MultiFractal4D : public Module4D
    {
    public:

        MultiFractal4D( Module4D& source,
                   uint32_t  numOctaves  = 6,
                   real_t    lacunarity  = 2.0,
                   real_t    persistence = 0.5 ) :
            source( source ),
            numOctaves( numOctaves ),
            lacunarity( lacunarity ),
            persistence( persistence )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        Module4D& source;
        uint32_t  numOctaves;
        real_t    lacunarity;
        real_t    persistence;
    };

    class RidgedMultiFractal1D : public Module1D
    {
    public:

        RidgedMultiFractal1D( Module1D& source,
                              uint32_t  numOctaves = 6,
                              real_t    lacunarity = 1.5,
                              real_t    h          = 1.0,
                              real_t    offset     = 1.0,
                              real_t    gain       = 2.0 ) :
            source( source ),
            numOctaves( numOctaves ),
            lacunarity( lacunarity ),
            h( h ),
            offset( offset ),
            gain( gain )
        {}       

        virtual real_t getValue( real_t x ) const override;

    private:

        Module1D& source;
        uint32_t  numOctaves;
        real_t    lacunarity;
        real_t    h;
        real_t    offset;
        real_t    gain;
    };

    class RidgedMultiFractal2D : public Module2D
    {
    public:

        RidgedMultiFractal2D( Module2D& source,
                              uint32_t  numOctaves = 6,
                              real_t    lacunarity = 1.5,
                              real_t    h          = 1.0,
                              real_t    offset     = 1.0,
                              real_t    gain       = 2.0 ) :
            source( source ),
            numOctaves( numOctaves ),
            lacunarity( lacunarity ),
            h( h ),
            offset( offset ),
            gain( gain )
        {}      

        virtual real_t getValue( real_t x, real_t y ) const override;

    private:

        Module2D& source;
        uint32_t  numOctaves;
        real_t    lacunarity;
        real_t    h;
        real_t    offset;
        real_t    gain;
    };

    class RidgedMultiFractal3D : public Module3D
    {
    public:

        RidgedMultiFractal3D( Module3D& source,
                              uint32_t  numOctaves = 6,
                              real_t    lacunarity = 1.5,
                              real_t    h          = 1.0,
                              real_t    offset     = 1.0,
                              real_t    gain       = 2.0 ) :
            source( source ),
            numOctaves( numOctaves ),
            lacunarity( lacunarity ),
            h( h ),
            offset( offset ),
            gain( gain )
        {}      
      

        virtual real_t getValue( real_t x, real_t y, real_t z ) const override;

    private:

        Module3D& source;
        uint32_t  numOctaves;
        real_t    lacunarity;
        real_t    h;
        real_t    offset;
        real_t    gain;
    };

    class RidgedMultiFractal4D : public Module4D
    {
    public:

        RidgedMultiFractal4D( Module4D& source,
                              uint32_t  numOctaves = 6,
                              real_t    lacunarity = 1.5,
                              real_t    h          = 1.0,
                              real_t    offset     = 1.0,
                              real_t    gain       = 2.0 ) :
            source( source ),
            numOctaves( numOctaves ),
            lacunarity( lacunarity ),
            h( h ),
            offset( offset ),
            gain( gain )
        {}      

        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        Module4D& source;
        uint32_t  numOctaves;
        real_t    lacunarity;
        real_t    h;
        real_t    offset;
        real_t    gain;
    };
}
