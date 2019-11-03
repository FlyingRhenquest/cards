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
 * A playing card object, suitable for a game like blackjack or poker or
 * something.
 *
 */

#include <cstdint>
#include <string>

#ifndef _HPP_FR_CARD
#define _HPP_FR_CARD

namespace fr {

  namespace cards {

    // It's a kind of generic name but I can always change it later.
    
    class card {

    public:
      
      // I can easily represent 52 playing cards with individual bits with an int64_t and it might
      // make grading hands easier later or. Or at least more interesting.
      std::uint64_t id;

      // For cards where suite has less than 16 cards, we can represent the card's value relative
      // to any other card in the deck with a ushort.
      std::uint16_t short_id;

      // This card's name, text ones should always be an option
      std::string name;

      card(std::uint64_t id = 0l, std::uint16_t short_id = 0, std::string name = "") : id(id), short_id(short_id), name(name)
      {
      }

      ~card()
      {
      }

    };

  }
}

#endif
