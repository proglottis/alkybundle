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

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
  setupUi(this);
  ingredient_dialog = new IngredientDialog(this);
}

void MainWindow::showAbout()
{
  QMessageBox::about(this, tr("About AlkyBundle"), tr("About AlkyBundle"));
}

void MainWindow::showAddIngredient()
{
  ingredient_dialog->show();
  if(ingredient_dialog->exec() == QDialog::Accepted) {
    QMessageBox::information(this, tr("Accepted"), tr("Accepted"));
  }
}

} // namespace qt
} // namespace ui
} // namespace alky
