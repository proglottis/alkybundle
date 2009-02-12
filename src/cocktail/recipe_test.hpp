// Recipe leaf class unit-testing.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include <cxxtest/TestSuite.h>

#include "cocktail/recipe.hpp"
#include "cocktail/instructionlist.hpp"

using alky::cocktail::Recipe;
using alky::cocktail::InstructionList;

boost::shared_ptr<InstructionList> EMPTY_INSTRUCTIONS(new InstructionList());

class RecipeTest : public CxxTest::TestSuite {
public:
  void testGetName(void)
  {
    std::string name = "Foo";
    Recipe recipe(name, "", "", "", EMPTY_INSTRUCTIONS);
    TS_ASSERT_EQUALS(recipe.name(), name);
  }

  void testGetDescription(void)
  {
    std::string description = "Foo";
    Recipe recipe("", description, "", "", EMPTY_INSTRUCTIONS);
    TS_ASSERT_EQUALS(recipe.description(), description);
  }

  void testGetCopyright(void)
  {
    std::string copyright = "Fake Copyright (C) 1900 John Doe";
    Recipe recipe("", "", copyright, "", EMPTY_INSTRUCTIONS);
    TS_ASSERT_EQUALS(recipe.copyright(), copyright);
  }

  void testGetLicence(void)
  {
    std::string licence = "Public Domain";
    Recipe recipe("", "", "", licence, EMPTY_INSTRUCTIONS);
    TS_ASSERT_EQUALS(recipe.licence(), licence);
  }

  void testGetInstructions(void)
  {
    boost::shared_ptr<InstructionList> instructions(new InstructionList());
    instructions->push_back("TEST");
    Recipe recipe("", "", "", "", instructions);
    TS_ASSERT_EQUALS(recipe.instructions(), instructions);
  }

  void testSetDescription(void)
  {
    std::string description = "Foo";
    Recipe recipe("", "", "", "", EMPTY_INSTRUCTIONS);
    recipe.set_description(description);
    TS_ASSERT_EQUALS(recipe.description(), description);
  }

  void testSetCopyright(void)
  {
    std::string copyright = "Fake Copyright (C) 1900 John Doe";
    Recipe recipe("", "", "", "", EMPTY_INSTRUCTIONS);
    recipe.set_copyright(copyright);
    TS_ASSERT_EQUALS(recipe.copyright(), copyright);
  }

  void testSetLicence(void)
  {
    std::string licence = "Public Domain";
    Recipe recipe("", "", "", "", EMPTY_INSTRUCTIONS);
    recipe.set_licence(licence);
    TS_ASSERT_EQUALS(recipe.licence(), licence);
  }

  void testSetInstructions(void)
  {
    boost::shared_ptr<InstructionList> instructions(new InstructionList());
    instructions->push_back("TEST");
    Recipe recipe("", "", "", "", EMPTY_INSTRUCTIONS);
    recipe.set_instructions(instructions);
    TS_ASSERT_EQUALS(recipe.instructions(), instructions);
  }

  void testEqualsByName(void)
  {
    std::string name = "Foo";
    Recipe recipe1(name, "A", "B", "C", EMPTY_INSTRUCTIONS);
    Recipe recipe2(name, "D", "E", "F", EMPTY_INSTRUCTIONS);
    TS_ASSERT(recipe1 == recipe2);
  }

  void testNotEqualsByName(void)
  {
    std::string other = "Foo";
    Recipe recipe1("A", other, other, other, EMPTY_INSTRUCTIONS);
    Recipe recipe2("B", other, other, other, EMPTY_INSTRUCTIONS);
    TS_ASSERT(recipe1 != recipe2);
  }
};
