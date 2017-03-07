// -*- mode: c++; -*-

#pragma once

#include "math_defs.h"

namespace Noise
{
    class Module
    {
    public:

        virtual real_t getValue( real_t x )                               const = 0;
        virtual real_t getValue( real_t x, real_t y )                     const = 0;
        virtual real_t getValue( real_t x, real_t y, real_t z )           const = 0;
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const = 0;
    };
}
