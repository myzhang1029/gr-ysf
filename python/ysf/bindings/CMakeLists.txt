# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Check if there is C++ code at all
########################################################################
if(NOT ysf_sources)
    message(STATUS "No C++ sources... skipping python bindings")
    return()
endif(NOT ysf_sources)

########################################################################
# Check for pygccxml
########################################################################
gr_python_check_module_raw("pygccxml" "import pygccxml" PYGCCXML_FOUND)

include(GrPybind)

########################################################################
# Python Bindings
########################################################################

list(APPEND ysf_python_files python_bindings.cc)

gr_pybind_make_oot(ysf ../../.. gr::ysf "${ysf_python_files}")

# copy bindings extension for use in QA test module
add_custom_command(
    TARGET ysf_python
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:ysf_python>
            ${PROJECT_BINARY_DIR}/test_modules/gnuradio/ysf/)

install(
    TARGETS ysf_python
    DESTINATION ${GR_PYTHON_DIR}/gnuradio/ysf
    COMPONENT pythonapi)
