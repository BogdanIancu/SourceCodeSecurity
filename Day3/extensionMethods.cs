using System;

namespace ExtensionMethods
{
    static class ExtensionMethods
    {
        public static string toString(this int i)
        {
            return "Fooled you!";
        }
    }
	public class Program
	{
		public static void Main(string[] args)
		{
            int x = 99;
            //the proper call
            Console.WriteLine(x.ToString());
            //the call to the extension method
            Console.WriteLine(x.toString());
		}
	}
}