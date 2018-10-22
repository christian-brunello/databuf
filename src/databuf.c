/*
 * databuf.c
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

static databuf_t *databuf_alloc(void)
{
  return malloc(sizeof(databuf_t));
}

static void databuf_free(databuf_t *self)
{
  free(self);
}

static int databuf_initialize(databuf_t *self, databuf_endianness_t endian)
{
  memset(self, 0x00, sizeof(databuf_t));

  self->endian = endian;

  return 0;
}

static void databuf_finalize(databuf_t *self)
{
  if(self)
    {
      if(self->data)
	free(self->data);

      memset(self, 0x00, sizeof(databuf_t));
    }
}

databuf_t *databuf_new(databuf_endianness_t endian)
{
  databuf_t *r;

  if((r = databuf_alloc()) != NULL)
    {
      if(databuf_initialize(r, endian) != 0)
	{
	  databuf_finalize(r);
	  r = NULL;
	}
    }

  return r;
}

void databuf_delete(databuf_t *self)
{
  databuf_finalize(self);
  databuf_free(self);
}

int databuf_get_data(databuf_t *self, void **rdata, size_t *rsize)
{
  if(self->size == 0)
    return EBADF;

  if((*rdata = malloc(self->end)) == NULL)
    return errno;

  memcpy(*rdata, self->data, self->end);

  *rsize = self->end;

  return 0;
}

int databuf_set_data(databuf_t *self, void *data, size_t size)
{
  void *p;

  if((p = malloc(size)) == NULL)
    return errno;

  memcpy(p, data, size);

  if(self->data)
    free(self->data);

  self->data = p;
  self->size = size;
  self->end = size;
  self->off = 0;

  return 0;
}
