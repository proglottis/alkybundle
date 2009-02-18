// Ingredient Dialog

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "ingredientdialog.hpp"

#include <QFileDialog>
#include <QMessageBox>

namespace alky {
namespace ui {
namespace qt {

IngredientDialog::IngredientDialog(QWidget* parent)
    : QDialog(parent),
      builder_(),
      image_(QString::Null())
{
  setupUi(this);
}

QString IngredientDialog::image() const
{
  return image_;
}

void IngredientDialog::set_image(const QString& filename)
{
  QIcon icon;
  if(filename.isNull()) {
    icon.addPixmap(QPixmap(QString::fromUtf8(":/main/pixmaps/noimage.png")));
    noIngredientImage->setEnabled(false);
  }
  else {
    icon.addPixmap(QPixmap(filename));
    noIngredientImage->setEnabled(true);
  }
  ingredientImage->setIcon(icon);
  image_ = filename;
}

void IngredientDialog::accept()
{
  builder_.set_name(ingredientName->text().toStdWString());
  builder_.set_have(ingredientHave->checkState() == Qt::Checked);
  builder_.set_description(
      ingredientDescription->toPlainText().toStdWString());
  try {
    builder_.build();
    done(QDialog::Accepted);
  }
  catch(alky::cocktail::BuilderError e) {
    QMessageBox::critical(this, tr("Missing name"),
                          tr("Please enter a name for the ingredient."));
  }
}

void IngredientDialog::findImage()
{
  QString selectedFilter;
  QFileDialog::Options options;
  QString fileName = QFileDialog::getOpenFileName(
      this,
      tr("Select image"),
      tr(""),
      tr("Images (*.jpg *.jpeg *.png *.xpm)"),
      &selectedFilter,
      options);
  if(!fileName.isNull()) {
    set_image(fileName);
  }
}

void IngredientDialog::clearImage()
{
  set_image(QString::Null());
}

} // namespace qt
} // namespace ui
} // namespace alky
