set(sources
    src/string.cpp
)

set(exe_sources
    src/main.cpp
    ${sources}
)

set(headers
    include/technikum/string.h
    include/technikum/unique_ptr.h
)

set(test_sources
    src/main.cpp
    src/string_test.cpp
    src/unique_ptr_test.cpp
)
