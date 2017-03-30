#include <cmath>

#include <limits>

#include "util.h"
#include "vector.h"
#include "worley.h"

namespace Noise
{ 
    /*
     * Worley Module Methods
     */
    
    real_t Worley1D::getValue( real_t x ) const
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
            auto xc  = xi + i;

            // Generate reproducible random number
            auto xs0 = this->seed;
            auto xs1 = Util::Hash( Util::I64ToU64( xc ) );

            // Determine # feature points in this cell.
            auto numfp = this->lookupNumFeaturePoints( Util::RNG( xs0, xs1 ) );

            // Distribute feature points randomly around cell.
            for ( auto l = 0; l < numfp; l++ )
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
                Util::InsertAndSort( distances.data(), Worley1D::DISTANCES_SIZE, dist );
            }
        }
        
        // Return the distance to the closest feature point.
        return distances[0];
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
}
