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
 * Deck of cards, of course. This doesn't care what kind of cards it is. It
 * will happily accept any card into the deck, allow you to shuffle the
 * deck and get cards out of it.
 *
 * Don't create one of these manually, use an appropriate deck factory.
 *
 * Deck shuffling is handled via std::shuffle with a std::random_device
 * and std::mt19937. This is enough to suit my needs, but may or may not be
 * "casino grade." The implementation looks more solid than one I could build
 * off the top of my head, but if I were being particularly paranoid,
 * a USB quantum random number generator would be a good and fairly cheap
 * source of true random numbers.
 */

#include <algorithm>
#include <random>
#include <stdexcept>
#include "card.hpp"
#include <vector>

#ifndef _HPP_FR_DECK
#define _HPP_FR_DECK

namespace fr {

  namespace cards {

    class deck {

      std::vector<card> cards;

    public:

      deck()
      {
      }

      ~deck()
      {
      }

      // Add a card to the deck
      void add(card to_add)
      {
	cards.push_back(to_add);
      }

      // Removes front card and returns it.
      card get()
      {	
	if (cards.empty()) {
	  // I could throw or return empty here, but returning an
	  // unexpected value doesn't seem like a great move to me,
	  // so I'm throwing instead.
	  // Python will be fine with this, and you can catch the error there.
	  // You can also check size() before getting more cards if you don't
	  // want to worry about it.
	  throw std::logic_error("No more cards");
	}
	// This is less efficient than popping the card off the back,
	// but I feel like it's important to preserve the "top of the deck"
	// concept for the deck. It doesn't matter where you get the card
	// if the deck is shuffled, but this will get them out in the
	// order they were inserted if it hasn't been.
	card c = cards.front();
	cards.erase(cards.begin());
	return c;
      }

      // Peek at the first card in the deck (Returns top card but does not remove it.)
      card peek()
      {
	if (cards.empty()) {
	  throw std::logic_error("Empty deck");
	}
	return cards.front();
      }

      // Return number of cards in the deck
      size_t size()
      {
	return cards.size();
      }

      // Or you can check it this way
      bool empty()
      {
	return cards.empty();
      }

      void shuffle()
      {
	if (empty()) {
	  return;
	}

	std::random_device rd;
	std::mt19937 twister(rd());


	std::shuffle(cards.begin(), cards.end(), twister);
      }
      
    };
    
  }

}

#endif
