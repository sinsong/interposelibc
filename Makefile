export CFLAGS = -I$(realpath include) -fPIC
export OUTDIR = $(realpath .)/obj
# 没有 obj 目录的话，$(realpath obj) 未空

.PHONY: all
all: interposelibc.so

interposelibc.so: interpose conf
	$(CC) -shared -fPIC -ldl -o $(OUTDIR)/$@ `find obj -name *.o`

.PHONY: interpose
interpose:
	if [ ! -d obj ]; then mkdir obj; fi
	$(MAKE) -C interpose

.PHONY: conf
conf:
	$(MAKE) -C conf

.PHONY: test
TEST=test
test:
	@echo build test
	$(MAKE) -C test
	@echo ---------- test interpose ----------
	LD_PRELOAD=`pwd`/obj/interposelibc.so `pwd`/test/$(TEST)

.PHONY: clean
clean:
	# rm obj/interposelibc.so
	# find . -name *.o | xargs rm
	rm -rf obj
	$(MAKE) -C test clean