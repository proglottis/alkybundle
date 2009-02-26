# Build rules for AlkyBundle.

# Copyright (C) 2009  James Fargher

# Distributed under the GNU General Public License, Version 3.
# See accompanying file gpl-3.0.txt or copy at
#   <http://www.gnu.org/licenses/>

add_library(bundle
  ingredientbundle.cpp
)

if(CXXTEST_FOUND)
	cxxtest_add_test(test_bundle_ingredientbundle
		ingredientbundle_test.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/ingredientbundle_test.hpp
	)
	target_link_libraries(test_bundle_ingredientbundle bundle cocktail)
endif(CXXTEST_FOUND)

find_package(Boost COMPONENTS shared_ptr)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

find_package(SQLite3 REQUIRED)
include_directories(${SQLite3_INCLUDE_DIRS})
target_link_libraries(bundle ${SQLite3_LIBRARIES})
