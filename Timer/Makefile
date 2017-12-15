TARGET  = Timer
# Only *.cpp
SOURCES = main.cpp kbhit.cpp Timer.cpp
HEADERS = kbhit.h Timer.h

OUTDIR  = tmp

VARS = TARGET="$(TARGET)" SOURCES="$(SOURCES)" HEADERS="$(HEADERS)"

##############################################################

all:
	@echo Avalable targets for MS Windows and Visual C++ are:
	@echo 1} win_debug [win_debug_clean]
	@echo 2} win_release [win_release_clean]
	@echo ---
	@echo Avalable targets for GNU/Linux and GCC are:
	@echo 1} unx_debug [unx_debug_clean]
	@echo 2} unx_release [unx_release_clean]

##### Windows #################################################

win_debug:
	$(MAKE) -f Makefile.win debug   $(VARS) OUTDIR="$(OUTDIR)/$@"

win_debug_clean:
	$(MAKE) -f Makefile.win clean $(VARS) OUTDIR="$(OUTDIR)/$(@:_clean=)"

win_release:
	$(MAKE) -f Makefile.win release $(VARS) OUTDIR="$(OUTDIR)/$@"

win_release_clean:
	$(MAKE) -f Makefile.win clean $(VARS) OUTDIR="$(OUTDIR)/$(@:_clean=)"

##### Linux ###################################################

unx_debug:
	$(MAKE) -f Makefile.unx debug   $(VARS) OUTDIR="$(OUTDIR)/$@"

unx_debug_clean:
	$(MAKE) -f Makefile.unx clean $(VARS) OUTDIR="$(OUTDIR)/$(@:_clean=)"

unx_release:
	$(MAKE) -f Makefile.unx release $(VARS) OUTDIR="$(OUTDIR)/$@"

unx_release_clean:
	$(MAKE) -f Makefile.unx clean $(VARS) OUTDIR="$(OUTDIR)/$(@:_clean=)"
