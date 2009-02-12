# Build rules for AlkyBundle.

# Copyright (C) 2009  James Fargher

# Distributed under the GNU General Public License, Version 3.
# See accompanying file gpl-3.0.txt or copy at
#   <http://www.gnu.org/licenses/>

add_library(cocktail
	ingredient.cpp
        measure.cpp
        quantity.cpp
        instructionlist.cpp
	recipe.cpp
)

if(CXXTEST_FOUND)
	cxxtest_add_test(test_cocktail_ingredient
		ingredient_test.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/ingredient_test.hpp
	)
	target_link_libraries(test_cocktail_ingredient cocktail)

	cxxtest_add_test(test_cocktail_measure
		measure_test.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/measure_test.hpp
	)
	target_link_libraries(test_cocktail_measure cocktail)

	cxxtest_add_test(test_cocktail_quantity
		quantity_test.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/quantity_test.hpp
	)
	target_link_libraries(test_cocktail_quantity cocktail)

	cxxtest_add_test(test_cocktail_instructionlist
		instructionlist_test.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/instructionlist_test.hpp
	)
	target_link_libraries(test_cocktail_instructionlist cocktail)

	cxxtest_add_test(test_cocktail_recipe
		recipe_test.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/recipe_test.hpp
	)
	target_link_libraries(test_cocktail_recipe cocktail)
endif(CXXTEST_FOUND)

find_package(Boost COMPONENTS shared_ptr)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
