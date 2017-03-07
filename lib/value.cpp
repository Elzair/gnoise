#include <cmath>

#include "util.h"
#include "value.h"

namespace Noise
{
    real_t Value::getValue( real_t x ) const
    {
        auto xf = std::floor( x );
        auto xi = static_cast<uint64_t>( xf );
        
        auto tx = x - xf;

        auto c0 = this->getGridValue( xi );
        auto c1 = this->getGridValue( xi+1 );

        auto u = Quintic( tx );

        auto res = Lerp( u, c0, c1 );

        return res;
    }

    real_t Value::getValue( real_t x, real_t y ) const
    {
        auto xf = std::floor( x );
        auto xi = static_cast<uint64_t>( xf );
        auto yf = std::floor( y );
        auto yi = static_cast<uint64_t>( yf );

        auto tx = x - xf;
        auto ty = y - yf;

        auto c00 = this->getGridValue( xi,   yi );
        auto c01 = this->getGridValue( xi,   yi+1 );
        auto c10 = this->getGridValue( xi+1, yi );
        auto c11 = this->getGridValue( xi+1, yi+1 );

        auto u = Quintic( tx );
        auto v = Quintic( ty );

        auto res = Lerp( v,
                         Lerp( u, c00, c10 ),
                         Lerp( u, c10, c11 ) );

        return res;
    }

    real_t Value::getValue( real_t x, real_t y, real_t z ) const
    {
        auto xf = std::floor( x );
        auto xi = static_cast<uint64_t>( xf );
        auto yf = std::floor( y );
        auto yi = static_cast<uint64_t>( yf );
        auto zf = std::floor( z );
        auto zi = static_cast<uint64_t>( zf );

        auto tx = x - xf;
        auto ty = y - yf;
        auto tz = z - zf;

        auto c000 = this->getGridValue( xi,   yi,   zi );
        auto c001 = this->getGridValue( xi,   yi,   zi+1 );
        auto c010 = this->getGridValue( xi,   yi+1, zi );
        auto c011 = this->getGridValue( xi,   yi+1, zi+1 );
        auto c100 = this->getGridValue( xi+1, yi,   zi );
        auto c101 = this->getGridValue( xi+1, yi,   zi+1 );
        auto c110 = this->getGridValue( xi+1, yi+1, zi );
        auto c111 = this->getGridValue( xi+1, yi+1, zi+1 );

        auto u = Quintic( tx );
        auto v = Quintic( ty );
        auto w = Quintic( tz );

        auto res = Lerp( w,
                         Lerp( v,
                               Lerp( u, c000, c100 ),
                               Lerp( u, c010, c110 ) ),
                         Lerp( v,
                               Lerp( u, c001, c101 ),
                               Lerp( u, c011, c111 ) ) );

        return res;
    }

    real_t Value::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto xf = std::floor( x );
        auto xi = static_cast<uint64_t>( xf );
        auto yf = std::floor( y );
        auto yi = static_cast<uint64_t>( yf );
        auto zf = std::floor( z );
        auto zi = static_cast<uint64_t>( zf );
        auto af = std::floor( a );
        auto ai = static_cast<uint64_t>( af );

        auto tx = x - xf;
        auto ty = y - yf;
        auto tz = z - zf;
        auto ta = a - af;

        auto c0000 = this->getGridValue( xi,   yi,   zi,   ai );
        auto c0001 = this->getGridValue( xi,   yi,   zi,   ai+1 );
        auto c0010 = this->getGridValue( xi,   yi,   zi+1, ai );
        auto c0011 = this->getGridValue( xi,   yi,   zi+1, ai+1 );
        auto c0100 = this->getGridValue( xi,   yi+1, zi,   ai );
        auto c0101 = this->getGridValue( xi,   yi+1, zi,   ai+1 );
        auto c0110 = this->getGridValue( xi,   yi+1, zi+1, ai );
        auto c0111 = this->getGridValue( xi,   yi+1, zi+1, ai+1 );
        auto c1000 = this->getGridValue( xi+1, yi,   zi,   ai );
        auto c1001 = this->getGridValue( xi+1, yi,   zi,   ai+1 );
        auto c1010 = this->getGridValue( xi+1, yi,   zi+1, ai );
        auto c1011 = this->getGridValue( xi+1, yi,   zi+1, ai+1 );
        auto c1100 = this->getGridValue( xi+1, yi+1, zi,   ai );
        auto c1101 = this->getGridValue( xi+1, yi+1, zi,   ai+1 );
        auto c1110 = this->getGridValue( xi+1, yi+1, zi+1, ai );
        auto c1111 = this->getGridValue( xi+1, yi+1, zi+1, ai+1 );

        auto u = Quintic( tx );
        auto v = Quintic( ty );
        auto w = Quintic( tz );
        auto t = Quintic( ta );

        auto res = Lerp( t,
                         Lerp( w,
                               Lerp( v,
                                     Lerp( u, c0000, c1000 ),
                                     Lerp( u, c0100, c1100 ) ),
                               Lerp( v,
                                     Lerp( u, c0010, c1010 ),
                                     Lerp( u, c0110, c1110 ) ) ),
                         Lerp( w,
                               Lerp( v,
                                     Lerp( u, c0001, c1001 ),
                                     Lerp( u, c0101, c1101 ) ),
                               Lerp( v,
                                     Lerp( u, c0011, c1011 ),
                                     Lerp( u, c0111, c1111 ) ) ) );

        return res;
    }
    
    real_t Value::getGridValue( uint64_t x, uint64_t y, uint64_t z, uint64_t a ) const
    {
        const uint64_t prime1 = 60493;
        const uint64_t prime2 = 19990303;
        const uint64_t prime3 = 1376312589;
        const uint64_t shift  = 29;
        const uint64_t mask   = 0x7fffffffffffffff;

        auto n = ( Value::X_NOISE_GEN    * x +
                   Value::Y_NOISE_GEN    * y +
                   Value::Z_NOISE_GEN    * z +
                   Value::A_NOISE_GEN    * a +
                   Value::SEED_NOISE_GEN * this->seed ) & mask;
        n = ( n >> shift ) ^ n;

        auto ival = ( n * ( n * n * prime1 + prime2 ) + prime3 ) & mask;

        auto res = NormalizeU64( ival );

        return res;
    }
}
