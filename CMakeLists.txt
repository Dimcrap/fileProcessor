cmake_minimum_required(VERSION 3.15)

project(fileprocessor VERSION 1.0)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON )

set(SOURCES main.cpp app.cpp dirprocessor.cpp Threadpool.cpp allfilesWindow.cpp)
set(HEADERS app.h dirprocessor.h Threadpool.h allfilesWindow.h  )
set(TEST_SOURCES  dirprocessor.cpp test_dirprocessor.cpp Threadpool.cpp)

set(RAYLIB_INCLUDE_DIR "/usr/local/include/raylib.h")
set(RAYLIB_LIBRARY "/usr/local/lib/libraylib.so")
set(BOOST_INCLUDE_DIR "/home/unred/engineering/boost_1_85_0" 
CACHE PATH "/home/unred/engineering/boost/include")



add_executable(FP)

source_group("src" FILES ${HEADERS} ${SOURCES})

#find_package(BOOST_INCLUDE_DIR REQUIRED COMPONENTS signals2)
target_sources(FP PRIVATE ${HEADERS} ${SOURCES})
target_include_directories(FP PRIVATE ${BOOST_INCLUDE_DIR})
target_link_directories(FP PRIVATE ${RAYLIB_INCLUDE_DIR} )
target_link_libraries(FP PRIVATE ${RAYLIB_LIBRARY})


add_executable(test_dirprocessor)
target_sources(test_dirprocessor PRIVATE ${TEST_SOURCES})
target_include_directories(test_dirprocessor PRIVATE ${BOOST_INCLUDE_DIR})


if(NOT EXISTS ${BOOST_INCLUDE_DIR}/boost/version.hpp)
    message(WARNING "Boost not found at ${BOOST_INCLUDE_DIR}")
    message(WARNING "Set BOOSBOOST_INCLUDE_DIRT_ROOT to correct path with: cmake .. -DBOOST_ROOT=/your/path")
endif()