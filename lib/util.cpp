#include "util.h"

namespace Noise
{
    namespace Util
    {
        uint64_t HashFNV1A( uint64_t x )
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

        uint64_t XORShift128Plus( uint64_t& s0, uint64_t& s1 )
        {
            uint64_t       x = s0;
            const uint64_t y = s1;

            s0 = y;
            x ^= x << 23;
            s1 = x ^ y ^ ( x >> 17 ) ^ ( y >> 26 );
            return s1 + y;
        }

        // This function normalizes a 64-bit unsigned integer between -1.0 and 1.0.
        real_t NormalizeU64( uint64_t x )
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

        uint64_t MakeRealU64Range( real_t x )
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

        real_t Quintic( real_t t )
        {
            return t * t * t * ( t * ( t * 6 - 15 ) + 10 );
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
    }
}
