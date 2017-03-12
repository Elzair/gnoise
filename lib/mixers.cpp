#include <cmath>

#include "util.h"
#include "mixers.h"

namespace Noise
{ 
    /*
     * Blend Module Methods
     */
    
    real_t Blend1D::getValue( real_t x ) const
    {
        auto val1 = this->input1.getValue( x );
        auto val2 = this->input2.getValue( x );
        auto wval = this->weight.getValue( x );
        auto res  = Util::Lerp( wval, val1, val2 );

        return res;
    }

    real_t Blend2D::getValue( real_t x, real_t y ) const
    {
        auto val1 = this->input1.getValue( x, y );
        auto val2 = this->input2.getValue( x, y );
        auto wval = this->weight.getValue( x, y );
        auto res  = Util::Lerp( wval, val1, val2 );

        return res;
    }

    real_t Blend3D::getValue( real_t x, real_t y, real_t z ) const
    {
        auto val1 = this->input1.getValue( x, y, z );
        auto val2 = this->input2.getValue( x, y, z );
        auto wval = this->weight.getValue( x, y, z );
        auto res  = Util::Lerp( wval, val1, val2 );

        return res;
    }

    real_t Blend4D::getValue( real_t x, real_t y, real_t z, real_t a ) const
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
    
    real_t Difference1D::getValue( real_t x ) const
    {
        auto res = this->input1.getValue( x ) -
                   this->input2.getValue( x );

        return res;
    }

    real_t Difference2D::getValue( real_t x, real_t y ) const
    {
        auto res = this->input1.getValue( x, y ) -
                   this->input2.getValue( x, y );

        return res;
    }

    real_t Difference3D::getValue( real_t x, real_t y, real_t z ) const
    {
        auto res = this->input1.getValue( x, y, z ) -
                   this->input2.getValue( x, y, z );

        return res;
    }

    real_t Difference4D::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto res = this->input1.getValue( x, y, z, a ) -
                   this->input2.getValue( x, y, z, a );

        return res;
    }

    /*
     * Displace Module Methods
     */
    
    real_t Displace1D::getValue( real_t x ) const
    {
        auto xd  = this->xdisp.getValue( x );
        auto res = this->source.getValue( x + xd );

        return res;
    }

    real_t Displace2D::getValue( real_t x, real_t y ) const
    {
        auto xd  = this->xdisp.getValue( x );
        auto yd  = this->ydisp.getValue( y );
        auto res = this->source.getValue( x + xd, y + yd );

        return res;
    }

    real_t Displace3D::getValue( real_t x, real_t y, real_t z ) const
    {
        auto xd  = this->xdisp.getValue( x );
        auto yd  = this->ydisp.getValue( y );
        auto zd  = this->zdisp.getValue( z );
        auto res = this->source.getValue( x + xd,
                                          y + yd,
                                          z + zd );

        return res;
    }

    real_t Displace4D::getValue( real_t x, real_t y, real_t z, real_t w ) const
    {
        auto xd  = this->xdisp.getValue( x );
        auto yd  = this->ydisp.getValue( y );
        auto zd  = this->zdisp.getValue( z );
        auto wd  = this->wdisp.getValue( w );
        auto res = this->source.getValue( x + xd,
                                          y + yd,
                                          z + zd,
                                          w + wd );

        return res;
    }

    /*
     * Maximum Module Methods
     */
    
    real_t Maximum1D::getValue( real_t x ) const
    {
        auto val1 = this->input1.getValue( x );
        auto val2 = this->input2.getValue( x );
        auto res  = val1 > val2 ? val1 : val2;

        return res;
    }

    real_t Maximum2D::getValue( real_t x, real_t y ) const
    {
        auto val1 = this->input1.getValue( x, y );
        auto val2 = this->input2.getValue( x, y );
        auto res  = val1 > val2 ? val1 : val2;

        return res;
    }

    real_t Maximum3D::getValue( real_t x, real_t y, real_t z ) const
    {
        auto val1 = this->input1.getValue( x, y, z );
        auto val2 = this->input2.getValue( x, y, z );
        auto res  = val1 > val2 ? val1 : val2;

        return res;
    }

    real_t Maximum4D::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto val1 = this->input1.getValue( x, y, z, a );
        auto val2 = this->input2.getValue( x, y, z, a );
        auto res  = val1 > val2 ? val1 : val2;

        return res;
    }

    /*
     * Minimum Module Methods
     */
    
    real_t Minimum1D::getValue( real_t x ) const
    {
        auto val1 = this->input1.getValue( x );
        auto val2 = this->input2.getValue( x );
        auto res  = val1 < val2 ? val1 : val2;

        return res;
    }

    real_t Minimum2D::getValue( real_t x, real_t y ) const
    {
        auto val1 = this->input1.getValue( x, y );
        auto val2 = this->input2.getValue( x, y );
        auto res  = val1 < val2 ? val1 : val2;

        return res;
    }

    real_t Minimum3D::getValue( real_t x, real_t y, real_t z ) const
    {
        auto val1 = this->input1.getValue( x, y, z );
        auto val2 = this->input2.getValue( x, y, z );
        auto res  = val1 < val2 ? val1 : val2;

        return res;
    }

    real_t Minimum4D::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto val1 = this->input1.getValue( x, y, z, a );
        auto val2 = this->input2.getValue( x, y, z, a );
        auto res  = val1 < val2 ? val1 : val2;

        return res;
    }

    /*
     * Power Module Methods
     */
    
    real_t Power1D::getValue( real_t x ) const
    {
        auto res = std::pow( this->input1.getValue( x ),
                             this->input2.getValue( x ) );

        return res;
    }

    real_t Power2D::getValue( real_t x, real_t y ) const
    {
        auto res = std::pow( this->input1.getValue( x, y ),
                             this->input2.getValue( x, y ) );

        return res;
    }

    real_t Power3D::getValue( real_t x, real_t y, real_t z ) const
    {
        auto res = std::pow( this->input1.getValue( x, y, z ),
                             this->input2.getValue( x, y, z ) );

        return res;
    }

    real_t Power4D::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto res = std::pow( this->input1.getValue( x, y, z, a ),
                             this->input2.getValue( x, y, z, a ) );

        return res;
    }

    /*
     * Product Module Methods
     */
    
    real_t Product1D::getValue( real_t x ) const
    {
        auto res = this->input1.getValue( x ) *
                   this->input2.getValue( x );

        return res;
    }

    real_t Product2D::getValue( real_t x, real_t y ) const
    {
        auto res = this->input1.getValue( x, y ) *
                   this->input2.getValue( x, y );

        return res;
    }

    real_t Product3D::getValue( real_t x, real_t y, real_t z ) const
    {
        auto res = this->input1.getValue( x, y, z ) *
                   this->input2.getValue( x, y, z );

        return res;
    }

    real_t Product4D::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto res = this->input1.getValue( x, y, z, a ) *
                   this->input2.getValue( x, y, z, a );

        return res;
    }

    /*
     * Quotient Module Methods
     */
    
    real_t Quotient1D::getValue( real_t x ) const
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

    real_t Quotient2D::getValue( real_t x, real_t y ) const
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

    real_t Quotient3D::getValue( real_t x, real_t y, real_t z ) const
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

    real_t Quotient4D::getValue( real_t x, real_t y, real_t z, real_t a ) const
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
    
    real_t Select1D::getValue( real_t x ) const
    {
        auto val1 = this->choice1.getValue( x );
        auto val2 = this->choice2.getValue( x );
        auto sval = this->decider.getValue( x );
        auto res  = ( sval >= this->low && sval <= this->high )
                  ? val1
                  : val2;

        return res;
    }

    real_t Select2D::getValue( real_t x, real_t y ) const
    {
        auto val1 = this->choice1.getValue( x, y );
        auto val2 = this->choice2.getValue( x, y );
        auto sval = this->decider.getValue( x, y );
        auto res  = ( sval >= this->low && sval <= this->high )
                  ? val1
                  : val2;

        return res;
    }

    real_t Select3D::getValue( real_t x, real_t y, real_t z ) const
    {
        auto val1 = this->choice1.getValue( x, y, z );
        auto val2 = this->choice2.getValue( x, y, z );
        auto sval = this->decider.getValue( x, y, z );
        auto res  = ( sval >= this->low && sval <= this->high )
                  ? val1
                  : val2;

        return res;
    }

    real_t Select4D::getValue( real_t x, real_t y, real_t z, real_t a ) const
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
    
    real_t Sum1D::getValue( real_t x ) const
    {
        auto res = this->input1.getValue( x ) +
                   this->input2.getValue( x );

        return res;
    }

    real_t Sum2D::getValue( real_t x, real_t y ) const
    {
        auto res = this->input1.getValue( x, y ) +
                   this->input2.getValue( x, y );

        return res;
    }

    real_t Sum3D::getValue( real_t x, real_t y, real_t z ) const
    {
        auto res = this->input1.getValue( x, y, z ) +
                   this->input2.getValue( x, y, z );

        return res;
    }

    real_t Sum4D::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto res = this->input1.getValue( x, y, z, a ) +
                   this->input2.getValue( x, y, z, a );

        return res;
    }
}
