cmake_minimum_required(VERSION 3.12)
set (CMAKE_C_STANDARD 17)

project (nami)

set (NAMI_SRC
    "src/string.c"
    "src/win64_io.c")

add_library                (nami STATIC ${NAMI_SRC})
target_include_directories (nami PRIVATE "include")
target_compile_definitions (nami PRIVATE NAMI_BUILD_LIB)
target_link_options        (nami PRIVATE -nostdlib)

project (test)

set (TEST_SRC
    "test/main.c")

add_executable             (test ${TEST_SRC})
target_include_directories (test PRIVATE "include")
target_link_libraries      (test nami)
target_link_options        (test PRIVATE -nostdlib)