CFLAGS = -I$(realpath include) -fPIC
OUTDIR = $(realpath obj)

interposelibc.so: interpose conf
	$(CC) -shared -fPIC -ldl -o $(OUTDIR)/$@ `find obj -name *.o`

.PHONY: interpose
interpose:
	$(MAKE) OUTDIR="$(OUTDIR)" \
			CFLAGS="$(CFLAGS)" \
	-C interpose

.PHONY: conf
conf:
	$(MAKE) OUTDIR="$(OUTDIR)" \
			CFLAGS="$(CFLAGS)" \
	-C conf

.PHONY: test
TEST=test
test:
	@echo build test
	$(MAKE) -C test
	@echo ---------- test interpose ----------
	LD_PRELOAD=`pwd`/obj/interposelibc.so `pwd`/test/$(TEST)

.PHONY: clean
clean:
	rm obj/interposelibc.so
	find . -name *.o | xargs rm
	$(MAKE) -C test clean