// Measure leaf class unit-testing.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include <cxxtest/TestSuite.h>

#include "cocktail/measure.hpp"

using alky::cocktail::Measure;

class MeasureTest : public CxxTest::TestSuite {
public:
  void testGetValue(void)
  {
    double value = 4.343;
    Measure measure(value, "");
    TS_ASSERT_EQUALS(measure.value(), value);
  }

  void testGetUnit(void)
  {
    std::string unit = "shot";
    Measure measure(0.0, unit);
    TS_ASSERT_EQUALS(measure.unit(), unit);
  }

  void testEquals(void)
  {
    Measure m1(1.0, "mL");
    Measure m2(1.0, "mL");
    TS_ASSERT(m1 == m2);
  }

  void testNotEqualsDiffValue(void)
  {
    std::string unit = "mL";
    Measure m1(1.0, unit);
    Measure m2(1.1, unit);
    TS_ASSERT(m1 != m2);
  }

  void testNotEqualsDiffUnit(void)
  {
    double value = 1.0;
    Measure m1(value, "mL");
    Measure m2(value, "shot");
    TS_ASSERT(m1 != m2);
  }
};
