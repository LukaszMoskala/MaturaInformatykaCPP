CXX=g++
LISTA = 2005 2006 2007 2008 2009 2010 2011 2012 2013 2014 2015-nowa 2015-stara 2016-stara 2016-nowa 2017-stara 2017-nowa 2018-stara 2018-nowa

#Puste rozszerzenie dla GNU/Linux
EXTENSION=
#Dla windowsa .exe
ifeq ($(OS),Windows_NT)
    EXTENSION=.exe
endif

all: $(LISTA) licencja

$(LISTA):
	$(MAKE) -C $@
.PHONY: $(LISTA)

clean:
	rm -f 20*/zad?.o
clean-bin:
	rm -f 20*/zad?$(EXTENSION)
licencja:
	@echo Zapoznaj się z licencją GNU GPL V3
