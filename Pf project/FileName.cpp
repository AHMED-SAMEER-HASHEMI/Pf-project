#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

// Global variables
unordered_set<string> registeredVoters;  // To store registered voter IDs
unordered_set<string> votedVoters;       // To track who has voted
vector<string> candidates;               // List of candidates
int voteCounts[100];                     // Array to count votes for each candidate

// Function to register a voter
void registerVoter() {
    string voterID;
    cout << "Enter Voter ID: ";
    cin >> voterID;

    // Check if the voter is already registered
    if (registeredVoters.find(voterID) != registeredVoters.end()) {
        cout << "This Voter ID is already registered.\n";
        return;
    }

    // Register the voter
    registeredVoters.insert(voterID);
    cout << "Voter registered successfully.\n";
}
003
// Function to authenticate voter using a simple password
bool authenticateVoter(const string& voterID) {
    string password;
    cout << "Enter password for voter " << voterID << ": ";
    cin >> password;

    // Check if the password matches (same for all voters)
    if (password == "12345") {
        return true;
    }
    else {
        cout << "Authentication failed.\n";
        return false;
    }
}

// Function to cast a vote
void castVote() {
    string voterID;
    cout << "Enter Voter ID: ";
    cin >> voterID;

    // Check if the voter is registered
    if (registeredVoters.find(voterID) == registeredVoters.end()) {
        cout << "You are not registered to vote.\n";
        return;
    }

    // Check if the voter has already voted
    if (votedVoters.find(voterID) != votedVoters.end()) {
        cout << "You have already voted.\n";
        return;
    }

    // Authenticate voter
    if (!authenticateVoter(voterID)) {
        return;
    }

    // Show candidates
    cout << "Candidates:\n";
    for (int i = 0; i < candidates.size(); i++) {
        cout << i + 1 << ". " << candidates[i] << endl;
    }

    int choice;
    cout << "Enter the number of the candidate you want to vote for: ";
    cin >> choice;

    // Check if the choice is valid
    if (choice < 1 || choice > candidates.size()) {
        cout << "Invalid choice.\n";
        return;
    }

    // Register the vote
    votedVoters.insert(voterID);
    voteCounts[choice - 1]++;
    cout << "Vote cast successfully.\n";
}

// Function to count and display votes for each candidate
void countVotes() {
    cout << "\nVote Results:\n";
    for (int i = 0; i < candidates.size(); i++) {
        cout << candidates[i] << ": " << voteCounts[i] << " vote(s)\n";
    }
}

// Function to set up candidates for the election
void setCandidates() {
    int numCandidates;
    cout << "Enter the number of candidates: ";
    cin >> numCandidates;

    candidates.clear();  // Clear previous candidates

    for (int i = 0; i < numCandidates; i++) {
        string candidate;
        cout << "Enter name of candidate " << i + 1 << ": ";
        cin >> candidate;
        candidates.push_back(candidate);
    }

    // Reset vote counts
    for (int i = 0; i < 100; i++) {
        voteCounts[i] = 0;
    }
    cout << "Candidates set successfully.\n";
}

// Function to display the menu
void displayMenu() {
    cout << "\n--- Digital Election System ---\n";
    cout << "1. Register Voter\n";
    cout << "2. Cast Vote\n";
    cout << "3. Count Votes\n";
    cout << "4. Set Candidates\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Main function
int main() {
    bool running = true;
    int choice;

    // Initialize the system
    setCandidates();  // Admin sets candidates at the start

    while (running) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            registerVoter();  // Register a voter
            break;
        case 2:
            castVote();  // Cast a vote
            break;
        case 3:
            countVotes();  // Count and display votes
            break;
        case 4:
            setCandidates();  // Set up the candidates
            break;
        case 5:
            running = false;  // Exit the program
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
