#include <iostream>
using namespace std;

template <typename T>
void sort(T a[], int n)
{
    int pos;
    T temp;
    for (int i = 0; i < n - 1; i++)
    {
        pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[pos])
                pos = j;
        }
        if (pos != i)
        {
            temp = a[i];
            a[i] = a[pos];
            a[pos] = temp;
        }
    }
    // display element
    cout << "\nSorted Elements Are:";
    for (int k = 0; k < n; k++)
    {
        cout << "\n"
             << a[k];
    }
    cout<<endl;
}

int main()
{
    int ch;
    int no;
    int ele;
    int fno;
    while (1)
    {
        cout << "\nMENU \n1.Int Sorting\n2.Char Sorting\n3.Float Sorting\n4.Exit";
        cout << "\nEnter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nInteger sorting\n";
            cout << "\nEnter no of elements to be sorted:\n";
            cin >> no;
            int sor1[100];
            cout << "\nEnter Elements:\n";
            for (int i = 0; i < no; i++)
            {
                cin >> sor1[i];
            }
            sort<int>(sor1, no);
            break;
        case 2:
            cout << "\nCharacter Sorting\n";
            cout << "\nEnter no of elements to be sorted:\n";
            cin >> ele;
            char sor2[100];
            cout << "\nEnter Elements:\n";
            for (int i = 0; i < ele; i++)
            {
                cin >> sor2[i];
            }
            sort<char>(sor2, ele);
            break;
        case 3:
            cout << "\nFloating Type Sorting\n";
            cout << "\nEnter no of elements to be sorted:\n";
            cin >> fno;
            float sor3[100];
            cout << "\nEnter Elements:\n";
            for (int i = 0; i < fno; i++)
            {
                cin >> sor3[i];
            }
            sort<float>(sor3, fno);
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}

Output 

MENU 
1.Int Sorting
2.Char Sorting
3.Float Sorting
4.Exit
Enter choice: 1

Integer sorting

Enter no of elements to be sorted:
7             

Enter Elements:
12 34 46 87 83
22 
76 

Sorted Elements Are:
12
22
34
46
76
83
87

MENU 
1.Int Sorting
2.Char Sorting
3.Float Sorting
4.Exit
Enter choice: 2

Character Sorting

Enter no of elements to be sorted:
6

Enter Elements:
a s d f g h

Sorted Elements Are:
a
d
f
g
h
s

MENU 
1.Int Sorting
2.Char Sorting
3.Float Sorting
4.Exit
Enter choice: 3

Floating Type Sorting

Enter no of elements to be sorted:
5

Enter Elements:
23.4 56.7 56.5 87.12 79.01

Sorted Elements Are:
23.4
56.5
56.7
79.01
87.12

MENU 
1.Int Sorting
2.Char Sorting
3.Float Sorting
4.Exit
Enter choice: 4
