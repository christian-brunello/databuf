/*
 * databuf.h
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

#ifndef DATABUF_H_INCLUDED
#define DATABUF_H_INCLUDED

#include "internals.h"

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum databuf_endianness_t
{
  DATABUF_ENDIANNESS_BIG,
  DATABUF_ENDIANNESS_LITTLE
} databuf_endianness_t;

databuf_endianness_t databuf_native_endianness(void);

typedef struct databuf databuf_t;


databuf_t *databuf_new(databuf_endianness_t endian);
void databuf_delete(databuf_t *self);

int databuf_seek(databuf_t *self, off_t off, int whence);

int databuf_get_data(databuf_t *self, void **rdata, size_t *rsize);
int databuf_set_data(databuf_t *self, void *data, size_t size);

int databuf_write(databuf_t *self, void *buf, size_t size);
int databuf_write_array(databuf_t *self, void *buf, size_t size, size_t count);

int databuf_read(databuf_t *self, void *buf, size_t size);
int databuf_read_array(databuf_t *self, void *buf, size_t size, size_t count);
#endif /* DATABUF_H_INCLUDED */

