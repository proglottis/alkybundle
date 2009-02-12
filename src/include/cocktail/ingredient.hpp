// Ingredient leaf class.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_COCKTAIL_INGREDIENT_HPP
#define ALKY_COCKTAIL_INGREDIENT_HPP

#include <string>

namespace alky {
namespace cocktail {

class Ingredient {
public:
  Ingredient(const std::string& name, const std::string& description,
             bool have);
  virtual ~Ingredient() {}

  std::string name() const;
  std::string description() const;
  bool have() const;

  void set_description(const std::string& description);
  void set_have(bool have);
private:
  Ingredient();
  Ingredient(const Ingredient&);
  void operator=(const Ingredient&);

  std::string name_;
  std::string description_;
  bool have_;
};

} // namespace cocktail
} // namespace alky

#endif // ALKY_COCKTAIL_INGREDIENT_HPP
