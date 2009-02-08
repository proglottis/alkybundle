# Build rules for AlkyBundle.

# Copyright (C) 2009  James Fargher

# Distributed under the GNU General Public License, Version 3.
# See accompanying file gpl-3.0.txt or copy at
#   <http://www.gnu.org/licenses/>

cmake_minimum_required(VERSION 2.6)
project(ALKYBUNDLE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory(src)
