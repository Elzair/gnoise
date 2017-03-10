// -*- mode: c++; -*-

#pragma once

#include "module.h"

namespace Noise
{ 
    class AbsoluteValue : public Module
    {
    public:

        AbsoluteValue( Module& source ) :
            source( source )
        {}
        
        virtual real_t getValue( real_t x )                               const override;
        virtual real_t getValue( real_t x, real_t y )                     const override;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        Module& source;
    };

    class Bias : public Module
    {
    public:

        Bias( Module& source, real_t bias ) :
            source( source ),
            bias( bias )
        {}
        
        virtual real_t getValue( real_t x )                               const override;
        virtual real_t getValue( real_t x, real_t y )                     const override;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        Module& source;
        real_t  bias;
    };

    class Billow : public Module
    {
    public:

        Billow( Module& source ) :
            source( source )
        {}
        
        virtual real_t getValue( real_t x )                               const override;
        virtual real_t getValue( real_t x, real_t y )                     const override;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        Module& source;
    };

    class Clamp : public Module
    {
    public:

        Clamp( Module& source,
               real_t  min = -1.0,
               real_t  max =  1.0 ) :
            source( source ),
            min( min ),
            max( max )
        {}
        
        virtual real_t getValue( real_t x )                               const override;
        virtual real_t getValue( real_t x, real_t y )                     const override;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        Module& source;
        real_t  min;
        real_t  max;
    };
    
    class Invert : public Module
    {
    public:

        Invert( Module& source ) :
            source( source )
        {}
        
        virtual real_t getValue( real_t x )                               const override;
        virtual real_t getValue( real_t x, real_t y )                     const override;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        Module& source;
    };

    class Scale : public Module
    {
    public:

        Scale( Module& source, real_t multiple ) :
            source( source ),
            multiple( multiple )
        {}
        
        virtual real_t getValue( real_t x )                               const override;
        virtual real_t getValue( real_t x, real_t y )                     const override;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        Module& source;
        real_t  multiple;
    };
}
