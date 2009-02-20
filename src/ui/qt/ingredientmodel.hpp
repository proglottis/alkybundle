// Ingredient bundle list model.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_UI_QT_INGREDIENTMODEL_HPP
#define ALKY_UI_QT_INGREDIENTMODEL_HPP

#include <QAbstractListModel>

#include "bundle/ingredientbundle.hpp"

namespace alky {
namespace ui {
namespace qt {

class IngredientModel : public QAbstractListModel {
  Q_OBJECT
public:
  enum ColumnType {
    COLUMN_NAME,
    COLUMN_HAVE,
    COLUMN_MAX  // To save from maintaining column count number
  };

  IngredientModel(boost::shared_ptr<alky::bundle::IngredientBundle> bundle,
                  QObject* parent=0);

  int rowCount(const QModelIndex& parent = QModelIndex()) const;
  int columnCount(const QModelIndex& parent = QModelIndex()) const;
  QVariant data(const QModelIndex& index, int role) const;
  QVariant headerData(int section, Qt::Orientation orientation,
                      int role = Qt::DisplayRole) const;
private:
  boost::shared_ptr<alky::bundle::IngredientBundle> bundle_;
};

} // namespace qt
} // namespace ui
} // namespace alky

#endif // ALKY_UI_QT_INGREDIENTMODEL_HPP
