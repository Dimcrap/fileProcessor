cmake_minimum_required(VERSION 3.15)

project(fileprocessor VERSION 1.0)
set(SOURCES main.cpp app.cpp dirprocessor.cpp Threadpool.cpp allfilesWindow.cpp)
set(HEADERS app.h dirprocessor.h Threadpool.h allfilesWindow.h  )
set(RAYLIB_INCLUDE_DIR "/usr/local/include/raylib.h")
set(RAYLIB_LIBRARY "/usr/local/lib/libraylib.so")
set(BOOST_INCLUDE_DIR "/home/unred/engineering/boost_1_85_0" 
    CACHE PATH "Path to Boost installation")

add_executable(FP)

source_group("src" FILES ${HEADERS} ${SOURCES})
target_sources(FP PRIVATE ${HEADERS} ${SOURCES})
target_include_directories(FP PRIVATE ${BOOST_INCLUDE_DIR})
target_link_directories(FP PRIVATE ${RAYLIB_INCLUDE_DIR} )
target_link_libraries(FP PRIVATE ${RAYLIB_LIBRARY})

