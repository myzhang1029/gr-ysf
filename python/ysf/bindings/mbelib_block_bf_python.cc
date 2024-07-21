/*
 * Copyright 2024 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(1)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(mbelib_block_bf.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(bc2f56a3224fae3c3ff19271da0e4ca0)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/ysf/mbelib_block_bf.h>
// pydoc.h is automatically generated in the build directory
#include <mbelib_block_bf_pydoc.h>

void bind_mbelib_block_bf(py::module& m)
{

    using mbelib_block_bf = gr::ysf::mbelib_block_bf;


    py::class_<mbelib_block_bf,
               gr::block,
               gr::basic_block,
               std::shared_ptr<mbelib_block_bf>>(m, "mbelib_block_bf", D(mbelib_block_bf))

        .def(py::init(&mbelib_block_bf::make), py::arg("codec"), D(mbelib_block_bf, make))


        ;
}
