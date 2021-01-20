OBJS = execve.o \
	   fork.o

OBJS += interposelibc.o \
		original_fp.o

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(OUTDIR)/$@

all: $(OBJS)