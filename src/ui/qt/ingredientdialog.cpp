// Ingredient Dialog

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "ingredientdialog.hpp"

#include <QFileDialog>

namespace alky {
namespace ui {
namespace qt {

IngredientDialog::IngredientDialog(QWidget* parent)
    : QDialog(parent),
      image_(QString::Null())
{
  setupUi(this);
}

void IngredientDialog::findImage()
{
  QString selectedFilter;
  QFileDialog::Options options;
  QString fileName = QFileDialog::getOpenFileName(this,
      tr("QFileDialog::getOpenFileName()"),
      tr(""),
      tr("Images (*.png *.xpm *.jpg *.jpeg)"),
      &selectedFilter,
      options);
  if(!fileName.isNull()) {
    image_ = fileName;
    ingredientImage->setIcon(QIcon(fileName));
    noIngredientImage->setEnabled(true);
  }
}

void IngredientDialog::noImage()
{
  noIngredientImage->setEnabled(false);
  QIcon icon;
  icon.addPixmap(QPixmap(QString::fromUtf8(":/main/pixmaps/noimage.png")));
  ingredientImage->setIcon(icon);
  image_ = QString::Null();
}

} // namespace qt
} // namespace ui
} // namespace alky
