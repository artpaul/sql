set (BOOST_ROOT_DIR "${PROJECT_SOURCE_DIR}/contrib/boost")

# filesystem

# set (SRCS_FILESYSTEM
#     "${BOOST_ROOT_DIR}/libs/filesystem/src/codecvt_error_category.cpp"
#     "${BOOST_ROOT_DIR}/libs/filesystem/src/directory.cpp"
#     "${BOOST_ROOT_DIR}/libs/filesystem/src/exception.cpp"
#     "${BOOST_ROOT_DIR}/libs/filesystem/src/operations.cpp"
#     "${BOOST_ROOT_DIR}/libs/filesystem/src/path.cpp"
#     "${BOOST_ROOT_DIR}/libs/filesystem/src/path_traits.cpp"
#     "${BOOST_ROOT_DIR}/libs/filesystem/src/portability.cpp"
#     "${BOOST_ROOT_DIR}/libs/filesystem/src/unique_path.cpp"
#     "${BOOST_ROOT_DIR}/libs/filesystem/src/utf8_codecvt_facet.cpp"
#     "${BOOST_ROOT_DIR}/libs/filesystem/src/windows_file_codecvt.cpp"
# )

# add_library (_boost_filesystem ${SRCS_FILESYSTEM})
# add_library (boost::filesystem ALIAS _boost_filesystem)
# target_include_directories (_boost_filesystem SYSTEM BEFORE PUBLIC ${BOOST_ROOT_DIR})

# if (OS_LINUX)
#     target_compile_definitions (_boost_filesystem PRIVATE
#         BOOST_FILESYSTEM_HAS_POSIX_AT_APIS=1
#     )
# endif ()


# headers-only
add_library (_boost_headers_only INTERFACE)
add_library (boost::headers_only ALIAS _boost_headers_only)
target_include_directories (_boost_headers_only SYSTEM BEFORE INTERFACE ${BOOST_ROOT_DIR})

target_compile_definitions (_boost_headers_only INTERFACE
  BOOST_ASIO_STANDALONE=1
  BOOST_ASIO_HAS_STD_INVOKE_RESULT=1 # Avoid using of deprecated in c++ > 17 std::result_of
  BOOST_TIMER_ENABLE_DEPRECATED=1 # wordnet-blast (enabled via USE_NLP) uses Boost legacy timer classes
)

# iostreams

set (SRCS_IOSTREAMS
    "${BOOST_ROOT_DIR}/libs/iostreams/src/file_descriptor.cpp"
    "${BOOST_ROOT_DIR}/libs/iostreams/src/gzip.cpp"
    "${BOOST_ROOT_DIR}/libs/iostreams/src/mapped_file.cpp"
    "${BOOST_ROOT_DIR}/libs/iostreams/src/zlib.cpp"
)

add_library (_boost_iostreams ${SRCS_IOSTREAMS})
add_library (boost::iostreams ALIAS _boost_iostreams)
target_include_directories (_boost_iostreams PRIVATE ${BOOST_ROOT_DIR})
#target_link_libraries (_boost_iostreams PRIVATE ch_contrib::zlib)
