MAKE_FLAGS?=-j5

all: clean
	mkdir -p build;
	cd build; cmake ..;
	cd build; ${MAKE} ${MAKE_FLAGS}

update:
	git submodule update --init --recursive

clean:
	rm -Rf build

.PHONY: clean update run
