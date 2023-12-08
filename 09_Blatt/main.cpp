#include <fstream>
#include "parser.hpp"
#include "renderer.hpp"
#include <filesystem>

/* todo: * implement missing definitions
 *       * open the file data.txt
 *       * read all points using the Parser
 *       * draw the points with the Renderer
 */

int main()
{   
    Parser<std::ifstream> parser{};
    Renderer renderer {30, 120};
    PointContainer points{};
    std::ifstream inputFile {"./data.txt"};
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }
    parser.parse(inputFile, points);
    inputFile.close();
    renderer.draw(points);
}