
all: clean build run
	cat SO

clean:
	echo "CLEAN" > SO

build:
	echo "BUILD" >> SO
	@lss

run:
	echo "RUN" >> SO

.ONESHELL:
run-instability-check:
	@i=0;
	@while [[ $$i -lt 5 ]] ; do
	@	echo "hello" || exit true;
	@	((i = i  + 1));
	@done

