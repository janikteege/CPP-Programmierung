#include <sstream>
#include <iostream>
#include "parser.hpp"
#include "renderer.hpp"
#include "test.hh"

using namespace std;

int main()
{
    stringstream output;

    stringstream ss;
    ss << "P( 0 4 )\nP( 7 14 )\nP( 1 13 )\nP( 7 14 )\nP( 2 12 )\nP( 29 3 )\nP( 0 4 )";
    Parser<stringstream> parser;
    PointContainer points;
    Renderer renderer(120, 30);

    parser.parse(ss, points);
    EXPECT_EQ(points.size(), 7, "parse point list");
    EXPECT(points[2].x == 1 && points[2].y == 13, "parse correct data");

    std::cout.rdbuf(output.rdbuf());
    renderer.draw(points);
    std::cout.rdbuf(cin.rdbuf());
    EXPECT(points.front().x == 29 && points.front().y == 3, "smallest element first");
    EXPECT(points.back().x == 7 && points.back().y == 14, "largest element last");

    EXPECT_EQ(points.size(), 5, "size after removing duplicates");
}