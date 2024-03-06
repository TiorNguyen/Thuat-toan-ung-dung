// Write a C program to perform some queries on a telco data (comming from stdin) with the following format:
// The first block of data consists of lines (terminated by a line containing #), each line (number of lines can be up to 100000) is under the form: 
//         call <from_number> <to_number> <date> <from_time> <end_time> 
// which is a call from the phone number <from_number> to a phone number <to_number> on <date>, and starting at time-point <from_time>, terminating at time-point <end_time>
// <from_number> and <to_number> are string of 10 characters (a phone number is correct if it contains only digits 0,1,...,9, otherwise, the phone number is incorrect)
// <date> is under the form YYYY-MM-DD (for example 2022-10-21)
// <from_time> and <to_time> are under the form hh:mm:ss (for example, 10:07:23)
 
// The second block consists of queries (terminated by a line containing #), each query in a line (number of lines can be up to 100000) and belongs to one of the following types:
// ?check_phone_number: print to stdout (in a new line) value 1 if no phone number is incorrect
// ?number_calls_from <phone_number>: print to stdout (in a new line) the number of times a call is made from <phone_number>
// ?number_total_calls: print to stdout (in a new line) the total number of calls of the data
// ?count_time_calls_from <phone_number>: print to stdout (in a new line) the total time duration (in seconds) the calls are made from <phone_number>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

// Struct to represent a call record
struct Call {
    string from_number;
    string to_number;
    string date;
    string from_time;
    string end_time;
};

// Function to check if a phone number is valid (contains only digits)
bool isValidPhoneNumber(const string& number) {
    for (char c : number) {
        if (!isdigit(c)) {
            return false; // Invalid phone number
        }
    }
    return true; // Valid phone number
}

int main() {
    vector<Call> calls;
    string line;

    // Read and store call data
    while (getline(cin, line) && line != "#") {
        istringstream iss(line);
        string type;
        iss >> type;

        if (type == "call") {
            Call call;
            iss >> call.from_number >> call.to_number >> call.date >> call.from_time >> call.end_time;
            if (!isValidPhoneNumber(call.from_number) || !isValidPhoneNumber(call.to_number)) {
                cerr << "Warning: Invalid phone number" << endl;
                continue;
            }
            calls.push_back(call);
        }
    }

    // Process queries
    while (getline(cin, line) && line != "#") {
        istringstream iss(line);
        string query;
        iss >> query;

        if (query == "?check_phone_number") {
            bool allValid = true;
            for (const Call& call : calls) {
                if (!isValidPhoneNumber(call.from_number) || !isValidPhoneNumber(call.to_number)) {
                    allValid = false;
                    break;
                }
            }
            cout << (allValid ? "1" : "0") << endl;
        } else if (query == "?number_calls_from") {
            string phone_number;
            iss >> phone_number;
            int count = 0;
            for (const Call& call : calls) {
                if (call.from_number == phone_number) {
                    count++;
                }
            }
            cout << count << endl;
        } else if (query == "?number_total_calls") {
            cout << calls.size() << endl;
        } else if (query == "?count_time_calls_from") {
            string phone_number;
            iss >> phone_number;
            int totalDuration = 0;
            for (const Call& call : calls) {
                if (call.from_number == phone_number) {
                    // Parse time and calculate duration in seconds
                    int from_hour, from_min, from_sec, end_hour, end_min, end_sec;
                    sscanf(call.from_time.c_str(), "%d:%d:%d", &from_hour, &from_min, &from_sec);
                    sscanf(call.end_time.c_str(), "%d:%d:%d", &end_hour, &end_min, &end_sec);
                    totalDuration += (end_hour - from_hour) * 3600 + (end_min - from_min) * 60 + (end_sec - from_sec);
                }
            }
            cout << totalDuration << endl;
        }
    }

    return 0;
}
