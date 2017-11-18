//preorder_recursion
void Preorder(bnode_type* C){
    if(C){
        printf("%d", C->key);
        Preorder(C->lc);
        Preorder(C->rc);
    }
}


//inorder_recursion
void Inorder(bnode_type* C){
    if(C){
        Preorder(C->lc);
        printf("%d", C->key);
        Preorder(C->rc);
    }
}


//postorder_recursion
void Postorder(bnode_type* C){
    if(C){
        Preorder(C->lc);
        Preorder(C->rc);
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
void PreOrderTraversal(BinTree BT){
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
void PreOrderTraversal(BinTree BT){
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

