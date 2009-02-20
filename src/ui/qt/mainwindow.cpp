// Main window.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "mainwindow.hpp"

#include <QMessageBox>

namespace alky {
namespace ui {
namespace qt {

MainWindow::MainWindow(
    boost::shared_ptr<alky::bundle::IngredientBundle> ingredients,
    boost::shared_ptr<IngredientDialogFactory> ingredient_factory,
    QAbstractListModel* ingredient_model,
    QWidget *parent)
    : QMainWindow(parent),
      ingredients_(ingredients),
      ingredient_factory_(ingredient_factory)
{
  setupUi(this);
  listIngredient->setModel(ingredient_model);
}

void MainWindow::showAbout()
{
  QMessageBox::about(this, tr("About AlkyBundle"), tr("About AlkyBundle"));
}

void MainWindow::showAddIngredient()
{
  IngredientDialog* ingredient_dialog = ingredient_factory_->create(this);
  ingredient_dialog->show();
  if(ingredient_dialog->exec() == QDialog::Accepted) {
    QMessageBox::information(this, tr("Accepted"),
        QString::fromStdWString(ingredient_dialog->ingredient()->name()));
  }
}

} // namespace qt
} // namespace ui
} // namespace alky
