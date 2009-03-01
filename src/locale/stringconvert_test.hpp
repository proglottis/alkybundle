// Wide string conversion unit-testing.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include <cxxtest/TestSuite.h>

#include "locale/stringconvert.hpp"

using alky::locale::StringConvert;

class StringConvertTest : public CxxTest::TestSuite {
public:
  void testWideToUTF8SanityData(void)
  {
    boost::shared_ptr<StringConvert> convert(StringConvert::create());
    std::wstring original(L"Test");
    std::string converted = convert->wide_to_utf8(original);
    TS_ASSERT_SAME_DATA(converted.c_str(), "Test", converted.size());
  }

  void testWideToUTF8SanitySize(void)
  {
    boost::shared_ptr<StringConvert> convert(StringConvert::create());
    std::wstring original(L"Test");
    std::string converted = convert->wide_to_utf8(original);
    TS_ASSERT_EQUALS(converted.size(), 4);
  }

  void testUTF8ToWideSanityData(void)
  {
    boost::shared_ptr<StringConvert> convert(StringConvert::create());
    std::string original("Test");
    std::wstring converted = convert->utf8_to_wide(original);
    TS_ASSERT_SAME_DATA(converted.c_str(), L"Test", converted.size());
  }

  void testUTF8ToWideSanitySize(void)
  {
    boost::shared_ptr<StringConvert> convert(StringConvert::create());
    std::string original("Test");
    std::wstring converted = convert->utf8_to_wide(original);
    TS_ASSERT_EQUALS(converted.size(), 4);
  }
};
