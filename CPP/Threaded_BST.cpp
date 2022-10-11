#include <bits/stdc++.h>
#include "Threaded_BST_Header.h"
#include <vector>
using namespace std;

/*
                6
               / \
              4
             / \
            2   5
           / \
          1   3
*/
int main()
{
    Threaded_BST<int> BT;
    cout<<"\t\t\t\t ---------- Threaded Binary Seach Tree ----------";
    Functions_after_switch :
    {
        cout<<"\n\nFuntions -\n\t1. Insert Array \t2. Search\t3. Display Tree \t4. Leaf Nodes\t5. LevelWise Traversal\n\t\t\t\t\t\tEnter Choice : ";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                int input;
                vector<int> v;
                cout<<"\nEnter -1 to stop entering elements...\nEnter Elements : ";
                bool app = true;
                while(app)
                {
                    cin>>input;
                    if(input == -1){app = false;}
                    else{v.push_back(input);}
                }
                BT.InsertArray(&v.front(), v.size());
                cout<<"\nBinary Tree built is : ";
                BT.Inorder(BT.GetRoot());
                goto Functions_after_switch;
            }
            case 2:
            {
                int search_key;
                cout<<"\nEnter key to be searches in tree : ";
                cin>>search_key;
                BT.isPresent(search_key);
                goto Functions_after_switch;
            }
            case 3:
            {
                cout<<"\nDisplay Tree -\n\t1.Inorder\t2.Preorder\t3.Postorder\n\t\tSelect View : ";
                int view;
                cin>>view;
                switch(view)
                {
                    case 1:
                    {
                        cout<<"\nInorder Traversal(ascending) : "; BT.Inorder(BT.GetRoot());
                        goto Functions_after_switch;
                    }
                    case 2:
                    {
                        cout<<"\nPreorder Traversal : "; BT.Preorder(BT.GetRoot());
                        goto Functions_after_switch;
                    }
                    case 3:
                    {
                        // cout<<"\nPostorder Traversal : "; BT.Postorder(BT.GetRoot());
                        // goto Functions_after_switch;
                    }
                }
            }
            case 4:
            {
                cout<<"\nDisplying Leaf Nodes : ";
                BT.DisplayLeafNodes(BT.GetRoot());
                goto Functions_after_switch;
            }
            case 5:
            {
                cout<<"\nLevel Wise Traversal : ";BT.DisplayLevelWise(BT.GetRoot());
                goto Functions_after_switch;
            }
            default :
            {
                cout<<"\n\n\t\t\t\t\t----Program Terminated----\n";
                return 0;
            }
        }
    }
}