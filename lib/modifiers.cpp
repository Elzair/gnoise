#include <cmath>

#include "modifiers.h"

namespace Noise
{ 
    /*
     * AbsoluteValue Module Methods
     */
    
    real_t AbsoluteValue::getValue( real_t x ) const
    {
        auto res = std::abs( this->source.getValue( x ) );

        return res;
    }

    real_t AbsoluteValue::getValue( real_t x, real_t y ) const
    {
        auto res = std::abs( this->source.getValue( x, y ) );

        return res;
    }

    real_t AbsoluteValue::getValue( real_t x, real_t y, real_t z ) const
    {
        auto res = std::abs( this->source.getValue( x, y, z ) );

        return res;
    }

    real_t AbsoluteValue::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto res = std::abs( this->source.getValue( x, y, z, a ) );

        return res;
    }

    /*
     * Bias Module Methods
     */
    
    real_t Bias::getValue( real_t x ) const
    {
        auto res = this->source.getValue( x ) + this->bias;

        return res;
    }

    real_t Bias::getValue( real_t x, real_t y ) const
    {
        auto res = this->source.getValue( x, y ) + this->bias;

        return res;
    }

    real_t Bias::getValue( real_t x, real_t y, real_t z ) const
    {
        auto res = this->source.getValue( x, y, z ) + this->bias;

        return res;
    }

    real_t Bias::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto res = this->source.getValue( x, y, z, a ) + this->bias;

        return res;
    }

    /*
     * Billow Module Methods
     */
    
    real_t Billow::getValue( real_t x ) const
    {
        auto res = 2.0 * std::abs( this->source.getValue( x ) ) - 1.0;

        return res;
    }

    real_t Billow::getValue( real_t x, real_t y ) const
    {
        auto res = 2.0 * std::abs( this->source.getValue( x, y ) ) - 1.0;

        return res;
    }

    real_t Billow::getValue( real_t x, real_t y, real_t z ) const
    {
        auto res = 2.0 * std::abs( this->source.getValue( x, y, z ) ) - 1.0;

        return res;
    }

    real_t Billow::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto res = 2.0 * std::abs( this->source.getValue( x, y, z, a ) ) - 1.0;

        return res;
    }

    /*
     * Clamp Module Methods
     */

    real_t Clamp::getValue( real_t x ) const
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

    real_t Clamp::getValue( real_t x, real_t y ) const
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

    real_t Clamp::getValue( real_t x, real_t y, real_t z ) const
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

    real_t Clamp::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto res = this->source.getValue( x, y, z, a );

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
    
    real_t Invert::getValue( real_t x ) const
    {
        auto res = this->source.getValue( x ) * -1.0;

        return res;
    }

    real_t Invert::getValue( real_t x, real_t y ) const
    {
        auto res = this->source.getValue( x, y ) * -1.0;

        return res;
    }

    real_t Invert::getValue( real_t x, real_t y, real_t z ) const
    {
        auto res = this->source.getValue( x, y, z ) * -1.0;

        return res;
    }

    real_t Invert::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto res = this->source.getValue( x, y, z, a ) * -1.0;

        return res;
    }

    /*
     * Scale Module Methods
     */
    
    real_t Scale::getValue( real_t x ) const
    {
        auto res = this->source.getValue( x ) * this->multiple;

        return res;
    }

    real_t Scale::getValue( real_t x, real_t y ) const
    {
        auto res = this->source.getValue( x, y ) * this->multiple;

        return res;
    }

    real_t Scale::getValue( real_t x, real_t y, real_t z ) const
    {
        auto res = this->source.getValue( x, y, z ) * this->multiple;

        return res;
    }

    real_t Scale::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        auto res = this->source.getValue( x, y, z, a ) * this->multiple;

        return res;
    }
}
