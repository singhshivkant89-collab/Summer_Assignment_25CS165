#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 10
#define TICKET_PRICE 12.50

// Structure to hold individual booking details
typedef struct {
    int seatNumber;
    char passengerName[50];
    int isActive; // 1 if booked, 0 if canceled or empty
} Booking;

// Global 2D array representing the theater layout
Booking theater[ROWS][COLS];

// Function Prototypes
void initializeTheater();
void displaySeats();
void bookTicket();
void cancelTicket();
void viewRevenue();
int getSeatCoordinates(int seatNum, int *r, int *c);

int main() {
    int choice;
    initializeTheater();

    while(1) {
        printf("\n===================================\n");
        printf("    MOVIE TICKET BOOKING SYSTEM    \n");
        printf("===================================\n");
        printf("1. View Available Seats\n");
        printf("2. Book a Ticket\n");
        printf("3. Cancel a Ticket\n");
        printf("4. View Total Revenue\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch(choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                viewRevenue();
                break;
            case 5:
                printf("Thank you for using the Ticket Booking System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid selection! Please choose a valid menu option.\n");
        }
    }
    return 0;
}

// Set up the theater grid with dynamic seat numbers (1 to 50)
void initializeTheater() {
    int seatCount = 1;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            theater[i][j].seatNumber = seatCount++;
            strcpy(theater[i][j].passengerName, "");
            theater[i][j].isActive = 0;
        }
    }
}

// Render a visual map of the seating layout
void displaySeats() {
    printf("\n----------- SEATING CHART -----------\n");
    printf("   [STAGE / SCREEN THIS WAY]\n\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(theater[i][j].isActive == 1) {
                printf("[ XX ] "); // XX denotes an already occupied seat
            } else {
                printf("[%02d ] ", theater[i][j].seatNumber); // Displays available seat ID
            }
        }
        printf("\n");
    }
    printf("-------------------------------------\n");
}

// Helper function to map a 1-50 seat number to its exact matrix row and column
int getSeatCoordinates(int seatNum, int *r, int *c) {
    if(seatNum < 1 || seatNum > (ROWS * COLS)) {
        return 0; // Out of bounds
    }
    *r = (seatNum - 1) / COLS;
    *c = (seatNum - 1) % COLS;
    return 1;
}

// Core logic to handle reservation and capture user data
void bookTicket() {
    int seatNum, r, c;
    displaySeats();
    
    printf("Enter the seat number you want to book (1-50): ");
    scanf("%d", &seatNum);

    if(!getSeatCoordinates(seatNum, &r, &c)) {
        printf("Error: Invalid seat number choice!\n");
        return;
    }

    if(theater[r][c].isActive == 1) {
        printf("Sorry, Seat %d is already taken.\n", seatNum);
        return;
    }

    printf("Enter Passenger Name: ");
    while(getchar() != '\n'); // Clear trailing newlines
    fgets(theater[r][c].passengerName, 50, stdin);
    theater[r][c].passengerName[strcspn(theater[r][c].passengerName, "\n")] = 0; // Strip newline character

    theater[r][c].isActive = 1;
    printf("\nSuccess! Ticket for Seat %d booked for %s.\n", seatNum, theater[r][c].passengerName);
    printf("Total Cost: $%.2f\n", TICKET_PRICE);
}

// Core logic to process cancellations and free up index spaces
void cancelTicket() {
    int seatNum, r, c;
    printf("Enter the seat number to cancel booking: ");
    scanf("%d", &seatNum);

    if(!getSeatCoordinates(seatNum, &r, &c)) {
        printf("Error: Invalid seat number.\n");
        return;
    }

    if(theater[r][c].isActive == 0) {
        printf("This seat is not currently booked.\n");
        return;
    }

    printf("Booking for %s at Seat %d has been successfully canceled.\n", theater[r][c].passengerName, seatNum);
    theater[r][c].isActive = 0;
    strcpy(theater[r][c].passengerName, "");
}

// Metric calculator evaluating active arrays against base pricing
void viewRevenue() {
    int activeBookings = 0;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(theater[i][j].isActive == 1) {
                activeBookings++;
            }
        }
    }
    printf("\n========== FINANCIAL REPORT ==========\n");
    printf("Total Tickets Sold: %d\n", activeBookings);
    printf("Total Revenue Gathered: $%.2f\n", activeBookings * TICKET_PRICE);
    printf("======================================\n");
}
