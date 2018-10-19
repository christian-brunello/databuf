/*
 * internals.h
 * This file is part of databuf
 *
 * Copyright (C) 2018 Christian Brunello
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Library General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public License
 *  along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DATABUF_INTERNALS_H_INCLUDED
#define DATABUF_INTERNALS_H_INCLUDED

#if HAVE_CONFIG_H
# include "config.h"
#endif /* HAVE_CONFIG_H */

#include <databuf.h>

#include <string.h>
#include <errno.h>

struct databuf
{
  databuf_endianness_t endian;
  uint8_t *data;
  size_t size;
  size_t end;
  size_t off;
};

void * databuf_to_endian(void *dst, const void *src, size_t size, databuf_endianness_t endianness);
#define databuf_from_endian databuf_to_endian


#endif /* DATABUF_INTERNALS_H_INCLUDED */

