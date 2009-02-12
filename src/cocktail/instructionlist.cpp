// Recipe instructions list.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "cocktail/instructionlist.hpp"

namespace alky {
namespace cocktail {

InstructionList::InstructionList()
    : list_()
{
}

void InstructionList::push_back(const std::string& instruction)
{
  list_.push_back(instruction);
}

std::string InstructionList::operator[](size_t i) const
{
  return list_[i];
}

size_t InstructionList::size() const
{
  return list_.size();
}

InstructionList::iterator InstructionList::begin()
{
  return list_.begin();
}

InstructionList::const_iterator InstructionList::begin() const
{
  return list_.begin();
}

InstructionList::iterator InstructionList::end()
{
  return list_.end();
}

InstructionList::const_iterator InstructionList::end() const
{
  return list_.end();
}

} // namespace cocktail
} // namespace alky
