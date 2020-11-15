// your IDE might require #include "pch.h" to work properly
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int icount; //count item[i], later used as maximum number of objects in array item[200]

struct Items {
    string name= "N/A"; //name of item
    string amount= "N/A"; //amount in warehouse
    string cost= "N/A"; //cost of item in $
    string weight= "N/A"; //weight of item in kg
    string expdate= "N/A"; //expiration date of product (optional)
    string date= "N/A"; //date when item was added to warehouse
    string id= "N/A"; //consecutive id

};
Items item[200];

//declaring functions
bool reading_from_file();
void writing_to_file();
void searching();
void removing();
void adding();
void clear_screen();
void press_any_key_to_continue();



//initialising functions

bool reading_from_file(){
    //Reading from items.txt to objects array item[200]

    icount=0;
    bool isitopen=false;
    ifstream fromFile;
    fromFile.open("items.txt");

    if (!fromFile.is_open())
        cerr << "Couldn't open the file!";
    else {
        isitopen = true;
        string tmpstring; //reading file
        while (!fromFile.eof()) {
            getline(fromFile, tmpstring);
            //ignore empty spaces
            if (tmpstring == "")
                continue;
            item[icount].name = tmpstring.substr(6, tmpstring.size());
            getline(fromFile, tmpstring);
            item[icount].amount = tmpstring.substr(8, tmpstring.size());
            getline(fromFile, tmpstring);
            item[icount].cost = tmpstring.substr(6, tmpstring.size());
            getline(fromFile, tmpstring);
            item[icount].weight = tmpstring.substr(8, tmpstring.size());
            getline(fromFile, tmpstring);
            item[icount].expdate = tmpstring.substr(17, tmpstring.size());
            getline(fromFile, tmpstring);
            item[icount].date = tmpstring.substr(12, tmpstring.size());
            getline(fromFile, tmpstring);
            item[icount].id = tmpstring.substr(4, tmpstring.size());
            icount++; //literally how many, not programmatically
        }
        fromFile.close();
    }
    return isitopen;
}

void writing_to_file(){
    //update file (code->items.txt)

    ofstream toFile;
    toFile.open("items.txt", ios::out | ios::trunc);

    if (!toFile.is_open())
        cerr << "Couldn't open the file!";

    for (int i=0; i<icount; i++) {
        toFile << "" << "\n";
        toFile << "Name: " << item[i].name << "\n";
        toFile << "Amount: " << item[i].amount << "\n";
        toFile << "Cost: " << item[i].cost << "\n";
        toFile << "Weight: " << item[i].weight << "\n";
        toFile << "Expiration date: " << item[i].expdate << "\n";
        toFile << "Date added: " << item[i].date << "\n";
        toFile << "ID: " << item[i].id << "\n";
    }
    toFile.close();
}

void searching(){
    //Search and output
    int choice; //user input category
    string search; //user input name in category
    int foundone=0; //how many items found with same name in category
    cout << "Choose how you want to find an item?" << "\n";
    cout << "1. by Name" << "\n";
    cout << "2. by Amount" << "\n";
    cout << "3. by Cost" << "\n";
    cout << "4. by Weight" << "\n";
    cout << "5. by Expiration date" << "\n";
    cout << "6. by Date added" << "\n";
    cout << "7. by ID" << "\n";
    cout << "Choose a category: ";
    cin >> choice;

    //assume by cost

    switch (choice) {
        case 1: {
            cout << "Input Name: ";
            cin >> search;
            clear_screen();

            for (int i = 0; i < icount; i++) {
                if (item[i].name == search) {
                    foundone++;
                    cout << "Name: " << item[i].name << "\n";
                    cout << "Amount: " << item[i].amount << "\n";
                    cout << "Cost: " << item[i].cost << "\n";
                    cout << "Weight: " << item[i].weight << "\n";
                    cout << "Expiration date: " << item[i].expdate << "\n";
                    cout << "Date added: " << item[i].date << "\n";
                    cout << "ID: " << item[i].id << "\n\n";
                }
            }
            if (foundone <= 0)
                cout << "Didn't find anything!" << "\n";
            else
                cout << "Found " << foundone << " item(s)!" << "\n";
        }
            break;

        case 2: {
            cout << "Input Amount: ";
            cin >> search;
            clear_screen();

            for (int i = 0; i < icount; i++) {
                if (item[i].amount == search) {
                    foundone++;
                    cout << "Name: " << item[i].name << "\n";
                    cout << "Amount: " << item[i].amount << "\n";
                    cout << "Cost: " << item[i].cost << "\n";
                    cout << "Weight: " << item[i].weight << "\n";
                    cout << "Expiration date: " << item[i].expdate << "\n";
                    cout << "Date added: " << item[i].date << "\n";
                    cout << "ID: " << item[i].id << "\n\n";
                }
            }
            if (foundone <= 0)
                cout << "Didn't find anything!" << "\n";
            else
                cout << "Found " << foundone << " item(s)!" << "\n";
        }
        break;

        case 3: {
            cout << "Input Cost: ";
            cin >> search;
            //for (int i=0; i<search.length(); i++){  ToDo: check user input
            //}
            clear_screen();

            for (int i = 0; i < icount; i++) {
                if (item[i].cost == search) {
                    foundone++;
                    cout << "Name: " << item[i].name << "\n";
                    cout << "Amount: " << item[i].amount << "\n";
                    cout << "Cost: " << item[i].cost << "\n";
                    cout << "Weight: " << item[i].weight << "\n";
                    cout << "Expiration date: " << item[i].expdate << "\n";
                    cout << "Date added: " << item[i].date << "\n";
                    cout << "ID: " << item[i].id << "\n\n";
                }
            }
            if (foundone <= 0)
                cout << "Didn't find anything!" << "\n";
            else
                cout << "Found " << foundone << " item(s)!" << "\n";
        }
        break;

        case 4: {
            cout << "Input Weight: ";
            cin >> search;
            clear_screen();

            for (int i = 0; i < icount; i++) {
                if (item[i].weight == search) {
                    foundone++;
                    cout << "Name: " << item[i].name << "\n";
                    cout << "Amount: " << item[i].amount << "\n";
                    cout << "Cost: " << item[i].cost << "\n";
                    cout << "Weight: " << item[i].weight << "\n";
                    cout << "Expiration date: " << item[i].expdate << "\n";
                    cout << "Date added: " << item[i].date << "\n";
                    cout << "ID: " << item[i].id << "\n\n";
                }
            }
            if (foundone <= 0)
                cout << "Didn't find anything!" << "\n";
            else
                cout << "Found " << foundone << " item(s)!" << "\n";
        }
            break;

        case 5: {
            cout << "Input Expiration date: ";
            cin >> search;
            clear_screen();

            for (int i = 0; i < icount; i++) {
                if (item[i].expdate == search) {
                    foundone++;
                    cout << "Name: " << item[i].name << "\n";
                    cout << "Amount: " << item[i].amount << "\n";
                    cout << "Cost: " << item[i].cost << "\n";
                    cout << "Weight: " << item[i].weight << "\n";
                    cout << "Expiration date: " << item[i].expdate << "\n";
                    cout << "Date added: " << item[i].date << "\n";
                    cout << "ID: " << item[i].id << "\n\n";
                }
            }
            if (foundone <= 0)
                cout << "Didn't find anything!" << "\n";
            else
                cout << "Found " << foundone << " item(s)!" << "\n";
        }
        break;

        case 6: {
            cout << "Input Date added: ";
            cin >> search;
            clear_screen();

            for (int i = 0; i < icount; i++) {
                if (item[i].date == search) {
                    foundone++;
                    cout << "Name: " << item[i].name << "\n";
                    cout << "Amount: " << item[i].amount << "\n";
                    cout << "Cost: " << item[i].cost << "\n";
                    cout << "Weight: " << item[i].weight << "\n";
                    cout << "Expiration date: " << item[i].expdate << "\n";
                    cout << "Date added: " << item[i].date << "\n";
                    cout << "ID: " << item[i].id << "\n\n";
                }
            }
            if (foundone <= 0)
                cout << "Didn't find anything!" << "\n";
            else
                cout << "Found " << foundone << " item(s)!" << "\n";
        }
        break;

        case 7: {
            cout << "Input ID: ";
            cin >> search;
            clear_screen();

            for (int i = 0; i < icount; i++) {
                if (item[i].id == search) {
                    foundone++;
                    cout << "Name: " << item[i].name << "\n";
                    cout << "Amount: " << item[i].amount << "\n";
                    cout << "Cost: " << item[i].cost << "\n";
                    cout << "Weight: " << item[i].weight << "\n";
                    cout << "Expiration date: " << item[i].expdate << "\n";
                    cout << "Date added: " << item[i].date << "\n";
                    cout << "ID: " << item[i].id << "\n\n";
                }
            }
            if (foundone <= 0)
                cout << "Didn't find anything!" << "\n";
            else
                cout << "Found " << foundone << " item(s)!" << "\n";
        }
        break;

        default: cout << "Incorrect user input!" << "\n";
        break;
    }

}

void removing() {
    //Remove
    int choice_remove; //user input category
    string remove; //user input name in category
    int foundone_remove; //how many items found with same name in category
    cout << "Choose how you want to remove an item?" << "\n";
    cout << "1. by Name" << "\n";
    cout << "2. by Amount" << "\n";
    cout << "3. by Cost" << "\n";
    cout << "4. by Weight" << "\n";
    cout << "5. by Expiration date" << "\n";
    cout << "6. by Date added" << "\n";
    cout << "7. by ID" << "\n";

    cout << "Choose a category: ";
    cin >> choice_remove;

    switch (choice_remove) {

        case 1: {
            cout << "Input Name: ";
            cin >> remove;

            foundone_remove = 0; //read search function
            for (int i = 0; i < icount; i++) {
                if (item[i].name == remove) {
                    item[i].name = "N/A";
                    item[i].amount = "N/A";
                    item[i].cost = "N/A";
                    item[i].weight = "N/A";
                    item[i].expdate = "N/A";
                    item[i].date = "N/A";
                    item[i].id = "N/A";
                    foundone_remove = 1;
                    cout << "Success!" << "\n";
                    break;
                }
            }
            if (foundone_remove == 0)
                cout << "Didn't find anything to remove!" << "\n";
        }
            break;

        case 2: {
            cout << "Input Amount: ";
            cin >> remove;

            foundone_remove = 0; //read search function
            for (int i = 0; i < icount; i++) {
                if (item[i].amount == remove) {
                    item[i].name = "N/A";
                    item[i].amount = "N/A";
                    item[i].cost = "N/A";
                    item[i].weight = "N/A";
                    item[i].expdate = "N/A";
                    item[i].date = "N/A";
                    item[i].id = "N/A";
                    foundone_remove = 1;
                    cout << "Success!" << "\n";
                    break;
                }
            }
            if (foundone_remove == 0)
                cout << "Didn't find anything to remove!" << "\n";
        }
            break;

        case 3: {
            cout << "Input Cost: ";
            cin >> remove;

            foundone_remove = 0; //read search function
            for (int i = 0; i < icount; i++) {
                if (item[i].cost == remove) {
                    item[i].name = "N/A";
                    item[i].amount = "N/A";
                    item[i].cost = "N/A";
                    item[i].weight = "N/A";
                    item[i].expdate = "N/A";
                    item[i].date = "N/A";
                    item[i].id = "N/A";
                    foundone_remove = 1;
                    cout << "Success!" << "\n";
                    break;
                }
            }
            if (foundone_remove == 0)
                cout << "Didn't find anything to remove!" << "\n";
        }
            break;

        case 4: {
            cout << "Input Weight: ";
            cin >> remove;

            foundone_remove = 0; //read search function
            for (int i = 0; i < icount; i++) {
                if (item[i].weight == remove) {
                    item[i].name = "N/A";
                    item[i].amount = "N/A";
                    item[i].cost = "N/A";
                    item[i].weight = "N/A";
                    item[i].expdate = "N/A";
                    item[i].date = "N/A";
                    item[i].id = "N/A";
                    foundone_remove = 1;
                    cout << "Success!" << "\n";
                    break;
                }
            }
            if (foundone_remove == 0)
                cout << "Didn't find anything to remove!" << "\n";
        }
            break;

        case 5: {
            cout << "Input Expiration date: ";
            cin >> remove;

            foundone_remove = 0; //read search function
            for (int i = 0; i < icount; i++) {
                if (item[i].expdate == remove) {
                    item[i].name = "N/A";
                    item[i].amount = "N/A";
                    item[i].cost = "N/A";
                    item[i].weight = "N/A";
                    item[i].expdate = "N/A";
                    item[i].date = "N/A";
                    item[i].id = "N/A";
                    foundone_remove = 1;
                    cout << "Success!" << "\n";
                    break;
                }
            }
            if (foundone_remove == 0)
                cout << "Didn't find anything to remove!" << "\n";
        }
            break;

        case 6: {
            cout << "Input Date added: ";
            cin >> remove;

            foundone_remove = 0; //read search function
            for (int i = 0; i < icount; i++) {
                if (item[i].date == remove) {
                    item[i].name = "N/A";
                    item[i].amount = "N/A";
                    item[i].cost = "N/A";
                    item[i].weight = "N/A";
                    item[i].expdate = "N/A";
                    item[i].date = "N/A";
                    item[i].id = "N/A";
                    foundone_remove = 1;
                    cout << "Success!" << "\n";
                    break;
                }
            }
            if (foundone_remove == 0)
                cout << "Didn't find anything to remove!" << "\n";
        }
            break;

        case 7: {
            cout << "Input ID: ";
            cin >> remove;

            foundone_remove = 0; //read search function
            for (int i = 0; i < icount; i++) {
                if (item[i].id == remove) {
                    item[i].name = "N/A";
                    item[i].amount = "N/A";
                    item[i].cost = "N/A";
                    item[i].weight = "N/A";
                    item[i].expdate = "N/A";
                    item[i].date = "N/A";
                    item[i].id = "N/A";
                    foundone_remove = 1;
                    cout << "Success!" << "\n";
                    break;
                }
            }
            if (foundone_remove == 0)
                cout << "Didn't find anything to remove!" << "\n";
        }
            break;

        default: cout << "Incorrect user input!" << "\n";
        break;
    }
}

void adding(){
    //Add
    // finding free space (1,2,3,X,5,6,X,8,10) to store new item data

    int thereitis=-1; //first free space cell in file (X) = {N/A N/A N/A N/A N/A}
    for (int i=0; i<icount; i++){
        if (item[i].name=="N/A") {
            thereitis = i;
            break;
        }
    }

    if (thereitis<0) //+1 space only if no "free" spaces available in between file (N/A ones).
        thereitis = icount++;
    string trash;
    getline (cin, trash);
    cout << "Please provide information about new item." << "\n";
    cout << "Name: ";
    getline(cin, item[thereitis].name);
    cout << "Amount: ";
    getline(cin, item[thereitis].amount);
    cout << "Cost: ";
    getline(cin, item[thereitis].cost);
    cout << "Weight: ";
    getline(cin, item[thereitis].weight);
    cout << "Expiration date: ";
    getline(cin, item[thereitis].expdate);
    cout << "Date added: ";
    getline(cin, item[thereitis].date);
    cout << "ID: ";
    getline(cin, item[thereitis].id);

    cout << "New item added successfuly!" << "\n";
}

void clear_screen(){
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void press_any_key_to_continue(){
    cout << "\n" << "Press any key to continue..." << "\n";
    system("read"); //for Windows use "system("pause");"
    clear_screen();
}







int main() {
    //Theme: Warehouse inventory accounting program for grocery store
    bool quit=false;
    int action;

    cout << "Welcome to the program that let's you find items in the warehouse!" << "\n\n";

    while (!quit) {
        reading_from_file();
        writing_to_file();
        cout << "What would you like to do?" << "\n";
        cout << "1. Search for an item in stock" << "\n";
        cout << "2. Remove an item in stock" << "\n";
        cout << "3. Add an item in stock" << "\n";
        cout << "4. Update item list" << "\n";
        cout << "5. FAQ" << "\n";
        cout << "0. Quit" << "\n";
        cout << ">> ";
        cin >> action;

        switch (action) {

            case 1: {
                clear_screen();
                searching();
                press_any_key_to_continue();
            }
                break;

            case 2: {
                clear_screen();
                removing();
                writing_to_file();
                press_any_key_to_continue();
            }
                break;


            case 3: {
                clear_screen();
                adding();
                writing_to_file();
                press_any_key_to_continue();
            }
                break;

            case 4: {
                clear_screen();
                if (reading_from_file()) {
                    cout << "File updated successfully!" << "\n";
                }
                press_any_key_to_continue();
            }
                break;

            case 5: {
                clear_screen();
                cout << "1) \"4. Update item list\" rewrites the information" << "\n";
                cout << "in the file with information temporarily stored" << "\n";
                cout << "in the code.";
                press_any_key_to_continue();
            }
            break;

            case 0: {
                quit = true;
                cout << "Thank you for using the program! Please come again soon." << "\n";
                }
                break;

            default: {
                cout << "Incorrect user input! Please try again." << "\n";
                press_any_key_to_continue();
            }
            break;
        }
    }


    return 0;
}
