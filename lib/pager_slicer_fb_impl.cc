/* -*- c++ -*- */
/*
 * Copyright 2004,2006,2007 Free Software Foundation, Inc.
 * Copyright 2024 Zhang Maiyun <me@maiyun.me>
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "pager_slicer_fb_impl.h"

namespace gr {
  namespace ysf {

    pager_slicer_fb::sptr
    pager_slicer_fb::make(float alpha)
    {
      return gnuradio::get_initial_sptr (new pager_slicer_fb_impl(alpha));
    }

    /*
     * The private constructor
     */
    pager_slicer_fb_impl::pager_slicer_fb_impl(float alpha)
      : gr::block("pager_slicer_fb",
              gr::io_signature::make(1, 1, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(unsigned char))),
        d_alpha(alpha)
    {
        d_beta = 1.0 - d_alpha;
        d_avg = 0.0;
    }

    /*
     * Our virtual destructor.
     */
    pager_slicer_fb_impl::~pager_slicer_fb_impl()
    {
    }

    void pager_slicer_fb_impl::forecast (int noutput_items, gr_vector_int &ninput_items_required)
    {
        ninput_items_required[0] = noutput_items;
    }

    // Tracks average, minimum, and peak, then converts input into one of:
    //
    // [0, 1, 2, 3]
    unsigned char pager_slicer_fb_impl::slice(float sample)
    {
        unsigned char decision;

        // Update DC level and remove
        d_avg = d_avg*d_beta+sample*d_alpha;
        sample -= d_avg;

        if (sample > 0) {
            if (sample > 2.0)
                decision = 3;
            else
                decision = 2;
        }
        else {
            if (sample < -2.0)
                decision = 0;
            else
                decision = 1;
        }

        return decision;
    }

    int pager_slicer_fb_impl::general_work(int noutput_items,
                       gr_vector_int &ninput_items,
                       gr_vector_const_void_star &input_items,
                       gr_vector_void_star &output_items)
    {
        float *iptr = (float *) input_items[0];
        unsigned char *optr = (unsigned char *) output_items[0];

        for (int i = 0; i < noutput_items; i++) {
            optr[i] = slice(iptr[i]);
        }

        consume_each(noutput_items);

        return noutput_items;
    }
  } /* namespace ysf */
} /* namespace gr */
