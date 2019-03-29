CXX=g++
LISTA = 2006 2007 2008 2009 2010 2011 2012 2013 2014 2015 2016 2017 2018

all: $(LISTA) licencja

$(LISTA):
	$(MAKE) -C $@
.PHONY: $(LISTA)

licencja:
	@echo Zapoznaj się z licencją GNU GPL V3
