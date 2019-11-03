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
 * Python API for cards
 *
 */

#include <pybind11/pybind11.h>
#include <fr/cards/poker_deck_factory.hpp>

PYBIND11_MODULE(fr_cards, m) {

  // I'll let you look at the ID and short ID too, but they're probably not super-useful to you
  pybind11::class_<fr::cards::card>(m, "card")
    .def(pybind11::init<std::uint64_t, std::uint16_t, std::string>(), pybind11::arg("long_id") = 0l, pybind11::arg("short_id") = 0, pybind11::arg("name"), "")
    .def_readonly("name", &fr::cards::card::name)
    .def_readonly("id", &fr::cards::card::id)
    .def_readonly("short_id", &fr::cards::card::short_id)
    ;

  // Do not create a deck manually (Unless you really want to.) Use the poker deck
  // factory to get a deck full of cards.
  pybind11::class_<fr::cards::deck>(m, "deck")
    .def(pybind11::init<>())
    .def("add", &fr::cards::deck::add)
    .def("get", &fr::cards::deck::get)
    .def("peek", &fr::cards::deck::peek)
    .def("size", &fr::cards::deck::size)
    .def("empty", &fr::cards::deck::empty)
    .def("shuffle", &fr::cards::deck::shuffle)
    ;

  pybind11::class_<fr::cards::poker_deck_factory>(m, "poker_deck_factory")
    .def_static("get", &fr::cards::poker_deck_factory::get)
    ;
    
}
