// Default main window implementation.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "defaultmainwindow.hpp"

namespace alky {
namespace ui {
namespace qt {

DefaultMainWindow::DefaultMainWindow(
      boost::shared_ptr<alky::bundle::IngredientBundle> ingredients,
      boost::shared_ptr<IngredientDialogFactory> ingredient_factory,
      QAbstractListModel* ingredient_model,
      QWidget* parent)
    : alky::ui::qt::MainWindow(),
      ingredients_(ingredients),
      ingredient_factory_(ingredient_factory)
{
  setParent(parent);
  setupUi(this);
  listIngredient->setModel(ingredient_model);
}

void DefaultMainWindow::showAbout()
{
  QMessageBox::about(this, tr("About AlkyBundle"), tr("About AlkyBundle"));
}

void DefaultMainWindow::showAddIngredient()
{
  IngredientDialog* ingredient_dialog = ingredient_factory_->create(this);
  ingredient_dialog->show();
  if(ingredient_dialog->exec() == QDialog::Accepted) {
    ingredients_->add(ingredient_dialog->ingredient());
  }
}

} // namespace qt
} // namespace ui
} // namespace alky
