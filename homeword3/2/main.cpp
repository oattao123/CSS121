#include <bits/stdc++.h>
//SortNode class implementation here
template <class T>
class SortNode
{
protected:
    T value;
public:
    SortNode *prev;
    SortNode *next;

    SortNode( const T &value, SortNode *prev = nullptr, SortNode *next = nullptr )
    {
        this->value = value;
        this->prev  = prev;
        this->next  = next;
    }

    const T & getValue() const
    {
        return value;
    }

    T & getValue()
    {
        return value;
    }
};

template <class T>
class SortList
{
private:
    bool ascending = true;
    SortNode<T> *head = nullptr;
    SortNode<T> *tail = nullptr;

public:
    SortList() = default;
    void add( const T &value )
    {
        SortNode<T> *new_node = new SortNode<T>{ value, tail, nullptr };

        if (!head)
        {
            head = new_node;
        }
        else
        {
            tail->next = new_node;
        }

        tail = new_node;
    }

    SortNode<T> *remove( T val );
    void setAsc( bool a );
    void sort();
    std::ostream &print( std::ostream &os = std::cout ) const
    {
        for (SortNode<T> *current = head; current != nullptr; current = current->next)
        {
            os << current->getValue() << " -> ";
        }

        return os << "null";
    }
    SortNode<T> *getHead();
};

template <class T>
void SortList<T> ::sort()
{
    if (ascending)
    {
        SortNode<T> *node = head, *sortedh = nullptr, *sortedt = nullptr;

        while (node != NULL)
        {
            SortNode<T> *newnode = node;
            SortNode<T> *next = node->next;

            if (!sortedh)
            {
                sortedh = node;
                sortedt = node;
                node->next = nullptr;
            }
            else
            {
                SortNode<T> *ptr = sortedh;

                while (ptr != NULL && !( newnode->getValue() < ptr->getValue() ) )
                {
                    ptr = ptr->next;
                }

                if (!ptr)
                {
                    sortedt->next = newnode;
                    newnode->prev = sortedt;
                    newnode->next = nullptr;
                    sortedt = newnode;
                }
                else
                {
                    if (ptr->prev == NULL)
                    {
                        newnode->next = ptr;
                        newnode->prev = nullptr;
                        ptr->prev = newnode;
                        sortedh = newnode;
                    }
                    else
                    {
                        ptr->prev->next = newnode;
                        newnode->prev = ptr->prev;
                        newnode->next = ptr;
                        ptr->prev = newnode;
                    }

                }
            }

            node = next;
        }

        head = sortedh;
        tail = sortedt;
    }
}

int main()
{
    SortList<int> list;

    const int N = 20;

    srand( ( unsigned int )time( nullptr ) );
    for (int i = 0; i < N; i++)
    {
        list.add( rand() % N );
    }

    list.print() << '\n';

    list.sort();

    list.print() << '\n';
}