#include "util.h"
#include "white.h"

namespace Noise
{
    real_t White1D::getValue( real_t x ) const
    {
        auto res = Util::U64ToReal( Util::Hash( this->seed,
                                                Util::RealToU64( x) ) );

        return res;
    }

    real_t White2D::getValue( real_t x, real_t y ) const
    {
        auto res = Util::U64ToReal( Util::Hash( this->seed,
                                                Util::RealToU64( x ),
                                                Util::RealToU64( y ) ) );

        return res;
    }

    real_t White3D::getValue( real_t x, real_t y, real_t z ) const
    {
        auto res = Util::U64ToReal( Util::Hash( this->seed,
                                                Util::RealToU64( x ),
                                                Util::RealToU64( y ),
                                                Util::RealToU64( z ) ) );

        return res;
    }

    real_t White4D::getValue( real_t x, real_t y, real_t z, real_t w ) const
    {
        auto res = Util::U64ToReal( Util::Hash( this->seed,
                                                Util::RealToU64( x ),
                                                Util::RealToU64( y ),
                                                Util::RealToU64( z ),
                                                Util::RealToU64( w ) ) );

        return res;
    }
}
