#include <cmath>

#include <limits>

#include "util.h"
#include "vector.h"
#include "worley.h"

namespace Noise
{ 
    real_t Worley1D::getValue( real_t x ) const
    {
        auto distances = this->getValueHelper( x );
        
        // Return the distance to the closest feature point.
        return distances[0];
    }

    real_t Worley1D::getCustomValue(
        real_t                                                                x,
        std::function<real_t( std::array<real_t, Worley1D::DISTANCES_SIZE> )> fn
    )
    {
        auto distances = this->getValueHelper( x );

        return fn( distances );
    }

    std::array<real_t, Worley1D::DISTANCES_SIZE>
    Worley1D::getValueHelper( real_t x ) const
    {
        std::array<real_t, Worley1D::DISTANCES_SIZE> distances;

        for ( auto& distance : distances )
        {
            distance = 1.0e12; // Initialize distances to large value.
        }

        // Determine the unit location of point.
        real_t  xf = std::floor( x );
        int64_t xi = static_cast<int64_t>( xf );

        for ( int64_t i = -1; i <= 1; i++ )
        {
            auto xc = xi + i;

            // Generate reproducible random number
            auto xs0 = this->seed;
            auto xs1 = Util::Hash( Util::I64ToU64( xc ) );

            // Determine # feature points in this cell.
            auto numfp = this->lookupNumFeaturePoints( Util::RNG( xs0, xs1 ) );

            // Distribute feature points randomly around cell.
            for ( auto m = 0; m < numfp; m++ )
            {
                real_t fp = xf + Util::U64ToNormReal( Util::RNG( xs0, xs1 ) );
                auto dist = 0.0;

                if ( this->distCalcMethod == Distance::Euclidian )
                {
                    dist = ( x - fp ) * ( x - fp );
                }
                else if ( this->distCalcMethod == Distance::Manhattan )
                {
                    dist = std::abs( x - fp );
                }
                else if ( this->distCalcMethod == Distance::Chebyshev )
                {
                    dist = std::abs( x - fp );
                }

                // Keep track of the N closest feature points to the point x.
                Util::InsertAndSort( distances.data(),
                                     Worley1D::DISTANCES_SIZE,
                                     dist );
            }
        }

        return distances;
    }

    std::size_t Worley1D::lookupNumFeaturePoints( uint64_t num ) const
    {
        for ( auto i = Worley1D::MAX_PER_CELL-1; i > 0; i-- )
        {
            if ( num > this->probTable[i] )
            {
                return i;
            }
        }
    }

    real_t Worley2D::getValue( real_t x, real_t y ) const
    {
        auto distances = this->getValueHelper( x, y );
        
        // Return the distance to the closest feature point.
        return distances[0];
    }

    real_t Worley2D::getCustomValue(
        real_t                                                                x,
        real_t                                                                y,
        std::function<real_t( std::array<real_t, Worley2D::DISTANCES_SIZE> )> fn
    )
    {
        auto distances = this->getValueHelper( x, y );

        return fn( distances );
    }

    std::array<real_t, Worley2D::DISTANCES_SIZE>
    Worley2D::getValueHelper( real_t x, real_t y ) const
    {
        std::array<real_t, Worley2D::DISTANCES_SIZE> distances;

        for ( auto& distance : distances )
        {
            distance = 1.0e12; // Initialize distances to large value.
        }

        // Determine the unit location of point.
        real_t  xf = std::floor( x );
        int64_t xi = static_cast<int64_t>( xf );
        real_t  yf = std::floor( y );
        int64_t yi = static_cast<int64_t>( yf );

        for ( int64_t i = -1; i <= 1; i++ )
        {
            for ( int64_t j = -1; j <= 1; j++ )
            {
                auto xc = xi + i;
                auto yc = yi + j;

                // Generate reproducible random number
                auto xs0 = this->seed;
                auto xs1 = Util::Hash( Util::I64ToU64( xc ),
                                       Util::I64ToU64( yc ) );

                // Determine # feature points in this cell.
                auto numfp = this->lookupNumFeaturePoints( Util::RNG( xs0, xs1 ) );

                // Distribute feature points randomly around cell.
                for ( auto m = 0; m < numfp; m++ )
                {
                    real_t xfp  = xf + Util::U64ToNormReal( Util::RNG( xs0, xs1 ) );
                    real_t yfp  = yf + Util::U64ToNormReal( Util::RNG( xs0, xs1 ) );
                    auto   dist = 0.0;

                    if ( this->distCalcMethod == Distance::Euclidian )
                    {
                        dist = ( x - xfp ) * ( x - xfp ) +
                               ( y - yfp ) * ( y - yfp );
                    }
                    else if ( this->distCalcMethod == Distance::Manhattan )
                    {
                        dist = std::abs( x - xfp ) +
                               std::abs( y - yfp );
                    }
                    else if ( this->distCalcMethod == Distance::Chebyshev )
                    {
                        auto xd = std::abs( x - xfp );
                        auto yd = std::abs( y - yfp );
                        dist    = std::max( xd, yd );
                    }

                    // Keep track of the N closest feature points to the point x.
                    Util::InsertAndSort( distances.data(),
                                         Worley2D::DISTANCES_SIZE,
                                         dist );
                }
            }
        }

        return distances;
    }

    std::size_t Worley2D::lookupNumFeaturePoints( uint64_t num ) const
    {
        for ( auto i = Worley2D::MAX_PER_CELL-1; i > 0; i-- )
        {
            if ( num > this->probTable[i] )
            {
                return i;
            }
        }
    }

    real_t Worley3D::getValue( real_t x, real_t y, real_t z ) const
    {
        auto distances = this->getValueHelper( x, y, z );
        
        // Return the distance to the closest feature point.
        return distances[0];
    }

    real_t Worley3D::getCustomValue(
        real_t                                                                x,
        real_t                                                                y,
        real_t                                                                z,
        std::function<real_t( std::array<real_t, Worley3D::DISTANCES_SIZE> )> fn
    )
    {
        auto distances = this->getValueHelper( x, y, z );

        return fn( distances );
    }

    std::array<real_t, Worley3D::DISTANCES_SIZE>
    Worley3D::getValueHelper( real_t x, real_t y, real_t z ) const
    {
        std::array<real_t, Worley3D::DISTANCES_SIZE> distances;

        for ( auto& distance : distances )
        {
            distance = 1.0e12; // Initialize distances to large value.
        }

        // Determine the unit location of point.
        real_t  xf = std::floor( x );
        int64_t xi = static_cast<int64_t>( xf );
        real_t  yf = std::floor( y );
        int64_t yi = static_cast<int64_t>( yf );
        real_t  zf = std::floor( z );
        int64_t zi = static_cast<int64_t>( zf );

        for ( int64_t i = -1; i <= 1; i++ )
        {
            for ( int64_t j = -1; j <= 1; j++ )
            {
                for ( int64_t k = -1; k <= 1; k++ )
                {
                    auto xc = xi + i;
                    auto yc = yi + j;
                    auto zc = zi + k;

                    // Generate reproducible random number
                    auto xs0 = this->seed;
                    auto xs1 = Util::Hash( Util::I64ToU64( xc ),
                                           Util::I64ToU64( yc ),
                                           Util::I64ToU64( zc ) );

                    // Determine # feature points in this cell.
                    auto numfp = this->lookupNumFeaturePoints( Util::RNG( xs0, xs1 ) );

                    // Distribute feature points randomly around cell.
                    for ( auto m = 0; m < numfp; m++ )
                    {
                        real_t xfp  = xf + Util::U64ToNormReal( Util::RNG( xs0, xs1 ) );
                        real_t yfp  = yf + Util::U64ToNormReal( Util::RNG( xs0, xs1 ) );
                        real_t zfp  = zf + Util::U64ToNormReal( Util::RNG( xs0, xs1 ) );
                        auto   dist = 0.0;

                        if ( this->distCalcMethod == Distance::Euclidian )
                        {
                            dist = ( x - xfp ) * ( x - xfp ) +
                                   ( y - yfp ) * ( y - yfp ) +
                                   ( z - zfp ) * ( z - zfp );
                        }
                        else if ( this->distCalcMethod == Distance::Manhattan )
                        {
                            dist = std::abs( x - xfp ) +
                                   std::abs( y - yfp ) +
                                   std::abs( z - zfp );
                        }
                        else if ( this->distCalcMethod == Distance::Chebyshev )
                        {
                            auto xd = std::abs( x - xfp );
                            auto yd = std::abs( y - yfp );
                            auto zd = std::abs( z - zfp );
                            dist    = std::max( xd, std::max( yd, zd ) );
                        }

                        // Keep track of the N closest feature points to the point x.
                        Util::InsertAndSort( distances.data(), Worley3D::DISTANCES_SIZE, dist );
                    }
                }
            }
        }

        return distances;
    }

    std::size_t Worley3D::lookupNumFeaturePoints( uint64_t num ) const
    {
        for ( auto i = Worley3D::MAX_PER_CELL-1; i > 0; i-- )
        {
            if ( num > this->probTable[i] )
            {
                return i;
            }
        }
    }

    real_t Worley4D::getValue( real_t x, real_t y, real_t z, real_t w ) const
    {
        auto distances = this->getValueHelper( x, y, z, w );
        
        // Return the distance to the closest feature point.
        return distances[0];
    }

    real_t Worley4D::getCustomValue(
        real_t                                                                x,
        real_t                                                                y,
        real_t                                                                z,
        real_t                                                                w,
        std::function<real_t( std::array<real_t, Worley4D::DISTANCES_SIZE> )> fn
    )
    {
        auto distances = this->getValueHelper( x, y, z, w );

        return fn( distances );
    }

    std::array<real_t, Worley4D::DISTANCES_SIZE>
    Worley4D::getValueHelper( real_t x, real_t y, real_t z, real_t w ) const
    {
        std::array<real_t, Worley4D::DISTANCES_SIZE> distances;

        for ( auto& distance : distances )
        {
            distance = 1.0e12; // Initialize distances to large value.
        }

        // Determine the unit location of point.
        real_t  xf = std::floor( x );
        int64_t xi = static_cast<int64_t>( xf );
        real_t  yf = std::floor( y );
        int64_t yi = static_cast<int64_t>( yf );
        real_t  zf = std::floor( z );
        int64_t zi = static_cast<int64_t>( zf );
        real_t  wf = std::floor( w );
        int64_t wi = static_cast<int64_t>( wf );

        for ( int64_t i = -1; i <= 1; i++ )
        {
            for ( int64_t j = -1; j <= 1; j++ )
            {
                for ( int64_t k = -1; k <= 1; k++ )
                {
                    for ( int64_t l = -1; l <= 1; l++ )
                    {
                        auto xc = xi + i;
                        auto yc = yi + j;
                        auto zc = zi + k;
                        auto wc = wi + l;

                        // Generate reproducible random number
                        auto xs0 = this->seed;
                        auto xs1 = Util::Hash( Util::I64ToU64( xc ),
                                               Util::I64ToU64( yc ),
                                               Util::I64ToU64( zc ),
                                               Util::I64ToU64( wc ) );

                        // Determine # feature points in this cell.
                        auto numfp = this->lookupNumFeaturePoints( Util::RNG( xs0, xs1 ) );

                        // Distribute feature points randomly around cell.
                        for ( auto m = 0; m < numfp; m++ )
                        {
                            real_t xfp  = xf + Util::U64ToNormReal( Util::RNG( xs0, xs1 ) );
                            real_t yfp  = yf + Util::U64ToNormReal( Util::RNG( xs0, xs1 ) );
                            real_t zfp  = zf + Util::U64ToNormReal( Util::RNG( xs0, xs1 ) );
                            real_t wfp  = wf + Util::U64ToNormReal( Util::RNG( xs0, xs1 ) );
                            auto   dist = 0.0;

                            if ( this->distCalcMethod == Distance::Euclidian )
                            {
                                dist = ( x - xfp ) * ( x - xfp ) +
                                       ( y - yfp ) * ( y - yfp ) +
                                       ( z - zfp ) * ( z - zfp ) +
                                       ( w - wfp ) * ( w - wfp );
                            }
                            else if ( this->distCalcMethod == Distance::Manhattan )
                            {
                                dist = std::abs( x - xfp ) +
                                       std::abs( y - yfp ) +
                                       std::abs( z - zfp ) +
                                       std::abs( w - wfp );
                            }
                            else if ( this->distCalcMethod == Distance::Chebyshev )
                            {
                                auto xd = std::abs( x - xfp );
                                auto yd = std::abs( y - yfp );
                                auto zd = std::abs( z - zfp );
                                auto wd = std::abs( w - wfp );
                                dist    = std::max( xd, std::max( yd, std::max( zd, wd ) ) );
                            }

                            // Keep track of the N closest feature points to the point x.
                            Util::InsertAndSort( distances.data(),
                                                 Worley4D::DISTANCES_SIZE,
                                                 dist );
                        }
                    }
                }
            }
        }

        return distances;
    }

    std::size_t Worley4D::lookupNumFeaturePoints( uint64_t num ) const
    {
        for ( auto i = Worley4D::MAX_PER_CELL-1; i > 0; i-- )
        {
            if ( num > this->probTable[i] )
            {
                return i;
            }
        }
    }
}
