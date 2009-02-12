// Measure leaf class.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_COCKTAIL_MEASURE_HPP
#define ALKY_COCKTAIL_MEASURE_HPP

#include <string>

namespace alky {
namespace cocktail {

class Measure {
public:
  Measure(double value, const std::string& unit);
  virtual ~Measure() {}

  bool operator==(const Measure& other) const;
  bool operator!=(const Measure& other) const;

  double value() const;
  const std::string& unit() const;
private:
  Measure();
  Measure(const Measure&);
  void operator=(const Measure&);

  double value_;
  std::string unit_;
};

} // namespace cocktail
} // namespace alky

#endif // ALKY_COCKTAIL_MEASURE_HPP
