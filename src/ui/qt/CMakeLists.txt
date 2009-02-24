# Build rules for AlkyBundle.

# Copyright (C) 2009  James Fargher

# Distributed under the GNU General Public License, Version 3.
# See accompanying file gpl-3.0.txt or copy at
#   <http://www.gnu.org/licenses/>

find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

set(alkybundle_SRC
	main.cpp
	defaultmainwindow.cpp
	mainwindowfactory.cpp
	ingredientdialog.cpp
	ingredientdialogfactory.cpp
        ingredientmodel.cpp
)

qt4_wrap_ui(alkybundle_UI
	mainwindow.ui
	ingredientdialog.ui
)

qt4_wrap_cpp(alkybundle_MOC
	mainwindow.hpp
	defaultmainwindow.hpp
	ingredientdialog.hpp
        ingredientmodel.hpp
)

qt4_add_resources(alkybundle_RES
	resources.qrc
)

add_executable(alkybundle
	${alkybundle_SRC}
	${alkybundle_UI}
	${alkybundle_MOC}
	${alkybundle_RES}
)
target_link_libraries(alkybundle bundle cocktail ${QT_LIBRARIES})
