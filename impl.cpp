#include "menu.h"

MenuRestaurant::MenuRestaurant() {}
MenuRestaurant::~MenuRestaurant() {}

void MenuRestaurant::addDish(const std::string& dish, const double price) {
    dishes.push_back(dish);
    prices.push_back(price);
}

void MenuRestaurant::getMenu() const {
    std::cout << "\033[1;31mՁեզ ենք ներկայացնում մեր մենյուն`\033[0m\n" << std::endl;
    for (size_t i = 0; i < dishes.size(); ++i) {
        std::cout << "Ուտելիքը` " << dishes[i] << " - Գինը՝ " << prices[i] << std::endl;
    }
}

size_t MenuRestaurant::getMenuSize() const {
    return dishes.size();
}

Restaurant::Restaurant() : rest_rating(0) {}
Restaurant::~Restaurant() {}

void Restaurant::setName(const std::string& name) {
    rest_name = name;
}

void Restaurant::setAddr(const std::string& address) {
    rest_address = address;
}

void Restaurant::setRating(int rating) {
    rest_rating = rating;
}

std::string Restaurant::getName() const {
    return rest_name;
}

std::string Restaurant::getAddr() const {
    return rest_address;
}

int Restaurant::getRating() const {
    return rest_rating;
}

bool Restaurant::getDishPrice(const std::string& dish, double &price) const {
    for (int i = 0; i < dishes.size(); ++i) {
        if (dishes[i] == dish) {
            price = prices[i];
            return true;
        }
    }
    return false;
}

MenuAm::MenuAm() {}
MenuAm::~MenuAm() {}

void MenuAm::addRestaurant(const Restaurant& rest) {
    restaurants.push_back(rest);
}

void MenuAm::displayRestaurants() const {
    std::cout << "\033[1;31mԲարև Ձեզ! Ուրախ ենք Ձեզ տեսնել մեր ռեստորանների ցանցում: Եկեք ծանոթանանք ռեստորաններին`\033[0m\n" << std::endl;
    for (size_t i = 0; i < restaurants.size(); ++i) {
        std::cout << restaurants[i].getName() << std::endl;
        std::cout << "Հասցե` " << restaurants[i].getAddr() << std::endl;
        std::cout << "Rating " << restaurants[i].getRating() << std::endl;
        std::cout << std::endl;
    }
}

Restaurant* MenuAm::findRestaurantByName(const std::string& name) {
    for (int i = 0; i < restaurants.size(); ++i) {
        if (restaurants[i].getName() == name) {
            return &restaurants[i];
        }
    }
    return nullptr;
}

Box::Box() : currentRestaurant(nullptr) {}
Box::~Box() {}

void Box::setRestaurant(Restaurant* restaurant) {
    currentRestaurant = restaurant;
}

void Box::addToBox(const std::string& dish) {
    if (currentRestaurant == nullptr) {
        std::cout << "Ռեստորան ընտրված չէ։ " << std::endl;
        return;
    }

    double price;
    if (currentRestaurant->getDishPrice(dish, price)) {
        selectedDishes.push_back(dish);
        selectedPrices.push_back(price);
    } else {
        std::cout << "Նման ուտելիք չկա մենյունում։" << std::endl;
    }

    for (int i = 0; i < selectedDishes.size(); ++i) {
        std::cout << selectedDishes[i] << std::endl;
    }
}

double Box::totalPrice() const {
    double totalCount = 0;
    for (int i = 0; i < selectedDishes.size(); ++i) {
        totalCount += selectedPrices[i];
    }

    return totalCount;
}

void Box::displayBox() const {
    if (selectedDishes.size() == 0) {
        std::cout << "\033[1;36mԴուք պատվեր չեք գրանցել:\033[0m\n";
        return;
    } else {
        double total = totalPrice();
        std::cout << "Ձեր պատվերը` "; 
        for (size_t i = 0; i < selectedDishes.size(); ++i) {
            std::cout << selectedDishes[i] << " - " << selectedPrices[i] << "\n";
            
        }
        std::cout << "Ընդհանուր գինը: " << total << " դրամ" << std::endl;
    }
}


void Box::pay(double amountPaid) const {
     if (selectedDishes.size() == 0) {
        std::cout << "\033[1;36mԴուք պատվեր չեք գրանցել:\033[0m\n";
        return;
    }

    std::cout << "Վճարված գումարը` " << amountPaid << " դրամ" << std::endl;
    if (amountPaid < totalPrice()) {
        std::cout << "Գումարը անբավարար է։ Փորձեք կրկնին:" << std::endl;
    } else if (amountPaid > totalPrice()) {
        double change = amountPaid - totalPrice();
        std::cout << "Վերադարձված գումարը` " << change << " դրամ" << std::endl;
        std::cout << "Վճարումը հաստատված է։ Շնորհակալություն մեր ծառայություններից օգտվելու համար:" << std::endl;
    } else if (amountPaid == totalPrice()) {
        std::cout << "Վճարումը հաստատված է։ Շնորհակալություն մեր ծառայություններից օգտվելու համար:" << std::endl;
    }
}
