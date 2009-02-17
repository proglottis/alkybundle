// Builder error exception.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include "cocktail/buildererror.hpp"

namespace alky {
namespace cocktail {

BuilderError::BuilderError(const std::string& what) throw()
    : std::logic_error(what)
{}

} // namespace cocktail
} // namespace alky
