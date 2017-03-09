#include <cmath>

#include "util.h"
#include "value.h"

namespace Noise
{
    real_t Value::getValue( real_t x ) const
    {
        auto xf = std::floor( x );
        auto xi = Util::MakeRealU64Range( xf );
        
        auto tx = x - xf;

        auto c0 = this->getGridValue( xi );
        auto c1 = this->getGridValue( xi+1 );

        auto u = Util::Quintic( tx );

        auto res = Util::Lerp( u, c0, c1 );

        return res;
    }

    real_t Value::getValue( real_t x, real_t y ) const
    {
        auto xf = std::floor( x );
        auto xi = Util::MakeRealU64Range( xf );
        auto yf = std::floor( y );
        auto yi = Util::MakeRealU64Range( yf );

        auto tx = x - xf;
        auto ty = y - yf;

        auto c00 = this->getGridValue( xi,   yi );
        auto c01 = this->getGridValue( xi,   yi+1 );
        auto c10 = this->getGridValue( xi+1, yi );
        auto c11 = this->getGridValue( xi+1, yi+1 );

        auto u = Util::Quintic( tx );
        auto v = Util::Quintic( ty );

        auto res = Util::Lerp( v,
                         Util::Lerp( u, c00, c10 ),
                         Util::Lerp( u, c10, c11 ) );

        return res;
    }

    real_t Value::getValue( real_t x, real_t y, real_t z ) const
    {
        auto xf = std::floor( x );
        auto xi = Util::MakeRealU64Range( xf );
        auto yf = std::floor( y );
        auto yi = Util::MakeRealU64Range( yf );
        auto zf = std::floor( z );
        auto zi = Util::MakeRealU64Range( zf );

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

        auto u = Util::Quintic( tx );
        auto v = Util::Quintic( ty );
        auto w = Util::Quintic( tz );

        auto res = Util::Lerp( w,
                         Util::Lerp( v,
                               Util::Lerp( u, c000, c100 ),
                               Util::Lerp( u, c010, c110 ) ),
                         Util::Lerp( v,
                               Util::Lerp( u, c001, c101 ),
                               Util::Lerp( u, c011, c111 ) ) );

        return res;
    }

    real_t Value::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto xf = std::floor( x );
        auto xi = Util::MakeRealU64Range( xf );
        auto yf = std::floor( y );
        auto yi = Util::MakeRealU64Range( yf );
        auto zf = std::floor( z );
        auto zi = Util::MakeRealU64Range( zf );
        auto af = std::floor( a );
        auto ai = Util::MakeRealU64Range( af );

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

        auto u = Util::Quintic( tx );
        auto v = Util::Quintic( ty );
        auto w = Util::Quintic( tz );
        auto t = Util::Quintic( ta );

        auto res = Util::Lerp( t,
                         Util::Lerp( w,
                               Util::Lerp( v,
                                     Util::Lerp( u, c0000, c1000 ),
                                     Util::Lerp( u, c0100, c1100 ) ),
                               Util::Lerp( v,
                                     Util::Lerp( u, c0010, c1010 ),
                                     Util::Lerp( u, c0110, c1110 ) ) ),
                         Util::Lerp( w,
                               Util::Lerp( v,
                                     Util::Lerp( u, c0001, c1001 ),
                                     Util::Lerp( u, c0101, c1101 ) ),
                               Util::Lerp( v,
                                     Util::Lerp( u, c0011, c1011 ),
                                     Util::Lerp( u, c0111, c1111 ) ) ) );

        return res;
    }
    
    real_t Value::getGridValue( uint64_t x, uint64_t y, uint64_t z, uint64_t a ) const
    {
        const uint64_t prime1 = 22'801'763'489;   // one-billionth prime
        const uint64_t prime2 = 47'055'833'459;   // two-billionth prime
        const uint64_t prime3 = 97'011'687'217;   // four-billionth prime
        const uint64_t shift  = 29;
        const uint64_t mask   = 0x7fffffffffffffff;

        auto n = ( Value::X_NOISE_PRIME    * x +
                   Value::Y_NOISE_PRIME    * y +
                   Value::Z_NOISE_PRIME    * z +
                   Value::A_NOISE_PRIME    * a +
                   Value::SEED_NOISE_PRIME * this->seed ) & mask;
        n = ( n >> shift ) ^ n;

        auto ival = ( n * ( n * n * prime1 + prime2 ) + prime3 ) & mask;

        auto res = Util::NormalizeU64( ival );

        return res;
    }
}
