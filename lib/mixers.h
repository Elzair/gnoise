// -*- mode: c++; -*-

#pragma once

#include <cstdint>

#include "module.h"

namespace Noise
{ 
    class Blend1D : public Module1D
    {
    public:

        Blend1D( Module1D& input1, Module1D& input2, Module1D& weight ) :
            input1( input1 ),
            input2( input2 ),
            weight( weight )
        {}
        
        virtual real_t getValue( real_t x ) const override;

    private:

        Module1D& input1;
        Module1D& input2;
        Module1D& weight;
    };

    class Blend2D : public Module2D
    {
    public:

        Blend2D( Module2D& input1, Module2D& input2, Module2D& weight ) :
            input1( input1 ),
            input2( input2 ),
            weight( weight )
        {}
        
        virtual real_t getValue( real_t x, real_t y ) const override;

    private:

        Module2D& input1;
        Module2D& input2;
        Module2D& weight;
    };

    class Blend3D : public Module3D
    {
    public:

        Blend3D( Module3D& input1, Module3D& input2, Module3D& weight ) :
            input1( input1 ),
            input2( input2 ),
            weight( weight )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z ) const override;

    private:

        Module3D& input1;
        Module3D& input2;
        Module3D& weight;
    };

    class Blend4D : public Module4D
    {
    public:

        Blend4D( Module4D& input1, Module4D& input2, Module4D& weight ) :
            input1( input1 ),
            input2( input2 ),
            weight( weight )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        Module4D& input1;
        Module4D& input2;
        Module4D& weight;
    };

    class Difference1D : public Module1D
    {
    public:

        Difference1D( Module1D& input1, Module1D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x ) const override;

    private:

        Module1D& input1;
        Module1D& input2;
    };
    
    class Difference2D : public Module2D
    {
    public:

        Difference2D( Module2D& input1, Module2D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x, real_t y ) const override;

    private:

        Module2D& input1;
        Module2D& input2;
    };

    class Difference3D : public Module3D
    {
    public:

        Difference3D( Module3D& input1, Module3D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z ) const override;

    private:

        Module3D& input1;
        Module3D& input2;
    };

    class Difference4D : public Module4D
    {
    public:

        Difference4D( Module4D& input1, Module4D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        Module4D& input1;
        Module4D& input2;
    };

    class Displace1D : public Module1D
    {
    public:

        Displace1D( Module1D& source,
                    Module1D& xdisp ) :
            source( source ),
            xdisp( xdisp )
        {}
        
        virtual real_t getValue( real_t x ) const override;

    private:

        Module1D& source;
        Module1D& xdisp;
    };
    
    class Displace2D : public Module2D
    {
    public:

        Displace2D( Module2D& source,
                    Module1D& xdisp,
                    Module1D& ydisp ) :
            source( source ),
            xdisp( xdisp ),
            ydisp( ydisp )
        {}
        
        virtual real_t getValue( real_t x, real_t y ) const override;

    private:

        Module2D& source;
        Module1D& xdisp;
        Module1D& ydisp;
    };
    
    class Displace3D : public Module3D
    {
    public:

        Displace3D( Module3D& source,
                    Module1D& xdisp,
                    Module1D& ydisp,
                    Module1D& zdisp ) :
            source( source ),
            xdisp( xdisp ),
            ydisp( ydisp ),
            zdisp( zdisp )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z ) const override;

    private:

        Module3D&  source;
        Module1D&  xdisp;
        Module1D&  ydisp;
        Module1D&  zdisp;
    };
    
    class Displace4D : public Module4D
    {
    public:

        Displace4D( Module4D& source,
                    Module1D& xdisp,
                    Module1D& ydisp,
                    Module1D& zdisp,
                    Module1D& wdisp ) :
            source( source ),
            xdisp( xdisp ),
            ydisp( ydisp ),
            zdisp( zdisp ),
            wdisp( wdisp )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        Module4D&  source;
        Module1D&  xdisp;
        Module1D&  ydisp;
        Module1D&  zdisp;
        Module1D&  wdisp;
    };

    class Maximum1D : public Module1D
    {
    public:

        Maximum1D( Module1D& input1, Module1D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x ) const override;

    private:

        Module1D& input1;
        Module1D& input2;
    };

    class Maximum2D : public Module2D
    {
    public:

        Maximum2D( Module2D& input1, Module2D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x, real_t y ) const override;

    private:

        Module2D& input1;
        Module2D& input2;
    };

    class Maximum3D : public Module3D
    {
    public:

        Maximum3D( Module3D& input1, Module3D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z ) const override;

    private:

        Module3D& input1;
        Module3D& input2;
    };

    class Maximum4D : public Module4D
    {
    public:

        Maximum4D( Module4D& input1, Module4D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        Module4D& input1;
        Module4D& input2;
    };

    class Minimum1D : public Module1D
    {
    public:

        Minimum1D( Module1D& input1, Module1D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x ) const override;

    private:

        Module1D& input1;
        Module1D& input2;
    };

    class Minimum2D : public Module2D
    {
    public:

        Minimum2D( Module2D& input1, Module2D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x, real_t y ) const override;

    private:

        Module2D& input1;
        Module2D& input2;
    };

    class Minimum3D : public Module3D
    {
    public:

        Minimum3D( Module3D& input1, Module3D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z ) const override;

    private:

        Module3D& input1;
        Module3D& input2;
    };

    class Minimum4D : public Module4D
    {
    public:

        Minimum4D( Module4D& input1, Module4D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        Module4D& input1;
        Module4D& input2;
    };

    class Power1D : public Module1D
    {
    public:

        Power1D( Module1D& input1, Module1D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x ) const override;

    private:

        Module1D& input1;
        Module1D& input2;
    };

    class Power2D : public Module2D
    {
    public:

        Power2D( Module2D& input1, Module2D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x, real_t y ) const override;

    private:

        Module2D& input1;
        Module2D& input2;
    };

    class Power3D : public Module3D
    {
    public:

        Power3D( Module3D& input1, Module3D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z ) const override;

    private:

        Module3D& input1;
        Module3D& input2;
    };

    class Power4D : public Module4D
    {
    public:

        Power4D( Module4D& input1, Module4D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        Module4D& input1;
        Module4D& input2;
    };

    class Product1D : public Module1D
    {
    public:

        Product1D( Module1D& input1, Module1D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x )                               const override;

    private:

        Module1D& input1;
        Module1D& input2;
    };

    class Product2D : public Module2D
    {
    public:

        Product2D( Module2D& input1, Module2D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x, real_t y )                     const override;

    private:

        Module2D& input1;
        Module2D& input2;
    };

    class Product3D : public Module3D
    {
    public:

        Product3D( Module3D& input1, Module3D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;

    private:

        Module3D& input1;
        Module3D& input2;
    };

    class Product4D : public Module4D
    {
    public:

        Product4D( Module4D& input1, Module4D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        Module4D& input1;
        Module4D& input2;
    };

    class Quotient1D : public Module1D
    {
    public:

        Quotient1D( Module1D& input1,
                    Module1D& input2,
                    real_t    zeroVal = 0.0001 ) :
            input1( input1 ),
            input2( input2 ),
            zeroVal( zeroVal )
        {}
        
        virtual real_t getValue( real_t x ) const override;

    private:

        Module1D& input1;
        Module1D& input2;
        real_t    zeroVal;
    };
 
    class Quotient2D : public Module2D
    {
    public:

        Quotient2D( Module2D& input1,
                    Module2D& input2,
                    real_t    zeroVal = 0.0001 ) :
            input1( input1 ),
            input2( input2 ),
            zeroVal( zeroVal )
        {}
        
        virtual real_t getValue( real_t x, real_t y ) const override;

    private:

        Module2D& input1;
        Module2D& input2;
        real_t    zeroVal;
    };

    class Quotient3D : public Module3D
    {
    public:

        Quotient3D( Module3D& input1,
                    Module3D& input2,
                    real_t    zeroVal = 0.0001 ) :
            input1( input1 ),
            input2( input2 ),
            zeroVal( zeroVal )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;

    private:

        Module3D& input1;
        Module3D& input2;
        real_t    zeroVal;
    };

    class Quotient4D : public Module4D
    {
    public:

        Quotient4D( Module4D& input1,
                    Module4D& input2,
                    real_t    zeroVal = 0.0001 ) :
            input1( input1 ),
            input2( input2 ),
            zeroVal( zeroVal )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        Module4D& input1;
        Module4D& input2;
        real_t    zeroVal;
    };
   
    class Select1D : public Module1D
    {
    public:

        Select1D( Module1D& choice1,
                  Module1D& choice2,
                  Module1D& decider,
                  real_t    low  = -1.0,
                  real_t    high =  1.0 ) :
            choice1( choice1 ),
            choice2( choice2 ),
            decider( decider ),
            low( low ),
            high( high )
        {}
        
        virtual real_t getValue( real_t x ) const override;

    private:

        Module1D& choice1;
        Module1D& choice2;
        Module1D& decider;

        real_t  low;
        real_t  high;
    };
   
    class Select2D : public Module2D
    {
    public:

        Select2D( Module2D& choice1,
                  Module2D& choice2,
                  Module2D& decider,
                  real_t    low  = -1.0,
                  real_t    high =  1.0 ) :
            choice1( choice1 ),
            choice2( choice2 ),
            decider( decider ),
            low( low ),
            high( high )
        {}
        
        virtual real_t getValue( real_t x, real_t y ) const override;

    private:

        Module2D& choice1;
        Module2D& choice2;
        Module2D& decider;

        real_t  low;
        real_t  high;
    };
   
    class Select3D : public Module3D
    {
    public:

        Select3D( Module3D& choice1,
                  Module3D& choice2,
                  Module3D& decider,
                  real_t    low  = -1.0,
                  real_t    high =  1.0 ) :
            choice1( choice1 ),
            choice2( choice2 ),
            decider( decider ),
            low( low ),
            high( high )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z ) const override;

    private:

        Module3D& choice1;
        Module3D& choice2;
        Module3D& decider;

        real_t  low;
        real_t  high;
    };
   
    class Select4D : public Module4D
    {
    public:

        Select4D( Module4D& choice1,
                  Module4D& choice2,
                  Module4D& decider,
                  real_t    low  = -1.0,
                  real_t    high =  1.0 ) :
            choice1( choice1 ),
            choice2( choice2 ),
            decider( decider ),
            low( low ),
            high( high )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        Module4D& choice1;
        Module4D& choice2;
        Module4D& decider;

        real_t  low;
        real_t  high;
    };

    class Sum1D : public Module1D
    {
    public:

        Sum1D( Module1D& input1, Module1D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x ) const override;

    private:

        Module1D& input1;
        Module1D& input2;
    };

    class Sum2D : public Module2D
    {
    public:

        Sum2D( Module2D& input1, Module2D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x, real_t y ) const override;

    private:

        Module2D& input1;
        Module2D& input2;
    };

    class Sum3D : public Module3D
    {
    public:

        Sum3D( Module3D& input1, Module3D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z ) const override;

    private:

        Module3D& input1;
        Module3D& input2;
    };

    class Sum4D : public Module4D
    {
    public:

        Sum4D( Module4D& input1, Module4D& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

    private:

        Module4D& input1;
        Module4D& input2;
    };

}
