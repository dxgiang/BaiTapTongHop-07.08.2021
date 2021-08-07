#include <iostream>
using namespace std;

// khai báo cấu trúc 1 node trong cây nhị phân tìm kiếm
struct node
{
    int data;            // dữ liệu chứa trong 1 node
    struct node *pLeft;  // con trỏ liên kết với node bên trái <=> cây con trái
    struct node *pRight; // con trỏ liên kết với node bên phải <=> cây con phải
    node* next;
};
typedef struct node NODE;
typedef NODE *TREE;

// hàm khởi tạo cây nhị phân tìm kiếm
void KhoiTaoCay(TREE &t)
{
    t = NULL;
}

// hàm thêm 1 phần tử vào cây
void ThemNodeVaoCay(TREE &t, int x)
{
    // nếu cây rỗng
    if (t == NULL)
    {
        NODE *p = new NODE;
        p->data = x;
        p->pLeft = NULL;
        p->pRight = NULL;
        t = p;
    }
    else
    {
        // nếu phần tử thêm vào mà nhỏ hơn nút gốc thì sẽ duyệt qua bên trái
        if (x < t->data)
        {
            ThemNodeVaoCay(t->pLeft, x);
        }
        else if (x > t->data)
        {
            ThemNodeVaoCay(t->pRight, x);
        }
    }
}

// hàm xuất phần tử trong cây nhị phân tìm kiếm
void NLR(TREE t)
{
    if (t != NULL)
    {
        // xử lí
        cout << t->data << "  ";
        NLR(t->pLeft);
        NLR(t->pRight);
    }
}

// hàm xuất cây nhị phân theo RNL <=> xuất ra các phần tử từ lớn đến bé
void Duyet_RNL(TREE t)
{
    // nếu cây còn phần tử thì tiếp tục duyệt
    if (t != NULL)
    {
        Duyet_RNL(t->pRight);    // duyệt qua phải
        cout << t->data << "  "; // xuất giá trị của node
        Duyet_RNL(t->pLeft);     // duyệt qua phải
    }
}

// hàm kiểm tra số nguyên tố
bool KiemTraSoNguyenTo(int x)
{
    if (x < 2)
    {
        return false;
    }
    else
    {
        if (x == 2)
        {
            return true;
        }
        else
        {
            if (x % 2 == 0)
            {
                return false;
            }
            else
            {
                for (int i = 2; i < x; i++)
                {
                    if (x % i == 0)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

// hàm đếm số lượng số nguyên tố
void SoLuongSoNguyenTo(TREE t, int &dem)
{
    if (t != NULL)
    {
        // xử lí
        if (KiemTraSoNguyenTo(t->data) == true)
        {
            dem++;
        }
        //duyệt qua từng node trong cây
        SoLuongSoNguyenTo(t->pLeft, dem);
        SoLuongSoNguyenTo(t->pRight, dem);
    }
}

void deleteNode(Node** head_ref, Node* del)
{
    // base case
    struct Node* temp = *head_ref;
    if (*head_ref == NULL || del == NULL)
        return;
 
    // If node to be deleted is head node
    if (*head_ref == del)
        *head_ref = del->next;
    // traverse list till not found
    // delete node
    while (temp->next != del) {
        temp = temp->next;
    }
    // copy address of node
    temp->next = del->next;
    // Finally, free the memory occupied by del
    free(del);
 
    return;
}

void deletePrimeNodes(Node** head_ref)
{
    Node* ptr = *head_ref;
    Node* next;
 
    while (ptr != NULL) {
        next = ptr->next;
        // if true, delete node 'ptr'
        if (isPrime(ptr->data))
            deleteNode(head_ref, ptr);
        ptr = next;
    }
}

void printList(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// hàm nhập cây nhị phân tìm kiếm
void Menu(TREE &t)
{
    int luachon;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t ============= MENU  =============";
        cout << "\n1. Nhap phan tu";
        cout << "\n2. Duyet cay";
        cout << "\n3. Dem so luong so nguyen to";
        cout << "\n4. Duyet cay theo thu tu giam dan ";
        cout << "\n0. Thoat";
        cout << "\n\n\t\t =============  END  =============";

        cout << "\nNhap lua chon: ";
        cin >> luachon;

        if (luachon == 1)
        {
            int x;
            cout << "\nNhap phan tu: ";
            cin >> x;
            ThemNodeVaoCay(t, x);
        }
        else if (luachon == 2)
        {
            cout << "\n\t CAY NHI PHAN TIM KIEM\n";
            NLR(t);
            system("pause");
        }
        else if (luachon == 3)
        {
            int dem = 0;
            SoLuongSoNguyenTo(t, dem);
            cout << "\n\t SO LUONG SO NGUYEN TO: " << dem;

            system("pause");
        }
        else if (luachon == 4)
        {
            cout << "\n\t\t DUYET CAY THEO THU TU GIAM DAN\n";
            Duyet_RNL(t);
            system("pause");
        }
        else
        {
            break;
        }
    }
}

int main()
{
    TREE t;
    KhoiTaoCay(t);
    Menu(t);
    cout << "Original List: ";
    printList(head);
 
    deletePrimeNodes(&head);
 
    cout << "\nModified List: ";
    printList(head);

    system("pause");
    return 0;
}