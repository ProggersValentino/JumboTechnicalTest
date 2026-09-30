set(SRC_FILES
    "base.h"
    "base.cpp"
)

add_library(${SRC_LIB} STATIC ${SRC_FILES})

add_executable(${MAIN_EXE} main.cpp)

target_link_libraries(${MAIN_EXE} PRIVATE 
    ${SRC_LIB}
)