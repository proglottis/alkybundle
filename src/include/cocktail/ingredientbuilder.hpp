// Ingredient builder.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_COCKTAIL_INGREDIENTBUILDER_HPP
#define ALKY_COCKTAIL_INGREDIENTBUILDER_HPP

#include <string>

#include <boost/shared_ptr.hpp>

#include "cocktail/ingredient.hpp"
#include "cocktail/buildererror.hpp"

namespace alky {
namespace cocktail {

class IngredientBuilder {
public:
  IngredientBuilder() throw();
  virtual ~IngredientBuilder() throw() {}

  void set_name(const std::wstring& name) throw();
  void set_description(const std::wstring& description) throw();
  void set_have(bool have) throw();

  bool is_missing_name() const throw();

  boost::shared_ptr<Ingredient> build() throw(BuilderError);
private:
  IngredientBuilder(const IngredientBuilder&);
  void operator=(const IngredientBuilder&);

  std::wstring name_;
  std::wstring description_;
  bool have_;
};

} // namespace cocktail
} // namespace alky

#endif // ALKY_COCKTAIL_INGREDIENTBUILDER_HPP
