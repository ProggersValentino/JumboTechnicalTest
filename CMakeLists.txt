cmake_minimum_required(VERSION 3.20.0)
cmake_policy(SET CMP0140 NEW)

project(CMakeTemplate VERSION 0.1.0 LANGUAGES C CXX)

#set C++ version as a minimum
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(CACHE CMAKE_INSTALL_PREFIX PROPERTY VALUE "${CMAKE_CURRENT_SOURCE_DIR}/install/")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(AddLibraries)

add_external_libraries()

#Executables and libs 
set(MAIN_EXE "mainExecutable")
set(TESTS_EXE "testsExecutable")
set(SRC_LIB "srcLib")


add_subdirectory(src)
add_subdirectory(tests)

#installing executables to CMAKE_INSTALL_PREFIX
install(TARGETS ${MAIN_EXE} ${TESTS_EXE} ${SRC_LIB}
    RUNTIME DESTINATION bin
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)