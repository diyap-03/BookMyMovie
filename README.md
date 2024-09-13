# BookMyMovie

**BookMyMovie** is a console-based movie ticket booking application that allows users to select movies, choose theaters, pick showtimes, and book tickets. It handles common exceptions and provides different ticket types (Economy and Premium) with different pricing.

## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Classes](#classes)
- [Exception Handling](#exception-handling)
- [Future Improvements](#future-improvements)
- [Contributing](#contributing)
- [License](#license)

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

## Example Output

```plaintext
--------Welcome to BookMyMovie App-----------

Here is the list of available movies:
Movie Code      Movie Name
1               Oppenheimer
2               Jabtak
...

Enter the movie code for the movie you want to book:
1
...

Booking confirmed.
---------------------------------
|      MOVIE TICKET             |
---------------------------------
| Movie name: Oppenheimer       |
| Duration: 180                 |
| Venue: PVR                    |
| Show Time: 17:30              |
| Number of seats: 2            |
| Type: Premium                 |
---------------------------------


