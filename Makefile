all: cexample cppexample 

cexample: rust_math_ops/target/release/librust_math_ops.a libcmath_ops.so
	gcc cexample.c -L. -lcmath_ops -Lrust_math_ops/target/release -lrust_math_ops -o cexample 

cppexample: rust_math_ops/target/release/librust_math_ops.a libcmath_ops.so
	g++ cppexample.cpp -L. -lcmath_ops -Lrust_math_ops/target/release -lrust_math_ops -o cppexample

rust_math_ops/target/release/librust_math_ops.a:
	cargo build --release --manifest-path=rust_math_ops/Cargo.toml

libcmath_ops.so:
	gcc clib_math_ops.c -fPIC -o libcmath_ops.so -shared 

clean:
	cargo clean --manifest-path=rust_math_ops/Cargo.toml
	rm cexample && rm cppexample && rm *.so
