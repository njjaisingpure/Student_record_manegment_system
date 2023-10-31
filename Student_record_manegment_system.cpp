#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

class student
{

private:
    string name, roll_no, ERP_id, contact_info, emailid, address, passout_year, branch;

public:
    void menu();
    void create();
    void display();
    void modify();
    void deletew();
    void searchw();
};

void student ::display()
{
    system("cls");
    fstream file;
    file.open("Studentdata.txt", ios::in);
    cout << "\t\t\t-----------------------" << endl;
    cout << "\t\t\tDisplaying student data" << endl;
    cout << "\t\t\t-----------------------" << endl;
    if (!file)
    {
        int qw;
        cout << "\t\t\tData File not present or Created" << endl;
        cout << "\t\t\t1.go back to menu         2.exit" << endl;
        cin >> qw;
        file.close();
        if (qw == 1)
        {
            menu();
        }
        if (qw == 2)
        {
            exit(0);
        }
    }
    else
    {
        int ry = 0;
        file >> ERP_id >> name >> roll_no >> branch >> contact_info >> emailid >> passout_year >> address;
        while (!file.eof())
        {
            cout << "\n\n\t\t\tStudent No.: " << ry++ << endl;
            cout << "\t\t\tStudent Name: " << name << endl;
            cout << "\t\t\tStudent Branch: " << branch << endl;
            cout << "\t\t\tStudent ERP No.: " << ERP_id << endl;
            cout << "\t\t\tStudent RollNo.: " << roll_no << endl;
            cout << "\t\t\tStudent Mobile No.: " << contact_info << endl;
            cout << "\t\t\tStudent Email ID: " << emailid << endl;
            cout << "\t\t\tStudent Address: " << address << endl;
            cout << "\t\t\tStudent Passout Year: " << passout_year << endl;
            file >> ERP_id >> name >> roll_no >> branch >> contact_info >> emailid >> passout_year >> address;
        }
        if (ry == 0)
        {
            int ui;
            file.close();
        kiie:
            system("cls");
            cout << "\t\t\tNo Data is Present or Inserted" << endl;
            cout << "\t\t\t1.Go to menu            2.exit" << endl;
            cin >> ui;
            if (ui == 1)
            {
                menu();
            }
            if (ui == 2)
            {
                exit(0);
            }
            else
            {
                cout << "\t\t\tEnter corect option" << endl;
                goto kiie;
            }
        }
        while (true)
        {
            int ty;
            cout << "\t\t\t1.Go to menu     2.exit" << endl;
            cin >> ty;
            if (ty == 1)
            {
                menu();
            }
            if (ty == 2)
            {
                exit(0);
            }
            else
            {
                cout << "\t\t\tTry again 1.Goto menu 2.exit" << endl;
                cin >> ty;
            }
        }
        file.close();
    }
}

void student ::modify()
{
    fstream file, file1;
    string eprii;
    int cote = 0;
    system("cls");
    cout << "\t\t\t--------------------" << endl;
    cout << "\t\t\tStudent Modification" << endl;
    cout << "\t\t\t--------------------" << endl;
    file.open("Studentdata.txt", ios ::in);
    if (!file)
    {
        cout << "\t\t\tNo Data is present" << endl;
        file.close();
    }
    else
    {
        cout << "\t\t\tEnter the ERP id of student to modify" << endl;
        cin >> eprii;
        file1.open("Modifi.txt", ios::app | ios::out);
        file >> ERP_id >> name >> roll_no >> branch >> contact_info >> emailid >> passout_year >> address;
        while (!file.eof())
        {
            if (eprii != ERP_id)
            {
                file1 << " " << ERP_id << " " << name << " " << roll_no << " " << branch << " " << contact_info << " " << emailid << " " << passout_year << " " << address << "\n";
            }
            else
            {
                getchar();
                cout << "Student Name:";
                cin >> name;
                cout << "Student Branch:";
                cin >> branch;
                cout << "Student ERP No.:";
                cin >> ERP_id;
                cout << "Student RollNo.:";
                cin >> roll_no;
                cout << "Student Mobile No.:";
                cin >> contact_info;
                cout << "Student Email ID:";
                cin >> emailid;
                cout << "Student Address:";
                cin >> address;
                cout << "Student Passout Year:";
                cin >> passout_year;
                file1 << " " << ERP_id << " " << name << " " << roll_no << " " << branch << " " << contact_info << " " << emailid << " " << passout_year << " " << address << "\n";
                cote++;
                while (true)
                {
                    int ut;
                    system("cls");
                    cout << "\t\t\t1.modify again 2.display 3.menu" << endl;
                    cin >> ut;
                    if (ut == 1)
                    {
                        modify();
                    }
                    else if (ut == 2)
                    {
                        display();
                    }
                    else if (ut == 3)
                    {
                        menu();
                    }
                }
            }
            file >> ERP_id >> name >> roll_no >> branch >> contact_info >> emailid >> passout_year >> address;
        }
        if (cote == 0)
        {
            int e;
        t:
            // system("cls");
            cout << "\t\t\tStudent ERP ID no not found" << endl;
            cout << "\t\t\t1.try again  2.menu" << endl;
            cin >> e;
            switch (e)
            {
            case 1:
                modify();
                break;
            case 2:
                menu();
                break;
            default:
                cout << "\t\t\tEnter correct option" << endl;
                goto t;
                break;
            }
        }
        file1.close();
        file.close();
        remove("Studentdata.txt");
        rename("Modifi.txt", "Studentdata.txt");
    }
}

void student ::deletew()
{
    system("cls");
    fstream file, file1;
    string ides;
    int count = 0;
    file.open("Studentdata.txt", ios::in);
    cout << "\t\t\t---------------------" << endl;
    cout << "\t\t\tStudent Data Deletion" << endl;
    cout << "\t\t\t---------------------" << endl;
    if (!file)
    {
        int up;
        file.close();
    qa:
        cout << "\t\t\tNo File Data Present or not creates" << endl;
        cout << "\t\t\t1.menu     2.Create file     3.exit" << endl;
        cin >> up;
        switch (up)
        {
        case 1:
            menu();
            break;
        case 2:
            create();
            break;
        case 3:
            exit(0);
        default:
            cout << "\t\t\tEnter valid option" << endl;
            goto qa;
        }
    }
    else
    {
        cout << "\t\t\tEnter the ERP id of the Student" << endl;
        cin >> ides;
        file1.open("Modifi.txt", ios ::app | ios ::out);
        file >> ERP_id >> name >> roll_no >> branch >> contact_info >> emailid >> passout_year >> address;
        while (!file.eof())
        {
            if (ides != ERP_id)
            {
                file1 << " " << ERP_id << " " << name << " " << roll_no << " " << branch << " " << contact_info << " " << emailid << " " << passout_year << " " << address << endl;
            }
            else
            {
                system("cls");
                count++;
                int cytew;
                cout << "\t\t\tSucessfully deleated the Student data" << endl;
                goto yutere;
            }
            file >> ERP_id >> name >> roll_no >> branch >> contact_info >> emailid >> passout_year >> address;
        }
        if (count == 0)
        {
        haa:
            system("cls");
            int yre;
            cout << "\t\t\tStudent ERP ID not FOUND!" << endl;
            getchar();
            cout << "\t\t\t1.try again       2.menue" << endl;
            cin >> yre;
            switch (yre)
            {
            case 1:
                deletew();
                break;
            case 2:
                menu();
                break;
            default:
                goto haa;
            }
        }
    yutere:
        while (true)
        {
            int cuoisee;
            cout << "\t\t\t1.Go back to menu       2.exit" << endl;
            cin >> cuoisee;
            if (cuoisee == 1)
            {
                file1.close();
                file.close();
                remove("Studentdata.txt");
                rename("Modifi.txt", "Studentdata.txt");
                menu();
            }
            if (cuoisee == 2)
            {
                file1.close();
                file.close();
                remove("Studentdata.txt");
                rename("Modifi.txt", "Studentdata.txt");
                exit(0);
            }
        }
    }
}

void student ::searchw()
{
    system("cls");
    fstream file;
    file.open("Studentdata.txt", ios::in);
    if (!file)
    {
        while (true)
        {
            system("cls");
            int tre;
            cout << "\t\t\tNo Data is present" << endl;
            cout << "\t\t\t1.Go back   2.exit" << endl;
            cin >> tre;
            if (tre == 1)
            {
                menu();
            }
            if (tre == 2)
            {
                system("cls");
                exit(0);
            }
        }
    }
    else
    {
        string erp;
        int cot = 0;
        cout << "\t\t\t---------------------\n";
        cout << "\t\t\t Student data Search" << endl;
        cout << "\t\t\t---------------------\n";
        cout << "\t\t\t To Search Enter Student ERP ID" << endl;
        cin >> erp;
        file >> ERP_id >> name >> roll_no >> branch >> contact_info >> emailid >> passout_year >> address;
        while (!file.eof())
        {
            if (erp == ERP_id)
            {
                system("cls");
                int ew;
                cout << "\t\t\tStudent Name: " << name << endl;
                cout << "\t\t\tStudent Branch: " << branch << endl;
                cout << "\t\t\tStudent ERP No.: " << ERP_id << endl;
                cout << "\t\t\tStudent RollNo.: " << roll_no << endl;
                cout << "\t\t\tStudent Mobile No.: " << contact_info << endl;
                cout << "\t\t\tStudent Email ID: " << emailid << endl;
                cout << "\t\t\tStudent Address: " << address << endl;
                cout << "\t\t\tStudent Passout Year: " << passout_year << endl;
                cot++;
                cout << "\t\t\t1.research       2.menu" << endl;
                cin >> ew;
                if (ew == 1)
                {
                    searchw();
                }
                if (ew == 2)
                {
                    menu();
                }
            }
        }
        file >> ERP_id >> name >> roll_no >> branch >> contact_info >> emailid >> passout_year >> address;
        if (cot == 0)
        {
            int re;
            cout << "\t\t\tNo Data Found" << endl;
            cout << "\t\t\t1.menu   2.exit" << endl;
            while (true)
            {
                cin >> re;
                if (re == 1)
                {
                    menu();
                }
                if (re == 2)
                {
                    exit(0);
                    file.close();
                }
            }
        }
        file.close();
    }
}

void student ::create()
{
    int opt;
    system("cls");
    cout << "\t\t\tNotice: Do you want to create new record\n";
    cout << "\t\t\t1.yes\t\t\t\t2.back\n";
    cin >> opt;
    if (opt == 1)
    {
        goto w;
    }
    if (opt == 2)
    {
        menu();
    }
    {
    w:
        system("cls");
        fstream file;
        cout << "--------------------------\n";
        cout << "----New Student Record----\n";
        cout << "--------------------------\n";
        getchar();
        cout << "Student Name:";
        getline(cin, name);
        cout << "Student Branch:";
        cin >> branch;
        cout << "Student ERP No.:";
        cin >> ERP_id;
        cout << "Student RollNo.:";
        cin >> roll_no;
        cout << "Student Mobile No.:";
        cin >> contact_info;
        cout << "Student Email ID:";
        cin >> emailid;
        cout << "Student Address:";
        cin >> address;
        cout << "Student Passout Year:";
        cin >> passout_year;
        file.open("Studentdata.txt", ios::app | ios::out);
        file << " " << ERP_id << " " << name << " " << roll_no << " " << branch << " " << contact_info << " " << emailid << " " << passout_year << " " << address << "\n";
        file.close();
        cout << " successfully created";
        system("cls");
        while (true)
        {
            int t;
            cout << "Do you want to enter another new record\n";
            cout << "1.yes      2.back to menu     3.Display\n";
            cin >> t;
            if (t == 1)
            {
                goto w;
            }
            if (t == 2)
            {
                menu();
            }
            if (t == 3)
            {
                display();
            }
        }
    }
}

void student ::menu()
{
    int choese;
menue:
    system("cls");
    cout << "\t\t\t-----------------------------\n";
    cout << "\t\t\t---Student Recod Manegment---\n";
    cout << "\t\t\t-----------------------------\n";
    cout << "\t\t\t1. Create new Record\n";
    cout << "\t\t\t2. Modify the Record\n";
    cout << "\t\t\t3. Search the Record\n";
    cout << "\t\t\t4. Delete the Record\n";
    cout << "\t\t\t5. Display the Record\n";
    cout << "\t\t\t6. exit\n";
    cout << "\t\t\t--------------------------------\n";
    cout << "\t\t\tChoese option from [1/2/3/4/5/6]\n";
    cout << "\t\t\t--------------------------------\n";
    cin >> choese;
    switch (choese)
    {
    case 1:
        create();
        break;
    case 2:
        modify();
        break;
    case 3:
        searchw();
        break;
    case 4:
        deletew();
        break;
    case 5:
        display();
        break;
    case 6:
        system("cls");
        exit(0);
    default:
        while (true)
        {
            system("cls");
            cout << "\t\t\tPlease enter valid choise Try Again\n";
            int x;
            cout << "\t\t\t1.try agian\t\t\t 2.to exit\n";
            cin >> x;
            if (x == 1)
            {
                // getchar();
                goto menue;
            }
            if (x == 2)
            {
                exit(0);
            }
        }
    }
}
int main()
{
    student data;
    data.menu();
    return 0;
}
