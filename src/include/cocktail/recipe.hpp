// Recipe leaf class.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_COCKTAIL_RECIPE_HPP
#define ALKY_COCKTAIL_RECIPE_HPP

#include <string>

#include <boost/shared_ptr.hpp>

#include "cocktail/quantity.hpp"
#include "cocktail/instructionlist.hpp"

namespace alky {
namespace cocktail {

class Recipe {
public:
  Recipe(const std::wstring& name, const std::wstring& description,
         const std::wstring& copyright,
         const std::wstring& licence,
         boost::shared_ptr<InstructionList> instructions);
  virtual ~Recipe() {}

  bool operator==(const Recipe& other) const;
  bool operator!=(const Recipe& other) const;

  std::wstring name() const;
  std::wstring description() const;
  std::wstring copyright() const;
  std::wstring licence() const;
  boost::shared_ptr<InstructionList> instructions() const;

  void set_description(const std::wstring& description);
  void set_copyright(const std::wstring& copyright);
  void set_licence(const std::wstring& licence);
  void set_instructions(boost::shared_ptr<InstructionList> instructions);
private:
  Recipe();
  Recipe(const Recipe&);
  void operator=(const Recipe&);

  std::wstring name_;
  std::wstring description_;
  std::wstring copyright_;
  std::wstring licence_;
  boost::shared_ptr<InstructionList> instructions_;
};

} // namespace cocktail
} // namespace alky

#endif // ALKY_COCKTAIL_RECIPE_HPP
