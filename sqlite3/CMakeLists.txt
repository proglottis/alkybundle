# Build rules for SQLite3.

# Copyright (C) 2009  James Fargher

# Distributed under the GNU General Public License, Version 3.
# See accompanying file gpl-3.0.txt or copy at
#   <http://www.gnu.org/licenses/>

include_directories(.)
add_library(sqlite3
  sqlite3.c
)

if(UNIX)
	target_link_libraries(sqlite3 "pthread" "dl")
endif(UNIX)
