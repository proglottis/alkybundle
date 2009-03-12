# Build rules for AlkyBundle.

# Copyright (C) 2009  James Fargher

# Distributed under the GNU General Public License, Version 3.
# See accompanying file gpl-3.0.txt or copy at
#   <http://www.gnu.org/licenses/>

add_library(locale
  stringconvert.cpp
  iconvstringconvert.cpp
)

if(CXXTEST_FOUND)
	cxxtest_add_test(test_locale_stringconvert
		stringconvert_test.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/stringconvert_test.hpp
	)
	target_link_libraries(test_locale_stringconvert locale)
endif(CXXTEST_FOUND)

find_package(Boost COMPONENTS shared_ptr)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

if(UNIX)
	find_package(Iconv REQUIRED)
	include_directories(${Iconv_INCLUDE_DIRS})
	target_link_libraries(locale ${Iconv_LIBRARIES})
endif(UNIX)
