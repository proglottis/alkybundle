// Ingredient bundle.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_BUNDLE_INGREDIENTBUNDLE_HPP
#define ALKY_BUNDLE_INGREDIENTBUNDLE_HPP

#include <boost/shared_ptr.hpp>

#include "cocktail/ingredient.hpp"
#include "bundle/ingredientbundlelistener.hpp"

namespace alky {
namespace bundle {

class IngredientBundle {
public:
  static boost::shared_ptr<IngredientBundle> create();

  virtual ~IngredientBundle() {}

  virtual size_t size() const = 0;
  virtual boost::shared_ptr<alky::cocktail::Ingredient> at(
      size_t index) = 0;
  virtual boost::shared_ptr<const alky::cocktail::Ingredient> at(
      size_t index) const = 0;

  virtual void add(
      boost::shared_ptr<alky::cocktail::Ingredient> ingredient) = 0;

  virtual void add_listener(
      boost::shared_ptr<IngredientBundleListener> listener) = 0;

protected:
  IngredientBundle() {}
};

} // namespace bundle
} // namespace alky

#endif // ALKY_BUNDLE_INGREDIENTBUNDLE_HPP
