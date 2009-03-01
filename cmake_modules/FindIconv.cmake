# - Find Iconv
# Essentially just checks that Iconv is installed.
#
#  Iconv_FOUND - set to true if Iconv is found
#  Iconv_INCLUDE_DIRS - include directories
#  Iconv_LIBRARIES - libraries for linking

# Copyright (C) 2009  James Fargher

# Distributed under the GNU General Public License, Version 3.
# See accompanying file gpl-3.0.txt or copy at
#   <http://www.gnu.org/licenses/>

find_path(Iconv_INCLUDE_DIR NAMES iconv.h)
set(Iconv_LIBRARIES "")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Iconv DEFAULT_MSG
	Iconv_INCLUDE_DIR
)
set(Iconv_INCLUDE_DIRS ${Iconv_INCLUDE_DIR})
