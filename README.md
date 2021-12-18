# EMNIST and MNIST Data Importer

This is a small library to import the _famous_ [MNIST data set](https://web.archive.org/web/20210302011733/http://yann.lecun.com/exdb/mnist/).
Additionally the [EMNIST data sets](https://www.nist.gov/itl/products-and-services/emnist-dataset) with accordingly mapped labels can be imported too. 
For the latter the mapping file is required. 

The corresponding publications:

- [EMNIST](https://arxiv.org/abs/1702.05373)
- [MNIST](https://ieeexplore.ieee.org/document/726791)

## Dependencies

**NOTE:** Build and run was _neither tested under Windows nor macOS_, it might work, it might not work.

* cmake >= 3.8
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 7.5
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* **No other additional libraries are required**

## Build and Test

1. Clone this repo: `git clone git@github.com:akutschi/emnist-mnist-reader.git`
1. Clone the submodule to get the data sets: `git submodule add git@gitlab.com:akutschi/emnist-mnist-data.git data`
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./MNIST-Data`

## Usage

See `src/main.cpp`. 
Download the datasets from the original sources or use the data sets in the [GitLab repository](https://gitlab.com/akutschi/emnist-mnist-data/-/tree/main).
Simply add the header where the object `MNISTDataSet` is required.

```cpp
#include "mnist_data.h"

int main 
{
  MNISTDataSet mnist_data(
    "./train-images-idx3-ubyte", 
    "./train-labels-idx1-ubyte")
    ;

  MNISTDataSet emnist_data1(
    "./emnist-balanced-train-images-idx3-ubyte", 
    "./emnist-balanced-train-labels-idx1-ubyte",
    "./emnist-balanced-mapping.txt"
    );
}
```

As you can see there are two choices. 
The first one has two parameters and can be used when no mapping is required.
The _original_ MNIST data set does not require a mapping file.
The command is then: 

```cpp
MNISTDataSet data_set_no_mapping(
  "path/to/images/in/idx/format",
  "path/to/labels"
  );
```

The second choice is required when the mapping should be applied. 
This is recommended when using the EMNIST data set.
See the corresponding paper for further explanations.
The command is basically the same plus the path to the mapping file:

```cpp
MNISTDataSet data_set_no_mapping(
  "path/to/images/in/idx/format",
  "path/to/labels/in/idx/format",
  "path/to/mapping/in/txt/format"
  );
```

In both cases the result looks more or less like the following representation. In fact it's a `vector of structs`.

```
dataset_vector{
  data_struct_1{
    data{
      Vector that contains the image information
    }
    output{
      Vector that contains the output
    }
    label{
      ASCII integer with the label
    }
  }
  data_struct_2{
    data{
      Vector that contains the image information
    }
    output{
      Vector that contains the output
    }
    label{
      ASCII integer with the label
    }
  }

  ...

  data_struct_n{
    data{
      Vector that contains the image information
    }
    output{
      Vector that contains the output
    }
    label{
      ASCII integer with the label
    }
  }
}
```

# THE IDX FILE FORMAT ([Source](https://web.archive.org/web/20210302011733/http://yann.lecun.com/exdb/mnist/))

The IDX file format is a simple format for vectors and multidimensional matrices of various numerical types.

The basic format is

```
magic number
size in dimension 0
size in dimension 1
size in dimension 2
.....
size in dimension N
data
```

The magic number is an integer (MSB first). The first 2 bytes are always 0.

The third byte codes the type of the data:
- 0x08: unsigned byte
- 0x09: signed byte
- 0x0B: short (2 bytes)
- 0x0C: int (4 bytes)
- 0x0D: float (4 bytes)
- 0x0E: double (8 bytes)

The 4-th byte codes the number of dimensions of the vector/matrix: 
- 1 for vectors
- 2 for matrices, 
- ...


The sizes in each dimension are 4-byte integers (MSB first, high endian, like in most non-Intel processors).

The data is stored like in a C array, i.e. the index in the last dimension changes the fastest. 

# License

GPLv3, see [license](./LICENSE).

# Contributing

Feel free to open issues or merge requests if you find problems or have ideas for improvements. Thank you.
