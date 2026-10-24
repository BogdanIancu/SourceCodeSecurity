using System;

namespace OptionalParameters
{

	class A
	{
		public virtual void PrintValue(int x = 1)
		{ 
			Console.WriteLine("A: " + x);
		}
		
	};

	class B : A
	{
		public override void PrintValue(int x = 2)
		{ 
			Console.WriteLine("B: " + x);
		}
		
	};

	public class Program
	{
		public static void Main(string[] args)
		{
            A a = new A();
			B b  = new B();
			a = b;
			a.PrintValue();
			b.PrintValue();
		}
	}
}