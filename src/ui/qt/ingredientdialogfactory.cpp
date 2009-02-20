// Ingredient dialog factory.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "ingredientdialogfactory.hpp"

namespace alky {
namespace ui {
namespace qt {

IngredientDialog *IngredientDialogFactory::create(QWidget *parent)
{
  return new IngredientDialog(parent);
}

} // namespace qt
} // namespace ui
} // namespace alky
