cmake_minimum_required(VERSION 3.2)

PROJECT(dmfakeit)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()
ModuleSetWinCompilerFlags()

SET(DMFAKEIT_VERSION_MAJOR "1")
SET(DMFAKEIT_VERSION_MINOR "0")
SET(DMFAKEIT_VERSION_PATCH "1")
SET(DMFAKEIT_VERSION "${DMFAKEIT_VERSION_MAJOR}.${DMFAKEIT_VERSION_MINOR}.${DMFAKEIT_VERSION_PATCH}")

MESSAGE(STATUS "VERSION: ${DMFAKEIT_VERSION}")

OPTION(USE_DMFAKEIT "use dmfakeit" OFF)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/include/dmfakeit_config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/include/dmfakeit_config.h)

ModuleImportAll("thirdparty")
LibImport("dmfakeit_module" "src/dmfakeit_module")
ExeImport("test" "dmfakeit_module")

#ADD_CUSTOM_COMMAND(
#TARGET dmfakeittest
#PRE_BUILD
#COMMAND ${CMAKE_COMMAND} -E copy_if_different
#${CMAKE_CURRENT_SOURCE_DIR}/config/test.csv
#$<TARGET_FILE_DIR:dmfakeittest>
#)

#INSTALL(DIRECTORY include/ DESTINATION include)
#INSTALL(TARGETS dmfakeit
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib)

#SET(DMFAKEIT_LIBS "dmfakeit")
#MARK_AS_ADVANCED(${DMFAKEIT_LIBS})