CC = gcc
CFLAGS = -Wall -g -fprofile-arcs -ftest-coverage
CLIBS = -lcunit
OBJS = fact.o fact_test.o
SRCS = fact.c fact_test.c


%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

utest:
	$(CC) $(CFLAG) $(SRCS) -o utest $^ $(CLIBS)

depend:
	makedepend -- $(CFLAGS) -- $(SRCS) -I/usr/lib/gcc/x86_64-unknown-linux-gnu/4.9.2/include

clean:
	rm -rf utest
# DO NOT DELETE

fact.o: /usr/include/stdio.h /usr/include/features.h
fact.o: /usr/include/stdc-predef.h /usr/include/sys/cdefs.h
fact.o: /usr/include/bits/wordsize.h /usr/include/gnu/stubs.h
fact.o: /usr/lib/gcc/x86_64-unknown-linux-gnu/4.9.2/include/stddef.h
fact.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
fact.o: /usr/include/libio.h /usr/include/_G_config.h /usr/include/wchar.h
fact.o: /usr/lib/gcc/x86_64-unknown-linux-gnu/4.9.2/include/stdarg.h
fact.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
fact.o: /usr/include/stdlib.h /usr/include/bits/waitflags.h
fact.o: /usr/include/bits/waitstatus.h /usr/include/endian.h
fact.o: /usr/include/bits/endian.h /usr/include/bits/byteswap.h
fact.o: /usr/include/bits/byteswap-16.h /usr/include/sys/types.h
fact.o: /usr/include/time.h /usr/include/sys/select.h
fact.o: /usr/include/bits/select.h /usr/include/bits/sigset.h
fact.o: /usr/include/bits/time.h /usr/include/sys/sysmacros.h
fact.o: /usr/include/bits/pthreadtypes.h /usr/include/alloca.h
fact.o: /usr/include/bits/stdlib-float.h fact.h
fact_test.o: fact.h /usr/include/CUnit/CUnit.h /usr/include/string.h
fact_test.o: /usr/include/features.h /usr/include/stdc-predef.h
fact_test.o: /usr/include/sys/cdefs.h /usr/include/bits/wordsize.h
fact_test.o: /usr/include/gnu/stubs.h
fact_test.o: /usr/lib/gcc/x86_64-unknown-linux-gnu/4.9.2/include/stddef.h
fact_test.o: /usr/include/xlocale.h /usr/include/math.h
fact_test.o: /usr/include/bits/huge_val.h /usr/include/bits/huge_valf.h
fact_test.o: /usr/include/bits/huge_vall.h /usr/include/bits/inf.h
fact_test.o: /usr/include/bits/nan.h /usr/include/bits/mathdef.h
fact_test.o: /usr/include/bits/mathcalls.h /usr/include/CUnit/CUError.h
fact_test.o: /usr/include/errno.h /usr/include/bits/errno.h
fact_test.o: /usr/include/linux/errno.h /usr/include/asm/errno.h
fact_test.o: /usr/include/asm-generic/errno.h
fact_test.o: /usr/include/asm-generic/errno-base.h /usr/include/CUnit/CUnit.h
fact_test.o: /usr/include/CUnit/TestDB.h /usr/include/setjmp.h
fact_test.o: /usr/include/bits/setjmp.h /usr/include/bits/sigset.h
fact_test.o: /usr/include/CUnit/TestRun.h /usr/include/stdio.h
fact_test.o: /usr/include/bits/types.h /usr/include/bits/typesizes.h
fact_test.o: /usr/include/libio.h /usr/include/_G_config.h
fact_test.o: /usr/include/wchar.h
fact_test.o: /usr/lib/gcc/x86_64-unknown-linux-gnu/4.9.2/include/stdarg.h
fact_test.o: /usr/include/bits/stdio_lim.h /usr/include/bits/sys_errlist.h
fact_test.o: /usr/include/CUnit/Basic.h
