// Wide string conversion interface.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_LOCALE_STRINGCONVERT_HPP
#define ALKY_LOCALE_STRINGCONVERT_HPP

#include <string>

#include <boost/shared_ptr.hpp>

namespace alky {
namespace locale {

class StringConvert {
public:
  static boost::shared_ptr<StringConvert> create();

  virtual ~StringConvert() {}

  virtual std::string wide_to_utf8(const std::wstring& in) = 0;
  virtual std::wstring utf8_to_wide(const std::string& in) = 0;
protected:
  StringConvert() {}
};

} // namespace locale
} // namespace alky

#endif // ALKY_LOCALE_STRINGCONVERT_HPP
