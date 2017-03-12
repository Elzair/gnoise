#include <cmath>

#include "util.h"
#include "vector.h"
#include "perlin.h"

namespace Noise
{
    real_t Perlin1D::getValue( real_t x ) const
    {
        Noise::VectorN<1> P  = { x };
        Noise::VectorN<1> Pf = { std::floor( x ) };
        
        auto c0 = this->getGridValue( P, Pf );
        auto c1 = this->getGridValue( P, Pf + Noise::VectorN<1>{1.0} );

        auto u = Util::Quintic( P[0] - Pf[0] );

        auto res = Util::Lerp( u, c0, c1 );

        return res;
    }

    real_t Perlin1D::getGridValue( const Noise::VectorN<1>& pos,
                                   const Noise::VectorN<1>& gridpos ) const
    {
        Noise::VectorN<1> gradient {
            Util::NormalizeU64( Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( gridpos[0] ) ) )
        };
        gradient.normalize();

        auto res = gradient.dot( pos - gridpos );

        return res;
    }

    real_t Perlin2D::getValue( real_t x, real_t y ) const
    {
        Noise::VectorN<2> P  = { x, y };
        Noise::VectorN<2> Pf = { std::floor( x ),
                                 std::floor( y ) };

        auto c00 = this->getGridValue( P, Pf );
        auto c01 = this->getGridValue( P, Pf + Noise::VectorN<2>{0.0, 1.0} );
        auto c10 = this->getGridValue( P, Pf + Noise::VectorN<2>{1.0, 0.0} );
        auto c11 = this->getGridValue( P, Pf + Noise::VectorN<2>{1.0, 1.0} );

        auto u = Util::Quintic( P[0] - Pf[0] );
        auto v = Util::Quintic( P[1] - Pf[1] );

        auto res = Util::Lerp( v,
                         Util::Lerp( u, c00, c10 ),
                         Util::Lerp( u, c10, c11 ) );

        return res;
    }

    real_t Perlin2D::getGridValue( const Noise::VectorN<2>& pos,
                                   const Noise::VectorN<2>& gridpos ) const
    {
        Noise::VectorN<2> gradient {
            Util::NormalizeU64( Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( gridpos[0] ) ) ),
            Util::NormalizeU64( Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( gridpos[1] ) ) )
        };
        gradient.normalize();

        auto res = gradient.dot( pos - gridpos );

        return res;
    }

    real_t Perlin3D::getValue( real_t x, real_t y, real_t z ) const
    {
        Noise::VectorN<3> P  = { x, y, z };
        Noise::VectorN<3> Pf = { std::floor( x ),
                                 std::floor( y ),
                                 std::floor( z ) };

        auto c000 = this->getGridValue( P, Pf );
        auto c001 = this->getGridValue( P, Pf + Noise::VectorN<3>{0.0, 0.0, 1.0} );
        auto c010 = this->getGridValue( P, Pf + Noise::VectorN<3>{0.0, 1.0, 0.0} );
        auto c011 = this->getGridValue( P, Pf + Noise::VectorN<3>{0.0, 1.0, 1.0} );
        auto c100 = this->getGridValue( P, Pf + Noise::VectorN<3>{1.0, 0.0, 0.0} );
        auto c101 = this->getGridValue( P, Pf + Noise::VectorN<3>{1.0, 0.0, 1.0} );
        auto c110 = this->getGridValue( P, Pf + Noise::VectorN<3>{1.0, 1.0, 0.0} );
        auto c111 = this->getGridValue( P, Pf + Noise::VectorN<3>{1.0, 1.0, 1.0} );

        auto u = Util::Quintic( P[0] - Pf[0] );
        auto v = Util::Quintic( P[1] - Pf[1] );
        auto s = Util::Quintic( P[2] - Pf[2] );

        auto res = Util::Lerp( s,
                         Util::Lerp( v,
                               Util::Lerp( u, c000, c100 ),
                               Util::Lerp( u, c010, c110 ) ),
                         Util::Lerp( v,
                               Util::Lerp( u, c001, c101 ),
                               Util::Lerp( u, c011, c111 ) ) );

        return res;
    }

    real_t Perlin3D::getGridValue( const Noise::VectorN<3>& pos,
                                   const Noise::VectorN<3>& gridpos ) const
    {
        Noise::VectorN<3> gradient {
            Util::NormalizeU64( Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( gridpos[0] ) ) ),
            Util::NormalizeU64( Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( gridpos[1] ) ) ),
            Util::NormalizeU64( Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( gridpos[2] ) ) )
        };
        gradient.normalize();

        auto res = gradient.dot( pos - gridpos );

        return res;
    }

    real_t Perlin4D::getValue( real_t x, real_t y, real_t z, real_t w ) const
    {
        Noise::VectorN<4> P  = { x, y, z, w };
        Noise::VectorN<4> Pf = { std::floor( x ),
                                 std::floor( y ),
                                 std::floor( z ),
                                 std::floor( w ) };

        auto c0000 = this->getGridValue( P, Pf );
        auto c0001 = this->getGridValue( P, Pf + Noise::VectorN<4>{0.0, 0.0, 0.0, 1.0} );
        auto c0010 = this->getGridValue( P, Pf + Noise::VectorN<4>{0.0, 0.0, 1.0, 0.0} );
        auto c0011 = this->getGridValue( P, Pf + Noise::VectorN<4>{0.0, 0.0, 1.0, 1.0} );
        auto c0100 = this->getGridValue( P, Pf + Noise::VectorN<4>{0.0, 1.0, 0.0, 0.0} );
        auto c0101 = this->getGridValue( P, Pf + Noise::VectorN<4>{0.0, 1.0, 0.0, 1.0} );
        auto c0110 = this->getGridValue( P, Pf + Noise::VectorN<4>{0.0, 1.0, 1.0, 0.0} );
        auto c0111 = this->getGridValue( P, Pf + Noise::VectorN<4>{0.0, 1.0, 1.0, 1.0} );
        auto c1000 = this->getGridValue( P, Pf + Noise::VectorN<4>{1.0, 0.0, 0.0, 0.0} );
        auto c1001 = this->getGridValue( P, Pf + Noise::VectorN<4>{1.0, 0.0, 0.0, 1.0} );
        auto c1010 = this->getGridValue( P, Pf + Noise::VectorN<4>{1.0, 0.0, 1.0, 0.0} );
        auto c1011 = this->getGridValue( P, Pf + Noise::VectorN<4>{1.0, 0.0, 1.0, 1.0} );
        auto c1100 = this->getGridValue( P, Pf + Noise::VectorN<4>{1.0, 1.0, 0.0, 0.0} );
        auto c1101 = this->getGridValue( P, Pf + Noise::VectorN<4>{1.0, 1.0, 0.0, 1.0} );
        auto c1110 = this->getGridValue( P, Pf + Noise::VectorN<4>{1.0, 1.0, 1.0, 0.0} );
        auto c1111 = this->getGridValue( P, Pf + Noise::VectorN<4>{1.0, 1.0, 1.0, 1.0} );

        auto u = Util::Quintic( P[0] - Pf[0] );
        auto v = Util::Quintic( P[1] - Pf[1] );
        auto s = Util::Quintic( P[2] - Pf[2] );
        auto t = Util::Quintic( P[3] - Pf[3] );

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

    real_t Perlin4D::getGridValue( const Noise::VectorN<4>& pos,
                                   const Noise::VectorN<4>& gridpos ) const
    {
        Noise::VectorN<4> gradient {
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
