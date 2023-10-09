add_library(pg_query STATIC)

set_target_properties(pg_query PROPERTIES LINKER_LANGUAGE C)
set_target_properties(pg_query PROPERTIES C_STANDARD 11)

target_include_directories(pg_query
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
    PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/protobuf"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/postgres/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/vendor"
)

set(PG_QUERY_SOURCE
    "src/pg_query.c"
    "src/pg_query_deparse.c"
    "src/pg_query_fingerprint.c"
    "src/pg_query_json_plpgsql.c"
    "src/pg_query_normalize.c"
    "src/pg_query_outfuncs_json.c"
    "src/pg_query_outfuncs_protobuf.c"
    "src/pg_query_parse.c"
    "src/pg_query_parse_plpgsql.c"
    "src/pg_query_readfuncs_protobuf.c"
    "src/pg_query_scan.c"
    "src/pg_query_split.c"
    "src/postgres_deparse.c"
    "src/postgres/src_backend_catalog_namespace.c"
    "src/postgres/src_backend_catalog_pg_proc.c"
    "src/postgres/src_backend_commands_define.c"
    "src/postgres/src_backend_nodes_bitmapset.c"
    "src/postgres/src_backend_nodes_copyfuncs.c"
    "src/postgres/src_backend_nodes_equalfuncs.c"
    "src/postgres/src_backend_nodes_extensible.c"
    "src/postgres/src_backend_nodes_list.c"
    "src/postgres/src_backend_nodes_makefuncs.c"
    "src/postgres/src_backend_nodes_nodeFuncs.c"
    "src/postgres/src_backend_nodes_value.c"
    "src/postgres/src_backend_parser_gram.c"
    "src/postgres/src_backend_parser_parser.c"
    "src/postgres/src_backend_parser_scan.c"
    "src/postgres/src_backend_parser_scansup.c"
    "src/postgres/src_backend_postmaster_postmaster.c"
    "src/postgres/src_backend_storage_ipc_ipc.c"
    "src/postgres/src_backend_storage_lmgr_s_lock.c"
    "src/postgres/src_backend_tcop_postgres.c"
    "src/postgres/src_backend_utils_activity_pgstat_database.c"
    "src/postgres/src_backend_utils_adt_datum.c"
    "src/postgres/src_backend_utils_adt_expandeddatum.c"
    "src/postgres/src_backend_utils_adt_format_type.c"
    "src/postgres/src_backend_utils_adt_ruleutils.c"
    "src/postgres/src_backend_utils_error_assert.c"
    "src/postgres/src_backend_utils_error_elog.c"
    "src/postgres/src_backend_utils_fmgr_fmgr.c"
    "src/postgres/src_backend_utils_hash_dynahash.c"
    "src/postgres/src_backend_utils_init_globals.c"
    "src/postgres/src_backend_utils_mb_mbutils.c"
    "src/postgres/src_backend_utils_misc_guc.c"
    "src/postgres/src_backend_utils_mmgr_aset.c"
    "src/postgres/src_backend_utils_mmgr_mcxt.c"
    "src/postgres/src_common_encnames.c"
    "src/postgres/src_common_hashfn.c"
    "src/postgres/src_common_keywords.c"
    "src/postgres/src_common_kwlookup.c"
    "src/postgres/src_common_pg_prng.c"
    "src/postgres/src_common_psprintf.c"
    "src/postgres/src_common_string.c"
    "src/postgres/src_common_stringinfo.c"
    "src/postgres/src_common_wchar.c"
    "src/postgres/src_pl_plpgsql_src_pl_comp.c"
    "src/postgres/src_pl_plpgsql_src_pl_funcs.c"
    "src/postgres/src_pl_plpgsql_src_pl_gram.c"
    "src/postgres/src_pl_plpgsql_src_pl_handler.c"
    "src/postgres/src_pl_plpgsql_src_pl_scanner.c"
    "src/postgres/src_port_pg_bitutils.c"
    "src/postgres/src_port_pgsleep.c"
    "src/postgres/src_port_pgstrcasecmp.c"
    "src/postgres/src_port_qsort.c"
    "src/postgres/src_port_snprintf.c"
    "src/postgres/src_port_strerror.c"
    "src/postgres/src_port_strnlen.c"
    "vendor/protobuf-c/protobuf-c.c"
    "vendor/xxhash/xxhash.c"
    "protobuf/pg_query.pb-c.c"
)

set_source_files_properties(${PG_QUERY_SOURCE} PROPERTIES COMPILE_FLAGS
    "-Wno-unused-function -Wno-unused-value -Wno-unused-variable -fno-strict-aliasing -fwrapv -Wno-deprecated-non-prototype -Wno-macro-redefined"
)

target_compile_definitions(pg_query PRIVATE
    -DHAVE_STRCHRNUL
)

target_sources(pg_query PRIVATE
    ${PG_QUERY_SOURCE}
)
