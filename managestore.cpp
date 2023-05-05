#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
*Class: Item
*Description: This class represents a basic implementation of a Item object.
*/
class Item{
    protected:
        int id;
        string name;
        int price;
    public:
        Item(string name,int price);
        int getID();
        string getName();
        int getPrice();
        void setName(string name);
        void setPrice(int price);
};
/*
*Contructor: Item
*Discription: This constructor initializes a new instance of the Item class.
*Input:
*   name: name of item
*   price: price of item
*/
Item::Item(string name,int price){
    static int id = 100;
    this->id = id;
    id ++;
    this->name = name;
    this->price = price;
}

/*
*Function: getID
*Description: This function returns id of current Item
*Output: id of current Item
*/
int Item::getID(){
    return this->id;
}

/*
*Function: getName
*Description: This function returns name of current Item
*Output: name of current Item
*/
string Item::getName(){
    return this->name;
}

/*
*Function: getPrice
*Description: This function returns price of current Item
*Output: price of current Item
*/
int Item::getPrice(){
    return this->price;
}
/*
*Function: setName
*Description: This function set name of current Item
*Input:
    name: name of item
*Output: none
*/
void Item::setName(string name){
    this->name = name;
}

/*
*Function: setPrice
*Description: This function set price of current Item
*Input:
    price: price of item
*Output: none
*/
void Item::setPrice(int price){
    this->price = price;
}

class ItemBuy : public Item{
    private:
        int quantity;
    public:
        ItemBuy(int id, string name,int price,int quantity);
        int getQuantity();
        void setQuantity(int quantity);
};
ItemBuy::ItemBuy(int id, string name,int price,int quantity):Item(name,price){
    this->id = id;
    this->name = name;
    this->price = price;
    this->quantity = quantity;
}

int ItemBuy::getQuantity(){
    return this->quantity;
}

void ItemBuy::setQuantity(int quantity){
    this->quantity = quantity;
}

class table{
    private:
        bool status;
    public:
        vector<ItemBuy>bill;
        table();
        void setStatus(bool status);
        bool getStatus();
        void payMent();
};
table::table(){
    status = 0;
}
void table::setStatus(bool status){
    this->status = status;
}
bool table::getStatus(){
    return this->status;
}
void table::payMent(){
    
}

/*
*Class: Manage
*Description: This class represents a basic implementation of a Manage object.
*/
class Manage{
    protected:
        int* numberOfTable;
        int choiceOption;
        vector<Item> *listItems;
    public:
        bool returnOption;
        Manage(vector<Item> &listItems,int &numberOfTable);
        // Manage(int &numberOfTable);
        void displayMenuManage();
        void chooseManage();
        void addItem();
        void reviseName(Item &x);
        void revisePrice(Item &x);
        void reviseItem();
        void delectItem();
        void displayList();
        void displayItem(Item x);
        void setTable();
};
Manage :: Manage(vector<Item> &listItems,int &numberOfTable){
    this->listItems = &listItems;
    this->numberOfTable = &numberOfTable;
}
void Manage::displayMenuManage(){
    cout<<"-------------------------"<<endl;
    cout<<"\tMenu Manage"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"1. Add Item"<<endl;
    cout<<"2. Revise Item"<<endl;
    cout<<"3. Remove Item"<<endl;
    cout<<"4. List of Item"<<endl;
    cout<<"5. Set numbers of table"<<endl;
    cout<<"0. Back to main menu"<<endl;
    do{
        cout<<"Enter your choice: ";
        cin>>this->choiceOption;
    }while(this->choiceOption<0 || this->choiceOption>5 ); 
}
void Manage::chooseManage(){
    switch (this->choiceOption)
    {
    case 1:
        addItem();
        break;
    case 2:
        reviseItem();
        break;
    case 3:
        delectItem();
        break;
    case 4:
        cout<<"listItems[0].getName()"<<endl;
        displayList();
        break;
    case 5:
        setTable();
        break;
    case 0:
        this->returnOption = 0;
        break;
    default:
        break;
    }
}
void Manage::addItem(){
    again:
    string name;
    int price;
    int choice;
    cout<<"-------------------------"<<endl;
    cout<<"\tAdd Item"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"Name: ";
    cin>>name;
    cout<<"Price: ";
    cin>>price;
    Item newItem(name,price);
    this->listItems->push_back(newItem);
    displayList();
    do{
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"1. Continue Add New Item"<<endl;
        cout<<"0. Return Menu Manage"<<endl;
        cout<<"Your choice: ";
        cin>>choice;
    }while(choice <0 || choice>1);
    switch (choice)
    {
    case 0:
        this->returnOption = 1;
        break;
    case 1:
        goto again;
    default:
        break;
    }
}
void Manage::reviseName(Item &x){
    string name;
    cout<<"New Name: ";
    cin>>name;
    x.setName(name);
    displayItem(x);
}
void Manage::revisePrice(Item &x){
    int price;
    cout<<"New Price: ";
    cin>>price;
    x.setPrice(price);
    displayItem(x);
}
void Manage::reviseItem(){
    int id;
    int choice = 3;
    displayList();
    again:
    cout<<"Revise ID: ";
    cin>>id;
    for(auto &x:*listItems)
    {
        if(x.getID() == id) 
        {
            again2:
            displayItem(x);
            cout<<"1. Revise Name"<<endl;
            cout<<"2. Revise Price"<<endl;
            do{
                cout<<"Your choice: ";
                cin>>choice;
            }while(choice < 1 || choice > 2); 
            if(choice == 1)reviseName(x);
            else revisePrice(x);
            cout<<"1. Continue revise"<<endl;
            cout<<"0. Return menu manage"<<endl;
            do{
                cout<<"Your choice: ";
                cin>>choice;
            }while(choice < 0 || choice > 1);
            if(choice == 1)goto again2;
            else break;
        }   
    }
    if(choice == 3){
        cout<<"ID doesn't exist"<<endl;
        goto again;
    }
}
void Manage::delectItem(){
    int id;
    int choice = 3;
    cout<<"-------------------------"<<endl;
    cout<<"\tRemove Item"<<endl;
    cout<<"-------------------------"<<endl;
    displayList();
    again:
    if(listItems->size() != 0){
        cout<<"Remove ID: ";
        cin>>id;
        for(int i = 0; i<listItems->size();i++)
        {
            if ((*listItems)[i].getID() == id)
            {
                listItems->erase(listItems->begin()+i);
                displayList();
                if(listItems->size() != 0){
                    cout<<"1. Continue remove"<<endl;
                    cout<<"0. Return menu manage"<<endl;
                    do{
                        cout<<"Your choice: ";
                        cin>>choice;
                    }while(choice < 0 || choice > 1);
                }else 
                {
                    cout<<"Press 0 to return menu manage"<<endl;
                    do{
                        cout<<"Your choice: ";
                        cin>>choice;
                    }while(choice != 0);
                }
                if(choice == 1)goto again;
                else break;
            }
        }
        if(choice == 3){
            cout<<"ID doesn't exist"<<endl;
            goto again;
        }
    }
}
void Manage::displayItem(Item x){
    cout<<"Id\t\tName\t\tPrice (vnd)"<<endl;
    cout<<x.getID()<<"\t\t"<<x.getName()<<"\t\t"<<x.getPrice()<<endl;
}
void Manage::displayList(){
    int choice;
    cout<<"-----------------------------------------------------------"<<endl;
    if(listItems->size() == 0)cout<<"List Is Empty!!!"<<endl;
    else
    {
        int i = 0;
        cout<<"List Of Items"<<endl;
        cout<<"Number\t\tId\t\tName\t\tPrice (vnd)"<<endl;
       for(auto x:*listItems)
       {
            i++;
            cout<<i<<"\t\t"<<x.getID()<<"\t\t"<<x.getName()<<"\t\t"<<x.getPrice()<<endl;
       }
    }
    if(this->choiceOption == 4){
        do{
            cout<<"Press 0 to return Menu Manage: ";
            cin>>choice;
            this->returnOption = 1;
        }while(choice != 0);
    }
}
void Manage::setTable(){
    cout<<"-------------------------"<<endl;
    cout<<"Set Number Of Table: ";
    cin>>*this->numberOfTable;
    this->returnOption = 1;
}
class Staff : public Manage{
    private:
        int numberOfTable;
        int currentTable;
        vector<table> listTables; 
        vector<Item> *listItems;
        int choiceMenu;
    public:
        Staff(vector<Item> &listItems,int numberOfTable);
        int returnOption;
        void displayStatusTable();
        void chooseTable();
        void displayMenuStaff();
        void chooseMenuStaff();
        void displayBill(table table);
        void addItem(table &table);
        void displayItemsBought(table table);
        void displayItem(ItemBuy x);
        void reviseItem(table &table);
        // void delectItem();
        
        // void displayItem(Item x);
        // void setTable(); 

};

Staff::Staff(vector<Item> &listItems,int numberOfTable):Manage(listItems,numberOfTable){
    this->listItems = &listItems;
    this->numberOfTable = numberOfTable;
    listTables.resize(numberOfTable);
    this->currentTable = 0;
}
void Staff::displayStatusTable(){
    cout<<"Table \t|";
    for(int i = 1; i<= this->numberOfTable;i++) cout<<"\t"<<i<<"\t|";
    cout<<"\n";
    cout<<"\t";
    for(int i = 1; i<= this->numberOfTable *16;i++)cout<<"-";
    cout<<"\n";
    cout<<"Status\t|";
    for(auto x : listTables)
    {
        if(x.getStatus() == 0)cout<<"\t"<<"\t|";
        else cout<<"\t"<<"X"<<"\t|";
    }
    cout<<"\n\n"; 
}
void Staff::chooseTable(){
    do{
        cout<<"Choose Table: ";
        cin>>this->currentTable;
    }while(this->currentTable > numberOfTable);
    if(listTables[currentTable - 1].getStatus() == 0) listTables[currentTable - 1].setStatus(1);
    displayMenuStaff();
}

void Staff::displayMenuStaff(){
    again:
    cout<<"-------------------------"<<endl;
    cout<<"Table "<<this->currentTable<<":"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"1. Add Item"<<endl;
    cout<<"2. Revise Item"<<endl;
    cout<<"3. Remove Item"<<endl;
    cout<<"4. List of Item"<<endl;
    cout<<"5. Cash PayMent"<<endl;
    cout<<"0. Back to Table Status"<<endl;
    do{
        cout<<"Enter your choice: ";
        cin>>this->choiceOption;
    }while(this->choiceOption<0 || this->choiceOption>5 ); 
    chooseMenuStaff();
    if(this->returnOption == 2) goto again;
}

void Staff::addItem(table &table){
    again:
    int quantity;
    int id;
    int choice;
    cout<<"-------------------------"<<endl;
    cout<<"\tAdd Item"<<endl;
    cout<<"-------------------------"<<endl;
    displayList();
    cout<<"Choose Item ID: ";
    cin>>id;
    for(auto x:*listItems)
    {
        if(x.getID() == id)
        {
            cout<<"You choosed "<<x.getName()<<endl;
            cout<<"Please Enter Quantity: ";
            cin>>quantity;
            ItemBuy newItem(id,x.getName(),x.getPrice(),quantity);
            table.bill.push_back(newItem);
            this->displayBill(table);
            do{
                cout<<"-----------------------------------------------------------"<<endl;
                cout<<"1. Continue Add Another Item"<<endl;
                cout<<"0. Return Staff Menu"<<endl;
                cout<<"Your choice: ";
                cin>>choice;
            }while(choice <0 || choice>1);
            switch (choice)
            {
            case 0:
                this->returnOption = 2;
                break;
            case 1:
                goto again;
            default:
                break;
            }
        }
    }
}

void Staff::displayItem(ItemBuy x){
     cout<<"-----------------------------------------------------------------------"<<endl;
    cout<<"Id\t\tName\t\tPrice (vnd)\t\tQuantity"<<endl;
    cout<<x.getID()<<"\t\t"<<x.getName()<<"\t\t"<<x.getPrice()<<"\t\t\t"<<x.getQuantity()<<endl;
}

void Staff::displayBill(table table){
    int choice;
    cout<<"-------------------------------------------------------------------------"<<endl;
    if(table.bill.size() == 0)cout<<"List Is Empty!!!"<<endl;
    else
    {
        int i = 0;
        cout<<"List Of Items"<<endl;
        cout<<"Number\t\tId\t\tName\t\tPrice (vnd)\t\tQuantity"<<endl;
       for(auto x:table.bill)
       {
            i++;
            cout<<i<<"\t\t"<<x.getID()<<"\t\t"<<x.getName()<<"\t\t"<<x.getPrice()<<"\t\t\t"<<x.getQuantity()<<endl;
       }
    }
     if(this->choiceOption == 4){
        do{
            cout<<"Press 0 to return Menu Manage: ";
            cin>>choice;
            this->returnOption = 1;
        }while(choice != 0);
    }
};


void Staff::displayItemsBought(table table){
    int choice;
    this->displayBill(table); 
}

void Staff::reviseItem(table &table){
    int id;
    int quantity;
    int choice = 2;
    again:
    this->displayBill(table);
    again2:
    cout<<"Revise ID: ";
    cin>>id;
    for(auto &x: table.bill)
    {
        if(x.getID() == id) 
        {
            this->displayItem(x);
            cout<<"Revise Quantity: ";
            cin>>quantity;
            x.setQuantity(quantity);
            this->displayItem(x);
            do{
                cout<<"-----------------------------------------------------------"<<endl;
                cout<<"1. Continue Revise"<<endl;
                cout<<"0. Return Staff Menu"<<endl;
                cout<<"Your choice: ";
                cin>>choice;
            }while(choice <0 || choice>1);
            switch (choice)
            {
            case 0:
                this->returnOption = 2;
                break;
            case 1:
                goto again;
            default:
                break;
            }
        }
    }
        if(choice == 3){
        cout<<"ID doesn't exist"<<endl;
        goto again2;
    }
}
void Staff::chooseMenuStaff(){
    switch (this->choiceOption)
    {
        case 1:
            addItem(listTables[currentTable]);
            break;
        case 2:
            reviseItem(listTables[currentTable]);
            break;
        // case 3:
        //     delectItem(listTables[currentTable].bill);
        //     break;
        case 4:
           displayBill(listTables[currentTable]);
            break;
        // case 5:
        //     listTables[currentTable].payMent();
        //     break;
        case 0:
            this->returnOption = 1;
            break;
        default:
            break;
    }
}
class mainMenu{
    private:
        int numberOfTable;
        vector<Item>listItems; 
        int choiceMenu;
    public:
        mainMenu();
        void displayMainMenu();
        void chooseMenu();
        void menuManage();
        void menuStaff();
};
mainMenu::mainMenu(){
    this->numberOfTable = 1;
    again:
    displayMainMenu();
    chooseMenu();
    goto again;
}
void mainMenu::displayMainMenu(){
    cout<<"-------------------------"<<endl;
    cout<<"\tMain Menu"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"1. Manager"<<endl;
    cout<<"2. Employee"<<endl;
    do{
        cout<<"Enter your choice: ";
        cin>>this->choiceMenu;
    }while(this->choiceMenu != 1 && this->choiceMenu != 2); 
}
void mainMenu::chooseMenu(){
    switch (this->choiceMenu)
    {
        case 1:
            menuManage();
            break;
        case 2:
            menuStaff();
            break;
        default:
            break;
    }
}
void mainMenu::menuManage(){
   static Manage menu(this->listItems,this->numberOfTable);
    again:
        menu.displayMenuManage();
        menu.chooseManage();
        if(menu.returnOption == 1)goto again;       
}
void mainMenu::menuStaff(){
    static Staff menu(this->listItems,this->numberOfTable);
    again:
        menu.displayStatusTable();
        menu.chooseTable();
        if(menu.returnOption == 1)goto again;
}

int main(){
    mainMenu mainMenu;
    return 0;
}