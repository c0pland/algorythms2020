// Algorythms_Lab_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
struct Ingridient;
struct Item{// A
    std::string name;
    Item* next;
    Ingridient* ingridient;//B
};

struct Ingridient { // B
    int count;
    Item* item;//A
    Ingridient* next;
};

void AddItem(Item* item, std::string name, Ingridient* ingridient);
void AddItem(Item* head, Item* item);
void PrintItems(Item* head);
Item* GenerateItem(std::string name, Ingridient* ingridient);
Ingridient* GenerateIngridient(int count,Item* item);
void PrintIngridients(Item* item);
void DeleteIngridient(Item* head, Item* item);
void DeleteItem(Item* head, Item* item);
int main()
{

    Item* head = GenerateItem("Stolewnica",NULL);
    Item* bolt = GenerateItem("Bolt",NULL);
    Item* gaika = GenerateItem("gaika", NULL);
    Ingridient* boltIng = GenerateIngridient(2, bolt);
    Ingridient* gaikaIng = GenerateIngridient(4, gaika);
    
    head->ingridient = boltIng;
    head->ingridient->next = gaikaIng;
    
    AddItem(head, bolt);
    AddItem(head, gaika);
    
    PrintIngridients(head);
    PrintItems(head);

    
    
}

void PrintItems(Item* head)
    {
        Item* tmp = head;
        while (tmp->next != NULL)
        {
            std::cout << tmp->name << " ";
            tmp = tmp->next;
        }
        std::cout << tmp->name << " ";
    }

Item* GenerateItem(std::string name, Ingridient* ingridient)
{
    Item* item = new Item();
    item->name = name;
    item->next = NULL;
    item->ingridient = ingridient;
    return item;
}

Ingridient* GenerateIngridient(int count, Item* item)
{
    Ingridient* ingridient = new Ingridient();
    ingridient->count = count;
    ingridient->next = NULL;
    ingridient->item = item;
    return ingridient;
}

void PrintIngridients(Item* item)
{
    Ingridient* tmp = item->ingridient;
    while (tmp->next != nullptr)
    {
        std::cout << tmp->item->name <<" v razmere "<<tmp->count << " wtuk\n";
        tmp = tmp->next;
    }
    std::cout << tmp->item->name << " v razmere " << tmp->count << " wtuk\n";
}

void DeleteIngridient(Item* head , Item* item)
{
    Item* tmp = head;
    while (tmp->next != nullptr)
    {
        if (tmp->ingridient->item->name == item->name)
        {
            //delete tmp->ingridient
        }
    }
}

void DeleteItem(Item* head, Item* item)
{

}



void AddItem(Item* item, std::string name, Ingridient* ingridient)
{
    Item* itm = new Item;
    itm->name = name;
    itm->ingridient = ingridient;
    itm->next = nullptr;
    item->next = itm;
}

void AddItem(Item* head, Item* item)
{
    Item* tmp = head;
    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
    }
    tmp->next = item;
}
