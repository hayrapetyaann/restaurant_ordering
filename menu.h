#ifndef MENU
#define MENU

#include <iostream>
#include <vector>
#include <string>

class MenuRestaurant {
protected:
    std::vector<std::string> dishes;
    std::vector<double> prices;
public:
    MenuRestaurant();
    ~MenuRestaurant();
    void addDish(const std::string& dish, const double price);
    void getMenu() const;
    size_t getMenuSize() const;
};


class Restaurant : public MenuRestaurant {
private:
    std::string rest_name;
    std::string rest_address;
    int rest_rating;
public:
    Restaurant();
    void setName(const std::string& name);
    void setAddr(const std::string& address);
    void setRating(int rating);
    std::string getName() const;
    std::string getAddr() const;
    int getRating() const;
    bool getDishPrice(const std::string& dish, double &price) const;
    ~Restaurant();
};

class MenuAm {
protected:
    std::vector<Restaurant> restaurants;
public:
    MenuAm();
    void addRestaurant(const Restaurant& rest);
    void displayRestaurants() const;
    Restaurant* findRestaurantByName(const std::string& name);
    ~MenuAm();
};

class Box {
private:
    std::vector<std::string> selectedDishes;
    std::vector<double> selectedPrices;
    Restaurant* currentRestaurant;  
public:
    Box();
    void setRestaurant(Restaurant* restaurant);
    ~Box();
    void addToBox(const std::string& dish);
    void displayBox() const;
    double totalPrice() const;
    void pay(double amountPaid) const;
};

#endif
