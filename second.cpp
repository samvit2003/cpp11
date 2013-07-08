int main()
{
  int x;      //Default Constructor
  int y{26};  //Copy Constructor
  int z = 27; //Copy Constructor
  z = x;      //Assignment
  
  bool isEq = (y == z);   //Equality
  bool isLt = (x < y);    //Order
  
  //Unary Operators
  y++;
  z--;
  
  //Binary Operators
  int a0 = x + y;
  int a1 = y - x;
  int a2 = x * y;
  int a3 = x / y;
  int a4 = x % y;
  
  return 0;
}
