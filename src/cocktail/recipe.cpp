// Recipe leaf class.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "cocktail/recipe.hpp"

namespace alky {
namespace cocktail {

Recipe::Recipe(const std::wstring& name, const std::wstring& description,
               const std::wstring& copyright,
               const std::wstring& licence,
               boost::shared_ptr<InstructionList> instructions)
    : name_(name),
      description_(description),
      copyright_(copyright),
      licence_(licence),
      instructions_(instructions)
{
}

bool Recipe::operator==(const Recipe& other) const
{
  return name_ == other.name_;
}

bool Recipe::operator!=(const Recipe& other) const
{
  return name_ != other.name_;
}

std::wstring Recipe::name() const
{
  return name_;
}

std::wstring Recipe::description() const
{
  return description_;
}

std::wstring Recipe::copyright() const
{
  return copyright_;
}

std::wstring Recipe::licence() const
{
  return licence_;
}

boost::shared_ptr<InstructionList> Recipe::instructions() const
{
  return instructions_;
}

void Recipe::set_description(const std::wstring& description)
{
  description_ = description;
}

void Recipe::set_copyright(const std::wstring& copyright)
{
  copyright_ = copyright;
}

void Recipe::set_licence(const std::wstring& licence)
{
  licence_ = licence;
}

void Recipe::set_instructions(boost::shared_ptr<InstructionList> instructions)
{
  instructions_ = instructions;
}

} // namespace cocktail
} // namespace alky
