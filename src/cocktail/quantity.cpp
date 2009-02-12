// Quantity leaf class.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "cocktail/quantity.hpp"

namespace alky {
namespace cocktail {

Quantity::Quantity(const std::string& name, boost::shared_ptr<Measure> measure)
: name_(name), measure_(measure)
{
}

std::string Quantity::name() const
{
  return name_;
}

boost::shared_ptr<Measure> Quantity::measure() const
{
  return measure_;
}

void Quantity::set_measure(boost::shared_ptr<Measure> measure)
{
  measure_ = measure;
}

} // namespace cocktail
} // namespace alky
