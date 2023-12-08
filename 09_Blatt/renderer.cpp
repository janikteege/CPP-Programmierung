#include <iostream>
#include <algorithm>
#include "renderer.hpp"
#include "point.hpp"

Renderer::Renderer(int rows, int colums)
    : m_rows(rows), m_colums(colums)
{
}



void Renderer::draw(PointContainer& points)
{
    std::sort(points.begin(), points.end());
    auto last = std::unique(points.begin(), points.end());
    points.erase(last, points.end());

    auto currentPoint = points.begin();
    for (int y = 0; y < m_rows; y++)
    {
        for (int x = 0; x < m_colums; x++)
        {
            if (currentPoint!=points.end() && currentPoint->x == x && currentPoint->y == y) {
                std::cout << '@';
                currentPoint++;
            }
            else {
                std::cout << ' ';
            }
        }
        std::cout << '\n';
    }
}