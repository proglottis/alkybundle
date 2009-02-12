// Main window.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "mainwindow.hpp"

namespace alky {
namespace ui {
namespace qt {

MainWindow::MainWindow(QWidget* parent)
: QMainWindow(parent)
{
  setupUi(this);
}

} // namespace qt
} // namespace ui
} // namespace alky
