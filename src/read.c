/*
 * read.c
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

int databuf_read(databuf_t *self, void *buf, size_t size)
{
  if(self->end - self->off < size)
    return EIO;

  databuf_from_endian(buf, self->data + self->off, size, self->endian);

  self->off += size;

  return 0;
}

int databuf_read_array(databuf_t *self, void *buf, size_t size, size_t count)
{
  size_t i;
  int r;

  for(i = 0; i < count; i++)
    if((r = databuf_read(self, buf + size * i, size)) != 0)
      return r;

  return 0;
}
