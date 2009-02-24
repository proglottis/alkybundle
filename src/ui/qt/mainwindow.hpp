// Abstract main window.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_MAINWINDOW_HPP
#define ALKY_MAINWINDOW_HPP

#include <QMainWindow>
#include <QAbstractListModel>

namespace alky {
namespace ui {
namespace qt {

class MainWindow : public QMainWindow {
  Q_OBJECT
public:
  virtual ~MainWindow() {}
public slots:
  virtual void showAbout() = 0;
  virtual void showAddIngredient() = 0;
protected:
  MainWindow() : QMainWindow() {}
};

} // namespace qt
} // namespace ui
} // namespace alky

#endif // ALKY_MAINWINDOW_HPP
