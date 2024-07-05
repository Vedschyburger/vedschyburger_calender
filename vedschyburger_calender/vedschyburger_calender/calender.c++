#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

// Event class definition
class Event {
public:
    Event(const std::string& name, const std::tm& date) : name(name), date(date) {}

    std::string getName() const {
        return name;
    }

    std::tm getDate() const {
        return date;
    }

    void printEvent() const {
        std::cout << "Event: " << name << " on " << date.tm_mday << "/" << date.tm_mon + 1 << "/" << date.tm_year + 1900 << std::endl;
    }

private:
    std::string name;
    std::tm date;
};

// Calendar class definition
class Calendar {
public:
    void addEvent(const Event& event) {
        events.push_back(event);
    }

    void removeEvent(const std::string& eventName) {
        events.erase(std::remove_if(events.begin(), events.end(),
            [&eventName](const Event& event) {
                return event.getName() == eventName;
            }), events.end());
    }

    void showEvents() const {
        if (events.empty()) {
            std::cout << "No events in the calendar." << std::endl;
        } else {
            for (const auto& event : events) {
                event.printEvent();
            }
        }
    }

private:
    std::vector<Event> events;
};

// Function to print the menu
void printMenu() {
    std::cout << "1. Add Event\n2. Remove Event\n3. Show Events\n4. Exit\n";
}

// Function to create a date
std::tm createDate(int day, int month, int year) {
    std::tm date = {};
    date.tm_mday = day;
    date.tm_mon = month - 1;
    date.tm_year = year - 1900;
    return date;
}

// Main function
int main() {
    Calendar calendar;
    int choice;

    while (true) {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string name;
            int day, month, year;
            std::cout << "Enter event name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter event date (day month year): ";
            std::cin >> day >> month >> year;

            std::tm date = createDate(day, month, year);
            Event event(name, date);
            calendar.addEvent(event);

        } else if (choice == 2) {
            std::string name;
            std::cout << "Enter event name to remove: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            calendar.removeEvent(name);

        } else if (choice == 3) {
            calendar.showEvents();

        } else if (choice == 4) {
            break;

        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
