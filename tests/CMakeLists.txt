set(MainTests "dtest.cc")

add_executable(${TESTS_EXE} ${MainTests})
target_link_libraries(${TESTS_EXE} PRIVATE 
    Catch2::Catch2WithMain
    ${SRC_LIB}
)

include(CTest)
include(Catch)
enable_testing()
catch_discover_tests(${TESTS_EXE})
