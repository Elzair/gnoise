// -*- mode: c++; -*-

#pragma once

#include <cstdint>

#include "module.h"

namespace Noise
{ 
    class Blend : public Module
    {
    public:

        Blend( Module& input1, Module& input2, Module& weight ) :
            input1( input1 ),
            input2( input2 ),
            weight( weight )
        {}
        
        virtual real_t getValue( real_t x )                               const override;
        virtual real_t getValue( real_t x, real_t y )                     const override;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        Module& input1;
        Module& input2;
        Module& weight;
    };

    class Difference : public Module
    {
    public:

        Difference( Module& input1, Module& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x )                               const override;
        virtual real_t getValue( real_t x, real_t y )                     const override;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        Module& input1;
        Module& input2;
    };
    
    class Displace : public Module
    {
    public:

        Displace( Module& source,
                  Module& xdisp ) :
            source( source ),
            xdisp( xdisp ),
            ydisp( xdisp ),
            zdisp( xdisp ),
            adisp( xdisp )
        {}
        Displace( Module& source,
                  Module& xdisp,
                  Module& ydisp ) :
            source( source ),
            xdisp( xdisp ),
            ydisp( ydisp ),
            zdisp( ydisp ),
            adisp( ydisp )
        {}
        Displace( Module& source,
                  Module& xdisp,
                  Module& ydisp,
                  Module& zdisp ) :
            source( source ),
            xdisp( xdisp ),
            ydisp( ydisp ),
            zdisp( zdisp ),
            adisp( zdisp )
        {}
        Displace( Module& source,
                  Module& xdisp,
                  Module& ydisp,
                  Module& zdisp,
                  Module& adisp ) :
            source( source ),
            xdisp( xdisp ),
            ydisp( ydisp ),
            zdisp( zdisp ),
            adisp( adisp )
        {}
        
        virtual real_t getValue( real_t x )                               const override;
        virtual real_t getValue( real_t x, real_t y )                     const override;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        uint32_t num_displacements;
        Module&  source;
        Module&  xdisp;
        Module&  ydisp;
        Module&  zdisp;
        Module&  adisp;
    };

    class Maximum : public Module
    {
    public:

        Maximum( Module& input1, Module& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x )                               const override;
        virtual real_t getValue( real_t x, real_t y )                     const override;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        Module& input1;
        Module& input2;
    };

    class Minimum : public Module
    {
    public:

        Minimum( Module& input1, Module& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x )                               const override;
        virtual real_t getValue( real_t x, real_t y )                     const override;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        Module& input1;
        Module& input2;
    };

    class Power : public Module
    {
    public:

        Power( Module& input1, Module& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x )                               const override;
        virtual real_t getValue( real_t x, real_t y )                     const override;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        Module& input1;
        Module& input2;
    };

    class Product : public Module
    {
    public:

        Product( Module& input1, Module& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x )                               const override;
        virtual real_t getValue( real_t x, real_t y )                     const override;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        Module& input1;
        Module& input2;
    };

    class Quotient : public Module
    {
    public:

        Quotient( Module& input1,
                  Module& input2,
                  real_t  zeroVal = 0.0001 ) :
            input1( input1 ),
            input2( input2 ),
            zeroVal( zeroVal )
        {}
        
        virtual real_t getValue( real_t x )                               const override;
        virtual real_t getValue( real_t x, real_t y )                     const override;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        Module& input1;
        Module& input2;
        real_t  zeroVal;
    };
    
    class Select : public Module
    {
    public:

        Select( Module& choice1,
                Module& choice2,
                Module& decider,
                real_t  low = -1.0,
                real_t high =  1.0 ) :
            choice1( choice1 ),
            choice2( choice2 ),
            decider( decider ),
            low( low ),
            high( high )
        {}
        
        virtual real_t getValue( real_t x )                               const override;
        virtual real_t getValue( real_t x, real_t y )                     const override;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        Module& choice1;
        Module& choice2;
        Module& decider;

        real_t  low;
        real_t  high;
    };

    class Sum : public Module
    {
    public:

        Sum( Module& input1, Module& input2 ) :
            input1( input1 ),
            input2( input2 )
        {}
        
        virtual real_t getValue( real_t x )                               const override;
        virtual real_t getValue( real_t x, real_t y )                     const override;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const override;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        Module& input1;
        Module& input2;
    };
}
