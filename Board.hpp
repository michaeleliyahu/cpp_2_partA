#include <iostream>
#include "Direction.hpp"
using ariel::Direction;
using std::string;

namespace ariel
{
    class Board{
    public:
    void post(int colomn, int row, Direction x,const string &str);
    static string read(int colomn, int row, Direction x, int ch_num);
    void show();
    };
}