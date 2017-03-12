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
     * Billow Module Methods
     */
    
    real_t Billow1D::getValue( real_t x ) const
    {
        auto res = 2.0 * std::abs( this->source.getValue( x ) ) - 1.0;

        return res;
    }

    real_t Billow2D::getValue( real_t x, real_t y ) const
    {
        auto res = 2.0 * std::abs( this->source.getValue( x, y ) ) - 1.0;

        return res;
    }

    real_t Billow3D::getValue( real_t x, real_t y, real_t z ) const
    {
        auto res = 2.0 * std::abs( this->source.getValue( x, y, z ) ) - 1.0;

        return res;
    }

    real_t Billow4D::getValue( real_t x, real_t y, real_t z, real_t w ) const
    {
        auto res = 2.0 * std::abs( this->source.getValue( x, y, z, w ) ) - 1.0;

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
}
