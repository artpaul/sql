add_library(miniocpp STATIC ${SRCS})

target_include_directories(miniocpp PRIVATE
  "include"
)

target_sources(miniocpp
  "src/args.cc"
  "src/baseclient.cc"
  "src/client.cc"
  "src/http.cc"
  "src/request.cc"
  "src/response.cc"
  "src/select.cc"
  "src/signer.cc"
  "src/types.cc"
  "src/utils.cc"
)

target_link_libraries(miniocpp PUBLIC
  contrib-httplib
)
