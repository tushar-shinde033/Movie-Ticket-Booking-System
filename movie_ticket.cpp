#include <iostream>
#include <vector>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 5;
const int SEAT_PRICE = 10;


vector<vector<bool>> seats(NUM_ROWS, vector<bool>(NUM_COLS, false));

void displaySeats() {
    cout << "Current Seat Availability:" << endl;
    for (int row = 0; row < NUM_ROWS; ++row) {
        for (int col = 0; col < NUM_COLS; ++col) {
            if (seats[row][col]) {
                cout << " X ";
            } else {
                cout << " O ";
            }
        }
        cout << endl;
    }
    cout << endl;
}


int calculateTotalCost(const vector<pair<int, int>>& selectedSeats) {
    int totalCost = 0;
    for (const auto& seat : selectedSeats) {
        totalCost += SEAT_PRICE;
    }
    return totalCost;
}

int main() {
    cout << "Welcome to the Movie Ticket Booking System!" << endl;

    while (true) {
        displaySeats();

        cout << "1. View Movie Listings" << endl;
        cout << "2. Book Tickets" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Movie Listings:" << endl;
                cout << "1. Movie A" << endl;
                cout << "2. Movie B" << endl;
                break;
            }
            case 2: {
                displaySeats();
                vector<pair<int, int>> selectedSeats;
                int row, col;

                cout << "Enter the row and column of the seat you want to book: ";
                cin >> row >> col;

                if (row < 1 || row > NUM_ROWS || col < 1 || col > NUM_COLS) {
                    cout << "Invalid seat selection. Please try again." << endl;
                    break;
                }

                if (seats[row - 1][col - 1]) {
                    cout << "Seat is already booked. Please select another seat." << endl;
                    break;
                }

                seats[row - 1][col - 1] = true;
                selectedSeats.emplace_back(row, col);

                int totalCost = calculateTotalCost(selectedSeats);
                cout << "Seat booked successfully!" << endl;
                cout << "Total Cost: $" << totalCost << endl;
                break;
            }
            case 3: {
                cout << "Thank you for using the Movie Ticket Booking System. Goodbye!" << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please select a valid option." << endl;
                break;
            }
        }
    }

    return 0;
}
