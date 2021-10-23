#include <iostream>
#include <fstream>
#include "Make Appointment.h"
#include "Display Reciept.h"
#include "Change Appointment.h"
#include "Delete Appointment.h"
using namespace std;

void welcome();
void actions();

//number of startup available cleaners
int availableCln = 30;

//functions for making a new appointment
void prices(int);
void newAppointment(appointment *, int);

//functions for calculating price & displaying reciept
void displayAppointment(appointment[]);
double totalprice(appointment[], int);
void receipt(appointment[]);
void partition();

//functions for updating info for existing appointments
void updateAppointment(appointment[]);
int verifyApt(appointment[], int);
int verifyUpdateCh();
void update(int, appointment[], int row);

//function for deleting an existing appointment
void deleteAppointment(appointment *);

//to track number of existing appointments
int numApp = 0;

int main()
{
     welcome();
     int userChoice;
     appointment customers[ROW];
     appointment *custPt = &customers[0];
     //initializing all aptId to 0
     for (int i = 0; i < ROW; i++)
          (custPt + i)->aptId = 0;

     //to track index of new appointments
     int i = 0;

     //continuously ask user what he wants to do, until he choose to exit program
     do
     {
          actions();

          //input user choice
          cout << "---Your Choice: ";
          cin >> userChoice;

          //check user choice
          if (userChoice == 1)
          {
               if (availableCln == 0)
               {
                    cout << "\nSorry, there are no available cleaners ;(\n\n";
                    system("pause");
                    system("cls");
               }

               else
               {
                    //display prices of Neat4U program
                    prices(availableCln);
                    //make new appointment
                    newAppointment(custPt, i);
                    ++numApp;
                    ++i;
                    system("pause");
                    system("cls");
               }
          }
          else if (userChoice == 2)
          {
               //display reciept
               displayAppointment(customers);
               system("pause");
               system("cls");
          }
          else if (userChoice == 3)
          {
               //update appointment info
               updateAppointment(customers);
               system("pause");
               system("cls");
          }
          else if (userChoice == 4)
          {
               //delete existing appointment
               deleteAppointment(custPt);
               system("pause");
               system("cls");
          }
          else if (userChoice == 5)
               break;
          else
          {
               cout << "\nInvalid Choice! Try Again...\n\n";
               system("pause");
               system("cls");
          }
     } while (true);

     cout << "\nNeat4U thanks you for your trust ;)\n\n";

     system("pause");
     return 0;
}

void welcome()
{
     cout << " ---------------------------------------------------------------------------\n"
          << "|                          Welcome to Neat4U                                |\n"
          << "|                          ===================                              |\n"
          << "| Neat4U is a specialized company that provides cleaning services for its   |\n"
          << "| beloved customers. Services are conducted in the form that our customers  |\n"
          << "| want. They can specify the service type: light, medium, or heavy cleaning.|\n"
          << "| They can also set the time of cleaning they need, ranging from 1 to 8     |\n"
          << "| hours. Not only that; they can specify the exact number of cleaners they  |\n"
          << "| need for the service.                                                     |\n"
          << "|                                                                           |\n"
          << "| Neat4U ensures that its customers feel comfortable with its services ;)   |\n"
          << "|                                                                           |\n"
          << " ---------------------------------------------------------------------------\n\n";

     system("pause");
     system("cls");
}

void actions()
{
     cout << "Neat4U Welcomes You ;)\n"
          << "1. Make a new appointment\n"
          << "2. Display reciept for existing appointment\n"
          << "3. Update existing appointment\n"
          << "4. Cancel existing appointment\n"
          << "5. Exit program\n";
}
