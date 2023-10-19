// Libraries
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <locale.h>
#include <fstream>
#include <iostream>
using namespace std;

string line;

//TDA
struct vehicle {
	// Attributes
	char model[20];
	char brand[20];
	int year;
	int passengers;
	int doors;
	char color[20];
	char plate[20];
	char owner[20];
	int infractions;
	char transmission[20];
	// Pointers
	vehicle *next;
	vehicle *prev;
};

vehicle *FIRST = NULL;
vehicle *LAST = NULL;

// Function prototypes
void menu(void);
void insertStart(void);
void insertEnd(void);
void deleteStart(void);
void deleteEnd(void);
void showVehicles(void);
void searchYear(void);
void searchOwner(void);
void sortByYear(void);
void backup(void);
void readData(void);


// Main function
int main(void) {
    // Variables
    int option;
	
	// Switch
    do {
        system("cls");
        menu();
        cout << "\nEnter a menu option --> ";
        cin >> option;
        switch (option) {
            case 1:
                insertStart();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                deleteStart();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                showVehicles();
                break;
            case 6:
                searchYear();
                break;
            case 7:
                searchOwner();
                break;
            case 8:
                sortByYear();
                break;
            case 9:
                backup();
                break;
            case 10:
                readData();
                break;
            case 0:
                cout << "You selected to exit." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        } // Switch
        system("pause");
    } while (option != 0);

    return 0;
} // Main

// Functions----------------------------------------------------------------

// #0 Menu function, user interface
void menu(void) {
    cout << "                Vehicle Registry" << endl;
    cout << "______________________________________________________________" << endl;
    cout << "Welcome to the vehicle registry! Select an option below:\n" << endl;

    cout << "1) Add a vehicle to the start of the list" << endl;
    cout << "2) Add a vehicle to the end of the list" << endl;
    cout << "3) Delete the first vehicle in the list" << endl;
    cout << "4) Delete the last vehicle in the list" << endl;
    cout << "5) Show all registered vehicles" << endl;
    cout << "6) Search for vehicles by year" << endl;
    cout << "7) Search for vehicles by owner" << endl;
    cout << "8) Sort vehicles in ascending order by year" << endl;
    cout << "9) Backup information to a file" << endl;
    cout << "10) Consult data from the file\n" << endl;

    cout << "0) Exit" << endl;
} // Menu

/// #1 Function to add a vehicle to the start of the list
void insertStart(void) {
    // 1) Declare the pointer variable
    vehicle *newVehicle;
	
	/// 2) Request memory
    newVehicle = (vehicle *)malloc(sizeof(vehicle));
	
	// 3) Validate the pointer
    if (newVehicle == NULL) {
        cout << "Not enough memory available" << endl;
        return;
    }
	
	// 4) Store information
    cout << "Enter vehicle details" << endl;
    cout << "------------------------" << endl;
    cin.ignore();

	cout << "Model -->" << endl;
    cin.getline(newVehicle->model, 20, '\n');

    cout << "Brand -->" << endl;
    cin.getline(newVehicle->brand, 20, '\n');

	do {
        // Validate that it's a valid year
        cout << "Year of the vehicle (between 1950 and 2022) -->" << endl;
        cin >> newVehicle->year;
        if (newVehicle->year < 1950 || newVehicle->year > 2022) {
            cout << "Invalid year" << endl;
            cin.ignore();
        }
    } while (newVehicle->year < 1950 || newVehicle->year > 2022);
	
	do {
        // Validate that the number of passengers is greater than 0
        cout << "Number of passengers -->" << endl;
        cin >> newVehicle->passengers;
        if (newVehicle->passengers <= 0) {
            cout << "The vehicle must have at least 1 passenger" << endl;
        }
    } while (newVehicle->passengers <= 0);
	
	do {
        // Validate that the number of doors is greater than 0
        cout << "Number of doors -->" << endl;
        cin >> newVehicle->doors;
        if (newVehicle->doors <= 0) {
            cout << "The vehicle must have at least 1 door" << endl;
        }
    } while (newVehicle->doors <= 0);
	
	cout << "Color -->" << endl;
    cin >> newVehicle->color;

    cout << "Plate -->" << endl;
    cin >> newVehicle->plate;
    cin.ignore();

    cout << "Owner --> " << endl;
    cin.getline(newVehicle->owner, 20, '\n');
	
	do {
        // Validate that infractions are not negative
        cout << "Infractions -->" << endl;
        cin >> newVehicle->infractions;
        if (newVehicle->infractions < 0) {
            cout << "Infractions cannot be a negative number" << endl;
        }
    } while (newVehicle->infractions < 0);
	
	cout << "Transmission -->" << endl;
    cin >> newVehicle->transmission;
    cout << "------------------------" << endl;
	
	//# 5) Add it to the beginning of the Doubly Linked List of Vehicles
// case a) Empty List
if (FIRST == NULL || LAST == NULL) {
    newVehicle->next = NULL;
    newVehicle->prev = NULL;
    FIRST = newVehicle;
    LAST = newVehicle;
    cout << "Added successfully!" << endl;
    return;
}// if

// case b) Non-empty List
newVehicle->prev = NULL;
newVehicle->next = FIRST;
FIRST->prev = newVehicle;
FIRST = newVehicle;
cout << "Added successfully!" << endl;
return;
}//insertAtBeginning

//# 2 Function to add a vehicle to the end of the list
void insertEnd(void) {
    // 1) Declare the pointer variable
    vehicle *newVehicle;

    // 2) Request memory
    newVehicle = (vehicle *)malloc(sizeof(vehicle));

    // 3) Validate the pointer
    if (newVehicle == NULL) {
        cout << "Not enough memory available" << endl;
        return;
    }//if

    // 4) Store information
    cout << "Enter vehicle data" << endl;
    cout << "--------------------------------" << endl;
    cin.ignore();

    cout << "Model -->" << endl;
    cin.getline(newVehicle->model, 20, '\n');

    cout << "Brand -->" << endl;
    cin.getline(newVehicle->brand, 20, '\n');

    do {
        // Validate that it is a valid year
        cout << "Vehicle year (between 1950 and 2022) -->" << endl;
        cin >> newVehicle->year;
        if (newVehicle->year < 1950 || newVehicle->year > 2022) {
            cout << "Invalid year" << endl;
            cin.ignore();
        }//if
    } while (newVehicle->year < 1950 || newVehicle->year > 2022);

    do {
        // Validate that the number of passengers is greater than 0
        cout << "Number of passengers -->" << endl;
        cin >> newVehicle->passengers;
        if (newVehicle->passengers <= 0) {
            cout << "The vehicle must have at least 1 passenger" << endl;
        }
    } while (newVehicle->passengers <= 0);

    do {
        // Validate that the number of doors is greater than 0
        cout << "Number of doors -->" << endl;
        cin >> newVehicle->doors;
        if (newVehicle->doors <= 0) {
            cout << "The vehicle must have at least 1 door" << endl;
        }
    } while (newVehicle->doors <= 0);

    cout << "Color -->" << endl;
    cin >> newVehicle->color;

    cout << "License Plate -->" << endl;
    cin >> newVehicle->plate;
    cin.ignore();

    cout << "Owner --> " << endl;
    cin.getline(newVehicle->owner, 20, '\n');

    do {
        // Validate that the number of infractions is not less than 0
        cout << "Infractions -->" << endl;
        cin >> newVehicle->infractions;
        if (newVehicle->infractions < 0) {
            cout << "Infractions cannot be a negative number" << endl;
        }
    } while (newVehicle->infractions < 0);

    cout << "Transmission -->" << endl;
    cin >> newVehicle->transmission;
    cout << "---------------------------------" << endl;

    // 5) Add it to the end of the Doubly Linked List of Vehicles
    // case a) Empty List
    if (FIRST == NULL || LAST == NULL) {
        newVehicle->next = NULL;
        newVehicle->prev = NULL;
        FIRST = newVehicle;
        LAST = newVehicle;
        cout << "Added successfully!" << endl;
        return;
    }// if

    // case b) Non-empty Doubly Linked List
    newVehicle->next = NULL;
    newVehicle->prev = LAST;
    LAST->next = newVehicle;
    LAST = newVehicle;
}//insertAtEnd

//# 3 Function to delete the first vehicle in the list
void deleteStart(void) {
    // Declaration of variables
    vehicle *toDelete = FIRST;

    // case a) Empty List
    if (FIRST == NULL) {
        cout << "Nothing to delete here" << endl;
        return;
    }//if

    cout << "Data of the vehicle to delete" << endl;
    cout << "_____________________________" << endl;
    cout << "Model: " << toDelete->model << endl;
    cout << "Brand: " << toDelete->brand << endl;
    cout << "Year: " << toDelete->year << endl;
    cout << "Number of passengers: " << toDelete->passengers << endl;
    cout << "Number of doors: " << toDelete->doors << endl;
    cout << "Color: " << toDelete->color << endl;
    cout << "License Plate: " << toDelete->plate << endl;
    cout << "Owner: " << toDelete->owner << endl;
    cout << "Infractions: " << toDelete->infractions << endl;
    cout << "Transmission: " << toDelete->transmission << endl;
    cout << "_______________________________" << endl;

    // case b) List with 1 node
    if (FIRST == LAST) {
        free(toDelete);
        cout << "Record deleted successfully";
        FIRST = LAST = NULL;
        return;
    }//if

    // case c) List with 2 or more nodes
    FIRST = FIRST->next;
    FIRST->prev = NULL;
    free(toDelete);
    cout << "Record deleted successfully";
    return;
}//deleteStart

//# 4 Function to delete the last vehicle in the list
void deleteEnd(void) {
    // Declaration of variables
    vehicle *toDelete = FIRST;

    // case a) Empty List
    if (FIRST == NULL) {
        cout << "Nothing to delete here" << endl;
        return;
    }//if

    cout << "Data of the vehicle to delete" << endl;
    cout << "_____________________________" << endl;
    cout << "Model: " << toDelete->model << endl;
    cout << "Brand: " << toDelete->brand << endl;
    cout << "Year: " << toDelete->year << endl;
    cout << "Number of passengers: " << toDelete->passengers << endl;
    cout << "Number of doors: " << toDelete->doors << endl;
    cout << "Color: " << toDelete->color << endl;
    cout << "License Plate: " << toDelete->plate << endl;
    cout << "Owner: " << toDelete->owner << endl;
    cout << "Infractions: " << toDelete->infractions << endl;
    cout << "Transmission: " << toDelete->transmission << endl;
    cout << "_______________________________" << endl;

    // case b) List with 1 node
    if (FIRST == LAST) {
        free(toDelete);
        cout << "Record deleted successfully";
        FIRST = LAST = NULL;
        return;
    }//if

    // case c) List with 2 or more nodes
    LAST = LAST->prev;
    LAST->next = NULL;
    free(toDelete);
    cout << "Record deleted successfully";
    return;
}//deleteAtEnd

//# 5 Function to display all vehicles in the list
void showVehicles(void) {
    // Declare a pointer
    vehicle *copy = FIRST;

    // a) Empty List
    if (FIRST == NULL) {
        cout << "Nothing to see" << endl;
        return;
    }//if

    // b) Non-empty List
    system("cls");
    cout << "Vehicles registered in the list" << endl;
    while (copy != NULL) {
        cout << "______________________________________" << endl;
        cout << "Model: " << copy->model << endl;
        cout << "Brand: " << copy->brand << endl;
        cout << "Year: " << copy->year << endl;
        cout << "Number of passengers: " << copy->passengers << endl;
        cout << "Number of doors: " << copy->doors << endl;
        cout << "Color: " << copy->color << endl;
        cout << "License Plate: " << copy->plate << endl;
        cout << "Owner: " << copy->owner << endl;
        cout << "Infractions: " << copy->infractions << endl;
        cout << "Transmission: " << copy->transmission << endl;
        cout << "______________________________________" << endl;
        copy = copy->next;
    }//while
    cout << "__________________________________________" << endl;

    return;
}//showVehicles

//# 6 Function to display all vehicles with the same year in the list
void searchYear(void) {
    // Declaration of variables
    int targetYear;
    vehicle *copy = FIRST;

    // Empty List, no vehicles
    if (FIRST == NULL) {
        cout << "No vehicles in the list" << endl;
        return;
    }//if

    // Request the year of the vehicle
    cout << "Enter the year of the vehicle to search --> ";
    cin >> targetYear;
    cin.ignore();

    while (copy != NULL) {
        if (targetYear == copy->year) {
            cout << "Data of the found vehicle" << endl;
            cout << "_____________________________" << endl;
            cout << "Model: " << copy->model << endl;
            cout << "Brand: " << copy->brand << endl;
            cout << "Year: " << copy->year << endl;
            cout << "Number of passengers: " << copy->passengers << endl;
            cout << "Number of doors: " << copy->doors << endl;
            cout << "Color: " << copy->color << endl;
            cout << "License Plate: " << copy->plate << endl;
            cout << "Owner: " << copy->owner << endl;
            cout << "Infractions: " << copy->infractions << endl;
            cout << "Transmission: " << copy->transmission << endl;
            cout << "_______________________________" << endl;
        } //if
        if (copy->next == NULL) {
            return;
        }
        copy = copy->next;
    }//while

    cout << "The year " << targetYear << " is not registered in the list" << endl;
    return;
}//searchYear

//# 7 Function to search for the owner of a vehicle
void searchOwner(void) {
    // Declaration of variables
    char targetOwner[20];
    vehicle *copy = FIRST;

    // Empty List, no vehicles
    if (FIRST == NULL) {
        cout << "There are no vehicles in the list" << endl;
        return;
    }//if

    // Request the owner of the vehicle
    cout << "Enter the owner's name to search --> ";
    cin >> targetOwner;

    cin.ignore();
    while (copy != NULL) {
        if (strcmp(targetOwner, copy->owner) == 0) {
            cout << "Data of the found vehicle" << endl;
            cout << "_____________________________" << endl;
            cout << "Model: " << copy->model << endl;
            cout << "Brand: " << copy->brand << endl;
            cout << "Year: " << copy->year << endl;
            cout << "Number of passengers: " << copy->passengers << endl;
            cout << "Number of doors: " << copy->doors << endl;
            cout << "Color: " << copy->color << endl;
            cout << "License Plate: " << copy->plate << endl;
            cout << "Owner: " << copy->owner << endl;
            cout << "Infractions: " << copy->infractions << endl;
            cout << "Transmission: " << copy->transmission << endl;
            cout << "_______________________________" << endl;
            return;
        } //if
        copy = copy->next;
    }//while

    cout << "The owner " << targetOwner << " is not registered in the list" << endl;
    return;
}//searchOwner

//# 8 Function to sort vehicles by their year in ascending order
void sortByYear(void) {
    // Declare a pointer
    vehicle *copy = FIRST, *copy2 = NULL;
    int temp;

    // a) Empty List
    if (FIRST == NULL) {
        cout << "No vehicles are registered" << endl;
        return;
    }//if

    // b) List with 1 node
    if (copy->next == NULL && copy->prev == NULL) {
        cout << "Vehicle Data" << endl;
        cout << "_____________________________" << endl;
        cout << "Model: " << copy->model << endl;
        cout << "Brand: " << copy->brand << endl;
        cout << "Year: " << copy->year << endl;
        cout << "Number of passengers: " << copy->passengers << endl;
        cout << "Number of doors: " << copy->doors << endl;
        cout << "Color: " << copy->color << endl;
        cout << "License Plate: " << copy->plate << endl;
        cout << "Owner: " << copy->owner << endl;
        cout << "Infractions: " << copy->infractions << endl;
        cout << "Transmission: " << copy->transmission << endl;
        cout << "_______________________________" << endl;
        return;
    }//if

    // c) List with 2 or more nodes
    while (copy != NULL) {
        copy2 = copy->next;
        while (copy2 != NULL) {
            if (copy->year > copy2->year) {
                temp = copy->year;
                copy->year = copy2->year;
                copy2->year = temp;
            } //if
            copy2 = copy2->next;
        } //while
        cout << "Vehicle Data" << endl;
        cout << "_____________________________" << endl;
        cout << "Model: " << copy->model << endl;
        cout << "Brand: " << copy->brand << endl;
        cout << "Year: " << copy->year << endl;
        cout << "Number of passengers: " << copy->passengers << endl;
        cout << "Number of doors: " << copy->doors << endl;
        cout << "Color: " << copy->color << endl;
        cout << "License Plate: " << copy->plate << endl;
        cout << "Owner: " << copy->owner << endl;
        cout << "Infractions: " << copy->infractions << endl;
        cout << "Transmission: " << copy->transmission << endl;
        cout << "_______________________________" << endl;
        if (copy->next == NULL) {
            return;
        } //if
        copy = copy->next;
    }//while principal

}//sortByYear

//# 9 Backup the data saved in the list to a file

void backup(void) {
    ofstream saveFile;

    // Check if the list is empty
    if (FIRST == NULL) {
        cout << "No data to back up" << endl;
        return;
    }//if

    // Open the file for writing
    saveFile.open("backup.txt", ios::app);

    // Save vehicle data to the file
    saveFile << "Vehicles registered in the list" << endl;
    vehicle *copy = FIRST;
    while (copy != NULL) {
        saveFile << "______________________________________" << endl;
        saveFile << "Model: " << copy->model << endl;
        saveFile << "Brand: " << copy->brand << endl;
        saveFile << "Year: " << copy->year << endl;
        saveFile << "Number of passengers: " << copy->passengers << endl;
        saveFile << "Number of doors: " << copy->doors << endl;
        saveFile << "Color: " << copy->color << endl;
        saveFile << "License Plate: " << copy->plate << endl;
        saveFile << "Owner: " << copy->owner << endl;
        saveFile << "Infractions: " << copy->infractions << endl;
        saveFile << "Transmission: " << copy->transmission << endl;
        saveFile << "______________________________________" << endl;
        copy = copy->next;
    }

    // Close the file
    saveFile.close();

    cout << "Data saved successfully!" << endl;
}

//10# Function to read the saved data from the file
void readData(void) {
    string line;
    string text;

    // Open the file for reading
    ifstream file("backup.txt");

    // Read the file line by line
    while (getline(file, line)) {
        text = text + line + "\n";
    }

    // Close the file
    file.close();

    // Display the read data
    cout << text << endl;
}
