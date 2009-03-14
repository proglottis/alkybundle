// Default home directory locator.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "resource/defaulthome.hpp"

#include <cstddef>

#include "locale/stringconvert.hpp"

namespace alky {
namespace resource {

using alky::locale::StringConvert;

std::wstring DefaultHome::config_dir() const
{
  boost::shared_ptr<StringConvert> convert(StringConvert::create());
  char* home;
  home = std::getenv("HOME");
  if(home == NULL) {
    return L"";
  }
  return convert->utf8_to_wide(home) + L"/.alkybundle";
}

} // namespace resource
} // namespace alky
