// Main window.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_MAINWINDOW_HPP
#define ALKY_MAINWINDOW_HPP

#include "ui_mainwindow.h"

namespace alky {
namespace ui {
namespace qt {

class MainWindow : public QMainWindow, private Ui::MainWindow {
  Q_OBJECT
public:
  MainWindow(QWidget *parent = 0);
  virtual ~MainWindow() {}
};

} // namespace qt
} // namespace ui
} // namespace alky

#endif // ALKY_MAINWINDOW_HPP
