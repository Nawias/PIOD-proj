cmake_minimum_required(VERSION 3.21)
project(programowanie)

set(CMAKE_CXX_STANDARD 14)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB glib-2.0)
pkg_check_modules(GOBJECT gobject-2.0)



if (GLIB_FOUND)
    message(Found glib-2.0)
endif (GLIB_FOUND)



add_executable(programowanie main.cpp FinalClasses/GobjectCat.cpp FinalClasses/GobjectCat.h FinalClasses/CppCat.cpp FinalClasses/CppCat.h)

target_include_directories(programowanie PRIVATE ${GLIB_INCLUDE_DIRS})
include_directories(${GLIB_INCLUDE_DIRS})
target_link_libraries(programowanie ${GLIB_LIBRARIES})
target_include_directories(programowanie PRIVATE ${GOBJECT_INCLUDE_DIRS})
include_directories(${GOBJECT_INCLUDE_DIRS})
target_link_libraries(programowanie ${GOBJECT_LIBRARIES})