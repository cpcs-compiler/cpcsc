set (SRCS
    codegen.c
    color.c
    error.c
    main.c
    node_dump.c
    node.c
    utils.c
)

if (WIN32)
    ENABLE_LANGUAGE(RC)
    set(SOURCES icon.rc ${SOURCES})
endif(WIN32)

bison_target (parser parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.c)
flex_target (scanner scanner.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.c)

add_flex_bison_dependency (scanner parser)

add_executable (cpcsc
    ${SRCS}
    ${BISON_parser_OUTPUTS}
    ${FLEX_scanner_OUTPUTS}
)

target_link_libraries (cpcsc PRIVATE ${llvm_libs})