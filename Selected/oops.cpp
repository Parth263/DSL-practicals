#include <iostream>
#include <vector>
#include <map>

class Movie {
public:
    std::string movieName;
    int movieDuration;

    Movie(std::string movieName, int movieDuration)
        : movieName(movieName), movieDuration(movieDuration) {}
};

class Show {
public:
    std::string movieName;
    int time;
    std::vector<std::vector<char>> seating;

    Show(std::string movieName, int time, int rows, int cols)
        : movieName(movieName), time(time) {
            seating = std::vector<std::vector<char>>(rows, std::vector<char>(cols, 'O'));
        }
};

class Refreshment {
public:
    std::string name;
    int price;

    Refreshment(std::string name, int price)
        : name(name), price(price) {}
};

class Cineplex {
private:
    std::map<std::string, Movie> movies;
    std::map<std::string, Show> shows;
    std::vector<Refreshment> refreshments;
    std::map<std::string, std::string> reviews;

public:
    Cineplex() {
        // Initialize movies, shows, and refreshments
        movies["Inception"] = Movie("Inception", 150);
        movies["Avengers"] = Movie("Avengers", 180);

        shows["Inception"] = Show("Inception", 14, 5, 10);
        shows["Avengers"] = Show("Avengers", 18, 6, 12);

        refreshments.push_back(Refreshment("Popcorn", 5));
        refreshments.push_back(Refreshment("Coke", 3));
        refreshments.push_back(Refreshment("Candy", 2));
    }

    void displayMovieList() {
        std::cout << "Movies currently being screened:" << std::endl;
        for (const auto& movie : movies) {
            std::cout << "- " << movie.first << " (" << movie.second.movieDuration << " mins)" << std::endl;
        }
    }

    void displayShowTimes(const std::string& movieName) {
        std::cout << "Showtimes for " << movieName << ":" << std::endl;
        std::cout << "1. " << shows[movieName].time << ":00" << std::endl;
    }

    void displaySeating(const std::string& movieName) {
        std::cout << "Seating arrangement for " << movieName << ":" << std::endl;
        for (const auto& row : shows[movieName].seating) {
            for (char seat : row) {
                std::cout << seat << " ";
            }
            std::cout << std::endl;
        }
    }

    void getTickets(const std::string& movieName) {
        displayShowTimes(movieName);
        int showTime;
        std::cout << "Enter the showtime number: ";
        std::cin >> showTime;

        if (showTime != 1) {
            std::cout << "Invalid showtime number." << std::endl;
            return;
        }

        displaySeating(movieName);

        // Code to book a ticket can be added here based on user input
        // For simplicity, let's assume the user chooses the first available seat
        shows[movieName].seating[0][0] = 'X';

        std::cout << "Ticket booked successfully!" << std::endl;
    }

    void chooseRefreshments() {
        std::cout << "Refreshments available:" << std::endl;
        for (const auto& refreshment : refreshments) {
            std::cout << "- " << refreshment.name << " ($" << refreshment.price << ")" << std::endl;
        }

        // Code to handle user's refreshment choices can be added here
    }

    void giveReview(const std::string& movieName) {
        std::string review;
        std::cout << "Enter your review for " << movieName << ": ";
        std::cin.ignore();
        std::getline(std::cin, review);
        reviews[movieName] = review;
        std::cout << "Thank you for your review!" << std::endl;
    }

    void runCineplex() {
        while (true) {
            std::cout << "\nWelcome to the Cineplex!" << std::endl;
            std::cout << "1. Display Movies" << std::endl;
            std::cout << "2. Get Tickets" << std::endl;
            std::cout << "3. Choose Refreshments" << std::endl;
            std::cout << "4. Give Movie Review" << std::endl;
            std::cout << "5. Exit" << std::endl;

            int choice;
            std::cout << "Enter your choice (1-5): ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    displayMovieList();
                    break;
                case 2: {
                    std::cout << "Enter the movie you want to watch: ";
                    std::string movieChoice;
                    std::cin >> movieChoice;
                    getTickets(movieChoice);
                    break;
                }
                case 3:
                    chooseRefreshments();
                    break;
                case 4: {
                    std::cout << "Enter the movie you want to review: ";
                    std::string movieReview;
                    std::cin >> movieReview;
                    giveReview(movieReview);
                    break;
                }
                case 5:
                    std::cout << "Thank you for visiting the Cineplex. Have a great day!" << std::endl;
                    return;
                default:
                    std::cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
            }
        }
    }
};

int main() {
    Cineplex cineplex;
    cineplex.runCineplex();

    return 0;
}
