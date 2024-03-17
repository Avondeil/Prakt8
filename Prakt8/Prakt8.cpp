

#include <iostream>
#include <vector>
using namespace std;


union Product
{
    struct Product_A
    {
        int inventoryNumber;
        string material;
        double weight;
    };
    struct Product_B
    {
        int inventoryNumber;
        double height;
        double width;
        double depth;
    };
};

int main()
{
    setlocale(LC_ALL, "ru");
    vector<Product::Product_A> products_a; // Вектор для записи изделий группы A
    vector<Product::Product_B> products_b; // Вектор для записи изделий группы B
    char group; // Переменная для записи группы (А или Б)
    int inventoryNumber; // Инвентарный номер изделия
    for (int i = 0; i < 5; i++)
    {
        cout << "Изделие номер " << i + 1 << endl;
        cout << "Выберите группу (A или B): ";
        cin >> group;
        switch (tolower(group))
        {
        case 'a':
        { 
            Product::Product_A pr;
            cout << "Введите инвентарный номер изделия: ";
            cin >> pr.inventoryNumber;
            
            // Используем цикл для проверки выбранного материала
            bool scan = true;
            while (scan)
            {
                cout << "Выберите материал: 1. Дерево 2. Пластмасса: ";
                short int selectMaterial;
                cin >> selectMaterial;
                if (selectMaterial == 1)
                {
                    pr.material = "Дерево"; scan = false;
                }
                else if (selectMaterial == 2)
                {
                    pr.material = "Пластмасса"; scan = false;
                }
                else cout << "Было введено некорректное значение, попробуйте снова!" << endl;
            }
            cout << "Введите вес: "; cin >> pr.weight; cout << "\n\n";
            products_a.push_back(pr);
            break; 
        }
        case 'b':
        {
            Product::Product_B pr;
            cout << "Введите инвентарный номер изделия: ";
            cin >> pr.inventoryNumber;
            cout << "Введите высоту изделия: "; cin >> pr.height;
            cout << "Введите ширину изделия: "; cin >> pr.width;
            cout << "Введите глубину изделия: "; cin >> pr.depth; cout << "\n\n";
            products_b.push_back(pr);
            break;
        }
        default:
        {
            cout << "Ошибка при вводе группы, повторите попытку!" << endl << endl;
            i--;
            break;
        }

        }    
    }

    // Вывод изделий групп А и B для наглядности
    cout << "Вывод всех изделий группы А:" << endl;
    for (const auto product : products_a)
    {   
        cout << "Инвентарный номер изделия: " << product.inventoryNumber << endl;
        cout << "Материал: " << product.material << endl;
        cout << "Вес: " << product.weight << endl << endl;
    }

    cout << "\n\nВывод всех изделий группы B:" << endl;
    for (const auto product : products_b)
    {
        cout << "Инвентарный номер изделия: " << product.inventoryNumber << endl;
        cout << "Высота: " << product.height << endl;
        cout << "Ширина: " << product.width << endl;
        cout << "Глубина: " << product.width << endl << endl;
    }

    // Вывод списка всех изделий группы А, 
    // изготовленных из дерева и имеющих вес не более некоторого заданного
    double weight;
    cout << "Введите вес, после которого изделия рассматриваться не будут: "; cin >> weight;
    for (const auto product : products_a)
    {
        if (product.material == "Дерево" && product.weight <= weight)
        {
            cout << "Инвентарный номер изделия: " << product.inventoryNumber << endl;
            cout << "Материал: " << product.material << endl;
            cout << "Вес: " << product.weight << endl << endl;
        }
    }
}

