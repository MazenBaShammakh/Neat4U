#include <iostream>
#include "Make Appointment.h"
using namespace std;

extern int availableCln;

void deleteAppointment(appointment *app)
{
     //check wherther there are existing appointments or not
    int x = 0;
    for(int i = 0; i < 30; i++)
    {
          if((app+i)->aptId == 0)
               ++x;
          }
     
     //apply updating only if there are appointments
     if(x < 30)
     {
          //user enters aptId to be deleted
          int deleteId;
          cout << "\nEnter appointment ID to delete appointment: ";
          cin >> deleteId;
          cout << endl;
          
          while(true)
          {
               for(int i = 0; i < numApp; i++)
               {
                    //set all values to 0 or "" for chosen appointment
                    if(app[i].aptId == deleteId)
                    {
                         availableCln += app[i].cleaners;
                         (app + i)->aptId = 0;
                         (app + i)->name = "";
                         (app + i)->phoneNo = "";
                         (app + i)->email = "";
                         (app + i)->address = "";
                         (app + i)->date = "";
                         (app + i)->type = ' ';
                         (app + i)->cleaners = 0;
                         (app + i)->duration = 0.0;
                         (app + i)->price = 0;
                         (app + i)->gender = ' ';
                         cout << "Appointment deleted successfully!\n\n\n";
                         return;
                    }
               }
               
               if(true)
               {
                    cout << "Appointment ID not found! Try Again: ";
                    cin >> deleteId;
                    cout << endl;
                    }
               }          
          }
     else
          cout << "\nNo appointments available...\nTry to make one ;)\n\n";
}
