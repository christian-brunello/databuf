/*
 * seek.c
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

int databuf_seek(databuf_t *self, off_t off, int whence)
{
  switch(whence)
    {
    case SEEK_SET:
      if(off > self->end)
	{
	  errno = EINVAL;
	  return -1;
	}
      self->off = off;
      break;
    case SEEK_CUR:
      if(self->off + off > self->end)
	{
	  errno = EINVAL;
	  return -1;
	}
      self->off += off;
      break;
    case SEEK_END:
      if(self->end + off > self->end)
	{
	  errno = EINVAL;
	  return -1;
	}
      self->off = self->end + off;
      break;
    default:
      errno = EINVAL;
      return -1;
    }

  return self->off;
}
