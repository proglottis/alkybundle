// Windows home directory locator.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "config.hpp"
#if defined(ALKY_PLATFORM_WINDOWS)

#include "resource/winhome.hpp"

#include <cstddef>

#include "locale/stringconvert.hpp"

namespace alky {
namespace resource {

using alky::locale::StringConvert;

std::wstring WinHome::config_dir() const
{
  boost::shared_ptr<StringConvert> convert(StringConvert::create());
  char* envdata;
  envdata = std::getenv("APPDATA");
  if(envdata == NULL) {
    envdata = std::getenv("HOME");
    if(envdata == NULL) {
      return L"";
    }
  }
  return convert->utf8_to_wide(envdata) + L"\\alkybundle";
}

} // namespace resource
} // namespace alky

#endif // ALKY_PLATFORM
