#include <iostream>

#include "mnist_data.h"


int main()
{
    std::cout << "Import mnist training data set" << std::endl;
    MNISTDataSet mnist_data("../data/mnist_data/train-images-idx3-ubyte", "../data/mnist_data/train-labels-idx1-ubyte");

    std::cout << "Import emnist balanced training data set" << std::endl;
    MNISTDataSet emnist_data1("../data/emnist_data/emnist-balanced-train-images-idx3-ubyte", "../data/emnist_data/emnist-balanced-train-labels-idx1-ubyte", "../data/emnist_data/emnist-balanced-mapping.txt");
    
    std::cout << "Done!"  << std::endl;

    return 0;
}