#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>
#include <iostream>
#include <functional>
#include "point.hpp"

namespace zaparin
{
  struct Polygon
  {
    std::vector< Point > points;
  };

  std::ostream& operator<<(std::ostream& out, const Polygon& plg);
  std::istream& operator>>(std::istream& in, Polygon& plg);

  //bool operator==(const Polygon& plg1, const Polygon& plg2);
}

#endif

