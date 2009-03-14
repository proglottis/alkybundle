// Linux home directory locator.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_RESOURCE_LINUXHOME_HPP
#define ALKY_RESOURCE_LINUXHOME_HPP

#include "config.hpp"
#if defined(ALKY_PLATFORM_LINUX)

#include "resource/home.hpp"

namespace alky {
namespace resource {

class LinuxHome : public Home {
public:
  LinuxHome() : Home() {}
  virtual ~LinuxHome() {}
  virtual std::wstring config_dir() const;
};

} // namespace resource
} // namespace alky

#endif // ALKY_PLATFORM

#endif // ALKY_RESOURCE_LINUXHOME_HPP
