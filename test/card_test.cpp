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
 * Test card interface. It doesn't do that much, but that just means it's easy to test.
 */

#include <fr/cards/card.hpp>
#include <cppunit/extensions/HelperMacros.h>

class card_test : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(card_test);
  CPPUNIT_TEST(empty_card_test);
  CPPUNIT_TEST(named_card_test);
  CPPUNIT_TEST(copy_test);
  CPPUNIT_TEST_SUITE_END();

public:

  void empty_card_test()
  {
    fr::cards::card card;
    CPPUNIT_ASSERT(card.name == "");
    CPPUNIT_ASSERT(card.id == 0l);
    CPPUNIT_ASSERT(card.short_id == 0);		 
  }

  void named_card_test()
  {
    fr::cards::card card(50, 5, "SOMETHING OF SOMETHINGS");
    CPPUNIT_ASSERT(card.name == "SOMETHING OF SOMETHINGS");
    CPPUNIT_ASSERT(card.id == 50);
    CPPUNIT_ASSERT(card.short_id == 5);
  }

  void copy_test()
  {
    fr::cards::card card(50, 5, "SOMETHING OF SOMETHINGS");
    fr::cards::card copied_card = card;
      
    CPPUNIT_ASSERT(copied_card.name.compare("SOMETHING OF SOMETHINGS") == 0);
    CPPUNIT_ASSERT(copied_card.id == 50);
    CPPUNIT_ASSERT(copied_card.short_id == 5);
  }
  
};

CPPUNIT_TEST_SUITE_REGISTRATION(card_test);
