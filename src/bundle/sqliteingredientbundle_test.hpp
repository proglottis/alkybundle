// SQLite3 ingredient bundle unit-testing.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include <cxxtest/TestSuite.h>

#include "bundle/sqliteingredientbundle.hpp"
#include "ingredientbundle_test.hpp"

using alky::bundle::IngredientBundle;
using alky::bundle::SQLiteIngredientBundle;
using alky::cocktail::Ingredient;

class SQLiteIngredientBundleTest : public CxxTest::TestSuite {
public:
  void setUp()
  {
    if(sqlite3_open(":memory:", &db) != SQLITE_OK) {
      TS_FAIL("Failed to create SQLite database");
    }
  }

  void tearDown()
  {
    sqlite3_close(db);
  }

  void testInitialSize(void)
  {
    boost::shared_ptr<IngredientBundle> bundle(new SQLiteIngredientBundle(db));
    TS_ASSERT_EQUALS(bundle->size(), 0);
  }

  void testAddSize(void)
  {
    boost::shared_ptr<IngredientBundle> bundle(new SQLiteIngredientBundle(db));
    boost::shared_ptr<Ingredient> ingredient(
        Ingredient::create(L"Test", L"", false));
    bundle->add(ingredient);
    TS_ASSERT_EQUALS(bundle->size(), 1);
  }

  void testAt(void)
  {
    boost::shared_ptr<IngredientBundle> bundle(new SQLiteIngredientBundle(db));
    boost::shared_ptr<Ingredient> ingredient(
        Ingredient::create(L"Test", L"", false));
    bundle->add(ingredient);
    TS_ASSERT(*bundle->at(0) == *ingredient);
  }

  void testConstAt(void)
  {
    boost::shared_ptr<IngredientBundle> bundle(new SQLiteIngredientBundle(db));
    boost::shared_ptr<Ingredient> ingredient(
        Ingredient::create(L"Test", L"", false));
    bundle->add(ingredient);
    boost::shared_ptr<const IngredientBundle> cbundle(bundle);
    TS_ASSERT(*cbundle->at(0) == *ingredient);
  }

  void testAddWithListener(void)
  {
    boost::shared_ptr<IngredientBundle> bundle(new SQLiteIngredientBundle(db));
    boost::shared_ptr<Ingredient> ingredient(
        Ingredient::create(L"Test", L"", false));
    boost::shared_ptr<MockIngredientListener> listener(
        new MockIngredientListener());
    bundle->add_listener(listener);
    bundle->add(ingredient);
    TS_ASSERT_EQUALS(listener->added_count(), 1);
  }
private:
  sqlite3* db;
};
