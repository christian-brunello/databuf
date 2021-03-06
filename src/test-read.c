/*
 * test-read.c
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

int test_read(void)
{
  databuf_endianness_t endian;
  databuf_t *d1;
  uint16_t val = 0x0102;
  uint16_t val2 = 0x0304;
  uint16_t val3;
  uint16_t val4;

#if WORDS_BIGENDIAN
  endian = DATABUF_ENDIANNESS_LITTLE;
#else
  endian = DATABUF_ENDIANNESS_BIG;
#endif

  if((d1 = databuf_new(endian)) == NULL)
    return -1;

  if(databuf_write(d1, &val, sizeof(uint16_t)) != 0)
    return -1;

  if(databuf_write(d1, &val2, sizeof(uint16_t)) != 0)
    return -1;

  if(databuf_seek(d1, 0, SEEK_SET) != 0)
    return -1;

  if(databuf_read(d1, &val3, sizeof(uint16_t)) != 0)
    return -1;

  if(databuf_read(d1, &val4, sizeof(uint16_t)) != 0)
    return -1;

  if(val != val3 || val2 != val4)
    return -1;

  databuf_delete(d1);

  return 0;
}

int main(int argc, char *argv[])
{
  if(test_read() != 0)
    return EXIT_FAILURE;

  return EXIT_SUCCESS;
}

