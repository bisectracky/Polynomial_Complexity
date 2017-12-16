//preorder_recursion
void PreOrder(bnode_type* C){
    if(C){
        printf("%d", C->key);
        PreOrder(C->lc);
        PreOrder(C->rc);
    }
}


//inorder_recursion
void InOrder(bnode_type* C){
    if(C){
        InOrder(C->lc);
        printf("%d", C->key);
        InOrder(C->rc);
    }
}


//postorder_recursion
void PostOrder(bnode_type* C){
    if(C){
        PostOrder(C->lc);
        PostOrder(C->rc);
        printf("%d", C->key);
    }
}


//preorder_nonrecursion
void PreOrderTraversal(BinTree BT){
    BinTree T = BT;
    Stack S = CreatStack(MaxSize);
    while(T || !IsEmpty(S)){
        while(T){
            Push(S,T);//It is the first time to meet the node
            printf("%d", T->Data);
            T = T->Left;
        }
        if(!IsEmpty(S)){
            T = Pop(S);//It is the second time to meet the node
            T = T->Right;
        }
    }
}



//inorder_nonrecursion
void InOrderTraversal(BinTree BT){
    BinTree T = BT;
    Stack S = CreatStack(MaxSize);
    while(T || !IsEmpty(S)){
        while(T){
            Push(S,T);//It is the first time to meet the node
            T = T->Left;
        }
        if(!IsEmpty(S)){
            T = Pop(S);//It is the second time to meet the node
            printf("%d", T->Data);
            T = T->Right;
        }
    }
}



//postorder_nonrecursion
void PostOrderTraversal(BinTree BT){
    BinTree T = BT;
    Stack S = CreatStack(MaxSize);
    while(T || !IsEmpty(S)){
        while(T){
            Push(S,T);//It is the first time to meet the node
            T = T->Left;
        }
        if(!IsEmpty(S)){
            T = Pop(S);//It is the second time to meet the node
            T = T->Right;
            printf("%d", T->Data);
        }
    }
}

