// Ingredient Dialog

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_UI_QT_INGREDIENTDIALOG_HPP
#define ALKY_UI_QT_INGREDIENTDIALOG_HPP

#include "ui_ingredientdialog.h"

namespace alky {
namespace ui {
namespace qt {

class IngredientDialog : public QDialog, private Ui::IngredientDialog {
  Q_OBJECT
public:
  IngredientDialog(QWidget *parent = 0);
  virtual ~IngredientDialog() {}
public slots:
  void findImage();
  void noImage();
private:
  QString image_;
};

} // namespace qt
} // namespace ui
} // namespace alky

#endif // ALKY_UI_QT_INGREDIENTDIALOG_HPP
