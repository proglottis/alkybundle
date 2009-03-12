// Wide string conversion using Windows API.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_LOCALE_WINSTRINGCONVERT_HPP
#define ALKY_LOCALE_WINSTRINGCONVERT_HPP

#include "config.hpp"
#if defined(ALKY_PLATFORM_WINDOWS)

#include "locale/stringconvert.hpp"

namespace alky {
namespace locale {

class WinStringConvert : public StringConvert {
public:
  WinStringConvert() : StringConvert() {}
  virtual ~WinStringConvert() {}

  virtual std::string wide_to_utf8(const std::wstring& in);
  virtual std::wstring utf8_to_wide(const std::string& in);
};

} // namespace locale
} // namespace alky

#endif // ALKY_PLATFORM

#endif // ALKY_LOCALE_WINSTRINGCONVERT_HPP
