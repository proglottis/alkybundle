// Wide string conversion interface.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "locale/stringconvert.hpp"

#include "config.hpp"
#include "locale/iconvstringconvert.hpp"
#include "locale/winstringconvert.hpp"

namespace alky {
namespace locale {

boost::shared_ptr<StringConvert> StringConvert::create()
{
#if defined(ALKY_PLATFORM_LINUX)
  boost::shared_ptr<StringConvert> convert(new IconvStringConvert());
#elif defined(ALKY_PLATFORM_WINDOWS)
  boost::shared_ptr<StringConvert> convert(new WinStringConvert());
#else // ALKY_PLATFORM
#  error No StringConvert implementation on current platform
#endif // ALKY_PLATFORM
  return convert;
}

} // namespace locale
} // namespace alky
