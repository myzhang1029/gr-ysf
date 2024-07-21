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


#ifndef INCLUDED_YSF_PAGER_SLICER_FB_H
#define INCLUDED_YSF_PAGER_SLICER_FB_H

#include <gnuradio/ysf/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace ysf {

    /*!
     * \brief <+description of block+>
     * \ingroup ysf
     *
     */
    class YSF_API pager_slicer_fb : virtual public gr::block
    {
     public:
      typedef std::shared_ptr<pager_slicer_fb> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of ysf::pager_slicer_fb.
       *
       * To avoid accidental use of raw pointers, ysf::pager_slicer_fb's
       * constructor is in a private implementation
       * class. ysf::pager_slicer_fb::make is the public interface for
       * creating new instances.
       */
      static sptr make(float alpha);
    };

  } // namespace ysf
} // namespace gr

#endif /* INCLUDED_YSF_PAGER_SLICER_FB_H */
