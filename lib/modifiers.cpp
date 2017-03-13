#include <cmath>

#include "modifiers.h"

namespace Noise
{ 
    /*
     * AbsoluteValue Module Methods
     */
    
    real_t AbsoluteValue1D::getValue( real_t x ) const
    {
        auto res = std::abs( this->source.getValue( x ) );

        return res;
    }

    real_t AbsoluteValue2D::getValue( real_t x, real_t y ) const
    {
        auto res = std::abs( this->source.getValue( x, y ) );

        return res;
    }

    real_t AbsoluteValue3D::getValue( real_t x, real_t y, real_t z ) const
    {
        auto res = std::abs( this->source.getValue( x, y, z ) );

        return res;
    }

    real_t AbsoluteValue4D::getValue( real_t x, real_t y, real_t z, real_t w ) const
    {
        auto res = std::abs( this->source.getValue( x, y, z, w ) );

        return res;
    }

    /*
     * Bias Module Methods
     */
    
    real_t Bias1D::getValue( real_t x ) const
    {
        auto res = this->source.getValue( x ) + this->bias;

        return res;
    }

    real_t Bias2D::getValue( real_t x, real_t y ) const
    {
        auto res = this->source.getValue( x, y ) + this->bias;

        return res;
    }

    real_t Bias3D::getValue( real_t x, real_t y, real_t z ) const
    {
        auto res = this->source.getValue( x, y, z ) + this->bias;

        return res;
    }

    real_t Bias4D::getValue( real_t x, real_t y, real_t z, real_t w ) const
    {
        auto res = this->source.getValue( x, y, z, w ) + this->bias;

        return res;
    }

    /*
     * Clamp Module Methods
     */

    real_t Clamp1D::getValue( real_t x ) const
    {
        auto res = this->source.getValue( x );

        if ( res < this->min )
        {
            res = min;
        }
        else if ( res > this->max )
        {
            res = max;
        }

        return res;
    }

    real_t Clamp2D::getValue( real_t x, real_t y ) const
    {
        auto res = this->source.getValue( x, y );

        if ( res < this->min )
        {
            res = min;
        }
        else if ( res > this->max )
        {
            res = max;
        }

        return res;
    }

    real_t Clamp3D::getValue( real_t x, real_t y, real_t z ) const
    {
        auto res = this->source.getValue( x, y, z );

        if ( res < this->min )
        {
            res = min;
        }
        else if ( res > this->max )
        {
            res = max;
        }

        return res;
    }

    real_t Clamp4D::getValue( real_t x, real_t y, real_t z, real_t w ) const
    {
        auto res = this->source.getValue( x, y, z, w );

        if ( res < this->min )
        {
            res = min;
        }
        else if ( res > this->max )
        {
            res = max;
        }

        return res;
    }

    /*
     * Invert Module Methods
     */
    
    real_t Invert1D::getValue( real_t x ) const
    {
        auto res = this->source.getValue( x ) * -1.0;

        return res;
    }

    real_t Invert2D::getValue( real_t x, real_t y ) const
    {
        auto res = this->source.getValue( x, y ) * -1.0;

        return res;
    }

    real_t Invert3D::getValue( real_t x, real_t y, real_t z ) const
    {
        auto res = this->source.getValue( x, y, z ) * -1.0;

        return res;
    }

    real_t Invert4D::getValue( real_t x, real_t y, real_t z, real_t w ) const
    {
        auto res = this->source.getValue( x, y, z, w ) * -1.0;

        return res;
    }

    /*
     * Scale Module Methods
     */
    
    real_t Scale1D::getValue( real_t x ) const
    {
        auto res = this->source.getValue( x ) * this->multiple;

        return res;
    }

    real_t Scale2D::getValue( real_t x, real_t y ) const
    {
        auto res = this->source.getValue( x, y ) * this->multiple;

        return res;
    }

    real_t Scale3D::getValue( real_t x, real_t y, real_t z ) const
    {
        auto res = this->source.getValue( x, y, z ) * this->multiple;

        return res;
    }

    real_t Scale4D::getValue( real_t x, real_t y, real_t z, real_t w ) const
    {
        auto res = this->source.getValue( x, y, z, w ) * this->multiple;

        return res;
    }

    /*
     * Terrace Module Methods
     */

    real_t Terrace1D::getValue( real_t x ) const
    {
        auto val = this->source.getValue( x );

        // Find first element in controlPoints that has a value larger than val.
        int64_t i = 0;
        while( i < this->controlPoints.size() ) 
        {
            if ( this->controlPoints[i] > val )
            {
                break;
            }

            i++;
        }

        // Find the two nearest control points to val.
        auto idx0 = Util::Wrap( i-1, 0, this->controlPoints.size() );
        auto idx1 = Util::Wrap( i,   0, this->controlPoints.size() );

        if ( idx0 == idx1 )
        {
            return this->controlPoints[i];
        }

        // Compute weight value used for linear interpolation.
        auto pt0    = this->controlPoints[idx0];
        auto pt1    = this->controlPoints[idx0];
        auto weight = ( val - pt0 ) / ( pt1 - pt0 );

        if ( this->invert )
        {
            weight   = 1.0 - weight;
            auto tmp = pt0;
            pt0      = pt1;
            pt1      = tmp;
        }

        // Square the weight value to produce the terrace effect.
        weight *= weight;

        // Perform linear interpolation.
        Util::Lerp( weight, pt0, pt1 );
    }

    real_t Terrace2D::getValue( real_t x, real_t y ) const
    {
        auto val = this->source.getValue( x, y );

        // Find first element in controlPoints that has a value larger than val.
        int64_t i = 0;
        while( i < this->controlPoints.size() ) 
        {
            if ( this->controlPoints[i] > val )
            {
                break;
            }

            i++;
        }

        // Find the two nearest control points to val.
        auto idx0 = Util::Wrap( i-1, 0, this->controlPoints.size() );
        auto idx1 = Util::Wrap( i,   0, this->controlPoints.size() );

        if ( idx0 == idx1 )
        {
            return this->controlPoints[i];
        }

        // Compute weight value used for linear interpolation.
        auto pt0    = this->controlPoints[idx0];
        auto pt1    = this->controlPoints[idx0];
        auto weight = ( val - pt0 ) / ( pt1 - pt0 );

        if ( this->invert )
        {
            weight   = 1.0 - weight;
            auto tmp = pt0;
            pt0      = pt1;
            pt1      = tmp;
        }

        // Square the weight value to produce the terrace effect.
        weight *= weight;

        // Perform linear interpolation.
        Util::Lerp( weight, pt0, pt1 );
    }

    real_t Terrace3D::getValue( real_t x, real_t y, real_t z ) const
    {
        auto val = this->source.getValue( x, y, z );

        // Find first element in controlPoints that has a value larger than val.
        int64_t i = 0;
        while( i < this->controlPoints.size() ) 
        {
            if ( this->controlPoints[i] > val )
            {
                break;
            }

            i++;
        }

        // Find the two nearest control points to val.
        auto idx0 = Util::Wrap( i-1, 0, this->controlPoints.size() );
        auto idx1 = Util::Wrap( i,   0, this->controlPoints.size() );

        if ( idx0 == idx1 )
        {
            return this->controlPoints[i];
        }

        // Compute weight value used for linear interpolation.
        auto pt0    = this->controlPoints[idx0];
        auto pt1    = this->controlPoints[idx0];
        auto weight = ( val - pt0 ) / ( pt1 - pt0 );

        if ( this->invert )
        {
            weight   = 1.0 - weight;
            auto tmp = pt0;
            pt0      = pt1;
            pt1      = tmp;
        }

        // Square the weight value to produce the terrace effect.
        weight *= weight;

        // Perform linear interpolation.
        Util::Lerp( weight, pt0, pt1 );
    }

    real_t Terrace4D::getValue( real_t x, real_t y, real_t z, real_t w ) const
    {
        auto val = this->source.getValue( x, y, z, w );

        // Find first element in controlPoints that has a value larger than val.
        int64_t i = 0;
        while( i < this->controlPoints.size() ) 
        {
            if ( this->controlPoints[i] > val )
            {
                break;
            }

            i++;
        }

        // Find the two nearest control points to val.
        auto idx0 = Util::Wrap( i-1, 0, this->controlPoints.size() );
        auto idx1 = Util::Wrap( i,   0, this->controlPoints.size() );

        if ( idx0 == idx1 )
        {
            return this->controlPoints[i];
        }

        // Compute weight value used for linear interpolation.
        auto pt0    = this->controlPoints[idx0];
        auto pt1    = this->controlPoints[idx0];
        auto weight = ( val - pt0 ) / ( pt1 - pt0 );

        if ( this->invert )
        {
            weight   = 1.0 - weight;
            auto tmp = pt0;
            pt0      = pt1;
            pt1      = tmp;
        }

        // Square the weight value to produce the terrace effect.
        weight *= weight;

        // Perform linear interpolation.
        Util::Lerp( weight, pt0, pt1 );
    }
}
