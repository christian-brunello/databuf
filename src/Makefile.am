AM_CPPFLAGS = -I$(top_srcdir)/src
AM_CFLAGS =
AM_LDFLAGS =

lib_LTLIBRARIES = libdatabuf.la

include_HEADERS = databuf.h
libdatabuf_la_SOURCES = databuf.h internals.h endianness.c databuf.c write.c read.c seek.c

check_PROGRAMS = test-endianness test-databuf test-write test-read test-seek

test_endianness_SOURCES = test-endianness.c
test_endianness_LDADD = -ldatabuf

test_databuf_SOURCES = test-endianness.c
test_databuf_LDADD = -ldatabuf

test_write_SOURCES = test-write.c
test_write_LDADD = -ldatabuf

test_read_SOURCES = test-read.c
test_read_LDADD = -ldatabuf

test_seek_SOURCES = test-seek.c
test_seek_LDADD = -ldatabuf

TESTS = $(check_PROGRAMS)



