#include <iostream>
using namespace std;

class Uid 
{
 private:  int id;
 public:
		Uid():   id (0) { }
		int get() { return id; }
		void set (int new_id) 
			{
			 if (id == 0)
				id = new_id;
			 else
				throw exception("id already set!");
			}
};

