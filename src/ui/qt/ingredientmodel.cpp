// Ingredient bundle list model.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "ingredientmodel.hpp"

#include <QIcon>

namespace alky {
namespace ui {
namespace qt {

using alky::bundle::IngredientBundle;

IngredientModel::IngredientModel(boost::shared_ptr<IngredientBundle> bundle,
                                 QObject* parent)
    : QAbstractListModel(parent),
      bundle_(bundle)
{
}

int IngredientModel::rowCount(const QModelIndex& parent) const
{
  return bundle_->size();
}

int IngredientModel::columnCount(const QModelIndex& parent) const
{
  return COLUMN_MAX;
}

QVariant IngredientModel::data(const QModelIndex& index, int role) const
{
  if(!index.isValid()) {
    return QVariant();
  }
  if(index.row() >= bundle_->size()) {
    return QVariant();
  }
  if(role == Qt::DisplayRole) {
    switch(index.column()) {
    case COLUMN_NAME:
      return QString::fromStdWString(bundle_->at(index.row())->name());
    case COLUMN_HAVE:
      return bundle_->at(index.row())->have();
    }
  }
  if(role == Qt::DecorationRole) {
    if(index.column() == COLUMN_NAME) {
      QIcon icon;
      icon.addPixmap(QPixmap(QString::fromUtf8(":/main/pixmaps/noimage.png")));
      return icon;
    }
  }
  return QVariant();
}

QVariant IngredientModel::headerData(int section, Qt::Orientation orientation,
                                     int role) const
{
  if(role != Qt::DisplayRole) {
    return QVariant();
  }
  if(orientation == Qt::Horizontal) {
    switch(section) {
    case COLUMN_NAME:
      return tr("Name");
    case COLUMN_HAVE:
      return tr("Have");
    }
  }
  return QVariant();
}

} // namespace qt
} // namespace ui
} // namespace alky
