// Ingredient builder.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "cocktail/ingredientbuilder.hpp"

namespace alky {
namespace cocktail {

IngredientBuilder::IngredientBuilder() throw()
    : name_(),
      description_(),
      have_(false)
{
}

void IngredientBuilder::set_name(const std::string& name) throw()
{
  name_ = name;
}

void IngredientBuilder::set_description(const std::string& description)
    throw()
{
  description_ = description;
}

void IngredientBuilder::set_have(bool have) throw()
{
  have_ = have;
}

bool IngredientBuilder::is_missing_name() const throw()
{
  return name_.empty();
}

boost::shared_ptr<Ingredient> IngredientBuilder::build()
    throw(BuilderError)
{
  if(is_missing_name()) {
    throw(BuilderError("Builder missing name"));
  }
  boost::shared_ptr<Ingredient> ing(new Ingredient(name_, description_,
                                                   have_));
  return ing;
}

} // namespace cocktail
} // namespace cocktail
