#pragma once
#include <iostream>
#include <iomanip>
#include "Make Appointment.h"
using namespace std;

extern int numApp;

void partition()
{
     for(int j=1 ; j<62 ; j++)
     	cout << "=";
     }

double totalprice(appointment app[], int i)
{
          double tPrice;	
	     //calculation for Heavy Cleaning Service
		if (app[i].type == 'H' || app[i].type == 'h')
		{
				//calculation for duration not more than 3 hours
                    if (app[i].duration <= 2)
				{
					tPrice = (40 + app[i].duration * 20) * app[i].cleaners;
				}
				//calculation for duration more than 2 hours
                    else if (app[i].duration > 2)
				{
					tPrice = (40 + 40 + ((app[i].duration - 2) * 18))* app[i].cleaners;
				}
		}
		//calculation for Medium Cleaning Service
          else if(app[i].type == 'M' || app[i].type == 'm')
		{
		
				//calculation for duration not more than 3 hours
                    if (app[i].duration <= 2)
				{
					tPrice = (25 + app[i].duration * 20) * app[i].cleaners;
				}
				//calculation for duration more than 2 hours
                    else if (app[i].duration > 2)
				{
					tPrice = (25 + 40 + ((app[i].duration - 2) * 18)) * app[i].cleaners;
				}
		}	
		//calculation for Light Cleaning Service
          else if(app[i].type == 'L' || app[i].type == 'l')
		{
		
				//calculation for duration not more than 3 hours
                    if (app[i].duration <= 2)
				{
					tPrice = (15 + app[i].duration * 20) * app[i].cleaners;
				}
				//calculation for duration more than 2 hours
                    else if (app[i].duration > 2)
				{
					tPrice = (15 + 40 + ((app[i].duration - 2) * 18)) * app[i].cleaners;
				}
		}	
	//return total price for the appointment
	return tPrice;
}

void receipt(appointment app[])
{
	int width = 60;
	int index;
	//can have only one variable
     //user input his appointment ID
          int displayId;
          cout << "\nEnter appointment ID to display reciept: ";
          cin >> displayId;
          cout << endl << endl;
          while(true)
          {
               for(int i=0 ; i < numApp ; i++)
     	    {
               //print reciept only if displayId exists
               if(displayId == app[i].aptId)
               {
                    	index = i;
                         //header of reciept
                         cout << setw(width / 3) << " " << "   Neat4You Sdn. Bhd.  " << endl;
                    	cout << setw(width / 3) << " " << "      IIUM Gombak." << endl;
                    	cout << setw(width / 3) << " " << "Contact: 019-21212121212" << endl;
     
                         partition();
     
                         //customer's personal details
                    	cout << "\n\nAppointment ID: " << setw(44)  << right << app[i].aptId << endl;	
                    	cout << "Name: " << setw(54) << right << app[i].name << endl;	
                    	cout << "Email: " << setw(53) <<  right << app[i].email << endl;
                    	cout << "PhoneNo: " << setw(51) <<  right << app[i].phoneNo << endl;
                         cout << "Address: " << setw(51) <<  right << app[i].address << endl;	
                    	cout << "Date: " << setw(54) <<  right << app[i].date << "\n" << endl;
                         
                         partition();
                         
                         //customer's appointment details
                    	//type of service
                         if(app[i].type == 'H' || app[i].type == 'h')
                    		cout << "\n\nType: " << setw(54) <<  right << "Heavy" << endl;
                    	
                         else if(app[i].type == 'M' || app[i].type == 'm')
                    		cout << "\n\nType: " << setw(54) <<  right << "Medium" << endl;
                    	
                         else if(app[i].type == 'L' || app[i].type == 'l')
                    		cout << "\n\nType: " << setw(54) <<  right << "Light" << endl;	
               		
                         //duration of cleaning
                         cout << "Duration: " << setw(47) <<  right << app[i].duration << " Hr" << endl;	
               		
                         //number of cleaners booked
                         cout << "No. of cleaner: " << setw(44) <<  right << app[i].cleaners << "\n" << endl;
                    
                         partition();
                         
                    	//price of appointment
                         cout << "\n\nAmount: " << setw(52) <<  right << app[i].price << endl;	
                    	
                         //footer of reciept
                         cout << "\n\t\t            Thank You" << endl;
                    	cout <<   "\t\t        See You next time.\n\n\n";
                         return;
                         }}
                    if(true)
                   {
                         cout << "Appointment ID not found! Try Again: ";
                         cin >> displayId;
                         cout << endl << endl;
                         }}
          
     
}

void displayAppointment(appointment app[])
{
     //check wherther there are existing appointments or not
    int x = 0;
    for(int i = 0; i < 30; i++)
    {
          if(app[i].aptId == 0)
               ++x;
          }
     
     //apply updating only if there are appointments
     if(x < 30)
     {
          //calculating price for all appointments
          for(int i =0 ; i < numApp ; i++)
     		app[i].price = totalprice(app, i);
     		
     	//displaying reciept for desired appointment ID
          receipt(app);	
          }
     else
          cout << "\nNo appointments available...\nTry to make one ;)\n\n";	
     }
