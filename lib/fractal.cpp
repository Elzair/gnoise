#include <cmath>

#include "fractal.h"

namespace Noise
{ 
    /*
     * Fractal Module Methods
     */
    
    real_t Fractal1D::getValue( real_t x ) const
    {
        real_t frequency = 1.0;
        real_t amplitude = 1.0;
        real_t res       = 0.0;

        for ( auto i = 0; i < this->numOctaves; i++ )
        {
            auto val = this->source.getValue( x * frequency );

            res       += val * amplitude;
            frequency *= this->lacunarity;
            amplitude *= this->persistence;
        }

        return res;
    }

    real_t Fractal2D::getValue( real_t x, real_t y ) const
    {
        real_t frequency = 1.0;
        real_t amplitude = 1.0;
        real_t res       = 0.0;

        for ( auto i = 0; i < this->numOctaves; i++ )
        {
            auto val = this->source.getValue( x * frequency,
                                              y * frequency );

            res       += val * amplitude;
            frequency *= this->lacunarity;
            amplitude *= this->persistence;
        }

        return res;
    }

    real_t Fractal3D::getValue( real_t x, real_t y, real_t z ) const
    {
        real_t frequency = 1.0;
        real_t amplitude = 1.0;
        real_t res       = 0.0;

        for ( auto i = 0; i < this->numOctaves; i++ )
        {
            auto val = this->source.getValue( x * frequency,
                                              y * frequency,
                                              z * frequency );

            res       += val * amplitude;
            frequency *= this->lacunarity;
            amplitude *= this->persistence;
        }

        return res;
    }

    real_t Fractal4D::getValue( real_t x, real_t y, real_t z, real_t a ) const
    {
        real_t frequency = 1.0;
        real_t amplitude = 1.0;
        real_t res       = 0.0;

        for ( auto i = 0; i < this->numOctaves; i++ )
        {
            auto val = this->source.getValue( x * frequency,
                                              y * frequency,
                                              z * frequency,
                                              a * frequency );

            res       += val * amplitude;
            frequency *= this->lacunarity;
            amplitude *= this->persistence;
        }

        return res;
    }

    RidgedMultiFractal1D::RidgedMultiFractal1D(
        Module1D& source,
        uint32_t  numOctaves,
        real_t    lacunarity,
        real_t    h,
        real_t    offset,
        real_t    gain
    ) :
        source( source ),
        numOctaves( numOctaves ),
        lacunarity( lacunarity ),
        h( h ),
        offset( offset ),
        gain( gain )
    {
        // Calculate the spectral weights.
        this->spectralWeights.resize( this->numOctaves );

        real_t frequency = 1.0;

        for ( auto i = 0; i < this->numOctaves; i++ )
        {
            this->spectralWeights[i] = pow( frequency, this->h );
            frequency *= this->lacunarity;
        }
    }

    real_t RidgedMultiFractal1D::getValue( real_t x ) const
    {
        real_t frequency = 1.0;
        real_t weight    = 1.0;
        real_t value;
        real_t res;

        for ( auto i = 0; i < this->numOctaves; i++ )
        {
            auto val = this->source.getValue( x * frequency );

            // Make the ridges.
            val = this->offset - std::abs( val );

            // Increase the sharpness of the ridges by squaring val.
            val = std::pow( val, 2.0 );

            // Apply weight from previous octave to val.
            val *= weight;

            // Calculate weight for next octave.
            weight = val * this->gain;

            if ( weight > 1.0 )
            {
                weight = 1.0;
            }
            else if ( weight < 0.0 )
            {
                weight = 0.0;
            }

            // Add val to output.
            res += ( this->spectralWeights[i] * val );

            frequency *= this->lacunarity;
        }

        return res;
    }

    RidgedMultiFractal2D::RidgedMultiFractal2D(
        Module2D& source,
        uint32_t  numOctaves,
        real_t    lacunarity,
        real_t    h,
        real_t    offset,
        real_t    gain
    ) :
        source( source ),
        numOctaves( numOctaves ),
        lacunarity( lacunarity ),
        h( h ),
        offset( offset ),
        gain( gain )
    {
        // Calculate the spectral weights.
        this->spectralWeights.resize( this->numOctaves );

        real_t frequency = 1.0;

        for ( auto i = 0; i < this->numOctaves; i++ )
        {
            this->spectralWeights[i] = pow( frequency, this->h );
            frequency *= this->lacunarity;
        }
    }

    real_t RidgedMultiFractal2D::getValue( real_t x, real_t y ) const
    {
        real_t frequency = 1.0;
        real_t weight    = 1.0;
        real_t value;
        real_t res;

        for ( auto i = 0; i < this->numOctaves; i++ )
        {
            auto val = this->source.getValue( x * frequency,
                                              y * frequency );

            // Make the ridges.
            val = this->offset - std::abs( val );

            // Increase the sharpness of the ridges by squaring val.
            val = std::pow( val, 2.0 );

            // Apply weight from previous octave to val.
            val *= weight;

            // Calculate weight for next octave.
            weight = val * this->gain;

            if ( weight > 1.0 )
            {
                weight = 1.0;
            }
            else if ( weight < 0.0 )
            {
                weight = 0.0;
            }

            // Add val to output.
            res += ( this->spectralWeights[i] * val );

            frequency *= this->lacunarity;
        }

        return res;
    }

    RidgedMultiFractal3D::RidgedMultiFractal3D(
        Module3D& source,
        uint32_t  numOctaves,
        real_t    lacunarity,
        real_t    h,
        real_t    offset,
        real_t    gain
    ) :
        source( source ),
        numOctaves( numOctaves ),
        lacunarity( lacunarity ),
        h( h ),
        offset( offset ),
        gain( gain )
    {
        // Calculate the spectral weights.
        this->spectralWeights.resize( this->numOctaves );

        real_t frequency = 1.0;

        for ( auto i = 0; i < this->numOctaves; i++ )
        {
            this->spectralWeights[i] = pow( frequency, this->h );
            frequency *= this->lacunarity;
        }
    }

    real_t RidgedMultiFractal3D::getValue( real_t x, real_t y, real_t z ) const
    {
        real_t frequency = 1.0;
        real_t weight    = 1.0;
        real_t value;
        real_t res;

        for ( auto i = 0; i < this->numOctaves; i++ )
        {
            auto val = this->source.getValue( x * frequency,
                                              y * frequency,
                                              z * frequency );

            // Make the ridges.
            val = this->offset - std::abs( val );

            // Increase the sharpness of the ridges by squaring val.
            val = std::pow( val, 2.0 );

            // Apply weight from previous octave to val.
            val *= weight;

            // Calculate weight for next octave.
            weight = val * this->gain;

            if ( weight > 1.0 )
            {
                weight = 1.0;
            }
            else if ( weight < 0.0 )
            {
                weight = 0.0;
            }

            // Add val to output.
            res += ( this->spectralWeights[i] * val );

            frequency *= this->lacunarity;
        }

        return res;
    }

    RidgedMultiFractal4D::RidgedMultiFractal4D(
        Module4D& source,
        uint32_t  numOctaves,
        real_t    lacunarity,
        real_t    h,
        real_t    offset,
        real_t    gain
    ) :
        source( source ),
        numOctaves( numOctaves ),
        lacunarity( lacunarity ),
        h( h ),
        offset( offset ),
        gain( gain )
    {
        // Calculate the spectral weights.
        this->spectralWeights.resize( this->numOctaves );

        real_t frequency = 1.0;

        for ( auto i = 0; i < this->numOctaves; i++ )
        {
            this->spectralWeights[i] = pow( frequency, this->h );
            frequency *= this->lacunarity;
        }
    }

    real_t RidgedMultiFractal4D::getValue( real_t x, real_t y, real_t z, real_t w ) const
    {
        real_t frequency = 1.0;
        real_t weight    = 1.0;
        real_t value;
        real_t res;

        for ( auto i = 0; i < this->numOctaves; i++ )
        {
            auto val = this->source.getValue( x * frequency,
                                              y * frequency,
                                              z * frequency,
                                              w * frequency );

            // Make the ridges.
            val = this->offset - std::abs( val );

            // Increase the sharpness of the ridges by squaring val.
            val = std::pow( val, 2.0 );

            // Apply weight from previous octave to val.
            val *= weight;

            // Calculate weight for next octave.
            weight = val * this->gain;

            if ( weight > 1.0 )
            {
                weight = 1.0;
            }
            else if ( weight < 0.0 )
            {
                weight = 0.0;
            }

            // Add val to output.
            res += ( this->spectralWeights[i] * val );

            frequency *= this->lacunarity;
        }

        return res;
    }
}
