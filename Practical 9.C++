#include <iostream>  
#include <algorithm> 
//The STL algorithms are generic because they can operate on a variety of data structures
#include <vector>    //The header file for the STL vector library is vector.

using namespace std;
class Item
{
public:
    char name[10];
    int quantity;
    int cost;
    int code;

    bool operator==(const Item &i1)                                                        
    {
        if (code == i1.code) // operator will return 1 if the comparison is true, or 0 if the comparison is false
            return 1;
        return 0;
    }

    bool operator<(const Item &i1)
    {
        if (code < i1.code) // operator will return 1 if the comparison is true, or 0 if the comparison is false
            return 1;
        return 0;
    }
};

vector<Item> o1;
void print(Item &i1);
void display();
void insert();
void search();
void dlt();

bool compare(const Item &i1, const Item &i2)
{
    // if (i1.name != i2.name) return i1.cost < i2.cost;
    return i1.cost < i2.cost;
}

void insert()
{
    Item i1;
    cout << "\nEnter Item Name: ";
    cin >> i1.name;
    cout << "\nEnter Item Quantity: ";
    cin >> i1.quantity;
    cout << "\nEnter Item Cost: ";
    cin >> i1.cost;
    cout << "\nEnter Item Code: ";
    cin >> i1.code;
    o1.push_back(i1);
    cout << endl;
}

void display()
{
    for_each(o1.begin(), o1.end(), print);
}

void print(Item &i1)
{
    cout << "\n";
    cout << "\nItem Name: " << i1.name;
    cout << "\nItem Quantity: " << i1.quantity;
    cout << "\nItem Cost: " << i1.cost;
    cout << "\nItem Code: " << i1.code;
    cout << endl;
}

void search()
{
    vector<Item>::iterator p;
    Item i1;
    cout << "\nEnter Item Code to search: ";
    cin >> i1.code;
    p = find(o1.begin(), o1.end(), i1);
    if (p == o1.end())
    {
        cout << "\nNot found.";
    }
    else
    {
        cout << "\nFound.";
    }
    cout << endl;
}

void dlt()
{
    vector<Item>::iterator p;
    Item i1;
    cout << "\nEnter Item Code to delete: ";
    cin >> i1.code;
    p = find(o1.begin(), o1.end(), i1);
    if (p == o1.end())
    {
        cout << "\nNot found.";
    }
    else
    {
        o1.erase(p);
        cout << "\nDeleted.";
    }
    cout << endl;
}

int main()
{
    int ch;
    do
    {
        cout << "\n***** Menu *****";
        cout << "\n1.Insert";
        cout << "\n2.Display";
        cout << "\n3.Search";
        cout << "\n4.Sort";
        cout << "\n5.Delete";
        cout << "\n6.Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:

            cout<<"Insert";
            insert();
            break;

        case 2:
            cout<<"Display";
            display();
            break;

        case 3:
            cout<<"Search";
            search();
            break;

        case 4:
            cout<<"Sort";
            sort(o1.begin(), o1.end(), compare);
            cout << "\n\n Sorted on Cost";
            display();
            break;

        case 5:
            cout<<"Delete";
            dlt();
            break;

        case 6:
            exit(0);
        }

    } while (ch != 7);

    return 0;
}

Output

***** Menu *****
1.Insert
2.Display
3.Search
4.Sort
5.Delete
6.Exit

Enter your choice: 1
Insert
Enter Item Name: Pen

Enter Item Quantity: 5

Enter Item Cost: 8

Enter Item Code: 01


***** Menu *****
1.Insert
2.Display
3.Search
4.Sort
5.Delete
6.Exit

Enter your choice: 1
Insert
Enter Item Name: Files

Enter Item Quantity: 7

Enter Item Cost: 20

Enter Item Code: 03


***** Menu *****
1.Insert
2.Display
3.Search
4.Sort
5.Delete
6.Exit

Enter your choice: 2
Display

Item Name: Pen
Item Quantity: 5
Item Cost: 8
Item Code: 1


Item Name: Files
Item Quantity: 7
Item Cost: 20
Item Code: 3

***** Menu *****
1.Insert
2.Display
3.Search
4.Sort
5.Delete
6.Exit

Enter your choice: 3
Search
Enter Item Code to search: 03

Found.

***** Menu *****
1.Insert
2.Display
3.Search
4.Sort
5.Delete
6.Exit

Enter your choice: 3
Search
Enter Item Code to search: 04

Not found.

***** Menu *****
1.Insert
2.Display
3.Search
4.Sort
5.Delete
6.Exit

Enter your choice: 4
Sort

 Sorted on Cost

Item Name: Pen
Item Quantity: 5
Item Cost: 8
Item Code: 1


Item Name: Files
Item Quantity: 7
Item Cost: 20
Item Code: 3

***** Menu *****
1.Insert
2.Display
3.Search
4.Sort
5.Delete
6.Exit

Enter your choice: 5
Delete
Enter Item Code to delete: 04

Not found.

***** Menu *****
1.Insert
2.Display
3.Search
4.Sort
5.Delete
6.Exit

Enter your choice: 5
Delete
Enter Item Code to delete: 03

Deleted.

***** Menu *****
1.Insert
2.Display
3.Search
4.Sort
5.Delete
6.Exit

Enter your choice: 6
