#include <cmath>

#include "util.h"
#include "worley.h"

namespace Noise
{ 
    /*
     * Worley Module Methods
     */
    
    real_t Worley::getValue( real_t x ) const
    {
    }

    real_t Worley::getValue( real_t x, real_t y ) const
    {
    }

    real_t Worley::getValue( real_t x, real_t y, real_t z ) const
    {
        // Determine enclosing cube of point.
        auto xf = std::floor( x );
        auto xi = Util::MakeRealU64Range( xf );
        auto yf = std::floor( y );
        auto yi = Util::MakeRealU64Range( yf );
        auto zf = std::floor( z );
        auto zi = Util::MakeRealU64Range( zf );

        // Hash all 
    }

    real_t Worley::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
    }
}
