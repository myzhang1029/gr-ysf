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
/* BINDTOOL_HEADER_FILE(dch_sink_b.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(273348c0c75314734525e49f8d0df992)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/ysf/dch_sink_b.h>
// pydoc.h is automatically generated in the build directory
#include <dch_sink_b_pydoc.h>

void bind_dch_sink_b(py::module& m)
{

    using dch_sink_b = gr::ysf::dch_sink_b;


    py::class_<dch_sink_b, gr::block, gr::basic_block, std::shared_ptr<dch_sink_b>>(
        m, "dch_sink_b", D(dch_sink_b))

        .def(py::init(&dch_sink_b::make), D(dch_sink_b, make))


        ;
}
