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
        
        auto c0 = this->getGridValue( P, Pf );
        auto c1 = this->getGridValue( P, Pf + Vector<1>{1.0} );

        auto u = Util::Quintic( P[0] - Pf[0] );

        auto res = Util::Lerp( u, c0, c1 );

        return res;
    }

    real_t Perlin::getValue( real_t x, real_t y ) const
    {
        Vector<2> P  = { x, y };
        Vector<2> Pf = { std::floor( x ),
                         std::floor( y ) };

        auto c00 = this->getGridValue( P, Pf );
        auto c01 = this->getGridValue( P, Pf + Vector<2>{0.0, 1.0} );
        auto c10 = this->getGridValue( P, Pf + Vector<2>{1.0, 0.0} );
        auto c11 = this->getGridValue( P, Pf + Vector<2>{1.0, 1.0} );

        auto u = Util::Quintic( P[0] - Pf[0] );
        auto v = Util::Quintic( P[1] - Pf[1] );

        auto res = Util::Lerp( v,
                         Util::Lerp( u, c00, c10 ),
                         Util::Lerp( u, c10, c11 ) );

        return res;
    }

    real_t Perlin::getValue( real_t x, real_t y, real_t z ) const
    {
        Vector<3> P  = { x, y, z };
        Vector<3> Pf = { std::floor( x ),
                         std::floor( y ),
                         std::floor( z ) };

        auto c000 = this->getGridValue( P, Pf );
        auto c001 = this->getGridValue( P, Pf + Vector<3>{0.0, 0.0, 1.0} );
        auto c010 = this->getGridValue( P, Pf + Vector<3>{0.0, 1.0, 0.0} );
        auto c011 = this->getGridValue( P, Pf + Vector<3>{0.0, 1.0, 1.0} );
        auto c100 = this->getGridValue( P, Pf + Vector<3>{1.0, 0.0, 0.0} );
        auto c101 = this->getGridValue( P, Pf + Vector<3>{1.0, 0.0, 1.0} );
        auto c110 = this->getGridValue( P, Pf + Vector<3>{1.0, 1.0, 0.0} );
        auto c111 = this->getGridValue( P, Pf + Vector<3>{1.0, 1.0, 1.0} );

        auto u = Util::Quintic( P[0] - Pf[0] );
        auto v = Util::Quintic( P[1] - Pf[1] );
        auto w = Util::Quintic( P[2] - Pf[2] );

        auto res = Util::Lerp( w,
                         Util::Lerp( v,
                               Util::Lerp( u, c000, c100 ),
                               Util::Lerp( u, c010, c110 ) ),
                         Util::Lerp( v,
                               Util::Lerp( u, c001, c101 ),
                               Util::Lerp( u, c011, c111 ) ) );

        return res;
    }

    real_t Perlin::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        Vector<4> P  = { x, y, z, a };
        Vector<4> Pf = { std::floor( x ),
                         std::floor( y ),
                         std::floor( z ),
                         std::floor( a ) };

        auto c0000 = this->getGridValue( P, Pf );
        auto c0001 = this->getGridValue( P, Pf + Vector<4>{0.0, 0.0, 0.0, 1.0} );
        auto c0010 = this->getGridValue( P, Pf + Vector<4>{0.0, 0.0, 1.0, 0.0} );
        auto c0011 = this->getGridValue( P, Pf + Vector<4>{0.0, 0.0, 1.0, 1.0} );
        auto c0100 = this->getGridValue( P, Pf + Vector<4>{0.0, 1.0, 0.0, 0.0} );
        auto c0101 = this->getGridValue( P, Pf + Vector<4>{0.0, 1.0, 0.0, 1.0} );
        auto c0110 = this->getGridValue( P, Pf + Vector<4>{0.0, 1.0, 1.0, 0.0} );
        auto c0111 = this->getGridValue( P, Pf + Vector<4>{0.0, 1.0, 1.0, 1.0} );
        auto c1000 = this->getGridValue( P, Pf + Vector<4>{1.0, 0.0, 0.0, 0.0} );
        auto c1001 = this->getGridValue( P, Pf + Vector<4>{1.0, 0.0, 0.0, 1.0} );
        auto c1010 = this->getGridValue( P, Pf + Vector<4>{1.0, 0.0, 1.0, 0.0} );
        auto c1011 = this->getGridValue( P, Pf + Vector<4>{1.0, 0.0, 1.0, 1.0} );
        auto c1100 = this->getGridValue( P, Pf + Vector<4>{1.0, 1.0, 0.0, 0.0} );
        auto c1101 = this->getGridValue( P, Pf + Vector<4>{1.0, 1.0, 0.0, 1.0} );
        auto c1110 = this->getGridValue( P, Pf + Vector<4>{1.0, 1.0, 1.0, 0.0} );
        auto c1111 = this->getGridValue( P, Pf + Vector<4>{1.0, 1.0, 1.0, 1.0} );

        auto u = Util::Quintic( P[0] - Pf[0] );
        auto v = Util::Quintic( P[1] - Pf[1] );
        auto w = Util::Quintic( P[2] - Pf[2] );
        auto t = Util::Quintic( P[3] - Pf[3] );

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

    real_t Perlin::getGridValue( const Vector<1>& pos,
                                 const Vector<1>& gridpos ) const
    {
        Vector<1> gradient {
            Util::NormalizeU64( Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( gridpos[0] ) ) )
        };
        gradient.normalize();

        auto res = gradient.dot( pos - gridpos );

        return res;
    }

    real_t Perlin::getGridValue( const Vector<2>& pos,
                                 const Vector<2>& gridpos ) const
    {
        Vector<2> gradient {
            Util::NormalizeU64( Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( gridpos[0] ) ) ),
            Util::NormalizeU64( Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( gridpos[1] ) ) )
        };
        gradient.normalize();

        auto res = gradient.dot( pos - gridpos );

        return res;
    }

    real_t Perlin::getGridValue( const Vector<3>& pos,
                                 const Vector<3>& gridpos ) const
    {
        Vector<3> gradient {
            Util::NormalizeU64( Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( gridpos[0] ) ) ),
            Util::NormalizeU64( Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( gridpos[1] ) ) ),
            Util::NormalizeU64( Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( gridpos[2] ) ) )
        };
        gradient.normalize();

        auto res = gradient.dot( pos - gridpos );

        return res;
    }

    real_t Perlin::getGridValue( const Vector<4>& pos,
                                 const Vector<4>& gridpos ) const
    {
        Vector<4> gradient {
            Util::NormalizeU64( Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( gridpos[0] ) ) ),
            Util::NormalizeU64( Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( gridpos[1] ) ) ),
            Util::NormalizeU64( Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( gridpos[2] ) ) ),
            Util::NormalizeU64( Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( gridpos[3] ) ) )
        };
        gradient.normalize();

        auto res = gradient.dot( pos - gridpos );

        return res;
    }
}
