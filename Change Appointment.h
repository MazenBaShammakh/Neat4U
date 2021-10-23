#include <iostream>
#include "Make Appointment.h"
#include "Display Reciept.h"
using namespace std;

extern const int ROW = 30;
extern int numApp, availableCln;
     
int verifyApt(appointment app[], int id)
{    
    bool notFound = true;
    //prompt user for desiredId until it's found
    while(notFound)
    {
           //compare desiredId with all existing aptId
           for(int i = 0; i < numApp; i++)
           {
               //when desiredId is found
               if(id == app[i].aptId)
               {
                    notFound = false;
                    //alert user that appointment found
                    cout << "Appointment found!\n";
                    //return row index to track his appointment & personal details
                    return i;
                        }}
           //ask user to enter another desiredId if it's not found
           if(notFound)
           {
                       cout << "\nTry again...\n";
                       cout << "Enter your appointment ID: ";
                       cin >> id;
                       }}
     }
     
int verifyUpdateCh()
{
    int upCh;
    cout << "\n\nUpdate Name - 1\n"
         << "Update PhoneNo - 2\n"
         << "Update Email - 3\n"
         << "Update Address - 4\n"
         << "Update Service Type - 5\n"
         << "Update Number of Cleaners - 6\n"
         << "Update Duration - 7\n"
         << "--- Your Choice: ";
    cin >> upCh;
    cout << endl;
    while(true)
    {
           switch(upCh)
           {
                 case 1: return 1;
                 case 2: return 2;
                 case 3: return 3;
                 case 4: return 4;
                 case 5: return 5;
                 case 6: return 6;
                 case 7: return 7;
                 default: cout << "Invalid input... Try Again: ";
                          cin >> upCh;
              }
           }    
    }
    
void update(int ch, appointment app[], int row)
{
     
     switch(ch)
     {
                     //updating name    
             case 1: cout << "Updating Name: ";
                     //cin >> records[row].name;
                     //cin.clear();
                     //cin.ignore(1,'\0');
                     cin.ignore();
                     getline(cin,app[row].name); 
                     cout << "\nName updated successfully!\n";
                     break;
                     //updating phone number
             case 2: cout << "Updating PhoneNo: ";
                     //cin >> records[row].phoneNo;
                     //cin.clear();
                     cin.ignore();
                     getline(cin,app[row].phoneNo); 
                     cout << "\nPhoneNo updated successfully!\n";
                     break;
                     //updating email
             case 3: cout << "Updating Email: ";
                     //cin >> records[row].email;
                     //cin.clear();
                     cin.ignore();
                     getline(cin,app[row].email); 
                     cout << "\nEmail updated successfully!\n";
                     break;
                     //updating address
             case 4: cout << "Updating Address: ";
                     //cin >> records[row].address;
                     //cin.clear();
                     cin.ignore();
                     getline(cin,app[row].address); 
                     cout << "\nAddress updated successfully!\n";
                     break;
                     //updating service type
             case 5: cout << "Updating Service Type: ";
                     cin >> app[row].type;
                     while(app[row].type !='l'&& app[row].type !='L'  &&  app[row].type != 'M' && app[row].type !='m' && app[row].type !='H' && app[row].type !='h')
               	{
               		cout << "Invalid Input! Re-enter: ";
               		cin >> app[row].type;
               	}
                     cout << "\nService type updated successfully!\n";
                     break;
                     //updating number of cleaners
             case 6: int newCln;
                     cout << "Updating Number of Cleaners: ";
                     cin >> newCln;
                     while(newCln > (app[row].cleaners + availableCln) || app[row].cleaners <= 0)
               	{
                       //re-enter available number of cleaners
                       cout << availableCln + app[row].cleaners << " Cleaners Available ONLY. Re-enter: ";
                   	   cin >> newCln;
                    }
                    
                    if(newCln < app[row].cleaners)
                         availableCln += (app[row].cleaners - newCln);
                    else if(newCln > app[row].cleaners)
                         availableCln -= (newCln - app[row].cleaners);
                    app[row].cleaners = newCln;
                     cout << "\nNumber of cleaners updated successfully!\n";
                     break;
                     //updating duration of cleaning
             case 7: cout << "Updating Duration: ";
                     cin >> app[row].duration;
                     while(app[row].duration > 8 || app[row].duration <= 0)
               	{
               		cout << "Invalid Input! Re-enter (1-8): ";
               		cin >> app[row].duration;
               	}
                     cout << "\nDuration updated successfully!\n";
                     break;
             }
     
     //updating price        
     app[row].price = totalprice(app, row);
     
     }
     
void updateAppointment(appointment app[])
{
    //check wherther there are existing appointments or not
    int x = 0;
    for(int i = 0; i < ROW; i++)
    {
          if(app[i].aptId == 0)
               ++x;
          }
     
     //apply updating only if there are appointments
     if(x < ROW)
     {
          //propmt user to enter his aptId
         int updateId;
         cout << "\nEnter appointment ID to update info: ";
         cin >> updateId;
         cout << endl;
         
         //verify desiredId
         int aptRow = verifyApt(app,updateId);
         
         prices(availableCln);
         
         //asking user about his update choice
         int uChoice,updateAgain;
         do{
             uChoice = verifyUpdateCh();
             
             //calling updateProvile or updateAppointment
             update(uChoice,app,aptRow);
             
             //prompt user to update again or not
             cout << "\nUpdate one more time - 1\nDone updating my info - 0\n---Your choice: ";
             cin >> updateAgain;
             }while(updateAgain == 1);
          }
     else
          cout << "\nNo appointments available...\nTry to make one ;)\n";
     cout << endl;
    
     }
