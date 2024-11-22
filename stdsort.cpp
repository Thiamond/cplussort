#include <iostream>
#include <fstream> // for file operations csv in this case
#include <vector>  // to store data
#include <algorithm>  // for std::sort
#include <sstream>  // for string stream
  int main(){
    std::vector<int> data;
    std::ifstream inFile("randbw50000.csv"); //open the csv

    if (!inFile.is_open()) {
      std::cerr << "Error: Could not open the file." << std::ends;
      return 1;
    }

    std::string line, cell; 

    // Read the file line by line
    while (std::getline(inFile, line)) {
        std::stringstream lineStream(line);

        // Split the line into cells using a comma as a delimiter
        while (std::getline(lineStream, cell, ',')) {
            try {
                data.push_back(std::stoi(cell)); // Convert the string to an integer
            } catch (const std::invalid_argument&) {
                std::cerr << "Error: Invalid number found in CSV: " << cell << std::endl;
                return 1;
            }
        }
    }

    inFile.close(); // Close the file

    // Sort the numbers in ascending order
    std::sort(data.begin(), data.end());

    // Output the sorted list
    std::cout << "Sorted numbers: ";
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0; // Indicate the program ran successfully
}
