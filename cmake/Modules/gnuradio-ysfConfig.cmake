find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_YSF gnuradio-ysf)

FIND_PATH(
    GR_YSF_INCLUDE_DIRS
    NAMES gnuradio/ysf/api.h
    HINTS $ENV{YSF_DIR}/include
        ${PC_YSF_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_YSF_LIBRARIES
    NAMES gnuradio-ysf
    HINTS $ENV{YSF_DIR}/lib
        ${PC_YSF_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-ysfTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_YSF DEFAULT_MSG GR_YSF_LIBRARIES GR_YSF_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_YSF_LIBRARIES GR_YSF_INCLUDE_DIRS)
