#include <iostream>

#include "vector.hpp"

using Vec3 = Math::Vector<float, 3>;
using Vec2 = Math::Vector<float, 2>;

int main()
{   
    // Create vectors
    Vec3 v1{1.0f, 2.0f, 3.0f};
    Vec3 v2{4.0f, 5.0f, 6.0f};

    // Test reading and writing using operator[]
    v1[0] = 0.0f;
    std::cout << "v1[0]: " << v1[0] << std::endl;
    std::cout << "v1[1]: " << v1[1] << std::endl;
    std::cout << "v1[2]: " << v1[2] << std::endl;

    // Test unary operator-
    Vec3 negated_v1 = -v1;
    std::cout << "Negated v1: " << negated_v1[0] << ", " << negated_v1[1] << ", " << negated_v1[2] << std::endl;

    // Test operator+
    Vec3 sum = v1 + v2;
    std::cout << "v1 + v2: " << sum[0] << ", " << sum[1] << ", " << sum[2] << std::endl;

    // Test operator-
    Vec3 diff = v1 - v2;
    std::cout << "v1 - v2: " << diff[0] << ", " << diff[1] << ", " << diff[2] << std::endl;

    // Test operator* (vector * scalar)
    Vec3 scaled_v1 = v1 * 2.0f;
    std::cout << "v1 * 2.0: " << scaled_v1[0] << ", " << scaled_v1[1] << ", " << scaled_v1[2] << std::endl;

    // Test operator* (scalar * vector)
    Vec3 scaled_v2 = 3.0f * v2;
    std::cout << "3.0 * v2: " << scaled_v2[0] << ", " << scaled_v2[1] << ", " << scaled_v2[2] << std::endl;

    // Test dot
    float dot_product = dot(v1, v2);
    std::cout << "dot(v1, v2): " << dot_product << std::endl;

    // Test cross product
    Vec3 cross_product = cross(v1, v2);
    std::cout << "cross(v1, v2): " << cross_product[0] << ", " << cross_product[1] << ", " << cross_product[2] << std::endl;
    
    return 0;
}
