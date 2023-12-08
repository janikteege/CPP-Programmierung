g++ -std=c++17 -fPIC -g -Wall -pedantic -c terminal.cc test.cc test_main.cc main.cpp renderer.cpp
g++ -g -o test_main terminal.o test.o renderer.o test_main.o
g++ -g -o main main.o renderer.o