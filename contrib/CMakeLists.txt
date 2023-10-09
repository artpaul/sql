add_subdirectory(avro)
add_subdirectory(boost)
add_subdirectory(cpp-httplib)
add_subdirectory(cxxopts)
add_subdirectory(fmt)
add_subdirectory(libpg_query)
add_subdirectory(snappy)
add_subdirectory(xxhash)

# Tests.
if(BUILD_TESTS)
    add_subdirectory(gtest)
    add_subdirectory(benchmark)
endif()
