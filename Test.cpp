#include "doctest.h"
#include "Board.hpp"
#include <iostream>
#include <string.h>
#include <string>
#include "Direction.hpp"
using ariel::Direction;
using namespace ariel;
using namespace std;

TEST_CASE("simple test:Horizontal")
{
    ariel::Board board;
    board.post(1, 2, Direction::Horizontal, "first");
    CHECK(board.read(1, 2, Direction::Vertical, 3) == "f__");

    board.post(2, 2, Direction::Horizontal, "second");
    CHECK(board.read(1, 2, Direction::Vertical, 3) == "fs_");

    board.post(3, 2, Direction::Horizontal, "three");
    CHECK(board.read(1, 2, Direction::Vertical, 3) == "fst");

    CHECK(board.read(1, 2, Direction::Horizontal, 5) == "first");
    CHECK(board.read(2, 2, Direction::Horizontal, 6) == "second");
    CHECK(board.read(3, 2, Direction::Horizontal, 5) == "three");
}
TEST_CASE("simple test:Vertical")
{
    ariel::Board board;
    board.post(2, 1, Direction::Vertical, "first");
    CHECK(board.read(2, 1, Direction::Horizontal, 3) == "f__");

    board.post(2, 2, Direction::Vertical, "second");
    CHECK(board.read(2, 1, Direction::Horizontal, 3) == "fs_");

    board.post(2, 3, Direction::Vertical, "three");
    CHECK(board.read(2, 1, Direction::Horizontal, 3) == "fst");

    CHECK(board.read(1, 2, Direction::Vertical, 5) == "first");
    CHECK(board.read(2, 2, Direction::Vertical, 6) == "second");
    CHECK(board.read(3, 2, Direction::Vertical, 5) == "three");
}
TEST_CASE("goot test")
{
    ariel::Board board;
    board.post(2, 2, Direction::Horizontal, "first");
    board.post(3, 2, Direction::Horizontal, "second");
    board.post(4, 2, Direction::Horizontal, "three");
    board.post(1, 3, Direction::Vertical, "allway");

    CHECK(board.read(1, 3, Direction::Vertical, 5) == "allwa");
    CHECK(board.read(1, 2, Direction::Horizontal, 5) == "flrst");
    CHECK(board.read(2, 2, Direction::Horizontal, 6) == "slcond");
    CHECK(board.read(3, 2, Direction::Horizontal, 5) == "twree");

    board.post(1, 4, Direction::Vertical, "wayall");

    CHECK(board.read(1, 2, Direction::Vertical, 5) == "wayall");
    CHECK(board.read(1, 2, Direction::Horizontal, 5) == "farst");
    CHECK(board.read(2, 2, Direction::Horizontal, 6) == "sycond");
    CHECK(board.read(3, 2, Direction::Horizontal, 5) == "tlree");
}
TEST_CASE("goot test")
{
    ariel::Board board;
    board.post(1, 2, Direction::Horizontal, "str");
    CHECK(board.read(1, 2, Direction::Horizontal, 3) == "s__");
}