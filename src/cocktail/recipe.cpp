// Recipe leaf class.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "cocktail/recipe.hpp"

namespace alky {
namespace cocktail {

Recipe::Recipe(const std::string& name, const std::string& description,
               const std::string& copyright,
               const std::string& licence,
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

std::string Recipe::name() const
{
  return name_;
}

std::string Recipe::description() const
{
  return description_;
}

std::string Recipe::copyright() const
{
  return copyright_;
}

std::string Recipe::licence() const
{
  return licence_;
}

boost::shared_ptr<InstructionList> Recipe::instructions() const
{
  return instructions_;
}

void Recipe::set_description(const std::string& description)
{
  description_ = description;
}

void Recipe::set_copyright(const std::string& copyright)
{
  copyright_ = copyright;
}

void Recipe::set_licence(const std::string& licence)
{
  licence_ = licence;
}

void Recipe::set_instructions(boost::shared_ptr<InstructionList> instructions)
{
  instructions_ = instructions;
}

} // namespace cocktail
} // namespace alky
