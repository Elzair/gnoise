#include <cmath>

#include "util.h"
#include "value.h"

namespace Noise
{
    real_t Value1D::getValue( real_t x ) const
    {
        auto xf = std::floor( x );
        auto xi = Util::MakeRealU64Range( xf );
        
        auto tx = x - xf;

        auto c0 = this->getGridValue( xi );
        auto c1 = this->getGridValue( xi+1 );

        real_t u;
        
        switch( this->interpMethod )
        {
        case Interp::Smooth:
            u = Util::Interpolation::SmoothStep( tx );
            break;
        case Interp::Smoother:
            u = Util::Interpolation::SmootherStep( tx );
            break;
        }

        auto res = Util::Lerp( u, c0, c1 );

        return res;
    }
    
    real_t Value1D::getGridValue( uint64_t x ) const
    {
        const uint64_t prime1 = 22801763489;   // one-billionth prime
        const uint64_t prime2 = 47055833459;   // two-billionth prime
        const uint64_t prime3 = 97011687217;   // four-billionth prime
        const uint64_t shift  = 29;
        const uint64_t mask   = 0x7fffffffffffffff;

        auto n = ( Value1D::X_NOISE_PRIME    * x +
                   Value1D::SEED_NOISE_PRIME * this->seed ) & mask;
        n = ( n >> shift ) ^ n;

        auto ival = ( n * ( n * n * prime1 + prime2 ) + prime3 ) & mask;

        auto res = Util::NormalizeU64( ival );

        return res;
    }

    real_t Value2D::getValue( real_t x, real_t y ) const
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

        real_t u, v;
        
        switch( this->interpMethod )
        {
        case Interp::Smooth:
            u = Util::Interpolation::SmoothStep( tx );
            v = Util::Interpolation::SmoothStep( ty );
            break;
        case Interp::Smoother:
            u = Util::Interpolation::SmootherStep( tx );
            v = Util::Interpolation::SmootherStep( ty );
            break;
        }

        auto res = Util::Lerp( v,
                         Util::Lerp( u, c00, c10 ),
                         Util::Lerp( u, c10, c11 ) );

        return res;
    }
    
    real_t Value2D::getGridValue( uint64_t x, uint64_t y ) const
    {
        const uint64_t prime1 = 22801763489;   // one-billionth prime
        const uint64_t prime2 = 47055833459;   // two-billionth prime
        const uint64_t prime3 = 97011687217;   // four-billionth prime
        const uint64_t shift  = 29;
        const uint64_t mask   = 0x7fffffffffffffff;

        auto n = ( Value2D::X_NOISE_PRIME    * x +
                   Value2D::Y_NOISE_PRIME    * y +
                   Value2D::SEED_NOISE_PRIME * this->seed ) & mask;
        n = ( n >> shift ) ^ n;

        auto ival = ( n * ( n * n * prime1 + prime2 ) + prime3 ) & mask;

        auto res = Util::NormalizeU64( ival );

        return res;
    }

    real_t Value3D::getValue( real_t x, real_t y, real_t z ) const
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

        real_t u, v, s;
        
        switch( this->interpMethod )
        {
        case Interp::Smooth:
            u = Util::Interpolation::SmoothStep( tx );
            v = Util::Interpolation::SmoothStep( ty );
            s = Util::Interpolation::SmoothStep( tz );
            break;
        case Interp::Smoother:
            u = Util::Interpolation::SmootherStep( tx );
            v = Util::Interpolation::SmootherStep( ty );
            s = Util::Interpolation::SmootherStep( tz );
            break;
        }

        auto res = Util::Lerp( s,
                         Util::Lerp( v,
                               Util::Lerp( u, c000, c100 ),
                               Util::Lerp( u, c010, c110 ) ),
                         Util::Lerp( v,
                               Util::Lerp( u, c001, c101 ),
                               Util::Lerp( u, c011, c111 ) ) );

        return res;
    }
    
    real_t Value3D::getGridValue( uint64_t x, uint64_t y, uint64_t z) const
    {
        const uint64_t prime1 = 22801763489;   // one-billionth prime
        const uint64_t prime2 = 47055833459;   // two-billionth prime
        const uint64_t prime3 = 97011687217;   // four-billionth prime
        const uint64_t shift  = 29;
        const uint64_t mask   = 0x7fffffffffffffff;

        auto n = ( Value3D::X_NOISE_PRIME    * x +
                   Value3D::Y_NOISE_PRIME    * y +
                   Value3D::Z_NOISE_PRIME    * z +
                   Value3D::SEED_NOISE_PRIME * this->seed ) & mask;
        n = ( n >> shift ) ^ n;

        auto ival = ( n * ( n * n * prime1 + prime2 ) + prime3 ) & mask;

        auto res = Util::NormalizeU64( ival );

        return res;
    }

    real_t Value4D::getValue( real_t x, real_t y, real_t z, real_t w ) const
    {
        auto xf = std::floor( x );
        auto xi = Util::MakeRealU64Range( xf );
        auto yf = std::floor( y );
        auto yi = Util::MakeRealU64Range( yf );
        auto zf = std::floor( z );
        auto zi = Util::MakeRealU64Range( zf );
        auto wf = std::floor( w );
        auto wi = Util::MakeRealU64Range( wf );

        auto tx = x - xf;
        auto ty = y - yf;
        auto tz = z - zf;
        auto tw = w - wf;

        auto c0000 = this->getGridValue( xi,   yi,   zi,   wi );
        auto c0001 = this->getGridValue( xi,   yi,   zi,   wi+1 );
        auto c0010 = this->getGridValue( xi,   yi,   zi+1, wi );
        auto c0011 = this->getGridValue( xi,   yi,   zi+1, wi+1 );
        auto c0100 = this->getGridValue( xi,   yi+1, zi,   wi );
        auto c0101 = this->getGridValue( xi,   yi+1, zi,   wi+1 );
        auto c0110 = this->getGridValue( xi,   yi+1, zi+1, wi );
        auto c0111 = this->getGridValue( xi,   yi+1, zi+1, wi+1 );
        auto c1000 = this->getGridValue( xi+1, yi,   zi,   wi );
        auto c1001 = this->getGridValue( xi+1, yi,   zi,   wi+1 );
        auto c1010 = this->getGridValue( xi+1, yi,   zi+1, wi );
        auto c1011 = this->getGridValue( xi+1, yi,   zi+1, wi+1 );
        auto c1100 = this->getGridValue( xi+1, yi+1, zi,   wi );
        auto c1101 = this->getGridValue( xi+1, yi+1, zi,   wi+1 );
        auto c1110 = this->getGridValue( xi+1, yi+1, zi+1, wi );
        auto c1111 = this->getGridValue( xi+1, yi+1, zi+1, wi+1 );

        real_t u, v, s, t;
        
        switch( this->interpMethod )
        {
        case Interp::Smooth:
            u = Util::Interpolation::SmoothStep( tx );
            v = Util::Interpolation::SmoothStep( ty );
            s = Util::Interpolation::SmoothStep( tz );
            t = Util::Interpolation::SmoothStep( tw );
            break;
        case Interp::Smoother:
            u = Util::Interpolation::SmootherStep( tx );
            v = Util::Interpolation::SmootherStep( ty );
            s = Util::Interpolation::SmootherStep( tz );
            t = Util::Interpolation::SmootherStep( tw );
            break;
        }

        auto res = Util::Lerp( t,
                         Util::Lerp( s,
                               Util::Lerp( v,
                                     Util::Lerp( u, c0000, c1000 ),
                                     Util::Lerp( u, c0100, c1100 ) ),
                               Util::Lerp( v,
                                     Util::Lerp( u, c0010, c1010 ),
                                     Util::Lerp( u, c0110, c1110 ) ) ),
                         Util::Lerp( s,
                               Util::Lerp( v,
                                     Util::Lerp( u, c0001, c1001 ),
                                     Util::Lerp( u, c0101, c1101 ) ),
                               Util::Lerp( v,
                                     Util::Lerp( u, c0011, c1011 ),
                                     Util::Lerp( u, c0111, c1111 ) ) ) );

        return res;
    }
    
    real_t Value4D::getGridValue( uint64_t x, uint64_t y, uint64_t z, uint64_t w ) const
    {
        const uint64_t prime1 = 22801763489;   // one-billionth prime
        const uint64_t prime2 = 47055833459;   // two-billionth prime
        const uint64_t prime3 = 97011687217;   // four-billionth prime
        const uint64_t shift  = 29;
        const uint64_t mask   = 0x7fffffffffffffff;

        auto n = ( Value4D::X_NOISE_PRIME    * x +
                   Value4D::Y_NOISE_PRIME    * y +
                   Value4D::Z_NOISE_PRIME    * z +
                   Value4D::W_NOISE_PRIME    * w +
                   Value4D::SEED_NOISE_PRIME * this->seed ) & mask;
        n = ( n >> shift ) ^ n;

        auto ival = ( n * ( n * n * prime1 + prime2 ) + prime3 ) & mask;

        auto res = Util::NormalizeU64( ival );

        return res;
    }
}
