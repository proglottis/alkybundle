// Compile time configurations

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_CONFIG_HPP
#define ALKY_CONFIG_HPP

// Platform: Linux
#if defined(linux) || defined(__linux) || defined(__linux__) || defined(__GNU__) || defined(__GLIBC__)
#  define ALKY_PLATFORM_LINUX 1

// Platform: Windows
#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
#  define ALKY_PLATFORM_WINDOWS 1

// Platform: OSX
#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)
#  define ALKY_PLATFORM_OSX 1

#endif // Platform

#endif // ALKY_CONFIG_HPP
