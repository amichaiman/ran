using System;
using System.Globalization;
using System.Threading;

namespace hw_c_sharp_1
{
    public class Rectangle
    {
        
        private int width;
        private int height;

        public int Width
        {
                // הסט והגט משמשים רק לבדיקת ושינוי קלט במקרה הצורך
            set
            {
                if (value <= 0)
                {
                    Console.WriteLine("Autocorrect. width = 1");
                    width = 1;
                }
                else
                {
                    width = value;
                }
            }
            get { return width; }
            
        } //כותבים ווידת עם אות גדולה 
        public int Height
        {
            // הסט והגט משמשים רק לבדיקת ושינוי קלט במקרה הצורך
            set
            {
                if (value <= 0)
                {
                    Console.WriteLine("Autocorrect. height = 1");
                    height = 1;
                }
            }
            get { return height; }
            
        }
        public char Tav { get; set; }
        public bool IsFrame { get; set; }
        
                
    
    
        public void intializeFromUser() //פונקציה שקולטת נתונים מהמשתמש
        {
            Console.WriteLine("Enter the width:");
            Width = int.Parse(Console.ReadLine()); //עוברים דרך הווידת עם האות הגדולה רק כדי לסנן קלט לא חוקי
             
            Console.WriteLine("Enter the hight:");
            Height= int.Parse(Console.ReadLine()); //עוברים דרך הווידת עם האות הגדולה רק כדי לסנן קלט לא חוקי

            Console.WriteLine("enter the char:");
            Tav = char.Parse(Console.ReadLine());
            
            Console.WriteLine("do you want it with fra");
            if (Console.ReadLine().ToLower().Equals("yes")) //אם מה שקלטנו - באותיות שהומרו לקטנות-מהמשתמש הוא סטרינג של יס אז
            {
                IsFrame = true;
            }
            else
            {
                IsFrame = false;
            }
        }

        public void PrintRectangleInfo()
        {
            Console.WriteLine("width is {0}, hight is {1}, char is {2}, isframe is {3}", Width , Height , Tav , IsFrame  );
        }

        public void DrawRectangle()
        {
            if(!IsFrame)  //אם איז פריים זה פלס כלומר זה לא רק מסגרת
            {
                for (int i = 0; i < Height; i++)
                {
                    for (int j = 0; j < Width; j++)
                    {
                        Console.Write(Tav);
                    }
    
                    Console.WriteLine();
                }
                
            }
            else
            {
                for (int i = 0; i < Width; i++)
                {
                    Console.Write(Tav);  //כלומר הדפסנו שורה ראשונה
                }

                Console.WriteLine();
                
                //עכשיו עושים את האמצע

                for (int i = 0; i < Height-2; i++) //כמה פעמים אנחנו מבצעים את האמצע, פחות שתיים כלומר פחות הראשונה והאחרונה
                {
                    Console.Write(Tav); //תו ראשון
                    for (int j = 0; j < Width-2; j++)
                    {
                        Console.Write(" ");  //כל האמצע רווחים רווחים
                    }
                    Console.WriteLine(Tav); //תו אחרון
                }
                
                
                for (int i = 0; i < Width; i++)
                {
                    Console.Write(Tav);  //כלומר הדפסנו שורה אחרונה
                }
            
             
               
            }
        }

        public int CalculateArea()
        {
            return Width * Height;

        }

        public void AddToWidthSize(int sizeWidthToAdd)
        {
            Width = Width + sizeWidthToAdd;
        }
        
        
        public void AddToHeightSize(int sizeHeightToAdd)
        {
            Height = Height + sizeHeightToAdd;
            
        }
        
    }
    
}