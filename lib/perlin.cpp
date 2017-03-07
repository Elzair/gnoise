#include <cmath>

#include "util.h"
#include "vector.h"
#include "perlin.h"

namespace Noise
{
    real_t Perlin::getValue( real_t x ) const
    {
        Vector<1> P  = { x };
        Vector<1> Pf = { std::floor( x ) };
        
        auto c0 = this->getGridVal( P, Pf );
        auto c1 = this->getGridVal( P, Pf + Vector<1>{1.0} );

        auto u = Quintic( P[0] - Pf[0] );

        auto res = Lerp( u, c0, c1 );

        return res;
    }

    real_t Perlin::getValue( real_t x, real_t y ) const
    {
        Vector<2> P  = { x, y };
        Vector<2> Pf = { std::floor( x ),
                         std::floor( y ) };

        auto c00 = this->getGridVal( P, Pf );
        auto c01 = this->getGridVal( P, Pf + Vector<2>{0.0, 1.0} );
        auto c10 = this->getGridVal( P, Pf + Vector<2>{1.0, 0.0} );
        auto c11 = this->getGridVal( P, Pf + Vector<2>{1.0, 1.0} );

        auto u = Quintic( P[0] - Pf[0] );
        auto v = Quintic( P[1] - Pf[1] );

        auto res = Lerp( v,
                         Lerp( u, c00, c10 ),
                         Lerp( u, c10, c11 ) );

        return res;
    }

    real_t Perlin::getValue( real_t x, real_t y, real_t z ) const
    {
        Vector<3> P  = { x, y, z };
        Vector<3> Pf = { std::floor( x ),
                         std::floor( y ),
                         std::floor( z ) };

        auto c000 = this->getGridVal( P, Pf );
        auto c001 = this->getGridVal( P, Pf + Vector<3>{0.0, 0.0, 1.0} );
        auto c010 = this->getGridVal( P, Pf + Vector<3>{0.0, 1.0, 0.0} );
        auto c011 = this->getGridVal( P, Pf + Vector<3>{0.0, 1.0, 1.0} );
        auto c100 = this->getGridVal( P, Pf + Vector<3>{1.0, 0.0, 0.0} );
        auto c101 = this->getGridVal( P, Pf + Vector<3>{1.0, 0.0, 1.0} );
        auto c110 = this->getGridVal( P, Pf + Vector<3>{1.0, 1.0, 0.0} );
        auto c111 = this->getGridVal( P, Pf + Vector<3>{1.0, 1.0, 1.0} );

        auto u = Quintic( P[0] - Pf[0] );
        auto v = Quintic( P[1] - Pf[1] );
        auto w = Quintic( P[2] - Pf[2] );

        auto res = Lerp( w,
                         Lerp( v,
                               Lerp( u, c000, c100 ),
                               Lerp( u, c010, c110 ) ),
                         Lerp( v,
                               Lerp( u, c001, c101 ),
                               Lerp( u, c011, c111 ) ) );

        return res;
    }

    real_t Perlin::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        Vector<4> P  = { x, y, z, a };
        Vector<4> Pf = { std::floor( x ),
                         std::floor( y ),
                         std::floor( z ),
                         std::floor( a ) };

        auto c0000 = this->getGridVal( P, Pf );
        auto c0001 = this->getGridVal( P, Pf + Vector<4>{0.0, 0.0, 1.0, 1.0} );
        auto c0010 = this->getGridVal( P, Pf + Vector<4>{0.0, 0.0, 1.0, 0.0} );
        auto c0011 = this->getGridVal( P, Pf + Vector<4>{0.0, 0.0, 1.0, 1.0} );
        auto c0100 = this->getGridVal( P, Pf + Vector<4>{0.0, 1.0, 0.0, 0.0} );
        auto c0101 = this->getGridVal( P, Pf + Vector<4>{0.0, 1.0, 0.0, 1.0} );
        auto c0110 = this->getGridVal( P, Pf + Vector<4>{0.0, 1.0, 1.0, 0.0} );
        auto c0111 = this->getGridVal( P, Pf + Vector<4>{0.0, 1.0, 1.0, 1.0} );
        auto c1000 = this->getGridVal( P, Pf + Vector<4>{1.0, 0.0, 0.0, 0.0} );
        auto c1001 = this->getGridVal( P, Pf + Vector<4>{1.0, 0.0, 0.0, 1.0} );
        auto c1010 = this->getGridVal( P, Pf + Vector<4>{1.0, 0.0, 1.0, 0.0} );
        auto c1011 = this->getGridVal( P, Pf + Vector<4>{1.0, 0.0, 1.0, 1.0} );
        auto c1100 = this->getGridVal( P, Pf + Vector<4>{1.0, 1.0, 0.0, 0.0} );
        auto c1101 = this->getGridVal( P, Pf + Vector<4>{1.0, 1.0, 0.0, 1.0} );
        auto c1110 = this->getGridVal( P, Pf + Vector<4>{1.0, 1.0, 1.0, 0.0} );
        auto c1111 = this->getGridVal( P, Pf + Vector<4>{1.0, 1.0, 1.0, 1.0} );

        auto u = Quintic( P[0] - Pf[0] );
        auto v = Quintic( P[1] - Pf[1] );
        auto w = Quintic( P[2] - Pf[2] );
        auto t = Quintic( P[3] - Pf[3] );

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

    real_t Perlin::getGridVal( const Vector<1>& pos,
                               const Vector<1>& gridpos ) const
    {
        auto xi = static_cast<uint64_t>( pos[0] );

        Vector<1> gradient {
            NormalizeU64( XORShift128Plus( this->seed, xi ) )
        };
        gradient.normalize();

        auto res = gradient.dot( pos - gridpos );

        return res;
    }

    real_t Perlin::getGridVal( const Vector<2>& pos,
                               const Vector<2>& gridpos ) const
    {
        auto xi = static_cast<uint64_t>( pos[0] );
        auto yi = static_cast<uint64_t>( pos[1] );

        Vector<2> gradient {
            NormalizeU64( XORShift128Plus( this->seed, xi ) ),
            NormalizeU64( XORShift128Plus( this->seed, yi ) )
        };
        gradient.normalize();

        auto res = gradient.dot( pos - gridpos );

        return res;
    }

    real_t Perlin::getGridVal( const Vector<3>& pos,
                               const Vector<3>& gridpos ) const
    {
        auto xi = static_cast<uint64_t>( pos[0] );
        auto yi = static_cast<uint64_t>( pos[1] );
        auto zi = static_cast<uint64_t>( pos[2] );

        Vector<3> gradient {
            NormalizeU64( XORShift128Plus( this->seed, xi ) ),
            NormalizeU64( XORShift128Plus( this->seed, yi ) ),
            NormalizeU64( XORShift128Plus( this->seed, zi ) )
        };
        gradient.normalize();

        auto res = gradient.dot( pos - gridpos );

        return res;
    }

    real_t Perlin::getGridVal( const Vector<4>& pos,
                               const Vector<4>& gridpos ) const
    {
        auto xi = static_cast<uint64_t>( pos[0] );
        auto yi = static_cast<uint64_t>( pos[1] );
        auto zi = static_cast<uint64_t>( pos[2] );
        auto ai = static_cast<uint64_t>( pos[3] );

        Vector<4> gradient {
            NormalizeU64( XORShift128Plus( this->seed, xi ) ),
            NormalizeU64( XORShift128Plus( this->seed, yi ) ),
            NormalizeU64( XORShift128Plus( this->seed, zi ) ),
            NormalizeU64( XORShift128Plus( this->seed, ai ) )
        };
        gradient.normalize();

        auto res = gradient.dot( pos - gridpos );

        return res;
    }
}
