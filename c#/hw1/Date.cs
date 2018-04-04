using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.Remoting.Messaging;
using System.Text;

namespace ConsoleApplication1
{
	class Date
	{
		//data members
		private int year, month, day;
		
		double daysSince1_1_1900;

		//constructors
		public Date()
		{
			daysSince1_1_1900 = 0;
			year = 1900;
			month = 1;
			day = 1;
		}

		public Date(int year, int month, int day)
		{
			daysSince1_1_1900 = getDaysCount (year, month, day);
			
			if (year > 2018 || year < 1900)
			{
				this.year = 1900;	
			}
			else
			{
				this.year = year;
			}

			if (month > 12 || month < 1)
			{
				this.month = 1;	
			}
			else
			{
				this.month = month;	
			}

			if (day > 31 || day < 1)
			{
				this.day = 1;
			}
			else
			{
				this.day = day;	
			}
			
		}
		

		//public methods
		public string getFormattedString()
		{
			return "" + day + "/" + month + "/" + year; 	//12/4/2015
		}
		//מתודה שמחזירה תאריך חדש. התאריך החדש הוא התאריך הנוכחי+הפרמטר דייזטואד
		//returns a new date that is daysToAdd days ahead of this date
		public Date addDays(int daysToAdd)
		{
			//יצרנו תאריך חדש. היום שנתנו לו זה היום בעוד איקס ימים. כנל לגבי החודש והשנה
			Date newDate = new Date(getDay(daysToAdd),getMonth(daysToAdd),getYear(daysToAdd));
			
			return newDate;
		}
		//מחזיר את מספר הימים מהיום שהוזן עד התאריך הנוכחי
		//returns the number of days from the given date to this date
		public double daysSince(Date startDate)
		{
			return getDaysCount(year, month, day) - getDaysCount(startDate.year, startDate.month, startDate.day);
		}
		//***********************************************************//
		// The following methods are methods you can use for the 
		// completion of your task but you don't have to understand:
		//***********************************************************//
		//private methods
		private double getDaysCount(int year, int month, int day){
			//parameter verification
			return (new DateTime (year, month, day) - new DateTime(1900, 1, 1)).TotalDays;
		}
		//מחזיר מספר שמסמל את השנה בחודש בעוד איקס ימים מהיום
		//returns the year of a date represented by days passed since 1/1/1900
		private int getYear(double daysSince111900)
		{
			return new DateTime (1900, 1, 1).AddDays (daysSince111900).Year;
		}
		//מחזיר מספר שמסמל את vהחודש בעוד איקס ימים מהיום
		//returns the month of a date represented by days passed since 1/1/1900
		private int getMonth(double daysSince111900)
		{
			DateTime newdDateTime = new DateTime (1900, 1, 1);
			newdDateTime.AddDays(daysSince111900);
			
			return newdDateTime.Month;
		}
		
		//מחזיר מספר שמסמל את היום בחודש בעוד איקס ימים מהיום
		//returns the day of a date represented by days passed since 1/1/1900
		private int getDay(double daysSince111900)
		{
			return new DateTime (1900, 1, 1).AddDays (daysSince111900).Day;
		}
	}
}
