// Ingredient bundle listener.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_BUNDLE_INGREDIENTBUNDLELISTENER_HPP
#define ALKY_BUNDLE_INGREDIENTBUNDLELISTENER_HPP

#include "cocktail/ingredient.hpp"

namespace alky {
namespace bundle {

class IngredientBundleListener {
public:
  virtual ~IngredientBundleListener() {}

  virtual void ingredient_added(size_t index,
      boost::shared_ptr<alky::cocktail::Ingredient> ingredient) = 0;
protected:
  IngredientBundleListener() {}
};

} // namespace bundle
} // namespace alky

#endif // ALKY_BUNDLE_INGREDIENTBUNDLELISTENER_HPP
