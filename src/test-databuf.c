/*
 * test-databuf.c
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

int test_databuf(void)
{
  databuf_t d1;
  databuf_t *d2;

  if(databuf_initialize(&d1, DATABUF_ENDIANNESS_BIG) != 0)
    return -1;

  if((d2 = databuf_new(DATABUF_ENDIANNESS_LITTLE)) == NULL)
    return -1;

  databuf_finalize(&d1);
  databuf_delete(d2);

  return 0;
}

int main(int argc, char *argv[])
{
  if(test_databuf() != 0)
    return EXIT_FAILURE;

  return EXIT_SUCCESS;
}

