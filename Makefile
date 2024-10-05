all: cexample cppexample 

cexample: rust_math_ops/target/release/librust_math_ops.a libcmath_ops.so libfortran_math_ops.so
	gcc $(shell python3.10-config --cflags) cexample.c $(shell python3.10-config --ldflags --embed) -L. -lfortran_math_ops -lcmath_ops -Lrust_math_ops/target/release -lrust_math_ops -o cexample 

cppexample: rust_math_ops/target/release/librust_math_ops.a libcmath_ops.so libfortran_math_ops.so
	g++ $(shell python3 -m pybind11 --includes) cppexample.cpp -lpython3.10 -L. -lfortran_math_ops -lcmath_ops  -Lrust_math_ops/target/release -lrust_math_ops -o cppexample 

rust_math_ops/target/release/librust_math_ops.a:
	cargo build --release --manifest-path=rust_math_ops/Cargo.toml

libcmath_ops.so:
	gcc clib_math_ops.c -fPIC -o libcmath_ops.so -shared 

libfortran_math_ops.so:
	gfortran -c f_math_ops.f90 -fPIC -o libfortran_math_ops.so -shared

clean:
	cargo clean --manifest-path=rust_math_ops/Cargo.toml
	rm cexample && rm cppexample && rm *.so
