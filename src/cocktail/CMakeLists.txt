# Build rules for AlkyBundle.

# Copyright (C) 2009  James Fargher

# Distributed under the GNU General Public License, Version 3.
# See accompanying file gpl-3.0.txt or copy at
#   <http://www.gnu.org/licenses/>

add_library(cocktail
	ingredient.cpp
)

if(CXXTEST_FOUND)
	cxxtest_add_test(test_cocktail_ingredient
		ingredient_test.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/ingredient_test.hpp
	)
	target_link_libraries(test_cocktail_ingredient cocktail)
endif(CXXTEST_FOUND)
