# Build rules for AlkyBundle.

# Copyright (C) 2009  James Fargher

# Distributed under the GNU General Public License, Version 3.
# See accompanying file gpl-3.0.txt or copy at
#   <http://www.gnu.org/licenses/>

add_library(resource
  home.cpp
  defaulthome.cpp
)

find_package(Boost COMPONENTS shared_ptr)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})
