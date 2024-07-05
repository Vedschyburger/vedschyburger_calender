#include <iostream>
#include <vector>
#include <string>
#include <ctime>

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
