// -*- mode: c++; -*-

#pragma once

#include <cstdint>
#include <cmath>

#include "module.h"
#include "util.h"

namespace Noise
{ 
    class Worley1D : public Module1D
    {
    public:

        enum class Distance
        {
            Euclidian,
            Manhattan,
            Chebyshev
        };

        Worley1D( uint64_t seed       = 0,
                  real_t   avgPerCell = 2.0,
                  Distance distcalc   = Distance::Euclidian ) :
            seed( seed ),
            avgPerCell( avgPerCell ),
            distcalc( distcalc )
        {
            // Use the Cumulative Distribution Function of the Poisson Distribution
            // to make a table on the odds of each cell having exactly n feature points.
            // https://en.wikipedia.org/wiki/Poisson_distribution
            real_t lambda = this->avgPerCell;
            real_t sum    = 0.0;

            for ( auto k = 0; k < MAX_PER_CELL; k++ )
            {
                sum += std::pow( lambda,
                                 static_cast<real_t>( k ) ) /
                                 static_cast<real_t>( Util::Factorial( k ) );
                real_t prob = std::exp( -1.0 * lambda ) * sum;

                this->probTable[k] = Util::MakeNormRealU64Range( prob );
            }
        }
        
        virtual real_t getValue( real_t x ) const override;

    private:

        static const std::size_t MAX_PER_CELL   = 9;
        static const std::size_t DISTANCES_SIZE = 4;

        uint64_t seed;
        real_t   avgPerCell;
        Distance distcalc;

        uint64_t probTable[MAX_PER_CELL];

        std::size_t lookupNumFeaturePoints( uint64_t num ) const;
    };
}
