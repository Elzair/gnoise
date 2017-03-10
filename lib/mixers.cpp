#include <cmath>

#include "util.h"
#include "mixers.h"

namespace Noise
{ 
    /*
     * Blend Module Methods
     */
    
    real_t Blend::getValue( real_t x ) const
    {
        auto val1 = this->input1.getValue( x );
        auto val2 = this->input2.getValue( x );
        auto wval = this->weight.getValue( x );
        auto res  = Util::Lerp( wval, val1, val2 );

        return res;
    }

    real_t Blend::getValue( real_t x, real_t y ) const
    {
        auto val1 = this->input1.getValue( x, y );
        auto val2 = this->input2.getValue( x, y );
        auto wval = this->weight.getValue( x, y );
        auto res  = Util::Lerp( wval, val1, val2 );

        return res;
    }

    real_t Blend::getValue( real_t x, real_t y, real_t z ) const
    {
        auto val1 = this->input1.getValue( x, y, z );
        auto val2 = this->input2.getValue( x, y, z );
        auto wval = this->weight.getValue( x, y, z );
        auto res  = Util::Lerp( wval, val1, val2 );

        return res;
    }

    real_t Blend::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto val1 = this->input1.getValue( x, y, z, a );
        auto val2 = this->input2.getValue( x, y, z, a );
        auto wval = this->weight.getValue( x, y, z, a );
        auto res  = Util::Lerp( wval, val1, val2 );

        return res;
    }

    /*
     * Difference Module Methods
     */
    
    real_t Difference::getValue( real_t x ) const
    {
        auto res = this->input1.getValue( x ) -
                   this->input2.getValue( x );

        return res;
    }

    real_t Difference::getValue( real_t x, real_t y ) const
    {
        auto res = this->input1.getValue( x, y ) -
                   this->input2.getValue( x, y );

        return res;
    }

    real_t Difference::getValue( real_t x, real_t y, real_t z ) const
    {
        auto res = this->input1.getValue( x, y, z ) -
                   this->input2.getValue( x, y, z );

        return res;
    }

    real_t Difference::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto res = this->input1.getValue( x, y, z, a ) -
                   this->input2.getValue( x, y, z, a );

        return res;
    }

    /*
     * Displace Module Methods
     */
    
    real_t Displace::getValue( real_t x ) const
    {
        auto xd  = this->xdisp.getValue( x );
        auto res = this->source.getValue( x + xd );

        return res;
    }

    real_t Displace::getValue( real_t x, real_t y ) const
    {
        auto xd  = this->xdisp.getValue( x );
        auto yd  = this->ydisp.getValue( y );
        auto res = this->source.getValue( x + xd, y + yd );

        return res;
    }

    real_t Displace::getValue( real_t x, real_t y, real_t z ) const
    {
        auto xd  = this->xdisp.getValue( x );
        auto yd  = this->ydisp.getValue( y );
        auto zd  = this->zdisp.getValue( z );
        auto res = this->source.getValue( x + xd,
                                          y + yd,
                                          z + zd );

        return res;
    }

    real_t Displace::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto xd  = this->xdisp.getValue( x );
        auto yd  = this->ydisp.getValue( y );
        auto zd  = this->zdisp.getValue( z );
        auto ad  = this->adisp.getValue( a );
        auto res = this->source.getValue( x + xd,
                                          y + yd,
                                          z + zd,
                                          a + ad );

        return res;
    }

    /*
     * Maximum Module Methods
     */
    
    real_t Maximum::getValue( real_t x ) const
    {
        auto val1 = this->input1.getValue( x );
        auto val2 = this->input2.getValue( x );
        auto res  = val1 > val2 ? val1 : val2;

        return res;
    }

    real_t Maximum::getValue( real_t x, real_t y ) const
    {
        auto val1 = this->input1.getValue( x, y );
        auto val2 = this->input2.getValue( x, y );
        auto res  = val1 > val2 ? val1 : val2;

        return res;
    }

    real_t Maximum::getValue( real_t x, real_t y, real_t z ) const
    {
        auto val1 = this->input1.getValue( x, y, z );
        auto val2 = this->input2.getValue( x, y, z );
        auto res  = val1 > val2 ? val1 : val2;

        return res;
    }

    real_t Maximum::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto val1 = this->input1.getValue( x, y, z, a );
        auto val2 = this->input2.getValue( x, y, z, a );
        auto res  = val1 > val2 ? val1 : val2;

        return res;
    }

    /*
     * Minimum Module Methods
     */
    
    real_t Minimum::getValue( real_t x ) const
    {
        auto val1 = this->input1.getValue( x );
        auto val2 = this->input2.getValue( x );
        auto res  = val1 < val2 ? val1 : val2;

        return res;
    }

    real_t Minimum::getValue( real_t x, real_t y ) const
    {
        auto val1 = this->input1.getValue( x, y );
        auto val2 = this->input2.getValue( x, y );
        auto res  = val1 < val2 ? val1 : val2;

        return res;
    }

    real_t Minimum::getValue( real_t x, real_t y, real_t z ) const
    {
        auto val1 = this->input1.getValue( x, y, z );
        auto val2 = this->input2.getValue( x, y, z );
        auto res  = val1 < val2 ? val1 : val2;

        return res;
    }

    real_t Minimum::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto val1 = this->input1.getValue( x, y, z, a );
        auto val2 = this->input2.getValue( x, y, z, a );
        auto res  = val1 < val2 ? val1 : val2;

        return res;
    }

    /*
     * Power Module Methods
     */
    
    real_t Power::getValue( real_t x ) const
    {
        auto res = std::pow( this->input1.getValue( x ),
                             this->input2.getValue( x ) );

        return res;
    }

    real_t Power::getValue( real_t x, real_t y ) const
    {
        auto res = std::pow( this->input1.getValue( x, y ),
                             this->input2.getValue( x, y ) );

        return res;
    }

    real_t Power::getValue( real_t x, real_t y, real_t z ) const
    {
        auto res = std::pow( this->input1.getValue( x, y, z ),
                             this->input2.getValue( x, y, z ) );

        return res;
    }

    real_t Power::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto res = std::pow( this->input1.getValue( x, y, z, a ),
                             this->input2.getValue( x, y, z, a ) );

        return res;
    }

    /*
     * Product Module Methods
     */
    
    real_t Product::getValue( real_t x ) const
    {
        auto res = this->input1.getValue( x ) *
                   this->input2.getValue( x );

        return res;
    }

    real_t Product::getValue( real_t x, real_t y ) const
    {
        auto res = this->input1.getValue( x, y ) *
                   this->input2.getValue( x, y );

        return res;
    }

    real_t Product::getValue( real_t x, real_t y, real_t z ) const
    {
        auto res = this->input1.getValue( x, y, z ) *
                   this->input2.getValue( x, y, z );

        return res;
    }

    real_t Product::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto res = this->input1.getValue( x, y, z, a ) *
                   this->input2.getValue( x, y, z, a );

        return res;
    }

    /*
     * Quotient Module Methods
     */
       /*
     * Minimum Module Methods
     */
    
    real_t Quotient::getValue( real_t x ) const
    {
        auto input1 = this->input1.getValue( x );
        auto input2 = this->input2.getValue( x );
        auto res    = input1 / input2;

        if ( std::isinf( res ) )
        {
            res = this->zeroVal;
        }

        return res;
    }

    real_t Quotient::getValue( real_t x, real_t y ) const
    {
        auto input1 = this->input1.getValue( x, y );
        auto input2 = this->input2.getValue( x, y );
        auto res    = input1 / input2;

        if ( std::isinf( res ) )
        {
            res = this->zeroVal;
        }

        return res;
    }

    real_t Quotient::getValue( real_t x, real_t y, real_t z ) const
    {
        auto input1 = this->input1.getValue( x, y, z );
        auto input2 = this->input2.getValue( x, y, z );
        auto res    = input1 / input2;

        if ( std::isinf( res ) )
        {
            res = this->zeroVal;
        }

        return res;
    }

    real_t Quotient::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto input1 = this->input1.getValue( x, y, z, a );
        auto input2 = this->input2.getValue( x, y, z, a );
        auto res    = input1 / input2;

        if ( std::isinf( res ) )
        {
            res = this->zeroVal;
        }

        return res;
    }

    /*
     * Select Module Methods
     */
    
    real_t Select::getValue( real_t x ) const
    {
        auto val1 = this->choice1.getValue( x );
        auto val2 = this->choice2.getValue( x );
        auto sval = this->decider.getValue( x );
        auto res  = ( sval >= this->low && sval <= this->high )
                  ? val1
                  : val2;

        return res;
    }

    real_t Select::getValue( real_t x, real_t y ) const
    {
        auto val1 = this->choice1.getValue( x, y );
        auto val2 = this->choice2.getValue( x, y );
        auto sval = this->decider.getValue( x, y );
        auto res  = ( sval >= this->low && sval <= this->high )
                  ? val1
                  : val2;

        return res;
    }

    real_t Select::getValue( real_t x, real_t y, real_t z ) const
    {
        auto val1 = this->choice1.getValue( x, y, z );
        auto val2 = this->choice2.getValue( x, y, z );
        auto sval = this->decider.getValue( x, y, z );
        auto res  = ( sval >= this->low && sval <= this->high )
                  ? val1
                  : val2;

        return res;
    }

    real_t Select::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto val1 = this->choice1.getValue( x, y, z, a );
        auto val2 = this->choice2.getValue( x, y, z, a );
        auto sval = this->decider.getValue( x, y, z, a );
        auto res  = ( sval >= this->low && sval <= this->high )
                  ? val1
                  : val2;

        return res;
    }

    /*
     * Sum Module Methods
     */
    
    real_t Sum::getValue( real_t x ) const
    {
        auto res = this->input1.getValue( x ) +
                   this->input2.getValue( x );

        return res;
    }

    real_t Sum::getValue( real_t x, real_t y ) const
    {
        auto res = this->input1.getValue( x, y ) +
                   this->input2.getValue( x, y );

        return res;
    }

    real_t Sum::getValue( real_t x, real_t y, real_t z ) const
    {
        auto res = this->input1.getValue( x, y, z ) +
                   this->input2.getValue( x, y, z );

        return res;
    }

    real_t Sum::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto res = this->input1.getValue( x, y, z, a ) +
                   this->input2.getValue( x, y, z, a );

        return res;
    }
}
