// -*- mode: c++; -*-

#pragma once

#include "module.h"

namespace Noise
{ 
    class AbsoluteValue1D : public Module1D
    {
    public:

        AbsoluteValue1D( Module1D& source ) :
            source( source )
        {}
        
        virtual real_t getValue( real_t x )                               const override;

    private:

        Module1D& source;
    };

    class AbsoluteValue2D : public Module2D
    {
    public:

        AbsoluteValue2D( Module2D& source ) :
            source( source )
        {}
        
        virtual real_t getValue( real_t x, real_t y )                     const override;

    private:

        Module2D& source;
    };

    class AbsoluteValue3D : public Module3D
    {
    public:

        AbsoluteValue3D( Module3D& source ) :
            source( source )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;

    private:

        Module3D& source;
    };

    class AbsoluteValue4D : public Module4D
    {
    public:

        AbsoluteValue4D( Module4D& source ) :
            source( source )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        Module4D& source;
    };

    class Bias1D : public Module1D
    {
    public:

        Bias1D( Module1D& source, real_t bias ) :
            source( source ),
            bias( bias )
        {}
        
        virtual real_t getValue( real_t x )                               const override;

    private:

        Module1D& source;
        real_t    bias;
    };

    class Bias2D : public Module2D
    {
    public:

        Bias2D( Module2D& source, real_t bias ) :
            source( source ),
            bias( bias )
        {}
        
        virtual real_t getValue( real_t x, real_t y )                     const override;

    private:

        Module2D& source;
        real_t    bias;
    };

    class Bias3D : public Module3D
    {
    public:

        Bias3D( Module3D& source, real_t bias ) :
            source( source ),
            bias( bias )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;

    private:

        Module3D& source;
        real_t    bias;
    };

    class Bias4D : public Module4D
    {
    public:

        Bias4D( Module4D& source, real_t bias ) :
            source( source ),
            bias( bias )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        Module4D& source;
        real_t    bias;
    };

    class Billow1D : public Module1D
    {
    public:

        Billow1D( Module1D& source ) :
            source( source )
        {}
        
        virtual real_t getValue( real_t x )                               const override;

    private:

        Module1D& source;
    };

    class Billow2D : public Module2D
    {
    public:

        Billow2D( Module2D& source ) :
            source( source )
        {}
        
        virtual real_t getValue( real_t x, real_t y )                     const override;

    private:

        Module2D& source;
    };

    class Billow3D : public Module3D
    {
    public:

        Billow3D( Module3D& source ) :
            source( source )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;

    private:

        Module3D& source;
    };

    class Billow4D : public Module4D
    {
    public:

        Billow4D( Module4D& source ) :
            source( source )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        Module4D& source;
    };

    class Clamp1D : public Module1D
    {
    public:

        Clamp1D( Module1D& source,
                 real_t    min = -1.0,
                 real_t    max =  1.0 ) :
            source( source ),
            min( min ),
            max( max )
        {}
        
        virtual real_t getValue( real_t x )                               const override;

    private:

        Module1D& source;
        real_t  min;
        real_t  max;
    };
    
    class Clamp2D : public Module2D
    {
    public:

        Clamp2D( Module2D& source,
                 real_t    min = -1.0,
                 real_t    max =  1.0 ) :
            source( source ),
            min( min ),
            max( max )
        {}
        
        virtual real_t getValue( real_t x, real_t y )                     const override;

    private:

        Module2D& source;
        real_t  min;
        real_t  max;
    };

    class Clamp3D : public Module3D
    {
    public:

        Clamp3D( Module3D& source,
                 real_t    min = -1.0,
                 real_t    max =  1.0 ) :
            source( source ),
            min( min ),
            max( max )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;

    private:

        Module3D& source;
        real_t  min;
        real_t  max;
    };

    class Clamp4D : public Module4D
    {
    public:

        Clamp4D( Module4D& source,
                 real_t    min = -1.0,
                 real_t    max =  1.0 ) :
            source( source ),
            min( min ),
            max( max )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        Module4D& source;
        real_t  min;
        real_t  max;
    };

    class Invert1D : public Module1D
    {
    public:

        Invert1D( Module1D& source ) :
            source( source )
        {}
        
        virtual real_t getValue( real_t x )                               const override;

    private:

        Module1D& source;
    };

    class Invert2D : public Module2D
    {
    public:

        Invert2D( Module2D& source ) :
            source( source )
        {}
        
        virtual real_t getValue( real_t x, real_t y )                     const override;

    private:

        Module2D& source;
    };

    class Invert3D : public Module3D
    {
    public:

        Invert3D( Module3D& source ) :
            source( source )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;

    private:

        Module3D& source;
    };

    class Invert4D : public Module4D
    {
    public:

        Invert4D( Module4D& source ) :
            source( source )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        Module4D& source;
    };

    class Scale1D : public Module1D
    {
    public:

        Scale1D( Module1D& source, real_t multiple ) :
            source( source ),
            multiple( multiple )
        {}
        
        virtual real_t getValue( real_t x )                               const override;

    private:

        Module1D& source;
        real_t    multiple;
    };
    
    class Scale2D : public Module2D
    {
    public:

        Scale2D( Module2D& source, real_t multiple ) :
            source( source ),
            multiple( multiple )
        {}
        
        virtual real_t getValue( real_t x, real_t y )                     const override;

    private:

        Module2D& source;
        real_t    multiple;
    };
    
    class Scale3D : public Module3D
    {
    public:

        Scale3D( Module3D& source, real_t multiple ) :
            source( source ),
            multiple( multiple )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;

    private:

        Module3D& source;
        real_t    multiple;
    };
    
    class Scale4D : public Module4D
    {
    public:

        Scale4D( Module4D& source, real_t multiple ) :
            source( source ),
            multiple( multiple )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        Module4D& source;
        real_t    multiple;
    };
}
