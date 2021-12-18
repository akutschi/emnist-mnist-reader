#ifndef MNIST_DATA_H
#define MNIST_DATA_H

#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include "idx_data.h"

struct MNISTDataEntry
{
    std::vector<int> data;   // Store pixel color values of the image
    std::vector<int> output; // Store the output in a 10 column vector
    int label;               // Store the handwritten character in number form
    // Constructor using initializer list to initialize its member variables
    MNISTDataEntry() : data(std::vector<int>()), output(std::vector<int>(10)), label(0) {}
};

class MNISTDataSet
{
public:
    // Parameters: Paths to images and labels
    MNISTDataSet(const std::string &, const std::string &);
    // Parameters: Paths to images, labels and mapping
    MNISTDataSet(const std::string &, const std::string &, const std::string &);

    std::vector<MNISTDataEntry> mnist_data() const; // Getter to receive the whole data set
    MNISTDataEntry mnist_data(int &) const;         // Getter to receive a struct from mnist_data
    std::vector<int> data_magic_values() const;
    std::vector<int> data_dimension_values() const;
    std::vector<int> label_magic_values() const;
    std::vector<int> label_dimension_values() const;

private:
    std::vector<MNISTDataEntry> _mnist_data;                     // Vector of structs, holds all MNIST data
    void mnist_struct(const std::string &, const std::string &); // Setter to fill up the vector of structs
    void mnist_label_map(const std::string &);                   // Vector of vectors for mapping
    void mnist_label_mapping();                                  // Change labels according to mapping
    std::vector<std::vector<int>> _mapping_table;
    std::vector<int> _data_magic_number;
    std::vector<int> _data_magic_dimensions;
    std::vector<int> _label_magic_number;
    std::vector<int> _label_magic_dimensions;
};

#endif