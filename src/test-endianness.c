/*
 * test-endianness.c
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

#include <string.h>
#include "internals.h"

int test_swap(void)
{
  uint8_t b1[100];
  uint8_t b2[100];

#if WORDS_BIGENDIAN
  databuf_to_endian(b1, b2, 0, DATABUF_ENDIANNESS_LITTLE);
#else
  databuf_to_endian(b1, b2, 0, DATABUF_ENDIANNESS_BIG);
#endif

  return 1;
}

int test_endian(void)
{
  uint32_t a;
  uint32_t b;
  void *p;

  a = 0x01020304;

#if WORDS_BIGENDIAN
  if(*((uint8_t*) &a) != 0x01)
    return 0;

  if(databuf_native_endianness() != DATABUF_ENDIANNESS_BIG)
    return 0;

  p = databuf_to_endian(&b, &a, sizeof(uint32_t), DATABUF_ENDIANNESS_BIG);

  if(memcmp(&a, &b, sizeof(uint32_t)) != 0)
    return 0;

  p = databuf_to_endian(&b, &a, sizeof(uint32_t), DATABUF_ENDIANNESS_LITTLE);

  if(memcmp(&a, &b, sizeof(uint32_t)) == 0)
    return 0;
#else
  if(*((uint8_t*) &a) != 0x04)
    return 0;

  if(databuf_native_endianness() != DATABUF_ENDIANNESS_LITTLE)
    return 0;

  p = databuf_to_endian(&b, &a, sizeof(uint32_t), DATABUF_ENDIANNESS_LITTLE);

  if(memcmp(&a, &b, sizeof(uint32_t)) != 0)
    return 0;

  p = databuf_to_endian(&b, &a, sizeof(uint32_t), DATABUF_ENDIANNESS_BIG);

  if(memcmp(&a, &b, sizeof(uint32_t)) == 0)
    return 0;
#endif /* WORDS_BIGENDIAN */

  return 1;
}

int main(int argc, char *argv[])
{
  if(!test_swap() 
     || !test_endian())
    return EXIT_FAILURE;

  return EXIT_SUCCESS;
}

