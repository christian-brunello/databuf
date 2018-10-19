/*
 * test-seek.c
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

int test_seek(void)
{
  databuf_endianness_t endian;
  databuf_t *d1;
  uint32_t arr[] = {0x00000001, 0x00000002, 0x00000003, 0x00000004};

#if WORDS_BIGENDIAN
  endian = DATABUF_ENDIANNESS_BIG;
#else
  endian = DATABUF_ENDIANNESS_LITTLE;
#endif

  if((d1 = databuf_new(endian)) == NULL)
    return -1;

  if(databuf_set_data(d1, arr, sizeof(arr)) != 0)
    return -1;

  if(databuf_seek(d1, 0, SEEK_SET) != 0)
    return -1;

  if(databuf_seek(d1, 0, SEEK_END) != sizeof(arr))
    return -1;

  if(databuf_seek(d1, -sizeof(arr), SEEK_END) != 0)
    return -1;

  databuf_delete(d1);

  return 0;
}

int main(int argc, char *argv[])
{
  if(test_seek() != 0)
    return EXIT_FAILURE;

  return EXIT_SUCCESS;
}

