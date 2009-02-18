// Ingredient leaf class.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "cocktail/ingredient.hpp"

namespace alky {
namespace cocktail {

class MemoryIngredient : public Ingredient {
public:
  MemoryIngredient(const std::wstring& name, const std::wstring& description,
             bool have)
      : Ingredient(),
        name_(name),
        description_(description),
        have_(have)
  {
  }

  std::wstring name() const
  {
    return name_;
  }

  std::wstring description() const
  {
    return description_;
  }

  bool have() const
  {
    return have_;
  }

  void set_description(const std::wstring& description)
  {
    description_ = description;
  }

  void set_have(bool have)
  {
    have_ = have;
  }

private:
  MemoryIngredient();
  MemoryIngredient(const MemoryIngredient&);
  void operator=(const MemoryIngredient&);

  std::wstring name_;
  std::wstring description_;
  bool have_;
};

boost::shared_ptr<Ingredient> Ingredient::create(
    const std::wstring& name,
    const std::wstring& description,
    bool have)
{
  boost::shared_ptr<Ingredient> ingredient(
      new MemoryIngredient(name, description, have));
  return ingredient;
}

} // namespace cocktail
} // namespace alky
