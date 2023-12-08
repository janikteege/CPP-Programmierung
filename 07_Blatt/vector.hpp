#pragma once

#include <cstdint>
#include <cstddef>

/* Implement a generic mathematical Vector.
 * todo: * add template parameters
 *       * implement the required operators
 *       * test all functions
 *       * keep it const correct
 */
namespace Math {

    // The vector should have both a generic numeric type(T) and a number of dimensions(N).
    // The data can be stored in an array of type T and size N.
    template<typename T, std::size_t N>
    class Vector
    {
    public:
        Vector() = default;  // Default constructor

        // Constructor to allow aggregate initialization
        Vector(std::initializer_list<T> values) {
            if (values.size() != N) {
                throw std::invalid_argument("Initializer list size does not match Vector dimensions.");
            }

            std::size_t i = 0;
            for (const auto& value : values) {
                data[i++] = value;
            }
        }
        // operator[] overload for reading!
        const T& operator[] (std::size_t index) const {
            return data[index];
        }

        // operator[] overload for read/write access!
        T& operator[] (std::size_t index) {
            return data[index];
        }

        // Todo: Implement a unary operator- overload that returns a copy with all components negated.
        Vector operator- () const {
            Vector result;
            for (size_t i = 0; i < N; i++) {
                result[i] = -data[i];
            }
            return result;
        }

        // operator+ overload that takes a vector of same type and size.
        Vector operator+ (const Vector& rhs) const {
            Vector result;
            for (size_t i = 0; i < N; i++) {
                result[i] = data[i] + rhs[i];
            }
            return result;
        }

        // operator- overload that takes a vector of same type and size.
        Vector operator- (const Vector& rhs) const {
            Vector result;
            for (size_t i = 0; i < N; i++) {
                result[i] = data[i] - rhs[i];
            }
            return result;
        }
    private:
        T data[N];
    };
	
    // operator* overload that takes a vector from the left and a scalar from the right side.
    // Returns a vector.
    template <typename T, std::size_t N>
    Vector<T, N> operator*(const Vector<T, N>& vec, T scalar) {
        Vector<T, N> result;
        for (std::size_t i = 0; i < N; ++i) {
            result[i] = vec[i] * scalar;
        }
        return result;
    }
	
    // operator* overload that takes a vector from the right and a scalar from the left side.
    // Returns a vector.
    template <typename T, std::size_t N>
    Vector<T, N> operator*(T scalar, const Vector<T, N>& vec) {
        return vec * scalar;
    }

    template <typename T, std::size_t N>
    T dot(const Vector<T,N>& v1, const Vector<T,N>& v2) {
        T result = v1[0] * v2[0];
        for (size_t i = 1; i < N; i++)
        {
            result += v1[i] * v2[i];
        }
        return result;
    }

    template <typename T>
    Vector<T, 3> cross(const Vector<T,3>& v1, const Vector<T,3>& v2) {
        Vector<T, 3> result;
        result[0] = v1[1] * v2[2] - v1[2] * v2[1];
        result[1] = v1[2] * v2[0] - v1[0] * v2[2];
        result[2] = v1[0] * v2[1] - v1[1] * v2[0];
        return result;
    }
}
