# BookMyMovie

**BookMyMovie** is a console-based movie ticket booking application that allows users to select movies, choose theaters, pick showtimes, and book tickets. It handles common exceptions and provides different ticket types (Economy and Premium) with different pricing.

## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Classes](#classes)
- [Exception Handling](#exception-handling)
- [Future Improvements](#future-improvements)


## Features

- **Movie Selection**: Browse through a list of movies and select one to watch.
- **Theater and Showtimes**: Choose a theater and a specific showtime for the selected movie.
- **Ticket Booking**: Book tickets with the option of Economy or Premium seating.
- **User Management**: Track users and their booking history.
- **Exception Handling**: The application handles various common errors gracefully, such as invalid choices or unavailability of seats.

## Installation

### Prerequisites

- A C++ compiler (e.g., GCC)
- A terminal or command prompt

### Steps

1. **Clone the repository**:
   ```sh
   git clone https://github.com/your-username/BookMyMovie.git
   cd BookMyMovie

2. **Compile the code**:
    ```sh
    g++ -o BookMyMovie main.cpp

3. **Run the application**:
    ```sh
    ./BookMyMovie

## Usage

- The application will guide you through the steps of selecting a movie, theater, showtime, and booking your tickets.
- You'll be prompted to enter your name and phone number for user management.
- After booking, you can review your booking details, and the application will confirm your booking.

## Classes

- **`Movie`**: Represents a movie with attributes like name, genre, duration, and rating.
- **`Theater`**: Represents a theater with showtimes and venue details.
- **`ShowTime`**: Represents a specific showtime for a movie in a theater.
- **`User`**: Represents a user with a name, phone number, and booking history.
- **`Ticket`**: An abstract class that calculates ticket prices and prints ticket details.
- **`EconomyTicket`** and **`PremiumTicket`**: Subclasses of `Ticket` that handle specific pricing and ticket details.
- **`Booking`**: Manages the booking process, seat availability, and ticket creation.
- **`TicketFactory`**: A factory class for creating `Ticket` objects.
- **`BookMyMovie`**: The main application class that manages movies, theaters, and users.

## Exception Handling

The application uses custom exceptions to handle various errors:

- **`InvalidChoiceException`**: Thrown when the user makes an invalid selection.
- **`BookingNotConfirmedException`**: Thrown when the user declines to confirm the booking.
- **`ShowTimeNotFoundException`**: Thrown when the selected showtime is not available.
- **`NoSeatsAvailableException`**: Thrown when there are not enough seats available for booking.
- **`InvalidSeatsException`**: Thrown when the user enters an invalid number of seats.
- **`MovieNotFoundException`**: Thrown when the selected movie is not found.
- **`TheaterNotFoundException`**: Thrown when the selected theater is not found.

## Future Improvements

- **GUI**: Implement a graphical user interface for better user interaction.
- **Database Integration**: Store movies, theaters, users, and booking information in a database.
- **Online Payment Integration**: Add functionality for processing payments online.
