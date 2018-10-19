/*
 * write.c
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

#define BLOCKSIZE 0x40

int databuf_write(databuf_t *self, void *buf, size_t size)
{
  if(self->size - self->off < size)
    {
      size_t size;
      uint8_t *data;

      size = self->size + BLOCKSIZE;
      if((data = malloc(size)) == NULL)
	return errno;

      if(self->data)
	{
	  memcpy(data, self->data, self->size);
	  free(self->data);
	}

      self->data = data;
      self->size = size;
    }

  databuf_to_endian(self->data + self->off, buf, size, self->endian);

  self->off += size;

  if(self->off > self->end)
    self->end = self->off;

  return 0;
}

int databuf_write_array(databuf_t *self, void *buf, size_t size, size_t count)
{
  size_t i;
  int r;

  for(i = 0; i < count; i++)
    if((r = databuf_write(self, buf + size * i, size)) != 0)
      return r;

  return 0;
}
