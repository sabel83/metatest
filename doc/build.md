# Building metatest

## Building the library on Linux

* `mkdir bin && cd bin && cmake ..` sets the build directory up
* `make` builds the code
* `make test` runs the unit tests
* `make website` generates the documentation
* `make install` installs it on the system

### Using a custom compiler

`cmake` should be given the following command line arguments:  <br />
`cmake .. -DCMAKE_CXX_COMPILER:STRING="<path to the compiler>"`

### Enabling C++11 during compilation

`cmake` should be given the following command line arguments: <br />
`cmake .. -DCMAKE_CXX_FLAGS:STRING="-std=c$$++$$0x"`

### Using a custom Boost version

`cmake` should be given the following command line arguments: <br />
`cmake .. -DCMAKE_CXX_FLAGS:STRING="-I<path to Boost includes>" -DCMAKE_SHARED_LINKER_FLAGS:STRING="-L<path to Boost libs>"`

### Installing into a custom directory

`cmake` should be given the following command line arguments: <br />
`cmake .. -DCMAKE_INSTALL_PREFIX:PATH=<path to install to>`

### Building the library on Windows

* Start the CMake gui.
* Set _Where is the source code_ to the root directory of the metatest source
  code.
* Set _Where to build the binaries_ to the directory where you would like to
  build the binaries to. It may be the "bin" directory of the metatest source
  code.
* Click on _Configure_ and choose the compiler to use.
* Click on _Generate_ to generate the solution file.
* Open the generated solution in your development environment and build it.
* When you run the unit tests and the examples on Windows, make sure you have
  `metatest.dll` on your `PATH`.

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu), 2010.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)

