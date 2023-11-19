#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Anime {
    string name;
    string genre;
    int score;
    bool air;
};

int main() {
    string name = "temp";
    string password = "temp";
    string login_name = "temp_1";
    string login_password = "temp_2";
    int input;
    string genre_in;
    bool air_in;
    int counter = 0;

    vector<Anime> anime(5);
    vector<vector<Anime>> database(10, vector<Anime>(5));

    // Initialize database
    database[1][0] = {"AOT", "Action", 10, true};
    database[2][0] = {"Death Note", "Thrill", 8, false};
    database[3][0] = {"Hero Academia", "Action", 10, true};
    database[4][0] = {"Haikyu", "Thrill", 7, true};
    database[5][0] = {"OnePunchMan", "Action", 9, false};
    database[3][1] = {"Naruto", "Shonen", 9, false};
    database[3][2] = {"Dragon Ball Z", "Shonen", 10, true};
    database[4][1] = {"Sailor Moon", "Shojo", 8, false};
    database[4][2] = {"Fruits Basket", "Shojo", 9, true};
    database[5][1] = {"Berserk", "Seinen", 9, false};
    database[5][2] = {"Tokyo Ghoul", "Seinen", 10, true};
    database[6][1] = {"Paradise Kiss", "Josei", 7, false};
    database[6][2] = {"Nana", "Josei", 9, true};
    database[7][1] = {"Sword Art Online", "Isekai", 10, false};
    database[7][2] = {"Re:Zero - Starting Life in Another World", "Isekai", 9, true};
    database[8][1] = {"Steins;Gate", "Mecha", 9, false};
    database[8][2] = {"Cowboy Bebop", "Mecha", 7, true};
    database[9][1] = {"Fullmetal Alchemist", "Fantasy", 10, false};
    database[9][2] = {"Attack on Titan", "Fantasy", 9, true};
    // Add more anime entries...

    cout << "TrueSearch:For a true Anime lover" << endl;
    cout << "Please register below to continue!" << endl;
    cout << "Enter a Username: ";
    cin >> name;
    cout << "Enter a Password: ";
    cin >> password;

    cout << "Registration successful!!" << endl;
    cout << "Now you can login!" << endl;

    // Allow three login attempts
    for (int attempt = 1; attempt <= 3; ++attempt) {
        cout << "Username: ";
        cin >> login_name;
        cout << "Password: ";
        cin >> login_password;

        if (password == login_password && name == login_name) {
            cout << "Thank you for logging in!" << endl;
            break;
        } else {
            cout << "Incorrect login credentials. Attempts remaining: " << 3 - attempt << endl;
            if (attempt == 3) {
                cout << "Maximum login attempts reached. Exiting." << endl;
                return 1;
            }
        }
    }

    cout << "Welcome to truesearch!" << endl;
    cout << "What genre of anime do you like?" << endl;
    cout << "1- Action 2- Thrill 3- Shonen 4- Shojo 5- Seinen 6- Isekai 7- Josei 8- Mecha 9- Fantasy : ";
    cin >> input;

    // Convert the if-else ladder into a switch statement for better readability
    switch (input) {
        case 1:
            genre_in = "Action";
            break;
        case 2:
            genre_in = "Thrill";
            break;
        case 3:
            genre_in = "Shonen";
            break;
        case 4:
            genre_in = "Shojo";
            break;
        case 5:
            genre_in = "Seinen";
            break;
        case 6:
            genre_in = "Isekai";
            break;
        case 7:
            genre_in = "Josei";
            break;
        case 8:
            genre_in = "Mecha";
            break;
        case 9:
            genre_in = "Fantasy";
            break;
        default:
            cout << "Invalid input. Exiting." << endl;
            return 1;
    }

    cout << "Do you want it to be on air?" << endl;
    cout << "1- Yes 2- No (Enter 1 or 2): ";
    cin >> input;

    // Simplify the if-else statement using a ternary operator
    air_in = (input == 1) ? true : false;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            if (!database[i][j].name.empty()) {  // Check if the anime entry is not empty
                if (database[i][j].genre == genre_in && database[i][j].air == air_in) {
                    anime[counter] = database[i][j];
                    counter++;
                }
            }
        }
    }

    for (int j = 0; j < counter; j++) {
        cout << "Search Result "<< ": " << anime[j].name << " \nRating: " << anime[j].score << endl;
    }

    return 0;
}
