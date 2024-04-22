// кмзи.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <map>
#include <string>

// Структура за избирател
struct Voter {
    std::string id;
    std::string name;
    bool hasVoted;
};

// Структура за кандидат
struct Candidate {
    std::string id;
    std::string name;
    int votes;
};

// Функция за регистрация на избирател
void registerVoter(std::map<std::string, Voter>& voters) {
    std::string id, name;
    std::cout << "Enter Voter ID: ";
    std::cin >> id;
    std::cout << "Enter Voter Name: ";
    std::cin >> name;

    if (voters.find(id) == voters.end()) {
        voters[id] = { id, name, false };
        std::cout << "Voter registered successfully.\n";
    }
    else {
        std::cout << "Voter already registered.\n";
    }
}

// Функция за добавяне на кандидат
void addCandidate(std::map<std::string, Candidate>& candidates) {
    std::string id, name;
    std::cout << "Enter Candidate ID: ";
    std::cin >> id;
    std::cout << "Enter Candidate Name: ";
    std::cin >> name;

    if (candidates.find(id) == candidates.end()) {
        candidates[id] = { id, name, 0 };
        std::cout << "Candidate added successfully.\n";
    }
    else {
        std::cout << "Candidate already exists.\n";
    }
}

// Функция за гласуване
void castVote(std::map<std::string, Voter>& voters, std::map<std::string, Candidate>& candidates) {
    std::string voterID, candidateID;
    std::cout << "Enter your Voter ID: ";
    std::cin >> voterID;

    if (voters.find(voterID) == voters.end() || voters[voterID].hasVoted) {
        std::cout << "Invalid voter ID or you have already voted.\n";
        return;
    }

    std::cout << "Enter Candidate ID you want to vote for: ";
    std::cin >> candidateID;
    if (candidates.find(candidateID) == candidates.end()) {
        std::cout << "Invalid candidate ID.\n";
        return;
    }

    voters[voterID].hasVoted = true;
    candidates[candidateID].votes++;
    std::cout << "Vote cast successfully.\n";
}

int main() {
    std::map<std::string, Voter> voters;
    std::map<std::string, Candidate> candidates;
    int choice;

    do {
        std::cout << "1. Register Voter\n2. Add Candidate\n3. Cast Vote\n4. Show Results\n0. Exit\nEnter choice: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            registerVoter(voters);
            break;
        case 2:
            addCandidate(candidates);
            break;
        case 3:
            castVote(voters, candidates);
            break;
        case 4:
            for (auto& candidate : candidates) {
                std::cout << "Candidate " << candidate.second.name << " has " << candidate.second.votes << " votes.\n";
            }
            break;
        case 0:
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
