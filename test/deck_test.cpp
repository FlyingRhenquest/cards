/**
 * Copyright 2019 Bruce Ide
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 * Test of a deck. Also verifies that poker deck factory generates a deck
 * with cards in it (but not much else.)
 */

#include <cppunit/extensions/HelperMacros.h>
#include <fr/cards/deck.hpp>
#include <fr/cards/poker_deck_factory.hpp>

class deck_test : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(deck_test);
  CPPUNIT_TEST(empty_deck_test);
  CPPUNIT_TEST(poker_deck_test);
  CPPUNIT_TEST_SUITE_END();

public:

  void empty_deck_test()
  {
    fr::cards::deck empty_deck;
    CPPUNIT_ASSERT(empty_deck.empty());
    bool get_threw = false;
    bool peek_threw = false;
    try {
      empty_deck.get();
    } catch (std::exception &e) {
      get_threw = true;
    }

    try {
      empty_deck.peek();
    } catch(std::exception &e) {
      peek_threw = true;
    }
    CPPUNIT_ASSERT(get_threw);
    CPPUNIT_ASSERT(peek_threw);
    CPPUNIT_ASSERT(empty_deck.size() == 0);

    // Let's add a card
    fr::cards::card card(50, 5, "SOMETHING OF SOMETHINGS");
    empty_deck.add(card);
    CPPUNIT_ASSERT(!empty_deck.empty());
    fr::cards::card ret = empty_deck.get();
    CPPUNIT_ASSERT(empty_deck.empty());
    CPPUNIT_ASSERT(ret.name == card.name);
    CPPUNIT_ASSERT(ret.id == card.id);
    CPPUNIT_ASSERT(ret.short_id == card.short_id);      
  }

  void poker_deck_test()
  {
    fr::cards::deck poker_deck = fr::cards::poker_deck_factory::get();
    CPPUNIT_ASSERT(poker_deck.size() == 52);
  }
  
};

CPPUNIT_TEST_SUITE_REGISTRATION(deck_test);
