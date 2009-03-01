// Wide string conversion using Iconv.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "locale/iconvstringconvert.hpp"

#include <iconv.h>

namespace alky {
namespace locale {

std::string IconvStringConvert::wide_to_utf8(const std::wstring& in)
{
  std::string out = "";
  size_t inlen = (in.size() + 1) * sizeof(wchar_t);
  size_t outlen = (inlen + 1) * sizeof(wchar_t);
  const char* inchar = (const char*)in.c_str();
  char* outbuffer = new char[outlen];
  char* outchar = outbuffer;
  iconv_t cd = iconv_open("UTF-8", "wchar_t");
  int res = iconv(cd, (char**)&inchar, &inlen, &outchar, &outlen);
  iconv_close(cd);
  if(!res) {
    out = outbuffer;
  }
  delete [] outbuffer;
  return out;
}

std::wstring IconvStringConvert::utf8_to_wide(const std::string& in)
{
  std::wstring out = L"";
  size_t inlen = in.size() + 1;
  size_t outlen = inlen * sizeof(wchar_t);
  const char* inchar = (const char*)in.c_str();
  wchar_t* outbuffer = new wchar_t[outlen];
  char* outchar = (char *)outbuffer;
  iconv_t cd = iconv_open("wchar_t", "UTF-8");
  int res = iconv(cd, (char**)&inchar, &inlen, &outchar, &outlen);
  iconv_close(cd);
  if(!res) {
    out = outbuffer;
  }
  delete [] outbuffer;
  return out;
}

} // namespace locale
} // namespace alky
