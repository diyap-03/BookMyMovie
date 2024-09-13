#include <iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;


class InvalidChoiceException : public exception {
public:
    const char* what() const throw() {
        return "Invalid choice. Please try again.";
    }
};

class BookingNotConfirmedException : public exception {
public:
    const char* what() const throw() {
        return "Booking not confirmed. Please try again.";
    }
};

class ShowTimeNotFoundException : public exception {
public:
    const char* what() const throw() {
        return "Show time not found. Please choose a valid show time.";
    }
};

class NoSeatsAvailableException : public exception {
public:
    const char* what() const throw() {
        return "No seats available for booking.";
    }
};

class InvalidSeatsException : public exception {
public:
    const char* what() const throw() {
        return "Invalid number of seats. Please try again.";
    }
};

class MovieNotFoundException : public exception {
public:
    const char* what() const throw() {
        return "Movie not found. Please choose a valid movie.";
    }
};

class TheaterNotFoundException : public exception {
public:
    const char* what() const throw() {
        return "Theater not found. Please choose a valid theater.";
    }
};

class ShowTime {
public:
    string showtime;
    ShowTime(string showtime) : showtime(showtime) {}

    void displayShowTimings() {
        cout << showtime;
    }
};

class Movie {
public:
    string name;
    string genre;
    int duration;
    string rating;

    Movie(string name, string genre, int duration, string rating) : name(name), genre(genre), duration(duration), rating(rating) {}

    void displayMovieDetails() {
        cout << "Movie Details" << endl;
        cout << "Name: " << name << endl;
        cout << "Genre: " << genre << endl;
        cout << "Duration: " << duration << endl;
        cout << "Rating: " << rating << endl;
    }
};

class Theater {
public:
    string venue;
    ShowTime* time[4];
    int numShows = 0;

    Theater() {}
    Theater(string venue) : venue(venue) {}

    void displayTheaterDetails() {
        cout << endl;
        cout << "Here is the list of available show timings in " << venue << ":" << endl;
        cout << "ShowTime Code" << "\t" << "Show Time" << endl;

        for (int i = 0; i < numShows; i++) {
            cout << i + 1 << "\t\t" << time[i]->showtime << endl;
        }
    }

    void addShow(ShowTime* show) {
        time[numShows++] = show;
    }
};


class User {
private:
    string name;
    string phone;
    int bookingCount;
public:
    User() {
        name = "";
        phone = "";
        bookingCount = 0;
    }

    User(string name, string phone) : name(name), phone(phone) {
//bookingCount++;
    }

    string getName()
    {
        return name;
    }
    string getPhone()
    {
        return phone;
    }
    int getBookingCount()
    {
        return bookingCount;
    }
    void IncrementBooking()
    {
         bookingCount++;
    }
};

class Ticket {
public:
    virtual void calculatePrice(int seatNumber) = 0;

    virtual void printDetails(int seats,Movie* m,User* u,Theater* t,int s) = 0;

};

class EconomyTicket : public Ticket {
public:
    void calculatePrice(int seatNumber){
        cout<<"Total cost for booking economy tickets: "<<150*seatNumber<<endl;
    }

    void printDetails(int seats,Movie* m,User* u,Theater* t,int s){
        cout<<"---------------------------------"<<endl;
        cout<<"|\tMOVIE TICKET\t        |"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"|"<<"Movie name:"<<m->name<<"\t\t"<<"|"<<endl;
        cout<<"|"<<"Duration:"<<m->duration<<"\t\t\t"<<"|"<<endl;
        cout<<"|"<<"Venue:"<<t->venue<<"\t\t\t"<<"|"<<endl;
        cout<<"|"<<"Show Time:"<<t->time[s]->showtime<<"\t\t"<<"|"<<endl;
        cout<<"|"<<"Number of seats:"<<seats<<"\t\t"<<"|"<<endl;
        cout<<"|"<<"Type: Economy"<<"\t\t\t"<<"|"<<endl;
        cout<<"|"<<"\t\t\t\t"<<"|"<<endl;
        cout<<"---------------------------------"<<endl;

    }
};

class PremiumTicket : public Ticket {
public:
    void calculatePrice(int seatNumber){
        cout<<"Total cost for booking premium tickets: "<<150*seatNumber*1.5<<endl;
    }

    void printDetails(int seats,Movie* m,User* u,Theater* t,int s){
        cout<<"---------------------------------"<<endl;
        cout<<"|\tMOVIE TICKET\t        |"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"|"<<"Movie name:"<<m->name<<"\t\t"<<"|"<<endl;
        cout<<"|"<<"Duration:"<<m->duration<<"\t\t\t"<<"|"<<endl;
        cout<<"|"<<"Venue:"<<t->venue<<"\t\t\t"<<"|"<<endl;
        cout<<"|"<<"Show Time:"<<t->time[s]->showtime<<"\t\t"<<"|"<<endl;
        cout<<"|"<<"Number of seats:"<<seats<<"\t\t"<<"|"<<endl;
        cout<<"|"<<"Type: Premium"<<"\t\t\t"<<"|"<<endl;
        cout<<"|"<<"\t\t\t\t"<<"|"<<endl;
        cout<<"---------------------------------"<<endl;

    }
};

class TicketFactory {
public:
    static Ticket* createTicket(int isPremium);
};

Ticket* TicketFactory::createTicket(int isPremium) {
    if (isPremium) {
        return new PremiumTicket();
    } else {
        return new EconomyTicket();

    }
}

class Booking {
public:
    int bookingId;
    int seatCount = 30;
    int seatsBooked = 0;
    Booking() {}

    void addBooking(int seats, User* u, Movie* m, Theater* t, int i) {
        seatCount = seatCount - seats;
        seatsBooked = seats;
        cout<<endl;
        cout << "For " << u->getName() << endl;
        cout << "Seats for "<< seatsBooked << "\nMovie: " << m->name << "\nTheater: " << t->venue << "\nTime: " << t->time[i]->showtime << endl;
        cout<<endl;

        u->IncrementBooking();
    }

    Ticket* bookTicket(int isPremium) {
        return TicketFactory::createTicket(isPremium);
    }

};



class BookMyMovie {
public:
    Movie* movies[10];
    int numMovies = 0;
    Theater* theaters[3];
    int numTheaters = 0;
    User* users[20];
    int numUsers = 0;

public:
    BookMyMovie() {}

    void displayMovie() {
        cout << "Here is the list of available movies:" << endl;
        cout << "Movie Code" << "\t" << "Movie Name" << endl;
        for (int i = 0; i < numMovies; i++) {
            cout << i + 1 << "\t\t" << movies[i]->name << endl;
        }
    }

    void displayTheater() {
        cout << "Here is the list of available theaters:" << endl;
        cout << "Theater Code" << "\t" << "Theater Name" << endl;
        for (int i = 0; i < numTheaters; i++) {
            cout << i + 1 << "\t\t" << theaters[i]->venue << endl;
        }
    }

    void displayUsers() {
        cout << "Users:" << endl;
        cout << "User name" << "\t" << "Phone number" << "\t" << "Booking Count" <<endl;
        for (int i = 0; i < numUsers; i++) {
            cout << users[i]->getName() << "\t\t" << users[i]->getPhone() << "\t\t" << users[i]->getBookingCount() <<endl;
        }
    }

    void addMovie(Movie* movie) {
        movies[numMovies++] = movie;
    }

    void addTheater(Theater* th) {
        theaters[numTheaters++] = th;
    }

    void addUser(User* user) {
        users[numUsers++] = user;
    }
};



int main()
{
    BookMyMovie app;

    Movie* movie1 = new Movie("Oppenheimer","Thriller",180,"*****");
    Movie* movie2 = new Movie("Jabtak","Romance",120,"***");
    Movie* movie3 = new Movie("Barbie","Comedy",130,"****");
    Movie* movie4 = new Movie("ShutterIsland","Thriller",180,"***");
    Movie* movie5 = new Movie("Barfi","Drama",110,"****");
    Movie* movie6 = new Movie("Father's Bride","Comedy",120,"***");
    Movie* movie7 = new Movie("Twilight","Fantasy",180,"**");
    Movie* movie8 = new Movie("Fast & Furious","Action",110,"****");
    Movie* movie9 = new Movie("End game","Action",100,"****");
    Movie* movie10 = new Movie("Spiderman2","Drama",110,"*****");

    app.addMovie(movie1);
    app.addMovie(movie2);
    app.addMovie(movie3);
    app.addMovie(movie4);
    app.addMovie(movie5);
    app.addMovie(movie6);
    app.addMovie(movie7);
    app.addMovie(movie8);
    app.addMovie(movie9);
    app.addMovie(movie10);

    Theater* th1 = new Theater("PVR");
    Theater* th2 = new Theater("Cinepolis");
    Theater* th3 = new Theater("Imax");

    app.addTheater(th1);
    app.addTheater(th2);
    app.addTheater(th3);

    ShowTime* show1 = new ShowTime("10:30");
    ShowTime* show2 = new ShowTime("13:30");
    ShowTime* show3 = new ShowTime("17:30");
    ShowTime* show4 = new ShowTime("21:30");

    app.theaters[0]->addShow(show1);
    app.theaters[0]->addShow(show2);
    app.theaters[0]->addShow(show3);
    app.theaters[0]->addShow(show4);

    app.theaters[1]->addShow(show1);
    app.theaters[1]->addShow(show2);
    app.theaters[1]->addShow(show3);
    app.theaters[1]->addShow(show4);

    app.theaters[2]->addShow(show1);
    app.theaters[2]->addShow(show2);
    app.theaters[2]->addShow(show3);
    app.theaters[2]->addShow(show4);

    cout<<"--------Welcome to BookMyMovie App-----------"<<endl;
    cout<<endl;

    char choice, confirm;
    string name, phone;
    int ch1, ch2, ch3, seats;
    int i = 0;
    int isPremium = 0;

    do
    {
        try {
            app.displayMovie();
            cout << endl;
            cout << "Enter the movie code for the movie you want to book:" << endl;
            cin >> ch1;
            if (ch1 < 1 || ch1 > app.numMovies) {
                throw MovieNotFoundException();
            }
            cout << endl;
            app.movies[ch1 - 1]->displayMovieDetails();

            cout << endl;
            app.displayTheater();
            cout << "Enter the code for the theater of your choice:" << endl;
            cin >> ch2;
            if (ch2 < 1 || ch2 > app.numTheaters) {
                throw TheaterNotFoundException();
            }
            cout << endl;
            app.theaters[ch2 - 1]->displayTheaterDetails();

            cout<<endl;
            cout << "Enter the code for the show time of your choice:" << endl;
            cin >> ch3;
            if (ch3 < 1 || ch3 > app.theaters[ch2 - 1]->numShows) {
                throw ShowTimeNotFoundException();
            }

            Booking b;
            cout<<endl;
            cout<<"Enter your details before proceeding:"<<endl;
            cout<<endl;
            cout << "Enter your name: " << endl;
            cin >> name;
            cout << "Enter your phone number: " << endl;
            cin >> phone;
            User* user1 = new User(name, phone);
            app.addUser(user1);

            cout << "Enter the number of seats you want to book for ";
            app.theaters[ch2 - 1]->time[ch3 - 1]->displayShowTimings();
            cout<<" show: "<< endl;
            cin >> seats;
            if (seats <= 0) {
                throw InvalidSeatsException();
            }

            if (seats > b.seatCount) {
                throw NoSeatsAvailableException();
            }

            b.addBooking(seats, app.users[i], app.movies[ch1 - 1], app.theaters[ch2 - 1], ch3 - 1);

            cout << "Enter the type of ticket: (1-Premium/0-Ecnonomy)" << endl;
            cin >> isPremium;
            if (isPremium != 0 && isPremium != 1) {
                throw InvalidChoiceException();
            }

            Ticket* ticket = b.bookTicket(isPremium);
            ticket->calculatePrice(seats);

            cout << "Booking confirm?(y/n)" << endl;
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y')
                cout << "Booking confirmed." << endl;
            else {
                throw BookingNotConfirmedException();
            }

            ticket->printDetails(seats,app.movies[ch1-1],app.users[i],app.theaters[ch2-1],ch3-1);

            cout << "Would you like to book another movie?(y/n)";
            cin >> choice;
            i++;
        }
        catch (exception& e) {
            cout << "Error: " << e.what() << endl;
            cout<<endl;
            choice = 'y';
        }
        cout<<endl;
    } while (choice == 'y');

    app.displayUsers();

    return 0;
}
