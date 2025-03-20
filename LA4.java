import java.util.Scanner;

public class LA4 {
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        System.out.println("The pyramid shows the"+a+"Belows");
        for(int i=1;i<=a;i++)
        {
           int n=0;
            for(int j=1;j<=2*a-1;j++)
           {
               if(n==i)
               {
                   break;
               }
               if(j==a-i+2*(n))
               {
                   System.out.print('*');
                   n++;
               }
               else
               {
                   System.out.print(' ');
               }
           }
           System.out.println();        }
    }

}
