CXX=g++
LISTA = 2006 2007 2008 2009 2010 2011 2012 2013 2014 2015 2016 2017-stara 2017-nowa 2018-stara 2018-nowa

all: $(LISTA) licencja

$(LISTA):
	$(MAKE) -C $@
.PHONY: $(LISTA)

licencja:
	@echo Zapoznaj się z licencją GNU GPL V3
