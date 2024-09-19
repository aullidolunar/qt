# data/unix

target_include_directories(${BIN_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

set(DATA_SOURCES ${DATA_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/unix_resource.qrc PARENT_SCOPE)
