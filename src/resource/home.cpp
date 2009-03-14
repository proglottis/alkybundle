// Home directory locator.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "resource/home.hpp"

#include "config.hpp"
#include "resource/linuxhome.hpp"
#include "resource/winhome.hpp"

namespace alky {
namespace resource {

boost::shared_ptr<Home> Home::create()
{
#if defined(ALKY_PLATFORM_LINUX)
  boost::shared_ptr<Home> home(new LinuxHome());
#elif defined(ALKY_PLATFORM_WINDOWS)
  boost::shared_ptr<Home> home(new WinHome());
#else // ALKY_PLATFORM
#  error No Home implemented on current platform
#endif // ALKY_PLATFORM
  return home;
}

} // namespace resource
} // namespace alky
