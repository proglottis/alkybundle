// Recipe instructions list unit-testing.

// Copyright (C) 2009  James Fargher

// Distributed under the GNU General Public License, Version 3.
// See accompanying file gpl-3.0.txt or copy at
//   <http://www.gnu.org/licenses/>

#include <cxxtest/TestSuite.h>

#include "cocktail/instructionlist.hpp"

using alky::cocktail::InstructionList;

class InstructionListTest : public CxxTest::TestSuite {
public:
  void testZeroInitialSize(void)
  {
    InstructionList list;
    TS_ASSERT_EQUALS(list.size(), 0);
  }

  void testPushBackSize(void)
  {
    const size_t LIMIT = 10;
    InstructionList list;
    for(size_t ii=0; ii<LIMIT; ii++) {
      list.push_back(L"TEST");
    }
    TS_ASSERT_EQUALS(list.size(), LIMIT);
  }

  void testAtConsistancy(void)
  {
    const wchar_t* WORDS[] = {L"A", L"B", L"C", L"D"};
    const size_t LEN = sizeof(WORDS) / sizeof(wchar_t*);
    InstructionList list;
    for(size_t ii=0; ii<LEN; ii++) {
      list.push_back(WORDS[ii]);
    }
    for(size_t ii=0; ii<LEN; ii++) {
      TS_ASSERT_EQUALS(list[ii], WORDS[ii]);
    }
  }

  void testIteratorConsistancy(void)
  {
    const wchar_t* WORDS[] = {L"A", L"B", L"C", L"D"};
    const size_t LEN = sizeof(WORDS) / sizeof(wchar_t*);
    InstructionList list;
    for(size_t ii=0; ii<LEN; ii++) {
      list.push_back(WORDS[ii]);
    }
    size_t ii=0;
    for(InstructionList::iterator it=list.begin(); it != list.end(); it++) {
      TS_ASSERT_EQUALS(*it, WORDS[ii]);
      ++ii;
    }
  }

  void testConstIteratorConsistancy(void)
  {
    typedef InstructionList::const_iterator citerator;
    const wchar_t* WORDS[] = {L"A", L"B", L"C", L"D"};
    const size_t LEN = sizeof(WORDS) / sizeof(wchar_t*);
    InstructionList list;
    for(size_t ii=0; ii<LEN; ii++) {
      list.push_back(WORDS[ii]);
    }
    const InstructionList& clist = list;
    size_t ii=0;
    for(citerator it=clist.begin(); it != clist.end(); it++) {
      TS_ASSERT_EQUALS(*it, WORDS[ii]);
      ++ii;
    }
  }
};
