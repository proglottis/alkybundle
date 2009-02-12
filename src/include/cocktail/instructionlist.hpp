// Recipe instructions list.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_COCKTAIL_INSTRUCTIONLIST_HPP
#define ALKY_COCKTAIL_INSTRUCTIONLIST_HPP

#include <string>
#include <vector>

namespace alky {
namespace cocktail {

class InstructionList {
public:
  typedef std::vector<std::string>::iterator iterator;
  typedef std::vector<std::string>::const_iterator const_iterator;

  InstructionList();
  virtual ~InstructionList() {}

  void push_back(const std::string& instruction);

  std::string operator[](size_t i) const;

  size_t size() const;

  iterator begin();
  const_iterator begin() const;

  iterator end();
  const_iterator end() const;
private:
  InstructionList(const InstructionList&);
  void operator=(const InstructionList&);

  std::vector<std::string> list_;
};

} // namespace cocktail
} // namespace alky

#endif // ALKY_COCKTAIL_INSTRUCTIONLIST_HPP
