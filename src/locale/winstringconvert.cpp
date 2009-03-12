// Wide string conversion using Windows API.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "config.hpp"
#if defined(ALKY_PLATFORM_WINDOWS)

#include <windows.h>

#include "locale/winstringconvert.hpp"

namespace alky {
namespace locale {

std::string WinStringConvert::wide_to_utf8(const std::wstring& in)
{
  std::string out = "";
  size_t inlen = (in.size() + 1) * sizeof(wchar_t);
  size_t outlen = (inlen + 1) * sizeof(wchar_t);
  const wchar_t* inchar = in.c_str();
  char* outbuffer = new char[outlen];
  int res = WideCharToMultiByte(CP_UTF8, 0, inchar, inlen, outbuffer, outlen,
                                (const CHAR *)0, (BOOL*)0);
  out = outbuffer;
  delete [] outbuffer;
  return out;
}

std::wstring WinStringConvert::utf8_to_wide(const std::string& in)
{
  std::wstring out;
  size_t inlen = in.size() + 1;
  size_t outlen = inlen * sizeof(wchar_t);
  const char* inchar = in.c_str();
  wchar_t* outbuffer = new wchar_t[outlen];
  int res = MultiByteToWideChar(CP_UTF8, 0, inchar, inlen, outbuffer, outlen);
  out = outbuffer;
  delete [] outbuffer;
  return out;
}

} // namespace locale
} // namespace alky

#endif // ALKY_PLATFORM
