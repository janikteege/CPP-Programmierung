#pragma once

#include <string>
#include <iostream>
#include "point.hpp"

// Parser that can read Points from streams.
// The StreamT can be any iostream such as fstream or stringstream.
template <typename StreamT>
class Parser
{
public:

    /* Extracts the points from the given stream and puts them into the container.
     * todo: implement
     */
    void parse(StreamT& stream, PointContainer& container)
    {
        while (stream.good())
        {
            parsePoint(stream, container);
            stream.ignore(1, '\n'); // read full line
        }
    }

    /* Parses a single point and puts it into the container.
     * todo: implement
     * hint: You can use formated stream in operators (">>").
     *       Syntax errors do not need to be handled.
     */
    void parsePoint(StreamT& stream, PointContainer& container)
    {
        char c{};
        int num1 {};
        int num2 {};
        // read   P    (     1        2     )
        stream >> c >> c >> num1 >> num2 >> c;
        if (c == ')') {
            container.push_back(Point{num1, num2});
        }
    }
    
private:
};
