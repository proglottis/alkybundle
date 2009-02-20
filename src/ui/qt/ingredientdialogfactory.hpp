// Ingredient dialog factory.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_UI_QT_INGREDIENTDIALOGFACTORY_HPP
#define ALKY_UI_QT_INGREDIENTDIALOGFACTORY_HPP

#include "ingredientdialog.hpp"

namespace alky {
namespace ui {
namespace qt {

class IngredientDialogFactory {
public:
  IngredientDialogFactory() {}
  virtual ~IngredientDialogFactory() {}

  virtual IngredientDialog *create(QWidget *parent);
};

} // namespace qt
} // namespace ui
} // namespace alky

#endif // ALKY_UI_QT_INGREDIENTDIALOGFACTORY_HPP
