/**
 * Description:
 *
 *          chương trình quản lý xe hơi cho 1 cửa hàng xe.
 *
 *
 * Original Author:    H.T.Phong
 * Created:   Dec 3, 2023
 *
 **/

#include <cstring>
#include <iostream>

const int stringMaxLen = 20;

struct Car
{
    char maker[stringMaxLen];
    char model[stringMaxLen];
    int year;
    double cost;
    int quantity;
};

const int maxType = 100;
struct Company
{
    int types;
    Car warehouse[maxType];
};

Company c = {.types = 2,
             .warehouse = {
                 {"Ford", "Taurus", 1997, 21000, 10},
                 {"Honda", "Accord", 1992, 11000, 5},
             }};

int findCar(Car car)
{
    for (int i = 0; i < c.types; i++)
    {
        if (!strcmp(c.warehouse[i].maker, car.maker) &&
            !strcmp(c.warehouse[i].model, car.model) &&
            c.warehouse[i].year == car.year && c.warehouse[i].cost == car.cost)
        {
            return i;
        }
    }
    return -1;
}

void getCarInput(Car &car)
{
    std::cout << "Maker: ";
    std::cin.ignore();
    std::cin.getline(car.maker, stringMaxLen);
    std::cout << "Model: ";
    std::cin.getline(car.model, stringMaxLen);
    std::cout << "Year: ";
    std::cin >> car.year;
    std::cout << "Cost: ";
    std::cin >> car.cost;
    std::cout << "Quantity: ";
    std::cin >> car.quantity;
}

void addCar()
{
    Car temp;
    getCarInput(temp);
    int findCarResult = findCar(temp);
    if (findCarResult != -1)
    {
        c.warehouse[findCarResult].quantity += temp.quantity;
    }
    else
    {
        c.warehouse[c.types++] = temp;
    }
}

void sellCar()
{
    Car temp;
    getCarInput(temp);
    int findCarResult = findCar(temp);
    if (findCarResult == -1)
    {
        std::cout << '\n' << "No car this type!" << '\n';
    }
    else
    {
        if (c.warehouse[findCarResult].quantity < temp.quantity)
        {
            std::cout << '\n' << "Not enough car this type!" << '\n';
        }
        else
        {
            c.warehouse[findCarResult].quantity -= temp.quantity;
        }
    }
}

void deleteCarTypes()
{
    Car temp;
    getCarInput(temp);
    int findCarResult = findCar(temp);
    if (findCarResult == -1)
    {
        std::cout << '\n' << "No car this type!" << '\n';
    }
    else
    {
        c.warehouse[findCarResult] = c.warehouse[c.types - 1];
        c.types--;
    }
}

void printWarehouse()
{
    std::cout << "Maker\tModel\tYear\tCost\tQuantity\n";
    for (int i = 0; i < c.types; i++)
    {
        std::cout << c.warehouse[i].maker << '\t' << c.warehouse[i].model
                  << '\t' << c.warehouse[i].year << '\t' << c.warehouse[i].cost
                  << '\t' << c.warehouse[i].quantity << '\t' << '\n';
    }
}

void Menu()
{
    while (true)
    {
        std::cout << "0. Exit" << '\n'
                  << "1. Add car" << '\n'
                  << "2. Print warehouse" << '\n'
                  << "3. Sell car" << '\n'
                  << "4. Remove car" << '\n'
                  << "5. Total sold" << '\n'
                  << "Enter your choice (number): ";
        int choiceNum;
        std::cin >> choiceNum;
        if (choiceNum == 0)
            break;

        switch (choiceNum)
        {
        case 1:
            addCar();
            break;
        case 2:
            printWarehouse();
            break;
        case 3:
            sellCar();
            break;
        case 4:
            deleteCarTypes();
            break;
        case 5:
            // printSold();
            break;
        }
        std::cout << '\n';
    }
}

int main()
{
    Menu();
    return 0;
}