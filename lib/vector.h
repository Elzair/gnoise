// -*- mode: c++; -*-

#pragma once

#include <cmath>
#include <cstddef>

#include <array>
#include <initializer_list>

#include "util.h"

namespace Noise
{
    template<std::size_t N>
    class Vector
    {
    public:

        std::array<real_t, N> vals;

        Vector<N>& operator+=( const Vector<N>& v )
        {
            for ( auto i = 0; i < N; i++ )
            {
                this->vals[i] += v[i];
            }

            return *this;
        }
    
        Vector<N>& operator+=( real_t n )
        {
            for ( auto i = 0; i < N; i++ )
            {
                this->vals[i] += n;
            }

            return *this;
        }

        Vector<N>& operator-=( const Vector<N>& v )
        {
            for ( auto i = 0; i < N; i++ )
            {
                this->vals[i] -= v[i];
            }

            return *this;
        }
        
        Vector<N>& operator-=( real_t n )
        {
            for ( auto i = 0; i < N; i++ )
            {
                this->vals[i] -= n;
            }

            return *this;
        }

        Vector<N>& operator*=( const Vector<N>& v )
        {
            for ( auto i = 0; i < N; i++ )
            {
                this->vals[i] *= v[i];
            }

            return *this;
        }
         
        Vector<N>& operator*=( real_t n )
        {
            for ( auto i = 0; i < N; i++ )
            {
                this->vals[i] *= n;
            }

            return *this;
        }
   
        Vector<N>& operator/=( const Vector<N>& v )
        {
            for ( auto i = 0; i < N; i++ )
            {
                this->vals[i] /= v[i];
            }

            return *this;
        }
         
        Vector<N>& operator/=( real_t n )
        {
            real_t nrecip = 1.0 / n; // Multiplying by 1/n should be faster than dividing by n.

            for ( auto i = 0; i < N; i++ )
            {
                this->vals[i] *= nrecip;
            }

            return *this;
        }

        Vector<N>& normalize()
        {
            real_t norm_mul = 1.0 / this->getLength();

            for ( auto& val : this->vals )
            {
                val *= norm_mul;
            }

            return *this;
        }

        real_t& operator[]( std::size_t idx )
        {
            return this->vals[ idx ];
        }

        const real_t& operator[]( std::size_t idx ) const
        {
            return this->vals[ idx ];
        }

        Vector<N> operator+( const Vector<N>& v ) const
        {
            Vector copy = *this;
            copy       += v;
        
            return copy;
        }

        Vector<N> operator+( real_t n ) const
        {
            Vector copy = *this;
            copy       += n;
        
            return copy;
        }

        Vector<N> operator-( const Vector<N>& v ) const
        {
            Vector copy = *this;
            copy       -= v;
        
            return copy;
        }

        Vector<N> operator-( real_t n ) const
        {
            Vector copy = *this;
            copy       -= n;
        
            return copy;
        }

        Vector<N> operator*( const Vector<N>& v ) const
        {
            Vector copy = *this;
            copy       *= v;
        
            return copy;
        }
 
        Vector<N> operator*( real_t n ) const
        {
            Vector copy = *this;
            copy       *= n;
        
            return copy;
        }
   
        Vector<N> operator/( const Vector<N>& v ) const
        {
            Vector copy = *this;
            copy       /= v;
        
            return copy;
        }
 
        Vector<N> operator/( real_t n ) const
        {
            Vector copy = *this;
            copy       /= n;
        
            return copy;
        }

        Vector<N> normalized() const
        {
            Vector copy = *this;
            copy.normalize();

            return copy;
        }

        real_t dot( const Vector<N>& v ) const
        {
            real_t dot_product;

            for ( auto i = 0; i < N; i++ )
            {
                dot_product = std::fma( this->vals[i],
                                        v[i],
                                        dot_product );
            }

            return dot_product;
        }

        real_t getLength() const
        {
            real_t len = sqrt( this->getLengthSq() );

            return len;
        }

    private:
    

        inline real_t getLengthSq() const
        {
            real_t lensq;

            for ( auto& val : this->vals )
            {
                lensq = std::fma( val,
                                  val,
                                  lensq );
            }

            return lensq;
        }
    };
}
