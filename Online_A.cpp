#include <iostream>
using namespace std;
struct L_list
{
    int value;
    L_list *next;

public:
    L_list(int m)
    {
        value = m;
        next = nullptr;
    }
};
class List
{
    L_list *head;
    int len;
    int current_pos = 0;

public:
    void init(int k, int n)
    {
        head = nullptr;
        len = k;
        int x;
        L_list *tem;
        L_list *prev;
        for (int i = 0; i < k; i++)
        {
            cin >> x;
            if (head == nullptr)
            {
                head = new L_list(x);
                prev = head;
            }
            else
            {
                tem = new L_list(x);
                prev->next = tem;
                prev = tem;
            }
        }
    }
    void insert(int item)
    {
        if (head == nullptr)
        {
            head = new L_list(item);
            len++;
            current_pos = 0;
            return;
        }
        L_list *tem = head;
        L_list *prev = head;
        for (int i = 0; i < current_pos; i++)
        {
            prev = tem;
            tem = tem->next;
        }
        if (head == tem)
        {
            prev = new L_list(item);
            prev->next = head;
            head = prev;
        }
        else
        {
            prev->next = new L_list(item);
            prev->next->next = tem;
        }
        len++;
    }
    int remove()
    {
        if (len == 0)
        {
            cout << "List underflow" << endl;
            return -1;
        }
        int rmv;
        L_list *tem = head;
        L_list *prev = head;
        for (int i = 0; i < current_pos; i++)
        {
            prev = tem;
            tem = tem->next;
        }
        if (head == tem)
        {
            rmv = head->value;
            head = head->next;
            delete tem;
        }
        else
        {
            prev->next = prev->next->next;
            rmv = tem->value;
            delete tem;
        }
        len--;
        if (len == current_pos)
            current_pos--;
        return rmv;
    }
    void moveToStart()
    {
        current_pos = 0;
    }
    void moveToEnd()
    {
        current_pos = len - 1;
    }
    void prev()
    {
        if (current_pos > 0)
            current_pos--;
    }
    void next()
    {
        if (current_pos < len - 1)
            current_pos++;
    }
    int length()
    {
        return len;
    }
    int currPos()
    {
        return current_pos;
    }
    void moveToPos(int pos)
    {
        if (0 > pos || pos >= len)
        {
            cout << "Wrong position !!  Position should be a positive number and smaller than list's length" << endl;
            return;
        }
        current_pos = pos;
    }
    int getValue()
    {
        if (len == 0)
        {
            cout << "List is empty" << endl;
            return -1;
        }
        L_list *tem = head;
        for (int i = 0; i < current_pos; i++)
        {
            tem = tem->next;
        }
        return tem->value;
    }

    void reorderList()
    {
        if (len <= 2)
        {
            return;
        }

        // Find the middle of the linked list
        L_list *slow = head;
        L_list *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the linked list
        L_list *prev = nullptr;
        L_list *current = slow->next;
        L_list *nextNode = nullptr;
        while (current != nullptr)
        {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        slow->next = nullptr;

        // Merge the two halves of the linked list
        L_list *first = head;
        L_list *second = prev;
        while (second != nullptr)
        {
            L_list *nextFirst = first->next;
            L_list *nextSecond = second->next;

            first->next = second;
            second->next = nextFirst;

            first = nextFirst;
            second = nextSecond;
        }
    }

    void print()
    {
        L_list *tem = head;
        for (int i = 0; i < len; i++)
        {
            cout << tem->value << " ";
            tem = tem->next;
        }
    }
};
int main()
{
    int n;
    cin >> n;
    List l;
    l.init(n, n);
    l.reorderList();
    l.print();
    return 0;
}