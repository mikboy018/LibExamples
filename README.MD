# CPP Library Examples
Importing functions from Rust, Headerfiles, C Shared Libs, and Python -- more to come

## Requirements
- [Rust](https://www.rust-lang.org/tools/install)
```
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
```
- [Pybind11](https://pypi.org/project/pybind11/)
```
python3 -m pip install pybind11
```

## Build
```
make clean; make all
```

## Run
C++ Executable
```
./cppexample
```
C Executable
```
./cexample
```