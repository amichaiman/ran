using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            Date d1 = new Date();
            Date d2 = new Date(2013, 5, 23);
            
            
            Date d3 = d2.addDays(15);
            double periodInDayd = d3.daysSince (d2);
				
            Console.WriteLine(d1.getFormattedString());
            Console.WriteLine(d2.getFormattedString());
            Console.WriteLine(d3.getFormattedString());
            Console.WriteLine (periodInDayd);
        }
    }
}
