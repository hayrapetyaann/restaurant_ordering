#include "menu.h"

int main() {
    Restaurant res1;
    Restaurant res2;
    Restaurant res3;
    Restaurant res4;

    res1.setName("Sherep");
    res1.setAddr("Ամիրյան 1");
    res1.setRating(3);
    res1.addDish("Ձվածեղ", 1200);
    res1.addDish("Bruschetta", 2000);
    res1.addDish("Կարտոֆիլ", 2990);

    res2.setName("Amar");
    res2.setAddr("Ձորափի փողոց 35");
    res2.setRating(5);
    res2.addDish("Ձվածեղ", 890);
    res2.addDish("Bruschetta", 1000);
    res2.addDish("Կարտոֆիլ", 5000);

    res3.setName("Katsin");
    res3.setAddr("Ամիրյան 4/6");
    res3.setRating(4);
    res3.addDish("Ձվածեղ", 890);
    res3.addDish("Bruschetta", 1900);
    res3.addDish("Կարտոֆիլ", 2000);

    res4.setName("Lavash");
    res4.setAddr("Թումանյան 21");
    res4.setRating(5);
    res4.addDish("Ձվածեղ", 1090);
    res4.addDish("Bruschetta", 2070);
    res4.addDish("Կարտոֆիլ", 1990);

    MenuAm allRes;
    allRes.addRestaurant(res1);
    allRes.addRestaurant(res2);
    allRes.addRestaurant(res3);
    allRes.addRestaurant(res4);
    allRes.displayRestaurants();

    std::cout << "\033[1;33mՄուտքագրեք Ձեր նախընտրած ռեստորանը\033[0m\n";
    std::string name;
    std::cin >> name;

    Restaurant* selectedRestaurant = allRes.findRestaurantByName(name);

    if (selectedRestaurant) {
        Box box;
        box.setRestaurant(selectedRestaurant);
        selectedRestaurant->getMenu();

        std::string dish;
        std::cout << "Մուտքագրեք նախընտրած ուտելիքը. " << std::endl;
        std::cin >> dish;
        box.addToBox(dish);
        box.displayBox();
        double price = 0;
        std::cout << "Խնդրում ենք վճարել գումարը։" << std::endl;
        std::cin >> price;
        box.pay(price);
    } else {
        std::cout << "Մենք չենք համագործակցում տվյալ ռեստորանի հետ, հայցում ենք Ձեր ներողամտությունը. շնորհակալություն:" << std::endl;
    }

    std::string karciq;
    std::cout << "\033[1;33mՁեր կարծիքը կարևոր է մեզ համար, խնդրում ենք գնահատել սպասարկման որակը:\033[0m\n";
    std::cin >> karciq;

    return 0;
}

