// SQLite3 ingredient bundle.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_BUNDLE_SQLITEINGREDIENTBUNDLE_HPP
#define ALKY_BUNDLE_SQLITEINGREDIENTBUNDLE_HPP

#include <string>
#include <vector>

#include "sqlite3.h"

#include "bundle/ingredientbundle.hpp"

namespace alky {
namespace bundle {

class SQLiteIngredientBundle : public IngredientBundle {
public:
  SQLiteIngredientBundle(sqlite3* db);
  virtual ~SQLiteIngredientBundle() {}

  virtual size_t size() const;
  virtual boost::shared_ptr<alky::cocktail::Ingredient> at(size_t index);
  virtual boost::shared_ptr<const alky::cocktail::Ingredient> at(
      size_t index) const;

  virtual void add(boost::shared_ptr<alky::cocktail::Ingredient> ingredient);

  virtual void add_listener(
      boost::shared_ptr<IngredientBundleListener> listener);
private:
  sqlite3* db_;
  std::vector<boost::shared_ptr<IngredientBundleListener> > listeners_;
};

} // namespace bundle
} // namespace alky

#endif // ALKY_BUNDLE_SQLITEINGREDIENTBUNDLE_HPP
