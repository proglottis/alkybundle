// Builder error exception.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#ifndef ALKY_COCKTAIL_BUILDERERROR_HPP
#define ALKY_COCKTAIL_BUILDERERROR_HPP

#include <stdexcept>

namespace alky {
namespace cocktail {

class BuilderError : public std::logic_error {
public:
  explicit BuilderError(const std::string& what) throw();
  virtual ~BuilderError() throw() {}
};

} // namespace cocktail
} // namespace alky

#endif // ALKY_COCKTAIL_BUILDERERROR_HPP
