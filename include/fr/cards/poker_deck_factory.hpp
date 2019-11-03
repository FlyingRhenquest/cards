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
 * Creates a poker deck.
 */

#include "deck.hpp"
#include <climits>
#include <tuple>
#include <vector>

#ifndef _HPP_FR_POKER_DECK_FACTORY
#define _HPP_FR_POKER_DECK_FACTORY

namespace fr {

  namespace cards {

    class poker_deck_factory {

    public:

      // Shifts for suites
      const int hearts_shift = 0;
      const int spades_shift = 16;
      const int diamonds_shift = 32;
      const int clubs_shift = 48;
      // Masks for suites
      const uint64_t hearts_mask = USHRT_MAX << hearts_shift;
      const uint64_t spades_mask = USHRT_MAX << spades_shift;
      const uint64_t diamonds_mask = USHRT_MAX << diamonds_shift;
      const uint64_t clubs_mask = USHRT_MAX << clubs_shift;
      
      static deck get()
      {
	deck retval;
	std::vector<std::string> suites{"Hearts", "Spades", "Diamonds", "Clubs"};
	std::vector<std::tuple<std::string, std::uint16_t>> values = {
	  {"Two",   2},
	  {"Three", 2 << 1},
	  {"Four",  2 << 2},
	  {"Five",  2 << 3},
	  {"Six",   2 << 4},
	  {"Seven", 2 << 5},
	  {"Eight", 2 << 6},
	  {"Nine",  2 << 7},
	  {"Ten",   2 << 8},
	  {"Jack",  2 << 9},
	  {"Queen", 2 << 10},
	  {"King",  2 << 11},
	  // Ace can be high or low for straights, so we'll set the low bit too.
	  {"Ace",   (2 << 12) + 1}
	};

	int shift_val = 0;
	for (auto suite : suites) {
	  for (auto [short_name, short_id] : values) {
	    std::string long_name(short_name);
	    long_name.append(" of ");
	    long_name.append(suite);
	    std::uint64_t long_id = short_id << shift_val;
	    retval.add(card(long_id, short_id, long_name));
	  }
	  shift_val += 16;
	}
	return retval;
      }
      
    };

  }
}

#endif
