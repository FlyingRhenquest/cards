cmake_minimum_required(VERSION 3.13)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

project(fr_cards CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(BEFORE ${CMAKE_SOURCE_DIR}/include)

find_package(PkgConfig REQUIRED)
find_package(pybind11 CONFIG)
pkg_search_module(cppunit REQUIRED cppunit)


if (pybind11_FOUND)
   pybind11_add_module(fr_cards MODULE ${CMAKE_SOURCE_DIR}/python3/fr_cards.cpp)
endif()


# Test stuff

if (EXISTS /usr/local/include/fr/cppunit OR EXISTS /usr/include/fr/cppunit)
  set(USE_FR_CPPUNIT TRUE)
else()
  SET(USE_FR_CPPUNIT FALSE)
endif()

if (USE_FR_CPPUNIT)
  add_compile_definitions(HAVE_FR_LISTENER)
endif()

#
# This brings the test up to the top level build directory, which is much easier than looking
# around trying to find them.
#

add_executable(card_test ${CMAKE_SOURCE_DIR}/test/card_test.cpp ${CMAKE_SOURCE_DIR}/test/test_runner_basic.cpp)
target_include_directories(card_test PRIVATE ${cppunit_INCLUDE_DIRS})
target_link_libraries(card_test PRIVATE ${cppunit_LIBRARIES})

add_executable(deck_test ${CMAKE_SOURCE_DIR}/test/deck_test.cpp ${CMAKE_SOURCE_DIR}/test/test_runner_basic.cpp)
target_include_directories(deck_test PRIVATE ${cppunit_INCLUDE_DIRS})
target_link_libraries(deck_test PRIVATE ${cppunit_LIBRARIES})

enable_testing()
add_test(NAME card_test COMMAND card_test)
add_test(NAME deck_test COMMAND deck_test)

# Set up installer
include(GNUInstallDirs)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include/fr/cards)
set(INSTALL_LIST
    ${INCLUDE_DIR}/card.hpp
    ${INCLUDE_DIR}/deck.hpp
    ${INCLUDE_DIR}/poker_deck_factory.hpp
    )

INSTALL(FILES
	${INSTALL_LIST}
	DESTINATION
	include/fr/cards
	)	

if (pybind11_FOUND)
   install(TARGETS fr_cards LIBRARY DESTINATION lib)
endif()
