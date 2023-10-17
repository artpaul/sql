add_library(iceberg)

target_include_directories(iceberg PUBLIC
  "${PROJECT_SOURCE_DIR}"
)

target_sources(iceberg PRIVATE
  "types/types.cc"
)
