// Main window factory.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_UI_QT_MAINWINDOWFACTORY_HPP
#define ALKY_UI_QT_MAINWINDOWFACTORY_HPP

#include "mainwindow.hpp"

namespace alky {
namespace ui {
namespace qt {

class MainWindowFactory {
public:
  MainWindowFactory() {}
  virtual ~MainWindowFactory() {}

  virtual MainWindow *create(QWidget *parent = 0);
};

} // namespace qt
} // namespace ui
} // namespace alky

#endif // ALKY_UI_QT_MAINWINDOWFACTORY_HPP
