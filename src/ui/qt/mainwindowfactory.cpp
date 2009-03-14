// Main window factory.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "mainwindowfactory.hpp"

#include "ingredientmodel.hpp"
#include "defaultmainwindow.hpp"
#include "resource/home.hpp"
#include "bundle/sqliteingredientbundle.hpp"
#include "locale/stringconvert.hpp"

namespace alky {
namespace ui {
namespace qt {

using alky::bundle::IngredientBundle;
using alky::bundle::SQLiteIngredientBundle;
using alky::cocktail::Ingredient;
using alky::resource::Home;
using alky::locale::StringConvert;

MainWindow *MainWindowFactory::create(QWidget *parent)
{
  boost::shared_ptr<StringConvert> convert(StringConvert::create());
  boost::shared_ptr<Home> home(Home::create());
  // TODO: Create sqlite manager
  sqlite3* db;
  sqlite3_open(convert->wide_to_utf8(
      home->config_dir() + L"/bundle.db").c_str(), &db);
  boost::shared_ptr<IngredientBundle> ingBundle(
    new SQLiteIngredientBundle(db));
  boost::shared_ptr<IngredientModel> ingModel(new IngredientModel(ingBundle));
  ingBundle->add_listener(ingModel);
  boost::shared_ptr<IngredientDialogFactory> ingFac(
      new IngredientDialogFactory());
  return new DefaultMainWindow(ingBundle, ingFac, ingModel.get());
}

} // namespace qt
} // namespace ui
} // namespace alky
