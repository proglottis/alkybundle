// Abstract Ingredient.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_COCKTAIL_INGREDIENT_HPP
#define ALKY_COCKTAIL_INGREDIENT_HPP

#include <string>

#include <boost/shared_ptr.hpp>

namespace alky {
namespace cocktail {

class Ingredient {
public:
  static boost::shared_ptr<Ingredient> create(
      const std::wstring& name,
      const std::wstring& description,
      bool have);

  virtual ~Ingredient() {}

  virtual std::wstring name() const = 0;
  virtual std::wstring description() const = 0;
  virtual bool have() const = 0;

  virtual void set_description(const std::wstring& description) = 0;
  virtual void set_have(bool have) = 0;
protected:
  Ingredient() {}
};

} // namespace cocktail
} // namespace alky

#endif // ALKY_COCKTAIL_INGREDIENT_HPP
