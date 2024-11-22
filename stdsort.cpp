#include <iostream> // to print out to the console
#include <fstream> // for file operations csv in this case
#include <vector>  // to store data from the csv
#include <algorithm>  // for std::sort
#include <sstream>  // for splitting lines of text
  int main(){
    std::vector<int> data; // vectors are dynamic, they can expand as we add in the numbers
    std::ifstream inFile("randbw50000.csv"); //open the csv using file stream library

    if (!inFile.is_open()) { //checks if the csv is open and returns true if so
      std::cerr << "Error: Could not open the file." << std::ends;
      return 1; // 0 for successful code, 1 for not
    }

    std::string line, cell; // declaring the line and cell variables

    // Read the file line by line
    while (std::getline(inFile, line)) { // keeps reading so far as there is a line
        std::stringstream lineStream(line); // splits the data

        // Split the line into cells using a comma as a delimiter
        while (std::getline(lineStream, cell, ',')) {// takes the lineStream (current
                                                                // line) and wherever there is a comma
                                                                // it splits the line into smaller pieces
            try {   // an attempt at handling exceptions
                data.push_back(std::stoi(cell)); // convert the string to an integer for sorting
            } catch (const std::invalid_argument&) { // catches non-integers and reports below error
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
