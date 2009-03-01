// Wide string conversion interface.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "locale/stringconvert.hpp"

#include "locale/iconvstringconvert.hpp"

namespace alky {
namespace locale {

boost::shared_ptr<StringConvert> StringConvert::create()
{
  boost::shared_ptr<StringConvert> convert(new IconvStringConvert());
  return convert;
}

} // namespace locale
} // namespace alky
