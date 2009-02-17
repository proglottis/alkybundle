// Ingredient leaf class unit-testing.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include <cxxtest/TestSuite.h>

#include "cocktail/ingredient.hpp"

using alky::cocktail::Ingredient;

class IngredientTest : public CxxTest::TestSuite {
public:
  void testGetName(void)
  {
    std::string name = "Foo";
    boost::shared_ptr<Ingredient> ingredient(Ingredient::create(name, "",
                                                                false));
    TS_ASSERT_EQUALS(ingredient->name(), name);
  }

  void testGetDescription(void)
  {
    std::string description = "Foo";
    boost::shared_ptr<Ingredient> ingredient(Ingredient::create("",
                                                                description,
                                                                false));
    TS_ASSERT_EQUALS(ingredient->description(), description);
  }

  void testGetHave(void)
  {
    bool have = true;
    boost::shared_ptr<Ingredient> ingredient(Ingredient::create("", "", have));
    TS_ASSERT_EQUALS(ingredient->have(), have);
  }

  void testSetDescription(void)
  {
    std::string description = "Foo";
    boost::shared_ptr<Ingredient> ingredient(Ingredient::create("", "",
                                                                false));
    ingredient->set_description(description);
    TS_ASSERT_EQUALS(ingredient->description(), description)
  }

  void testSetHave(void)
  {
    bool have = true;
    boost::shared_ptr<Ingredient> ingredient(Ingredient::create("", "",
                                                                false));
    ingredient->set_have(have);
    TS_ASSERT_EQUALS(ingredient->have(), have);
  }
};
