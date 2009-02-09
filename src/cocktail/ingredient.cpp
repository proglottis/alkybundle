// Ingredient leaf class.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "cocktail/ingredient.hpp"

namespace alky {
namespace cocktail {

Ingredient::Ingredient(const std::string& name, const std::string& description,
                       bool have)
: name_(name), description_(description), have_(have)
{
}

Ingredient::Ingredient(const Ingredient& other)
: name_(other.name_), description_(other.description_), have_(other.have_)
{
}

void Ingredient::operator=(const Ingredient& other)
{
  name_ = other.name_;
  description_ = other.description_;
  have_ = other.have_;
}

std::string Ingredient::name() const
{
  return name_;
}

std::string Ingredient::description() const
{
  return description_;
}

bool Ingredient::have() const
{
  return have_;
}

void Ingredient::set_description(const std::string& description)
{
  description_ = description;
}

void Ingredient::set_have(bool have)
{
  have_ = have;
}

} // namespace cocktail
} // namespace alky
