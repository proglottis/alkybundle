// Home directory locator.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "resource/home.hpp"

#include "resource/defaulthome.hpp"

namespace alky {
namespace resource {

boost::shared_ptr<Home> Home::create()
{
  boost::shared_ptr<Home> home(new DefaultHome());
  return home;
}

} // namespace resource
} // namespace alky
