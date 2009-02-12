// Measure leaf class.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "cocktail/measure.hpp"

namespace alky {
namespace cocktail {

Measure::Measure(double value, const std::string& unit)
: value_(value), unit_(unit)
{
}

bool Measure::operator==(const Measure& other) const
{
  return value_ == other.value_ && unit_ == other.unit_;
}

bool Measure::operator!=(const Measure& other) const
{
  return value_ != other.value_ || unit_ != other.unit_;
}

double Measure::value() const
{
  return value_;
}

const std::string& Measure::unit() const
{
  return unit_;
}

} // namespace cocktail
} // namespace alky
