#include "hospital.h"
#include <limits>



string nmaes[MAX_specification+1][MAX_queue+1];
int status[MAX_specification+1][MAX_queue+1];
int Lingth_queu[MAX_specification+1];

void shift_right(int spe, string names[], int status[])
{
    int len = Lingth_queu[spe];
    for (int i = len; i >= 0; i--)
    {
        names[i + 1] = names[i];
        status[i + 1] = status[i];
    }
    Lingth_queu[spe]++;
}

void shift_left(int check, string names[], int status[])
{
    int len = Lingth_queu[check];
    for (int i = 0; i < len; i++)
    {
        names[i] = names[i + 1];
        status[i] = status[i + 1];
    }
    Lingth_queu[check]--;
}

void Get_next_patient()
{
    cout << "Enter specialization: " << endl;
    int check;
    cin >> check;
    int len = Lingth_queu[check];
    if (len <= 0)
    {
        cout << "No patients at the moment. Please rest, Doctor." << endl;
    }
    else
    {
        cout << nmaes[check][0] << ", please go with the Doctor." << endl << endl << endl;
        shift_left(check, nmaes[check], status[check]);
    }
}

void print_all_patients()
{
    for (int i = 1; i <= 20; i++)
    {
        int len = Lingth_queu[i];
        if (len > 0)
        {
            cout << "There are " << len << " patients in specialization " << i << endl;
            for (int j = 0; j < len; j++)
            {
                cout << " " << nmaes[i][j] << "   ";
                if (status[i][j] == 1)
                {
                    cout << "urgent" << endl;
                }
                else
                {
                    cout << "regular" << endl;
                }
            }
        }
    }
}

bool Add_new_patient()
{
    int speci;
    string name;
    int st;

         bool check ;
        do{
           check = true ;
            cout<<"Enter the numper of specialization :  " ;
             cin >> speci ;
             if(cin.fail() ){
                  cout << "Invalid input. Please enter a number.\n";
                  cin.clear();
                   cin.ignore(numeric_limits<streamsize>::max(), '\n');
                   check = false ;
             }

        }while( check == false) ;


cout << "\nEnter the name of the patient: ";
cin >> name ;

cout<<"\n Enter the status of patient ( 0 / 1 ) : " ;
cin >> st ;


    int pos = Lingth_queu[speci];

    if (pos >= MAX_queue)
    {
        cout << "Sorry, we can't add more patients for this specialization." << endl;
        return false;
    }

    if (st == 0)
    {
        nmaes[speci][pos] = name;
        status[speci][pos] = st;

        Lingth_queu[speci]++;
    }
    else
    {
        shift_right(speci, nmaes[speci], status[speci]);
        nmaes[speci][0] = name;
        status[speci][0] = st;
    }

    return true;
}

int menu()
{
    cout << "1) Add new patient." << endl;
    cout << "2) Print all patients." << endl;
    cout << "3) Get next patient." << endl;
    cout << "4) Exit." << endl;
    int numper;
    cin >> numper;
    cout << "_____________________________________" << endl;
    return numper;
}

int System_hospital()
{
    int system = true;
    while (system)
    {
        int chois = menu();
        if (chois == 1)
        {
            Add_new_patient();
        }
        else if (chois == 2)
        {
            print_all_patients();
        }
        else if (chois == 3)
        {
            Get_next_patient();
        }
        else
        {
            break;
        }
    }
    return 0;
}
