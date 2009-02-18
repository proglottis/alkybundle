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
    std::wstring name = L"Foo";
    Recipe recipe(name, L"", L"", L"", EMPTY_INSTRUCTIONS);
    TS_ASSERT_EQUALS(recipe.name(), name);
  }

  void testGetDescription(void)
  {
    std::wstring description = L"Foo";
    Recipe recipe(L"", description, L"", L"", EMPTY_INSTRUCTIONS);
    TS_ASSERT_EQUALS(recipe.description(), description);
  }

  void testGetCopyright(void)
  {
    std::wstring copyright = L"Fake Copyright (C) 1900 John Doe";
    Recipe recipe(L"", L"", copyright, L"", EMPTY_INSTRUCTIONS);
    TS_ASSERT_EQUALS(recipe.copyright(), copyright);
  }

  void testGetLicence(void)
  {
    std::wstring licence = L"Public Domain";
    Recipe recipe(L"", L"", L"", licence, EMPTY_INSTRUCTIONS);
    TS_ASSERT_EQUALS(recipe.licence(), licence);
  }

  void testGetInstructions(void)
  {
    boost::shared_ptr<InstructionList> instructions(new InstructionList());
    instructions->push_back(L"TEST");
    Recipe recipe(L"", L"", L"", L"", instructions);
    TS_ASSERT_EQUALS(recipe.instructions(), instructions);
  }

  void testSetDescription(void)
  {
    std::wstring description = L"Foo";
    Recipe recipe(L"", L"", L"", L"", EMPTY_INSTRUCTIONS);
    recipe.set_description(description);
    TS_ASSERT_EQUALS(recipe.description(), description);
  }

  void testSetCopyright(void)
  {
    std::wstring copyright = L"Fake Copyright (C) 1900 John Doe";
    Recipe recipe(L"", L"", L"", L"", EMPTY_INSTRUCTIONS);
    recipe.set_copyright(copyright);
    TS_ASSERT_EQUALS(recipe.copyright(), copyright);
  }

  void testSetLicence(void)
  {
    std::wstring licence = L"Public Domain";
    Recipe recipe(L"", L"", L"", L"", EMPTY_INSTRUCTIONS);
    recipe.set_licence(licence);
    TS_ASSERT_EQUALS(recipe.licence(), licence);
  }

  void testSetInstructions(void)
  {
    boost::shared_ptr<InstructionList> instructions(new InstructionList());
    instructions->push_back(L"TEST");
    Recipe recipe(L"", L"", L"", L"", EMPTY_INSTRUCTIONS);
    recipe.set_instructions(instructions);
    TS_ASSERT_EQUALS(recipe.instructions(), instructions);
  }

  void testEqualsByName(void)
  {
    std::wstring name = L"Foo";
    Recipe recipe1(name, L"A", L"B", L"C", EMPTY_INSTRUCTIONS);
    Recipe recipe2(name, L"D", L"E", L"F", EMPTY_INSTRUCTIONS);
    TS_ASSERT(recipe1 == recipe2);
  }

  void testNotEqualsByName(void)
  {
    std::wstring other = L"Foo";
    Recipe recipe1(L"A", other, other, other, EMPTY_INSTRUCTIONS);
    Recipe recipe2(L"B", other, other, other, EMPTY_INSTRUCTIONS);
    TS_ASSERT(recipe1 != recipe2);
  }
};
