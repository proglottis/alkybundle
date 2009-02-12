// Quantity leaf class unit-testing.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include <cxxtest/TestSuite.h>

#include "cocktail/quantity.hpp"

using alky::cocktail::Quantity;
using alky::cocktail::Measure;

class QuantityTest : public CxxTest::TestSuite {
public:
  void testGetName(void)
  {
    std::string name = "Foo";
    boost::shared_ptr<Measure> measure(new Measure(0.0, ""));
    Quantity quant(name, measure);
    TS_ASSERT_EQUALS(quant.name(), name);
  }

  void testGetQuantity(void)
  {
    boost::shared_ptr<Measure> measure(new Measure(123.0, "shot"));
    Quantity quant("", measure);
    TS_ASSERT_EQUALS(quant.measure(), measure);
  }

  void testSetMeasure(void)
  {
    boost::shared_ptr<Measure> m1(new Measure(123.0, "shot"));
    boost::shared_ptr<Measure> m2(new Measure(2.0, "mL"));
    Quantity quant("", m1);
    quant.set_measure(m2);
    TS_ASSERT_EQUALS(quant.measure(), m2);
  }

};
