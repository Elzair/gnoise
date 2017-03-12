// -*- mode: c++; -*-

#pragma once

#include <cstdint>

#include "module.h"

namespace Noise
{
    class White1D : public Module1D
    {
    public:

        White1D( uint64_t seed = 0 ) : seed( seed )
        {}
        
        virtual real_t getValue( real_t x ) const override;

    private:

        uint64_t seed;
    };
    
    class White2D : public Module2D
    {
    public:

        White2D( uint64_t seed = 0 ) : seed( seed )
        {}
        
        virtual real_t getValue( real_t x, real_t y ) const override;

    private:

        uint64_t seed;
    };
    
    class White3D : public Module3D
    {
    public:

        White3D( uint64_t seed = 0 ) : seed( seed )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z ) const override;

    private:

        uint64_t seed;
    };
    
    class White4D : public Module4D
    {
    public:

        White4D( uint64_t seed = 0 ) : seed( seed )
        {}
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t a ) const override;

    private:

        uint64_t seed;
    };

}
