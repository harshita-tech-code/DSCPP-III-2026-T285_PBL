#ifndef MEAL_PLAN_HPP
#define MEAL_PLAN_HPP

#include <iostream>
#include <string>

// Base Class: MealPlan (CPP Units 2 & 3)
class MealPlan {
protected:
    int planID;
    std::string studentName;
    double basePrice;

public:
    MealPlan(int id, const std::string& name, double price);
    virtual ~MealPlan();

    virtual double calculateBill();
    virtual void displayPlanDetails() const;
};

// Derived Class: MonthlyTiffin (CPP Unit 3 - Single Inheritance)
class MonthlyTiffin : public MealPlan {
private:
    bool weekendPause; // Option to skip weekend deliveries

public:
    MonthlyTiffin(int id, const std::string& name, double price, bool pause);
    double calculateBill() override;
    void displayPlanDetails() const override;
    void toggleWeekendPause(bool pause);
};

#endif // MEAL_PLAN_HPP