// SQLite3 ingredient bundle.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "bundle/sqliteingredientbundle.hpp"

#include "cocktail/ingredientbuilder.hpp"
#include "locale/stringconvert.hpp"

namespace alky {
namespace bundle {

using alky::cocktail::Ingredient;
using alky::cocktail::IngredientBuilder;
using alky::locale::StringConvert;

class SQLiteIngredient : public Ingredient {
public:
  SQLiteIngredient(sqlite3* db, size_t index) : db_(db), index_(index) {}
  virtual ~SQLiteIngredient() {}

  virtual bool operator==(const Ingredient& other) const
  {
    return name() == other.name();
  }

  virtual std::wstring name() const
  {
    std::wstring name;
    boost::shared_ptr<StringConvert> convert(StringConvert::create());
    sqlite3_stmt* stmt;
    sqlite3_prepare(db_, "SELECT name FROM ingredient WHERE id=?;", -1, &stmt,
                    (const char**)0);
    sqlite3_bind_int(stmt, 1, index_ + 1);
    while(true) {
      int code = sqlite3_step(stmt);
      if(code == SQLITE_DONE || code == SQLITE_ERROR ||
          code == SQLITE_MISUSE) {
        break;
      }
      if(code == SQLITE_ROW) {
        name = convert->utf8_to_wide(std::string(
            (const char *)sqlite3_column_blob(stmt, 0),
            sqlite3_column_bytes(stmt, 0)));
      }
    }
    sqlite3_finalize(stmt);
    return name;
  }

  virtual std::wstring description() const
  {
    std::wstring description;
    boost::shared_ptr<StringConvert> convert(StringConvert::create());
    sqlite3_stmt* stmt;
    sqlite3_prepare(db_, "SELECT description FROM ingredient WHERE id=?;", -1,
                    &stmt,
                    (const char**)0);
    sqlite3_bind_int(stmt, 1, index_ + 1);
    while(true) {
      int code = sqlite3_step(stmt);
      if(code == SQLITE_DONE || code == SQLITE_ERROR ||
          code == SQLITE_MISUSE) {
        break;
      }
      if(code == SQLITE_ROW) {
        description = convert->utf8_to_wide(std::string(
            (const char *)sqlite3_column_blob(stmt, 0),
            sqlite3_column_bytes(stmt, 0)));
      }
    }
    sqlite3_finalize(stmt);
    return description;
  }

  virtual bool have() const
  {
    bool have = false;
    sqlite3_stmt* stmt;
    sqlite3_prepare(db_, "SELECT have FROM ingredient WHERE id=?;", -1, &stmt,
                    (const char**)0);
    sqlite3_bind_int(stmt, 1, index_ + 1);
    while(true) {
      int code = sqlite3_step(stmt);
      if(code == SQLITE_DONE || code == SQLITE_ERROR ||
          code == SQLITE_MISUSE) {
        break;
      }
      if(code == SQLITE_ROW) {
        have = sqlite3_column_int(stmt, 0);
      }
    }
    sqlite3_finalize(stmt);
    return have;
  }

  virtual void set_description(const std::wstring& description)
  {
  }

  virtual void set_have(bool have)
  {
  }
private:
  sqlite3* db_;
  size_t index_;
};

SQLiteIngredientBundle::SQLiteIngredientBundle(sqlite3* db)
    : IngredientBundle(),
      db_(db),
      listeners_()
{
  // TODO: Move table creation to database manager.. When that is made.
  char* error;
  int rc = sqlite3_exec(db_,
      "CREATE TABLE IF NOT EXISTS ingredient ("
      "    id INTEGER PRIMARY KEY AUTOINCREMENT,"
      "    name TEXT,"
      "    description TEXT,"
      "    have INTEGER"
      ");",
      (int(*)(void*,int,char**,char**))0,
      (void*)0,
      &error);
  if(rc != SQLITE_OK) {
    sqlite3_free(error);
  }
}

size_t SQLiteIngredientBundle::size() const
{
  sqlite3_stmt* stmt;
  sqlite3_prepare(db_, "SELECT COUNT(*) FROM ingredient;", -1, &stmt,
                  (const char**)0);
  int count = 0;
  while(true) {
    int code = sqlite3_step(stmt);
    if(code == SQLITE_DONE || code == SQLITE_ERROR || code == SQLITE_MISUSE) {
      break;
    }
    if(code == SQLITE_ROW) {
      count = sqlite3_column_int(stmt, 0);
    }
  }
  sqlite3_finalize(stmt);
  return count;
}

boost::shared_ptr<Ingredient> SQLiteIngredientBundle::at(size_t index)
{
  boost::shared_ptr<SQLiteIngredient> ing(new SQLiteIngredient(db_, index));
  return ing;
}

boost::shared_ptr<const Ingredient> SQLiteIngredientBundle::at(
    size_t index) const
{
  boost::shared_ptr<SQLiteIngredient> ing(new SQLiteIngredient(db_, index));
  return ing;
}

void SQLiteIngredientBundle::add(boost::shared_ptr<Ingredient> ingredient)
{
  boost::shared_ptr<StringConvert> convert(StringConvert::create());
  sqlite3_stmt* stmt;
  sqlite3_prepare(db_,
      "INSERT INTO ingredient (name, description, have) VALUES (?, ?, ?);",
      -1,
      &stmt,
      (const char**)0);
  sqlite3_bind_text(stmt, 1, convert->wide_to_utf8(ingredient->name()).c_str(),
                    -1,
                    SQLITE_STATIC);
  sqlite3_bind_text(stmt, 2,
                    convert->wide_to_utf8(ingredient->description()).c_str(),
                    -1,
                    SQLITE_STATIC);
  sqlite3_bind_int(stmt, 3, ingredient->have());
  while(true) {
    int code = sqlite3_step(stmt);
    if(code == SQLITE_DONE || code == SQLITE_ERROR || code == SQLITE_MISUSE) {
      break;
    }
  }
  sqlite3_finalize(stmt);
  size_t index = sqlite3_last_insert_rowid(db_);
  std::vector<boost::shared_ptr<IngredientBundleListener> >::iterator it;
  for(it=listeners_.begin(); it!=listeners_.end(); it++) {
    (*it)->ingredient_added(index);
  }
}

void SQLiteIngredientBundle::add_listener(
    boost::shared_ptr<IngredientBundleListener> listener)
{
  listeners_.push_back(listener);
}

} // namespace bundle
} // namespace alky
