// Ingredient bundle.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "bundle/ingredientbundle.hpp"

#include <vector>

namespace alky {
namespace bundle {

class MemIngredientBundle : public IngredientBundle {
public:
  MemIngredientBundle()
      : IngredientBundle(),
        list_(),
        listeners_()
  {
  }

  virtual ~MemIngredientBundle() {}

  virtual size_t size() const
  {
    return list_.size();
  }

  virtual boost::shared_ptr<alky::cocktail::Ingredient> at(size_t index)
  {
    return list_[index];
  }

  virtual boost::shared_ptr<const alky::cocktail::Ingredient> at(
      size_t index) const
  {
    return list_[index];
  }

  virtual void add(boost::shared_ptr<alky::cocktail::Ingredient> ingredient)
  {
    std::vector<boost::shared_ptr<IngredientBundleListener> >::iterator it;
    list_.push_back(ingredient);
    size_t n = list_.size() - 1;
    for(it=listeners_.begin(); it != listeners_.end(); it++) {
      (*it)->ingredient_added(n, ingredient);
    }
  }

  virtual void add_listener(
      boost::shared_ptr<IngredientBundleListener> listener)
  {
    listeners_.push_back(listener);
  }

private:
  std::vector<boost::shared_ptr<alky::cocktail::Ingredient> > list_;
  std::vector<boost::shared_ptr<IngredientBundleListener> > listeners_;
};

boost::shared_ptr<IngredientBundle> IngredientBundle::create()
{
  boost::shared_ptr<IngredientBundle> bundle(new MemIngredientBundle());
  return bundle;
}

} // namespace bundle
} // namespace alky
