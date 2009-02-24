// Default main window implementation.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_UI_QT_DEFAULTMAINWINDOW_HPP
#define ALKY_UI_QT_DEFAULTMAINWINDOW_HPP

#include <QMessageBox>

#include "ui_mainwindow.h"
#include "mainwindow.hpp"
#include "ingredientdialogfactory.hpp"
#include "bundle/ingredientbundle.hpp"

namespace alky {
namespace ui {
namespace qt {

class DefaultMainWindow : public MainWindow, private Ui::MainWindow {
  Q_OBJECT
public:
  DefaultMainWindow(
      boost::shared_ptr<alky::bundle::IngredientBundle> ingredients,
      boost::shared_ptr<IngredientDialogFactory> ingredient_factory,
      QAbstractListModel* ingredient_model,
      QWidget* parent = 0);
  virtual ~DefaultMainWindow() {}
public slots:
  virtual void showAbout();
  virtual void showAddIngredient();
private:
  boost::shared_ptr<alky::bundle::IngredientBundle> ingredients_;
  boost::shared_ptr<IngredientDialogFactory> ingredient_factory_;
};

} // namespace qt
} // namespace ui
} // namespace alky

#endif // ALKY_UI_QT_DEFAULTMAINWINDOW_HPP
