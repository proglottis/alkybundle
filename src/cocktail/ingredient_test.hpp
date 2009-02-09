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
    Ingredient ingredient(name, "", false);
    TS_ASSERT_EQUALS(ingredient.name(), name);
  }

  void testGetDescription(void)
  {
    std::string description = "Foo";
    Ingredient ingredient("", description, false);
    TS_ASSERT_EQUALS(ingredient.description(), description);
  }

  void testGetHave(void)
  {
    bool have = true;
    Ingredient ingredient("", "", have);
    TS_ASSERT_EQUALS(ingredient.have(), have);
  }

  void testCopyConstruct(void)
  {
    Ingredient ing1("Foo", "Bar", true);
    Ingredient ing2 = ing1;
    TS_ASSERT_EQUALS(ing1.name(), ing2.name());
    TS_ASSERT_EQUALS(ing1.description(), ing2.description());
    TS_ASSERT_EQUALS(ing1.have(), ing2.have());
  }

  void testCopy(void)
  {
    Ingredient ing1("Foo1", "Bar1", true);
    Ingredient ing2("Foo2", "Bar2", false);
    ing2 = ing1;
    TS_ASSERT_EQUALS(ing1.name(), ing2.name());
    TS_ASSERT_EQUALS(ing1.description(), ing2.description());
    TS_ASSERT_EQUALS(ing1.have(), ing2.have());
  }

  void testSetDescription(void)
  {
    std::string description = "Foo";
    Ingredient ingredient("", "", false);
    ingredient.set_description(description);
    TS_ASSERT_EQUALS(ingredient.description(), description)
  }

  void testSetHave(void)
  {
    bool have = true;
    Ingredient ingredient("", "", false);
    ingredient.set_have(have);
    TS_ASSERT_EQUALS(ingredient.have(), have);
  }
};
