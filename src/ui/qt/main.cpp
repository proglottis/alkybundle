// Entry Point.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include <QApplication>

#include "mainwindowfactory.hpp"

using alky::ui::qt::MainWindow;
using alky::ui::qt::MainWindowFactory;

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  MainWindowFactory *factory = new MainWindowFactory();
  MainWindow* mainwindow = factory->create();
  delete factory;

  mainwindow->show();

  return app.exec();
}
