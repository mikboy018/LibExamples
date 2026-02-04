PY_VERS?=3.10

PHONY.: test

all: cexample cppexample 

# NOTE: Need to set LD_LIBRARY_PATH=. or in the linking, add -Wl,-rpath,'$$ORIGIN' so it searches the build directory.

cexample: rust_math_ops/target/release/librust_math_ops.a libcmath_ops.so libfortranmath_ops.so
	gcc $(shell python${PY_VERS}-config --cflags) cexample.c $(shell python${PY_VERS}-config --ldflags --embed) -L. -lfortranmath_ops -lcmath_ops -Lrust_math_ops/target/release -lrust_math_ops -o cexample 

cppexample: rust_math_ops/target/release/librust_math_ops.a libcmath_ops.so libfortranmath_ops.so
	g++ $(shell python3 -m pybind11 --includes) cppexample.cpp -lpython${PY_VERS} -L. -lfortranmath_ops -lcmath_ops -Lrust_math_ops/target/release -lrust_math_ops -o cppexample 

rust_math_ops/target/release/librust_math_ops.a:
	cargo build --release --manifest-path=rust_math_ops/Cargo.toml

libcmath_ops.so:
	gcc clib_math_ops.c -fPIC -o libcmath_ops.so -shared 

libfortranmath_ops.so:
	gfortran -c f_math_ops.f90 -fPIC -o libfortranmath_ops.so -shared

clean:
	cargo clean --manifest-path=rust_math_ops/Cargo.toml
	rm cexample && rm cppexample && rm *.so && rm *.mod

test: cexample cppexample
	LD_LIBRARY_PATH=. ./cexample
	LD_LIBRARY_PATH=. ./cppexample
