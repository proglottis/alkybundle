# - Find SQLite3
# Find the SQLite3 library.
#
#  SQLite3_FOUND - set to true if SQLite3 is found
#  SQLite3_INCLUDE_DIRS - include directories
#  SQLite3_LIBRARIES - libraries for linking

# Copyright (C) 2009  James Fargher

# Distributed under the GNU General Public License, Version 3.
# See accompanying file gpl-3.0.txt or copy at
#   <http://www.gnu.org/licenses/>

find_path(SQLite3_INCLUDE_DIR NAMES sqlite3.h)
find_library(SQLite3_LIBRARIES NAMES sqlite3)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(SQLite3 DEFAULT_MSG
	SQLite3_LIBRARIES
	SQLite3_INCLUDE_DIR
)
set(SQLite3_INCLUDE_DIRS ${SQLite3_INCLUDE_DIR})
