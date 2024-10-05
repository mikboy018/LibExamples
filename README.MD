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
- [Fortran (NVFortran used here)](https://developer.nvidia.com/hpc-sdk-downloads)
```
curl https://developer.download.nvidia.com/hpc-sdk/ubuntu/DEB-GPG-KEY-NVIDIA-HPC-SDK | sudo gpg --dearmor -o /usr/share/keyrings/nvidia-hpcsdk-archive-keyring.gpg
echo 'deb [signed-by=/usr/share/keyrings/nvidia-hpcsdk-archive-keyring.gpg] https://developer.download.nvidia.com/hpc-sdk/ubuntu/amd64 /' | sudo tee /etc/apt/sources.list.d/nvhpc.list
sudo apt-get update -y
sudo apt-get install -y nvhpc-24-1
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