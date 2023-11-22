cmake_minimum_required(VERSION 3.12)
set (CMAKE_C_STANDARD 17)

project (nami)
enable_language (C ASM)

set (NAMI_SRC
    "src/string.c"
    "src/memory.c"
    "src/math.c"
    "src/numerics.c"

    "src/platform/posix_io.c"
    "src/platform/posix_memory.c"

    "src/platform/win64_io.c")

if (APPLE)
    set (NAMI_LIBS 
        "system")
else ()
    set (NAMI_LIBS "")
endif (APPLE)

add_library                (nami STATIC ${NAMI_SRC})
target_include_directories (nami PRIVATE "include" "src")
target_compile_definitions (nami PRIVATE NAMI_BUILD_LIB)
target_link_options        (nami PRIVATE -nostdlib)
target_link_libraries      (nami ${NAMI_LIBS})

project (test)

set (TEST_SRC
    "test/main.c")

add_executable             (test ${TEST_SRC})
target_include_directories (test PRIVATE "include")
target_link_libraries      (test nami)
target_link_options        (test PRIVATE -nostdlib)