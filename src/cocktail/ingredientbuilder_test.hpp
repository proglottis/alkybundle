// Ingredient builder unit-testing.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include <cxxtest/TestSuite.h>

#include "cocktail/ingredientbuilder.hpp"

using alky::cocktail::BuilderError;
using alky::cocktail::IngredientBuilder;
using alky::cocktail::Ingredient;

class IngredientBuilderTest : public CxxTest::TestSuite {
public:
  void testBuildName(void)
  {
    std::wstring name = L"Foo";
    IngredientBuilder builder;
    builder.set_name(name);
    boost::shared_ptr<Ingredient> ing = builder.build();
    TS_ASSERT_EQUALS(ing->name(), name)
  }

  void testBuildDescription(void)
  {
    std::wstring description = L"Foo";
    IngredientBuilder builder;
    builder.set_name(L"Bar");
    builder.set_description(description);
    boost::shared_ptr<Ingredient> ing = builder.build();
    TS_ASSERT_EQUALS(ing->description(), description)
  }

  void testBuildHave(void)
  {
    bool have = true;
    IngredientBuilder builder;
    builder.set_name(L"Bar");
    builder.set_have(have);
    boost::shared_ptr<Ingredient> ing = builder.build();
    TS_ASSERT_EQUALS(ing->have(), have)
  }

  void testBuildExceptionOnMissingName(void)
  {
    IngredientBuilder builder;
    TS_ASSERT_THROWS(builder.build(), BuilderError);
  }

  void testNameMissing(void)
  {
    IngredientBuilder builder;
    TS_ASSERT_EQUALS(builder.is_missing_name(), true);
  }

  void testNameNotMissing(void)
  {
    IngredientBuilder builder;
    builder.set_name(L"Foo");
    TS_ASSERT_EQUALS(builder.is_missing_name(), false);
  }
};
