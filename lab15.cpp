#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Movie {
private:
    string title;
    int yearReleased;
    string screenWriter;

public:
    // Setters
    void setTitle(const string& t) { title = t; }
    void setYearReleased(int y) { yearReleased = y; }
    void setScreenWriter(const string& s) { screenWriter = s; }

    // Getters
    string getTitle() const { return title; }
    int getYearReleased() const { return yearReleased; }
    string getScreenWriter() const { return screenWriter; }

    // Print method
    void print() const {
        cout << "Movie: " << title << endl;
        cout << "    Year released: " << yearReleased << endl;
        cout << "    Screenwriter: " << screenWriter << endl;
    }
};

int main() {
    vector<Movie> movies;  // Using vector as the container

    // Open the input file
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    // Read data into the Movie objects
    for (int i = 0; i < 4; ++i) {  // Loop to read 4 records
        Movie tempMovie;
        string title, screenWriter;
        int year;

        getline(inputFile, title);
        inputFile >> year;
        inputFile.ignore();  // Ignore the newline character after year
        getline(inputFile, screenWriter);

        tempMovie.setTitle(title);
        tempMovie.setYearReleased(year);
        tempMovie.setScreenWriter(screenWriter);

        movies.push_back(tempMovie);  // Append the movie object to the vector
    }

    // Close the input file
    inputFile.close();

    // Output the contents of the vector
    for (const auto& movie : movies) {
        movie.print();
    }

    return 0;
}