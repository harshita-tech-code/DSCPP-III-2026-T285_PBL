#include "meal_plan.hpp"

// Base Class Implementation
MealPlan::MealPlan(int id, const std::string& name, double price)
    : planID(id), studentName(name), basePrice(price) {}

MealPlan::~MealPlan() {}

double MealPlan::calculateBill() {
    return basePrice;
}

void MealPlan::displayPlanDetails() const {
    std::cout << "Plan ID: " << planID 
              << " | Student: " << studentName 
              << " | Base Price: Rs. " << basePrice << std::endl;
}

// Derived Class Implementation
MonthlyTiffin::MonthlyTiffin(int id, const std::string& name, double price, bool pause)
    : MealPlan(id, name, price), weekendPause(pause) {}

double MonthlyTiffin::calculateBill() {
    double bill = basePrice * 0.85; // 15% discount on base rate
    if (weekendPause) {
        bill -= 300.0; // Deduct for paused weekends
    }
    return (bill > 0.0) ? bill : 0.0;
}

void MonthlyTiffin::displayPlanDetails() const {
    std::cout << "[Monthly Pass] ID: " << planID 
              << " | Student: " << studentName 
              << " | Final Bill: Rs. " << const_cast<MonthlyTiffin*>(this)->calculateBill()
              << " | Weekend Pause: " << (weekendPause ? "Enabled" : "Disabled")
              << std::endl;
}

void MonthlyTiffin::toggleWeekendPause(bool pause) {
    weekendPause = pause;
}