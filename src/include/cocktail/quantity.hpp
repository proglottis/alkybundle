// Quantity leaf class.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_COCKTAIL_QUANTITY_HPP
#define ALKY_COCKTAIL_QUANTITY_HPP

#include <string>

#include <boost/shared_ptr.hpp>

#include "cocktail/measure.hpp"

namespace alky {
namespace cocktail {

class Quantity {
public:
  Quantity(const std::wstring& name, boost::shared_ptr<Measure> measure);
  virtual ~Quantity() {}

  std::wstring name() const;
  boost::shared_ptr<Measure> measure() const;

  void set_measure(boost::shared_ptr<Measure> measure);
private:
  Quantity();
  Quantity(const Quantity&);
  void operator=(const Quantity&);

  std::wstring name_;
  boost::shared_ptr<Measure> measure_;
};

} // namespace cocktail
} // namespace alky

#endif // ALKY_COCKTAIL_QUANTITY_HPP
