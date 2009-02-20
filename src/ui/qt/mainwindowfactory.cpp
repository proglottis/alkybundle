// Main window factory.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "mainwindowfactory.hpp"

#include "ingredientmodel.hpp"

namespace alky {
namespace ui {
namespace qt {

using alky::bundle::IngredientBundle;
using alky::cocktail::Ingredient;

MainWindow *MainWindowFactory::create(QWidget *parent)
{
  boost::shared_ptr<IngredientBundle> ingBundle(IngredientBundle::create());
  boost::shared_ptr<Ingredient> ing(Ingredient::create(L"Vodka", L"", false));
  ingBundle->add(ing);
  IngredientModel* ingModel = new IngredientModel(ingBundle);
  boost::shared_ptr<IngredientDialogFactory> ingFac(
      new IngredientDialogFactory());
  return new MainWindow(ingBundle, ingFac, ingModel);
}

} // namespace qt
} // namespace ui
} // namespace alky
