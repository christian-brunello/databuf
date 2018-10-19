/*
 * endianness.c
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

#include "internals.h"

databuf_endianness_t databuf_native_endianness(void)
{
#ifdef WORDS_BIGENDIAN
  return DATABUF_ENDIANNESS_BIG;
#else
  return DATABUF_ENDIANNESS_LITTLE;
#endif /* WORDS_BIGENDIAN */
}

static void swap_bytes(void *dst, const void *src, size_t size)
{
  uint8_t *dstp;
  const uint8_t *srcp;

  dstp = (uint8_t*) dst;
  srcp = (uint8_t*) src;

  while(size > 0)
    *dstp++ = srcp[--size];
}

void * databuf_to_endian(void *dst, const void *src, size_t size, databuf_endianness_t endianness)
{
  if(databuf_native_endianness() == endianness)
    memcpy(dst, src, size);
  else
    swap_bytes(dst, src, size);

  return dst;
}
