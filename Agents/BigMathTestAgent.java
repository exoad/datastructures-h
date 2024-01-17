import java.math.BigInteger;
import java.io.*;
import static java.lang.System.*;
import java.util.concurrent.TimeUnit;

/**
 * Controlled testing for BigMath by comparing the result from the executable file with the result from the BigInteger
 * class.
 * <p>
 * To use this class effectively, you need the following C++ Test File to bridge it:
 * <pre>
 * #include "BigMath.h"
 *
 * I32 main(int argc, CHAR* argv[])
 * {
 * string num1=argv[1];
 * string num2=argv[2];
 * BigMath n1=makeBigMath(num1);
 * BigMath n2=makeBigMath(num2);
 * BigMath res={0,nullptr};
 * if (argv[3][0]=='+')
 * res=n1+n2;
 * else if (argv[3][0]=='-')
 * res=n1-n2;
 * cout<<collateBigMath(res)<<endl;
 * }
 * </pre>
 * </p>
 *
 * @author Jack Meng (exoad)
 */
final class BigMathTestAgent
{
      // MODIFY TO MATCH YOUR ENVIRONMENT
      /** where the source file to launch the code is located */
      static final String CPP_FILE=".\\Projects\\BigMath_Test.cpp";
      /** where the exec file should be generated, usually no need to modify */
      static final String EXECUTABLE_FILE=".\\Projects\\BigMath_Testaa.out";

      // NO MODIFY
      static final char ADD='+';
      static final char SUBTRACT='-';

      // NO MODIFY
      static synchronized void test(String a,String b,char op)
      {
            assert op==ADD||op==SUBTRACT;
            BigInteger $a=new BigInteger(a);
            BigInteger $b=new BigInteger(b);
            assert $a.signum()!=-1&&$b.signum()!=-1;
            BigInteger $c=op==ADD
                        ? $a.add($b)
                        : $a.subtract($b);
            String c=$c.toString();
            String command=Shared.COMPILE_COMMAND+" "+CPP_FILE+" -o "+EXECUTABLE_FILE;
            try
            {
                  Process p=Runtime.getRuntime()
                                   .exec(command);
                  p.waitFor();
                  out.println(
                              p.exitValue()==0
                                          ? "compiled successfully"
                                          : "compile failed"
                  );
                  p=Runtime.getRuntime()
                           .exec(EXECUTABLE_FILE+" "+a+" "+b+" "+op);

                  p.waitFor(
                              2500,
                              TimeUnit.MILLISECONDS
                  );

                  if(p.isAlive())
                  {
                        p.destroy();
                        out.println("took too long for "+a+" "+op+" "+b+" = "+c+"!");
                        return;
                  }
                  if(p.exitValue()!=0)
                  {
                        out.println("exec failed");
                        return;
                  }
                  InputStream is=p.getInputStream();
                  BufferedReader br=new BufferedReader(new InputStreamReader(is));
                  String line;
                  while((line=br.readLine())!=null)
                        out.printf(
                                    line.equals(c)
                                                ? "OK got from exec: %s for %s %s %s = %s%n"
                                                : "ERROR from exec %s for %s %s %s = %s%n",
                                    line,
                                    a,
                                    op,
                                    b,
                                    c
                        );
            } catch(Exception e)
            {
                  e.printStackTrace();
            }
            out.println("=".repeat(44));
      }

      // MODIFY - add your own test cases
      public static void main(String... args)
      {
            out.println(new File(".").getAbsolutePath());
            test(
                        "3",
                        "5",
                        SUBTRACT
            ); // 8
            test(
                        "5",
                        "5",
                        ADD
            ); // 10
            test(
                        "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999",
                        "1",
                        ADD
            );
            test(
                        "12345",
                        "67890",
                        SUBTRACT
            );
            test(
                        "2000",
                        "3000",
                        SUBTRACT
            );
            test(
                        "3000",
                        "2000",
                        SUBTRACT
            );
            test(
                        "123456789012345678901234567890",
                        "987654321098765432109876543210",
                        ADD
            ); // 1111111111111111111011111111100
            test(
                        "987654321098765432109876543210",
                        "123456789012345678901234567890",
                        SUBTRACT
            ); // 864197531086419753208641975320
      }
}
