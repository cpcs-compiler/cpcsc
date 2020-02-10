# CpcSC ーCpcdosC+ Subset Compiler

[![License](https://img.shields.io/github/license/cpcs-compiler/cpcsc?style=flat-square)](LICENSE) 
[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-v2.0%20adopted-ff69b4.svg?style=flat-square)](CODE_OF_CONDUCT.md) 
[![GitHub issues](https://img.shields.io/github/issues/cpcs-compiler/cpcsc?style=flat-square)](https://github.com/cpcs-compiler/cpcsc/issues) 
[![Travis (.org)](https://img.shields.io/travis/cpcs-compiler/cpcsc?logo=travis-ci&logoColor=%23FFFFFF&style=flat-square)](https://travis-ci.org/cpcs-compiler/cpcsc) 
[![Codecov](https://img.shields.io/codecov/c/github/cpcs-compiler/cpcsc?logo=codecov&style=flat-square)](https://codecov.io/gh/cpcs-compiler/cpcsc)

CpcSC support a subset of the [CpcdosC+ language](https://doc.cpcdos.net)

## Usage

```bash
$ cpcsc -o helloworld.o ./examples/helloworld.cpc
$ ld -o helloworld helloworld.o -lcpcsc_runtime
$ ./helloworld
Hello World
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.
