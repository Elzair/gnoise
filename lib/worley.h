// -*- mode: c++; -*-

#pragma once

#include <cstdint>
#include <cmath>

#include <array>
#include <functional>

#include "module.h"
#include "util.h"

namespace Noise
{ 
    class Worley1D : public Module1D
    {
    public:

        static const std::size_t DISTANCES_SIZE = 4;

        Worley1D( uint64_t seed           = 0,
                  real_t   avgPerCell     = 2.0,
                  Distance distCalcMethod = Distance::Euclidian ) :
            seed( seed ),
            avgPerCell( avgPerCell ),
            distCalcMethod( distCalcMethod )
        {
            // Use the Cumulative Distribution Function of the Poisson Distribution
            // to make a table on the odds of each cell having exactly n feature points.
            // https://en.wikipedia.org/wiki/Poisson_distribution
            real_t lambda = this->avgPerCell;
            real_t sum    = 0.0;

            for ( auto k = 0; k < Worley1D::MAX_PER_CELL; k++ )
            {
                sum += std::pow( lambda,
                                 static_cast<real_t>( k ) ) /
                                 static_cast<real_t>( Util::Factorial( k ) );
                real_t prob = std::exp( -1.0 * lambda ) * sum;

                this->probTable[k] = Util::NormRealToU64( prob );
            }
        }
        
        virtual real_t getValue( real_t x ) const override;

        real_t getCustomValue(
            real_t                                                        x,
            std::function<real_t( std::array<real_t,
                                             Worley1D::DISTANCES_SIZE> )> fn );

    private:

        static const std::size_t MAX_PER_CELL = 9;

        uint64_t seed;
        real_t   avgPerCell;
        Distance distCalcMethod;

        std::array<uint64_t, Worley1D::MAX_PER_CELL> probTable;

        std::array<real_t, Worley1D::DISTANCES_SIZE> getValueHelper( real_t x ) const;

        std::size_t lookupNumFeaturePoints( uint64_t num ) const;
    };
    
    class Worley2D : public Module2D
    {
    public:

        static const std::size_t DISTANCES_SIZE = 4;

        Worley2D( uint64_t seed           = 0,
                  real_t   avgPerCell     = 2.0,
                  Distance distCalcMethod = Distance::Euclidian ) :
            seed( seed ),
            avgPerCell( avgPerCell ),
            distCalcMethod( distCalcMethod )
        {
            // Use the Cumulative Distribution Function of the Poisson Distribution
            // to make a table on the odds of each cell having exactly n feature points.
            // https://en.wikipedia.org/wiki/Poisson_distribution
            real_t lambda = this->avgPerCell;
            real_t sum    = 0.0;

            for ( auto k = 0; k < Worley2D::MAX_PER_CELL; k++ )
            {
                sum += std::pow( lambda,
                                 static_cast<real_t>( k ) ) /
                                 static_cast<real_t>( Util::Factorial( k ) );
                real_t prob = std::exp( -1.0 * lambda ) * sum;

                this->probTable[k] = Util::NormRealToU64( prob );
            }
        }
        
        virtual real_t getValue( real_t x, real_t y ) const override;

        real_t getCustomValue(
            real_t                                                        x,
            real_t                                                        y,
            std::function<real_t( std::array<real_t,
                                             Worley2D::DISTANCES_SIZE> )> fn );

    private:

        static const std::size_t MAX_PER_CELL = 9;

        uint64_t seed;
        real_t   avgPerCell;
        Distance distCalcMethod;

        std::array<uint64_t, Worley2D::MAX_PER_CELL> probTable;

        std::array<real_t, Worley2D::DISTANCES_SIZE> getValueHelper( real_t x, real_t y ) const;

        std::size_t lookupNumFeaturePoints( uint64_t num ) const;
    };
    
    class Worley3D : public Module3D
    {
    public:

        static const std::size_t DISTANCES_SIZE = 4;

        Worley3D( uint64_t seed           = 0,
                  real_t   avgPerCell     = 2.0,
                  Distance distCalcMethod = Distance::Euclidian ) :
            seed( seed ),
            avgPerCell( avgPerCell ),
            distCalcMethod( distCalcMethod )
        {
            // Use the Cumulative Distribution Function of the Poisson Distribution
            // to make a table on the odds of each cell having exactly n feature points.
            // https://en.wikipedia.org/wiki/Poisson_distribution
            real_t lambda = this->avgPerCell;
            real_t sum    = 0.0;

            for ( auto k = 0; k < Worley3D::MAX_PER_CELL; k++ )
            {
                sum += std::pow( lambda,
                                 static_cast<real_t>( k ) ) /
                                 static_cast<real_t>( Util::Factorial( k ) );
                real_t prob = std::exp( -1.0 * lambda ) * sum;

                this->probTable[k] = Util::NormRealToU64( prob );
            }
        }
        
        virtual real_t getValue( real_t x, real_t y, real_t z ) const override;

        real_t getCustomValue(
            real_t                                                        x,
            real_t                                                        y,
            real_t                                                        z,
            std::function<real_t( std::array<real_t,
                                             Worley3D::DISTANCES_SIZE> )> fn );

    private:

        static const std::size_t MAX_PER_CELL = 9;

        uint64_t seed;
        real_t   avgPerCell;
        Distance distCalcMethod;

        std::array<uint64_t, Worley3D::MAX_PER_CELL> probTable;

        std::array<real_t, Worley3D::DISTANCES_SIZE> getValueHelper( real_t x, real_t y, real_t z ) const;

        std::size_t lookupNumFeaturePoints( uint64_t num ) const;
    };
    
    class Worley4D : public Module4D
    {
    public:

        static const std::size_t DISTANCES_SIZE = 4;

        Worley4D( uint64_t seed           = 0,
                  real_t   avgPerCell     = 2.0,
                  Distance distCalcMethod = Distance::Euclidian ) :
            seed( seed ),
            avgPerCell( avgPerCell ),
            distCalcMethod( distCalcMethod )
        {
            // Use the Cumulative Distribution Function of the Poisson Distribution
            // to make a table on the odds of each cell having exactly n feature points.
            // https://en.wikipedia.org/wiki/Poisson_distribution
            real_t lambda = this->avgPerCell;
            real_t sum    = 0.0;

            for ( auto k = 0; k < Worley4D::MAX_PER_CELL; k++ )
            {
                sum += std::pow( lambda,
                                 static_cast<real_t>( k ) ) /
                                 static_cast<real_t>( Util::Factorial( k ) );
                real_t prob = std::exp( -1.0 * lambda ) * sum;

                this->probTable[k] = Util::NormRealToU64( prob );
            }
        }
        
        virtual real_t getValue( real_t x, real_t y, real_t z, real_t w ) const override;

        real_t getCustomValue(
            real_t                                                        x,
            real_t                                                        y,
            real_t                                                        z,
            real_t                                                        w,
            std::function<real_t( std::array<real_t,
                                             Worley4D::DISTANCES_SIZE> )> fn );

    private:

        static const std::size_t MAX_PER_CELL = 9;

        uint64_t seed;
        real_t   avgPerCell;
        Distance distCalcMethod;

        std::array<uint64_t, Worley4D::MAX_PER_CELL> probTable;

        std::array<real_t, Worley4D::DISTANCES_SIZE> getValueHelper( real_t x, real_t y, real_t z, real_t w ) const;

        std::size_t lookupNumFeaturePoints( uint64_t num ) const;
    };
}
