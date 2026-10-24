namespace Union
{
    class A
    {
        public readonly int x = 99;
    }

    //we define a class with the same memory layout
    class AA
    {
        public int x;
    }

    //and we do an union of the two classes
    [StructLayout(LayoutKind.Explicit)]
    class X_Modifier
    {
        [FieldOffset(0)] public A A;
        [FieldOffset(0)] public AA AA;
    }


    class Program
    {
        static void Main(string[] args)
        {
            var a = new A(); // a.X == 99

            //Changing AA's field leads to modification to A''s field
            var xModifier = new X_Modifier { A = a };
            xModifier.AA.x = -1;

            Console.WriteLine(a.x);
        }
    }
}