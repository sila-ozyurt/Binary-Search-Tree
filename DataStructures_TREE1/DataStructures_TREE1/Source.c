#include <stdio.h>
#include <stdlib.h>


struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

int search(int key, struct Node* root)
{
	if (root != NULL)
	{
		if (key == root->data)
		{
			return 1;
		}
		else if (key < root->data)
		{
			return search(key, root->left);
		}
		else
		{
			return search(key, root->right);
		}
	}

	return 0;

}

struct Node* findMin(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* deleteNode(struct Node** root, int data) {
    if ((*root) == NULL) {
        return *root;
    }

    if (data < (*root)->data) {
        (*root)->left = deleteNode(&((*root)->left), data);
    }
    else if (data > (*root)->data) {
        (*root)->right = deleteNode(&((*root)->right), data);
    }
    else {
        // Node to delete is found

        // If it has one child or not any
        if ((*root)->left == NULL) {
			struct Node* temp = (*root)->right;
			return temp;
        }
        else if ((*root)->right == NULL) {
			struct Node* temp =(*root)->left;
			free(root);
			return temp;
        }
       
            // If it has 2 children
            struct Node* minRight = findMin((*root)->right);
            (*root)->data = minRight->data;
            (*root)->right = deleteNode(&((*root)->right), minRight->data);
        
    }

    return *root;
}



//time complexity is n because it traverses all nodes
int calculateHeight(struct Node* root) {
	if (root == NULL) {
		return -1;
	}

	int leftDepth = calculateHeight(root->left);
	int rightDepth = calculateHeight(root->right);

	if (leftDepth >= rightDepth) {
		return leftDepth + 1;
	}
	else {
		return rightDepth + 1;
	}

}

int calculateTotalNodeNum(struct Node* root) {
	if (root == NULL) {
		return 0;
	}

	int leftDepth = calculateTotalNodeNum(root->left);
	int rightDepth = calculateTotalNodeNum(root->right);

	return leftDepth + rightDepth + 1;

}



void insert(int data,struct Node** root) {

	if ((*root) == NULL) {
		(*root) = newNode(data);
	}
	else if ((*root)->data >= data) {
		insert(data, &((*root)->left));
	}
	else if ((*root)->data < data) {
		insert(data, &((*root)->right));
	}
}



void preorder(struct Node* root) {

	if (root == NULL) return;

	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct Node* root) {

	if (root == NULL) return;
	
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);

}

void postorder(struct Node* root) {

	if (root == NULL) return;

	postorder(root->left);
	postorder(root->right);
	printf("%d\t",root->data);


}

int main() {

	struct Node* root = NULL;

	insert(50, &root);
	insert(30, &root);
	insert(20, &root);
	insert(40, &root);
	insert(70, &root);
	insert(6, &root);
	insert(80, &root);

    deleteNode(&root, 50);
	inorder(root);


	printf("\n\n%d", search(30,root));
	
	return 0;
}






 





















//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX_LIST 10
//
//typedef struct {
//    char name[20]; 
//    int link;
//} Node;
//
//
//Node linkedlist[MAX_LIST];
//int free_;
//int first;
//
//
//
//int get_item(int* r) {
//    if (free_ == -1) {
//        return 0; // Boþ öðe yoksa
//    }
//    else {
//        *r = free_;
//        free_ = linkedlist[free_].link;
//        return 1; // Baþarýlý bir þekilde öðe alýndý
//    }
//}
//
//
//
//void insert_item(char name[], int* list) {
//    int r, q, p;
//
//    // Boþ bir öðe al
//    if (get_item(&r)) {
//        // Yeni öðenin adýný belirtilen isim ile doldur
//        strcpy(linkedlist[r].name, name);
//
//        // Baþlangýçta q'yu NULL, p'yi listenin baþýný gösteren list ile baþlat
//        q = NULL;
//        p = *list;
//
//        // Yeni öðenin nereye ekleneceðini ara
//        while (p != NULL && strcmp(linkedlist[p].name, name) < 0) {
//            q = p;
//            p = linkedlist[p].link;
//        }
//
//        // Eðer yeni öðe listenin baþýna eklenecekse
//        if (q == NULL) {
//            *list = r;                 // Listenin baþýný güncelle
//            linkedlist[r].link = p;    // Yeni öðe ile eski listenin baþýný baðla
//        }
//        else {
//            // Eðer yeni öðe listenin ortasýna eklenecekse
//            linkedlist[q].link = r;    // Önceki eleman ile yeni öðeyi baðla
//            linkedlist[r].link = p;    // Yeni öðe ile sonraki elemaný baðla
//        }
//    }
//    else {
//        // Yeterli boþ öðe yoksa hata mesajý yazdýr
//        printf("\nNot enough free space!!");
//    }
//}
//
//
//int main() {
//
//
//
//    return 0;
//}