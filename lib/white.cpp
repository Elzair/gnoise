#include "util.h"
#include "white.h"

namespace Noise
{
    real_t White::getValue( real_t x ) const
    {
        auto xr  = Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( x ) );
        auto res = Util::NormalizeU64( xr );

        return res;
    }

    real_t White::getValue( real_t x, real_t y ) const
    {
        auto xr  = Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( x ) );
        auto yr  = Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( y ) );
        auto res = Util::NormalizeU64( xr ^ yr );

        return res;
    }

    real_t White::getValue( real_t x, real_t y, real_t z ) const
    {
        auto xr  = Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( x ) );
        auto yr  = Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( y ) );
        auto zr  = Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( z ) );
        auto res = Util::NormalizeU64( xr ^ yr ^ zr );

        return res;
    }

    real_t White::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto xr  = Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( x ) );
        auto yr  = Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( y ) );
        auto zr  = Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( z ) );
        auto ar  = Util::HashFNV1A( this->seed ^ Util::MakeRealU64Range( a ) );
        auto res = Util::NormalizeU64( xr ^ yr ^ zr ^ ar );

        return res;
    }
}
