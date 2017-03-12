// -*- mode: c++; -*-

#pragma once

#include "standalone_defs.h"

namespace Noise
{
    class Module1D
    {
    public:

        virtual real_t getValue( real_t x ) const = 0;
    };

    class Module2D
    {
    public:

        virtual real_t getValue( real_t x, real_t y ) const = 0;
    };
    
    class Module3D
    {
    public:

        virtual real_t getValue( real_t x, real_t y, real_t z ) const = 0;
    };
    
    class Module4D
    {
    public:

        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const = 0;
    };
}
