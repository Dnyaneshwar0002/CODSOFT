#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a structure to represent a movie
struct Movie {
    string title;
    string time;
    int availableSeats;
};

// Function to display a list of available movies and showtimes
void displayMovies(const vector<Movie>& movies) {
    cout << "Available Movies:\n";
    for (int i = 0; i < movies.size(); i++) {
        cout << i + 1 << ". " << movies[i].title << " at " << movies[i].time << " (" << movies[i].availableSeats << " seats available)\n";
    }
    cout << "\n";
}

int main() {
    // Create some sample movies
    vector<Movie> movies = {
        {"Movie 1", "12:00 PM", 50},
        {"Movie 2", "3:00 PM", 40},
        {"Movie 3", "6:00 PM", 30}
    };

    int choice;
    int selectedMovie;
    int numTickets;

    cout << "Welcome to the Movie Ticket Booking System!\n";

    do {
        displayMovies(movies);
cout << "Enter the number of the movie you want to watch (0 to exit): ";
        cin >> choice;

        if (choice >= 1 && choice <= movies.size()) {
            selectedMovie = choice - 1;

            cout << "How many tickets would you like to book for " << movies[selectedMovie].title << "? ";
            cin >> numTickets;

            if (numTickets <= movies[selectedMovie].availableSeats) {
                cout << "Booking successful! Enjoy the movie!\n\n";
                movies[selectedMovie].availableSeats -= numTickets;
            } else {
                cout << "Sorry, not enough seats available for your request. Please choose a different movie or fewer tickets.\n\n";
            }
        } else if (choice != 0) {
            cout << "Invalid choice. Please select a valid movie.\n\n";
        }
    } while (choice != 0);

    cout << "Thank you for using the Movie Ticket Booking System!\n";

    return 0;
}
