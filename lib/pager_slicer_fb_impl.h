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

#ifndef INCLUDED_YSF_PAGER_SLICER_FB_IMPL_H
#define INCLUDED_YSF_PAGER_SLICER_FB_IMPL_H

#include <gnuradio/ysf/pager_slicer_fb.h>

namespace gr {
  namespace ysf {

    class pager_slicer_fb_impl : public pager_slicer_fb
    {
     private:
        unsigned char slice(float sample);

        float d_alpha;      // DC removal time constant
        float d_beta;       // 1.0-d_alpha
        float d_avg;        // Average value for DC offset subtraction

     public:
      pager_slicer_fb_impl(float alpha);
      ~pager_slicer_fb_impl();

      void forecast (int noutput_items, gr_vector_int &ninput_items_required);

      int general_work(int noutput_items,
          gr_vector_int &ninput_items,
          gr_vector_const_void_star &input_items,
          gr_vector_void_star &output_items);
      float dc_offset() const { return d_avg; }
    };

  } // namespace ysf
} // namespace gr

#endif /* INCLUDED_YSF_PAGER_SLICER_FB_IMPL_H */
