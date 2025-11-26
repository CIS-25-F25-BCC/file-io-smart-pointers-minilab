// Problem 2: Broken File Writing
// This code attempts to write a log of transactions to a file, but has several bugs.
// Fix all the issues so the program correctly writes the log.
//
// Expected behavior when fixed:
//   - Creates "transactions.log" with formatted entries
//   - Each entry appears on its own line
//   - All data is actually written to the file (not lost)
//   - Program reports success or failure

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Transaction {
    std::string timestamp;
    std::string type;
    double amount;
};

void logTransactions(const std::vector<Transaction>& transactions,
                     const std::string& filename) {
    std::ofstream file(filename);

    // BUG 1: No error checking if file opened successfully

    for (int i = 0; i < transactions.size(); i++) {
        // BUG 2: Missing newline between entries, format is hard to read
        file << transactions[i].timestamp << " "
             << transactions[i].type << " "
             << transactions[i].amount;
    }

    // BUG 3: Not flushing/closing the file before function returns
    // Data might be lost if program crashes or file isn't properly closed
}

int main() {
    std::vector<Transaction> transactions;

    Transaction t1 = {"2025-11-26 10:30:00", "DEPOSIT", 500.00};
    Transaction t2 = {"2025-11-26 10:31:15", "WITHDRAWAL", 50.00};
    Transaction t3 = {"2025-11-26 10:32:45", "TRANSFER", 200.00};

    transactions.push_back(t1);
    transactions.push_back(t2);
    transactions.push_back(t3);

    logTransactions(transactions, "transactions.log");

    std::cout << "Transactions logged to transactions.log" << std::endl;
    std::cout << "Check the file to verify proper formatting." << std::endl;

    return 0;
}
