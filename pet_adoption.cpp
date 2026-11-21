#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Define the structure for a pet record
struct Pet {
    int id;
    string name;
    string animalType;
    string breed;
    int age;
    string gender;
    string adoptionStatus;
};

// Maximum number of pet records
const int MAX_PETS = 100;

void addPet(Pet pets[], int &petCount, int &nextPetID) {

	// Check if pet storage is full
	if (petCount >= MAX_PETS) {
	    cout << "\nPet storage is full!" << endl;
	    cout << "Cannot add more pet records." << endl;
	    return;
	}

    // Pet information will be entered here
	Pet newPet;

    newPet.id = nextPetID;
    
    cout << "Pet ID: " << newPet.id << endl;
    
    cout << "Enter Pet Name: ";
	getline(cin, newPet.name);
	
	while (newPet.name.empty()) {
    cout << "Pet name cannot be empty. Please enter a name: ";
    getline(cin, newPet.name);
	}

	cout << "Enter Animal Type: ";
	getline(cin, newPet.animalType);
	
	while (newPet.animalType.empty()) {
    cout << "Animal type cannot be empty. Please enter an animal type: ";
    getline(cin, newPet.animalType);
	}
    
	cout << "Enter Breed Type: ";
	getline(cin, newPet.breed);

	while (newPet.breed.empty()) {
		cout << "Breed cannot be empty. Please enter a breed: ";
		getline(cin, newPet.breed);
	}

	cout << "Enter Age: ";
	
	while (!(cin >> newPet.age) || newPet.age < 0) {
	    cout << "Invalid age. Please enter a valid age: ";
	
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string genderChoice;

		do {
			cout << "\nSelect Gender:" << endl;
			cout << "1. Male" << endl;
			cout << "2. Female" << endl;
			cout << "3. Unknown" << endl;
			cout << "Enter choice: ";
			getline(cin, genderChoice);

			if (genderChoice == "1") {
				newPet.gender = "Male";
			}
			else if (genderChoice == "2") {
				newPet.gender = "Female";
			}
			else if (genderChoice == "3") {
				newPet.gender = "Unknown";
			}
			else {
				cout << "Invalid choice. Please try again." << endl;
			}

		} while (genderChoice != "1" && genderChoice != "2" && genderChoice != "3");
	
	string statusChoice;

	do {
		cout << "\nSelect Adoption Status:" << endl;
		cout << "1. Available" << endl;
		cout << "2. Adopted" << endl;
		cout << "Enter choice: ";
		getline(cin, statusChoice);

		if (statusChoice == "1") {
			newPet.adoptionStatus = "Available";
		}
		else if (statusChoice == "2") {
			newPet.adoptionStatus = "Adopted";
		}
		else {
			cout << "Invalid choice. Please try again." << endl;
		}

	} while (statusChoice != "1" && statusChoice != "2");

	pets[petCount] = newPet;
	petCount++;
	nextPetID++;

	cout << "\nPet record added successfully!" << endl;
}

int findPetIndex(const Pet pets[], int petCount, int targetID) {

    for (int i = 0; i < petCount; i++) {
        if (pets[i].id == targetID) {
            return i;
        }
    }

    return -1;
}


void searchPet(const Pet pets[], int petCount) {

    int searchID;

    cout << "\n===== SEARCH PET RECORD =====" << endl;
    cout << "Enter Pet ID to search: ";

    while (!(cin >> searchID) || searchID <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid Pet ID. Please enter a valid number: ";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = findPetIndex(pets, petCount, searchID);

    if (result != -1) {
        cout << "\nPet record found!" << endl;
        cout << "------------------" << endl;
        cout << "Pet ID: " << pets[result].id << endl;
        cout << "Pet Name: " << pets[result].name << endl;
        cout << "Animal Type: " << pets[result].animalType << endl;
        cout << "Breed: " << pets[result].breed << endl;
        cout << "Age: " << pets[result].age << endl;
        cout << "Gender: " << pets[result].gender << endl;
        cout << "Adoption Status: " << pets[result].adoptionStatus << endl;
    }
    else {
        cout << "\nPet record not found!" << endl;
    }
}


int main() {

    // Create an array to store pet records
    Pet pets[MAX_PETS];

    // Number of pets currently stored
    int petCount = 0;
    int nextPetID = 101;

	// Add the first pet
	addPet(pets, petCount, nextPetID);
	
	// Add the second pet
	addPet(pets, petCount, nextPetID);

	// Search for a pet
searchPet(pets, petCount);

    // Display the pet record
for (int i = 0; i < petCount; i++) {
	
    cout << "PET RECORD DETAILS" << endl;
    cout << "------------------" << endl;
    cout << "Pet ID: " << pets[i].id << endl;
    cout << "Pet Name: " << pets[i].name << endl;
    cout << "Animal Type: " << pets[i].animalType << endl;
    cout << "Breed: " << pets[i].breed << endl;
    cout << "Age: " << pets[i].age << endl;
    cout << "Gender: " << pets[i].gender << endl;
    cout << "Adoption Status: " << pets[i].adoptionStatus << endl;
}

    cout << "\nTotal Pets: " << petCount << endl;

    return 0;
}
