#include "util.h"

namespace Noise
{
    namespace Util
    {
        uint64_t Hash( uint64_t x )
        {
            const uint64_t prime = 1099511628211; // i.e. 2^40 + 2^8 + 179
            uint64_t       hash  = 14695981039346656037;

            for ( auto i = 0; i < sizeof( uint64_t ); i++ )
            {
                hash = ( hash ^ ( x & 0xff ) ) * prime;
                x    = x >> 8;
            }

            return hash;
        }
        uint64_t Hash( uint64_t x, uint64_t y )
        {
            const uint64_t prime = 1099511628211; // i.e. 2^40 + 2^8 + 179
            uint64_t       hash  = 14695981039346656037;

            for ( auto i = 0; i < sizeof( uint64_t ); i++ )
            {
                hash = ( hash ^ ( x & 0xff ) ) * prime;
                x    = x >> 8;
            }

            for ( auto i = 0; i < sizeof( uint64_t ); i++ )
            {
                hash = ( hash ^ ( y & 0xff ) ) * prime;
                y    = y >> 8;
            }

            return hash;
        }

        uint64_t Hash( uint64_t x, uint64_t y, uint64_t z )
        {
            const uint64_t prime = 1099511628211; // i.e. 2^40 + 2^8 + 179
            uint64_t       hash  = 14695981039346656037;

            for ( auto i = 0; i < sizeof( uint64_t ); i++ )
            {
                hash = ( hash ^ ( x & 0xff ) ) * prime;
                x    = x >> 8;
            }

            for ( auto i = 0; i < sizeof( uint64_t ); i++ )
            {
                hash = ( hash ^ ( y & 0xff ) ) * prime;
                y    = y >> 8;
            }

            for ( auto i = 0; i < sizeof( uint64_t ); i++ )
            {
                hash = ( hash ^ ( z & 0xff ) ) * prime;
                z    = z >> 8;
            }

            return hash;
        }

        uint64_t Hash( uint64_t x, uint64_t y, uint64_t z, uint64_t w )
        {
            const uint64_t prime = 1099511628211; // i.e. 2^40 + 2^8 + 179
            uint64_t       hash  = 14695981039346656037;

            for ( auto i = 0; i < sizeof( uint64_t ); i++ )
            {
                hash = ( hash ^ ( x & 0xff ) ) * prime;
                x    = x >> 8;
            }

            for ( auto i = 0; i < sizeof( uint64_t ); i++ )
            {
                hash = ( hash ^ ( y & 0xff ) ) * prime;
                y    = y >> 8;
            }

            for ( auto i = 0; i < sizeof( uint64_t ); i++ )
            {
                hash = ( hash ^ ( z & 0xff ) ) * prime;
                z    = z >> 8;
            }

            for ( auto i = 0; i < sizeof( uint64_t ); i++ )
            {
                hash = ( hash ^ ( w & 0xff ) ) * prime;
                w    = w >> 8;
            }

            return hash;
        }

        uint64_t Hash( uint64_t x, uint64_t y, uint64_t z, uint64_t w, uint64_t r )
        {
            const uint64_t prime = 1099511628211; // i.e. 2^40 + 2^8 + 179
            uint64_t       hash  = 14695981039346656037;

            for ( auto i = 0; i < sizeof( uint64_t ); i++ )
            {
                hash = ( hash ^ ( x & 0xff ) ) * prime;
                x    = x >> 8;
            }

            for ( auto i = 0; i < sizeof( uint64_t ); i++ )
            {
                hash = ( hash ^ ( y & 0xff ) ) * prime;
                y    = y >> 8;
            }

            for ( auto i = 0; i < sizeof( uint64_t ); i++ )
            {
                hash = ( hash ^ ( z & 0xff ) ) * prime;
                z    = z >> 8;
            }

            for ( auto i = 0; i < sizeof( uint64_t ); i++ )
            {
                hash = ( hash ^ ( w & 0xff ) ) * prime;
                w    = w >> 8;
            }

            for ( auto i = 0; i < sizeof( uint64_t ); i++ )
            {
                hash = ( hash ^ ( r & 0xff ) ) * prime;
                r    = r >> 8;
            }

            return hash;
        }

        uint64_t RNG( uint64_t& s0, uint64_t& s1 )
        {
            uint64_t       x = s0;
            const uint64_t y = s1;

            s0 = y;
            x ^= x << 23;
            s1 = x ^ y ^ ( x >> 17 ) ^ ( y >> 26 );
            return s1 + y;
        }

        uint64_t I64ToU64( int64_t x )
        {
            uint64_t ux = x;
            ux         += std::numeric_limits<int64_t>::max();
            ux         += 1;

            return ux;
        }

        real_t U64ToReal( uint64_t x )
        {
            constexpr real_t invHalfMaxU64 = 2.0 / static_cast<real_t>( std::numeric_limits<uint64_t>::max() );

            // Divide the number by half the maximum uint64_t.
            real_t step1 = x * invHalfMaxU64;
            // Current Range: 0.0 ... 2.0
        
            // Subtract 1 to normalize the value.
            real_t res = step1 - 1.0;
            // Current Range: -1.0 ... 1.0

            return res;
        }

        real_t U64ToNormReal( uint64_t x )
        {
            constexpr real_t invMaxU64 = 1.0 / static_cast<real_t>( std::numeric_limits<uint64_t>::max() );

            // Divide the number by  the maximum uint64_t.
            real_t res = x * invMaxU64;
            // Current Range: 0.0 ... 1.0

            return res;
        }

        uint64_t RealToU64( real_t x )
        {
            real_t low  = static_cast<real_t>( std::numeric_limits<int64_t>::min() );
            real_t high = static_cast<real_t>( std::numeric_limits<int64_t>::max() );

            // First, clamp to int64_t range.
            if ( x < low )
            {
                x = low;
            }
            else if ( x > high )
            {
                x = high;
            }

            // Now, convert to uint64_t range.
            real_t val = x + std::abs( low ); 

            // Finally, convert number to uint64_t.
            uint64_t res = static_cast<uint64_t>( val );

            return res;
        }
        
        uint64_t NormRealToU64( real_t x )
        {
            // Assume x is between 0.0 and 1.0.
            auto newx = x * static_cast<real_t>( std::numeric_limits<uint64_t>::max() );
            auto res  = static_cast<uint64_t>( newx );

            return res;
        }

        real_t Lerp( real_t t, real_t a, real_t b )
        {
            return a + t * ( b - a );
        }

        void InsertionSort( Vector<real_t>& vec )
        {
            for ( auto i = 1; i < vec.size(); i++ )
            {
                auto x = vec[i];
                auto j = 0;
                
                while( ( j >= 0 ) && ( vec[j-1] > vec[j] ) )
                {
                    auto tmp = vec[j];
                    vec[j]   = vec[j-1];
                    vec[j-1] = tmp;
                }
                
                vec[j+1] = x;
            }
        }

        void InsertAndSort( real_t* arr, std::size_t n, real_t val )
        {
            real_t tmp = 0.0;

            for ( int i = n-1; i >= 0; i-- )
            {
                if ( val > arr[i] )
                {
                    break;
                }

                tmp    = arr[i];
                arr[i] = val;

                if ( i + 1 < n )
                {
                    arr[i+1] = tmp;
                }
            }
        }

        int64_t Wrap( int64_t val, int64_t low, int64_t high )
        {
            auto range = high - low + 1;

            if ( val < low )
            {
                val += range * ( ( low - val ) / range + 1);
            }

            auto res = low + ( val - low ) % range;

            return res;
        }

        uint64_t Factorial( uint64_t x )
        {
            auto res = 1;

            for ( auto i = 1; i <= x; i++ )
            {
                res *= i;
            }

            return res;
        }

        namespace Interpolation
        {
            real_t SmoothStep( real_t t )
            {
                return t * t * ( 3 - 2 * t );
            }

            real_t SmootherStep( real_t t )
            {
                return t * t * t * ( t * ( t * 6 - 15 ) + 10 );
            }
        }
    }
}
