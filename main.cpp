#include <iostream>
#include <cstdio>
#include<cstdlib>

using namespace std;
//deklarasi link list
struct node
{
    int info;
    struct node *next;
}*start;
//deklarasi class
    class single_llist

    {
        public:
            node* create_node(int);
            void insert_begin();
            void insert_pos();
            void insert_last();
            void delete_pos();
            void sort();
            void search();
            void update();
            void reverse();
            void display();
            single_llist()
            {
                start = NULL;
            }
    };

    /*
    main contain menu
    */
main()
{
    //pendeklerasian variabel
        int choice, nodes, element, position, i;
        single_llist sl;
        start = NULL;
        while (1)

{
            cout<<"---------------------------------"<<endl;
            cout<<"Tugas STRUKTUR DATA (Linked List UAS)"<<endl;
            cout<<"---------------------------------"<<endl;
            cout<<"1.Insert Node di Awal"<<endl;
            cout<<"2.Insert Node di akhir"<<endl;
            cout<<"3.Insert Node di posisi"<<endl;
            cout<<"4.Sorting Linked List"<<endl;
            cout<<"5.Delete Node"<<endl;
            cout<<"6.Update Node Value"<<endl;
            cout<<"7.Searching Element pada Linked List"<<endl;
            cout<<"8.Tampilkan Linked List"<<endl;
            cout<<"9.Reverse Linked List "<<endl;
            cout<<"10.Keluar "<<endl;
            cout<<"masukkan pilihan : ";
            /*
            membuat unit masukan dari var choice
            */
            cin>>choice;
/*
membuat menu lewat case
disini terdapat 10 menu
1.insert node di awal,2.insert node di akhir,3.Insert Node di posisi,4.Sorting Linked List
5.Delete Node,6.Update Node Value,7.Searching Element pada Linked List,8.Tampilkan Linked List,
9.Reverse Linked List,10.Exit
*/
            switch(choice)
            {
            case 1:
                cout<<"Masukkan Node di Awal: "<<endl;
                sl.insert_begin();
                cout<<endl;
                break;

            case 2:
                cout<<"Masukkan Node di akhir: "<<endl;
                sl.insert_last();
                cout<<endl;
                break;

            case 3:
                cout<<"Masukkan Node sesuai posisi:"<<endl;
                sl.insert_pos();
                cout<<endl;
                break;

            case 4:
                cout<<"Proses Sorting Link List: "<<endl;
                sl.sort();
                cout<<endl;
                break;

            case 5:
                cout<<"Hapus node Link List: "<<endl;
                sl.delete_pos();
                break;

            case 6:
                cout<<"Update Masukkan Node :"<<endl;
                sl.update();
                cout<<endl;
                break;

            case 7:
                cout<<"Cari element dengan Linked List: "<<endl;
                sl.search();
                cout<<endl;
                break;

            case 8:
                cout<<"Tampilkan elements dengan linked list"<<endl;
                sl.display();
                cout<<endl;
                break;

            case 9:
                cout<<"Reverse elements dengan Linked List"<<endl;
                sl.reverse();
                cout<<endl;
                break;

            case 10:
                cout<<"Keluar"<<endl;
                exit(1);
                break;
            default:
                cout<<"Pilihan Salah"<<endl;
            }
        }
    }

/*
       Buat Node dengan link list
     */

    node *single_llist::create_node(int value)

    {

        struct node *temp, *s;

        temp = new(struct node);

        if (temp == NULL)

        {
            cout<<"Sudah Terpenuhi "<<endl;
            return 0;

        }
        else
        {

            temp->info = value;

            temp->next = NULL;

            return temp;

        }

    }



    /*

     * Insert data di awal

     */

    void single_llist::insert_begin()
    {
        int value;
        cout<<"Masukkan Data Yang Akan Diinsert: ";
        cin>>value;

        struct node *temp, *p;
        temp = create_node(value);
        //menyatakan kondisi jika start kosong
        if (start == NULL)
        {
            start = temp;
            start->next = NULL;
        }

        else

        {

            p = start;

            start = temp;

            start->next = p;

        }

        cout<<"Element telah diinsertkan di awal node"<<endl;
        cout<<endl;
        cout<<endl;


    }



    /*

     * Inserting Node at last

     */

    void single_llist::insert_last()

    {

        int value;

        cout<<"Masukkan Data Yang Akan Diinsert: ";

        cin>>value;

        struct node *temp, *s;

        temp = create_node(value);

        s = start;

        while (s->next != NULL)

        {

            s = s->next;

        }

        temp->next = NULL;

        s->next = temp;


        cout<<"Element telah diinsertkan di akhir node"<<endl;
        cout<<endl;
        cout<<endl;
    }



    /*

     * Insertion of node at a given position

     */

    void single_llist::insert_pos()

    {

        int value, pos, counter = 0;

        cout<<"masukan data yang akan diinsert ";

        cin>>value;

        struct node *temp, *s, *ptr;

        temp = create_node(value);

        cout<<"pilih posisi pada node yang akan diinsert: ";

        cin>>pos;

        int i;

        s = start;

        while (s != NULL)

        {

            s = s->next;

            counter++;

        }

        if (pos == 1)

        {

            if (start == NULL)

            {

                start = temp;

                start->next = NULL;

            }

            else

            {

                ptr = start;

                start = temp;

                start->next = ptr;

            }

        }

        else if (pos > 1  && pos <= counter)

        {

            s = start;

            for (i = 1; i < pos; i++)

            {

                ptr = s;

                s = s->next;

            }

            ptr->next = temp;

            temp->next = s;

        }

        else

        {

            cout<<"tidak ada tempat untuk insert data "<<endl;

        }

    }



    /*

     * Sorting Link List

     */

    void single_llist::sort()

    {

        struct node *ptr, *s;

        int value;

        if (start == NULL)

        {

            cout<<"The List is empty"<<endl;

            return;

        }

        ptr = start;

        while (ptr != NULL)

        {

            for (s = ptr->next;s !=NULL;s = s->next)

            {

                if (ptr->info > s->info)

                {

                    value = ptr->info;

                    ptr->info = s->info;

                    s->info = value;

                }

            }

            ptr = ptr->next;

        }

    }



    /*

     * Delete element at a given position

     */

    void single_llist::delete_pos()

    {

        int pos, i, counter = 0;

        if (start == NULL)

        {

            cout<<"List is empty"<<endl;

            return;

        }

        cout<<"Enter the position of value to be deleted: ";

        cin>>pos;

        struct node *s, *ptr;

        s = start;

        if (pos == 1)

        {

            start = s->next;

        }

        else

        {

            while (s != NULL)

            {

                s = s->next;

                counter++;

            }

            if (pos > 0 && pos <= counter)

            {

                s = start;

                for (i = 1;i < pos;i++)

                {

                    ptr = s;

                    s = s->next;

                }

                ptr->next = s->next;

            }

            else

            {

                cout<<"Position out of range"<<endl;

            }

            free(s);

            cout<<"Element Deleted"<<endl;

        }

    }



    /*

     * Update a given Node

     */

    void single_llist::update()

    {

        int value, pos, i;

        if (start == NULL)

        {

            cout<<"List is empty"<<endl;

            return;

        }

        cout<<"Enter the node postion to be updated: ";

        cin>>pos;

        cout<<"Enter the new value: ";

        cin>>value;

        struct node *s, *ptr;

        s = start;

        if (pos == 1)

        {

            start->info = value;

        }

        else

        {

            for (i = 0;i < pos - 1;i++)

            {

                if (s == NULL)

                {

                    cout<<"There are less than "<<pos<<" elements";

                    return;

                }

                s = s->next;

            }

            s->info = value;

        }

        cout<<"Node Updated"<<endl;

    }



    /*

     * Searching an element

     */

    void single_llist::search()

    {

        int value, pos = 0;

        bool flag = false;

        if (start == NULL)

        {

            cout<<"List is empty"<<endl;

            return;

        }

        cout<<"Enter the value to be searched: ";

        cin>>value;

        struct node *s;

        s = start;

        while (s != NULL)

        {

            pos++;

            if (s->info == value)

            {

                flag = true;

                cout<<"Element "<<value<<" is found at position "<<pos<<endl;

            }

            s = s->next;

        }

        if (!flag)

            cout<<"Element "<<value<<" not found in the list"<<endl;

    }



    /*

     * Reverse Link List

     */

    void single_llist::reverse()

    {

        struct node *ptr1, *ptr2, *ptr3;

        if (start == NULL)

        {

            cout<<"List is empty"<<endl;

            return;

        }

        if (start->next == NULL)

        {

            return;

        }

        ptr1 = start;

        ptr2 = ptr1->next;

        ptr3 = ptr2->next;

        ptr1->next = NULL;

        ptr2->next = ptr1;

        while (ptr3 != NULL)

        {

            ptr1 = ptr2;

            ptr2 = ptr3;

            ptr3 = ptr3->next;

            ptr2->next = ptr1;

        }

        start = ptr2;

    }



    /*

     * Display Elements of a link list

     */

    void single_llist::display()

    {

        struct node *temp;

        if (start == NULL)

        {

            cout<<"The List is Empty"<<endl;

            return;

        }

        temp = start;

        cout<<"Elements of list are: "<<endl;

        while (temp != NULL)

        {

            cout<<temp->info<<"->";

            temp = temp->next;

        }

        cout<<"NULL"<<endl;

    }

