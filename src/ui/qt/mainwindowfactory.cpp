// Main window factory.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "mainwindowfactory.hpp"

#include "ingredientmodel.hpp"
#include "defaultmainwindow.hpp"

namespace alky {
namespace ui {
namespace qt {

using alky::bundle::IngredientBundle;
using alky::cocktail::Ingredient;

MainWindow *MainWindowFactory::create(QWidget *parent)
{
  boost::shared_ptr<IngredientBundle> ingBundle(IngredientBundle::create());
  boost::shared_ptr<IngredientModel> ingModel(new IngredientModel(ingBundle));
  ingBundle->add_listener(ingModel);
  boost::shared_ptr<IngredientDialogFactory> ingFac(
      new IngredientDialogFactory());
  return new DefaultMainWindow(ingBundle, ingFac, ingModel.get());
}

} // namespace qt
} // namespace ui
} // namespace alky
