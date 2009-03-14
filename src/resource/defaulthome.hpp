// Default home directory locator.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_RESOURCE_DEFAULTHOME_HPP
#define ALKY_RESOURCE_DEFAULTHOME_HPP

#include "resource/home.hpp"

namespace alky {
namespace resource {

class DefaultHome : public Home {
public:
  DefaultHome() : Home() {}
  virtual ~DefaultHome() {}
  virtual std::wstring config_dir() const;
};

} // namespace resource
} // namespace alky

#endif // ALKY_RESOURCE_DEFAULTHOME_HPP
