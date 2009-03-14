// Home directory locator.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_RESOURCE_HOME_HPP
#define ALKY_RESOURCE_HOME_HPP

#include <string>

#include <boost/shared_ptr.hpp>

namespace alky {
namespace resource {

class Home {
public:
  static boost::shared_ptr<Home> create();

  virtual std::wstring config_dir() const = 0;
protected:
  Home() {}
};

} // namespace resource
} // namespace alky

#endif // ALKY_RESOURCE_HOME_HPP
