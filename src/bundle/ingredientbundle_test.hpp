// Ingredient bundle unit-testing.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include <cxxtest/TestSuite.h>

#include <bundle/ingredientbundle.hpp>
#include <cocktail/ingredient.hpp>

using alky::bundle::IngredientBundle;
using alky::cocktail::Ingredient;

class IngredientBundleTest : public CxxTest::TestSuite {
public:
  void testInitialSize(void)
  {
    boost::shared_ptr<IngredientBundle> bundle(IngredientBundle::create());
    TS_ASSERT_EQUALS(bundle->size(), 0);
  }

  void testAddSize(void)
  {
    boost::shared_ptr<IngredientBundle> bundle(IngredientBundle::create());
    boost::shared_ptr<Ingredient> ingredient(
        Ingredient::create("", "", false));
    bundle->add(ingredient);
    TS_ASSERT_EQUALS(bundle->size(), 1);
  }

  void testAt(void)
  {
    boost::shared_ptr<IngredientBundle> bundle(IngredientBundle::create());
    boost::shared_ptr<Ingredient> ingredient(
        Ingredient::create("", "", false));
    bundle->add(ingredient);
    TS_ASSERT_EQUALS(bundle->at(0), ingredient);
  }

  void testConstAt(void)
  {
    boost::shared_ptr<IngredientBundle> bundle(IngredientBundle::create());
    boost::shared_ptr<Ingredient> ingredient(
        Ingredient::create("", "", false));
    bundle->add(ingredient);
    boost::shared_ptr<const IngredientBundle> cbundle(bundle);
    TS_ASSERT_EQUALS(cbundle->at(0), ingredient);
  }
};
