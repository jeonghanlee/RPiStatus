#
#  Copyright (c) 2020  Jeong Han Lee
#
#  The program is free software: you can redistribute
#  it and/or modify it under the terms of the GNU General Public License
#  as published by the Free Software Foundation, either version 2 of the
#  License, or any newer version.
#
#  This program is distributed in the hope that it will be useful, but WITHOUT
#  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
#  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
#  more details.
#
#  You should have received a copy of the GNU General Public License along with
#  this program. If not, see https://www.gnu.org/licenses/gpl-2.0.txt
#
# 
# Author  : Jeong Han Lee
# email   : jeonghan.lee@gmail.com
# Date    : Monday, November  2 21:48:42 PST 2020
# version : 0.0.1
#


TOP:=$(CURDIR)

ifeq ($(DESTDIR),)
    DESTDIR := $(TOP)/bin
endif

INCPATH:=$(TOP)/include
SRCPATH:=$(TOP)/src

VPATH = $(SRCPATH)

CFLAGS += -I $(INCPATH)

DS18B20_SRCS := ds18b20.c
THERMAL_SRCS := thermalzone.c

DS18B20_OBJS :=$(addsuffix .o,$(basename $(DS18B20_SRCS)))
THERMAL_OBJS :=$(addsuffix .o,$(basename $(THERMAL_SRCS)))

CFLAGS := -Wall -g
LDFLAGS := 

BINS := 1WireBin ThermalZone

build: $(BINS)

1WireBin: $(DS18B20_OBJS)
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@

ThermalZone: $(THERMAL_OBJS)
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@

.c.o :
	$(COMPILE.c) $(OUTPUT_OPTION) $<

install: $(BINS) 
	install -d $(DESTDIR)/
	install -m 755 $^ $(DESTDIR)/

.PHONY: distclean clean build install

clean:
	@$(RM) $(BIN_OBJS)

distclean: clean
	@$(RM) $(BINS)
	@$(RM) -r $(DESTDIR)

PRINT.%:
	@echo $* = $($*)
	@echo $*\'s origin is $(origin $*)
