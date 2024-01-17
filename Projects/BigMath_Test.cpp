#include "BigMath.h"
#include "../test.h"

// please see Agents/BigMathTestAgent.java to utilize this class

#ifdef __MANUAL_TEST

I32 main(int argc, CHAR* argv[])
{
      string num1=argv[1];
      string num2=argv[2];
      BigMath n1=makeBigMath(num1);
      BigMath n2=makeBigMath(num2);
      BigMath res={0,nullptr};
      if (argv[3][0]=='+')
            res=n1+n2;
      else if (argv[3][0]=='-')
            res=n1-n2;
      cout<<collateBigMath(res)<<endl;
}

#else

I32 main(void)
{
      cout<<collateBigMath(makeBigMath("987654321098765432109876543210")-makeBigMath("123456789012345678901234567890"))<<endl;
      cout<<collateBigMath(makeBigMath("3")-makeBigMath("8"));
}

#endif